/*
 * $Id: wip.prg 133 2012-04-20 23:35:49Z tfonrouge $
 *
 * Simple cpp source generator for qtHarbour bindings
 *
 * (C) 2012. qtHarbour     http://sourceforge.net/projects/qth/
 * (C) 2012. Teo Fonrouge  <tfonrouge/at/gmail/dot/com>
 *
 */

#ifdef __HBDEBUG
    #pragma debuginfo=on
#endif

#include "hbclass.ch"

#define _QTH_CLSTYPES_INC_      ".tmp/qth_clsTypes.inc"
#define _QTH_CASTDELETE_INC_    ".tmp/qth_castDeleteObj.inc"

STATIC hClsTypes

STATIC s_hEquiv := ;
    { ;
        "FILE"                                  => "void",;
        "float"                                 => "double",;
        "qint32"                                => "HB_INT",;
        "quint32"                               => "HB_UINT",;
        "qint64"                                => "HB_LONGLONG",;
        "qlonglong"                             => "HB_LONGLONG",;
        "QRgb"                                  => "HB_UINT",;
        "QFileInfoList"                         => "QList<QFileInfo>",;
        "QGradientStop"                         => "QPair<qreal,QColor>",;
        "QGradientStops"                        => "QVector<QGradientStop>",;
        "QItemSelection"                        => "QList<QItemSelectionRange>",;
        "qreal"                                 => "double",;
        "qulonglong"                            => "HB_ULONGLONG",;
        "short"                                 => "HB_SHORT",;
        "uchar"                                 => "HB_UCHAR",;
        "unsigned char"                         => "HB_UCHAR",;
        "ushort"                                => "HB_USHORT",;
        "uint"                                  => "HB_UINT";
    }

/*
    DescendFrom : returns .T. if clsName is descendant of clsParent
    Teo. Mexico 2012
*/
STATIC FUNCTION DescendFrom( clsName, clsParent )
    LOCAL recNo := QTHTREE->( RecNo() )

    clsParent := PadR( Upper( clsParent ), 40 )

    clsName := PadR( Upper( clsName ), 40 )

    IF clsName == clsParent
        RETURN .T.
    ENDIF

    QTHTREE->( OrdSetFocus( "X01" ) )

    QTHTREE->( DbSeek( clsName ) )

    WHILE Upper( QTHTREE->clsName ) == clsName
        IF Upper( PadR( QTHTREE->parent, 40 ) ) == clsParent
            QTHTREE->( DbGoTo( recNo ) )
            RETURN .T.
        ENDIF
        IF DescendFrom( QTHTREE->parent, clsParent )
            QTHTREE->( DbGoTo( recNo ) )
            RETURN .T.
        ENDIF
        QTHTREE->( DbSkip() )
    ENDDO

    QTHTREE->( DbGoTo( recNo ) )

RETURN .F.

/*
    Create_Tmp_Includes
    Teo. Mexico 2012
*/
FUNCTION Create_Tmp_Includes()
    LOCAL aWips
    LOCAL aLines
    LOCAL itm
    LOCAL fhClsTypes
    LOCAL fhCastDelete
    LOCAL s
    LOCAL clsName
    LOCAL fromStr
    LOCAL parentClsName
    LOCAL n
    LOCAL i

    fhClsTypes      := HB_FCreate( _QTH_CLSTYPES_INC_ )
    fhCastDelete    := HB_FCreate( _QTH_CASTDELETE_INC_ )

    aWips := Directory( "wip/*.wip" )

    ASort( aWips,,,{|x,y| Upper( x[ 1 ] ) < Upper( y[ 1 ] ) } )
    
    OpenTree( .T. )

    FOR EACH itm IN aWips
        aLines := File2Array( "wip/" + itm[ 1 ] )
        IF Len( aLines ) > 0
            clsName := SubStr( StrTran( itm[ 1 ], ".wip", "" ), 4 )
            n := AScan( aLines, {|e| s := HB_ATX( " *CLASS *.* FROM ", e ), !Empty( s ) } )
            IF n > 0
                fromStr := AllTrim( SubStr( aLines[ n ], Len( s ) + 1 ) )
                FOR i:=1 TO NumToken( fromStr, "," )
                    parentClsName := AllTrim( Token( fromStr, ",", i ) )
                    QTHTREE->( qthDbAppend() )
                    QTHTREE->clsname := clsName
                    QTHTREE->parent := parentClsName
                NEXT
            ENDIF
        ENDIF
    NEXT

    FOR EACH itm IN aWips
        aLines := File2Array( "wip/" + itm[ 1 ] )
        IF Len( aLines ) > 0
            clsName := SubStr( StrTran( itm[ 1 ], ".wip", "" ), 4 )
            FWrite( fhClsTypes, clsName )
            IF itm:__enumIndex < Len( aWips )
                FWrite( fhClsTypes, E",\n" )
            ENDIF
            IF !clsName == "Qt" .AND. !DescendFrom( clsName, "QObject" )
                FWrite( fhCastDelete, "case QtH::" + clsName + ": delete static_cast<" + clsName + E" *> (cppObjectPtr); break;\n" )
            ENDIF
        ENDIF
    NEXT

    FClose( fhCastDelete )
    FClose( fhClsTypes )

RETURN .T.

FUNCTION clsTypesList
    LOCAL a
    LOCAL itm

    IF hClsTypes = NIL
        hClsTypes := {}
        a := File2Array( _QTH_CLSTYPES_INC_ )
        FOR EACH itm IN a
            AAdd( hClsTypes, Token( itm, ", ", 1 ) )
        NEXT
    ENDIF

RETURN hClsTypes

FUNCTION equivList
RETURN s_hEquiv

FUNCTION ParseTypeInfo( line, paramParser, defValue )
    LOCAL tk
    LOCAL type
    LOCAL baseType
    LOCAL qualConst := .F.
    LOCAL targetName
    LOCAL isPointer
    LOCAL isReference
    LOCAL isVirtual
    LOCAL rawHbType
    LOCAL typeInfo
    LOCAL hbType
    LOCAL n
    LOCAL s
    LOCAL itm
    LOCAL nStart
    LOCAL typedef_mod

    typedef_mod := ;
        { ;
            "signed",;
            "unsigned";
        }

    tk := RTrim( Token( line, "(", 1 ) )

    WHILE .T.

        IF tk = "const"
            tk := SubStr( tk, 7 )
            qualConst := .T.
            LOOP
        ENDIF

        IF tk = "virtual"
            tk := SubStr( tk, 9 )
            isVirtual := .T.
            LOOP
        ENDIF

        EXIT

    ENDDO

    tk := AllTrim( tk )
    s := ""
    n := " "

    // removes extra spaces (more than two in a row)
    FOR EACH itm IN tk
        IF !itm == " " .OR. !n == " "
          s += itm
        ENDIF
        n := itm
    NEXT    

    tk := s

    // search for template token
    n := HB_At( ">", tk )
    IF n > 0
        baseType := Left( tk, n )
        ++n
    ELSE
    
        nStart := 1
        
        baseType := ""

        FOR EACH itm IN typedef_mod
            IF tk = itm
                baseType := itm + " "
                nStart := Len( itm ) + 1
                EXIT
            ENDIF
        NEXT

        baseType += Token( SubStr( tk, nStart ), " &*", 1 )

        n := Len( baseType ) + 1

    ENDIF

    s := AllTrim( SubStr( tk, n ) )
    
    IF !Empty( s )
        tk := s
    ENDIF
    
    isPointer := tk = "*"
    isReference := tk = "&"
    
    IF isPointer .OR. isReference
        type := baseType + Left( tk, 1 )
        tk := SubStr( tk, 2 )
    ELSE
        type := baseType
    ENDIF

    IF "const[]" $ tk
        tk := StrTran( tk, "const[]", "" )
    ENDIF

    targetName := AllTrim( tk )

    IF HB_HHasKey( s_hEquiv, baseType )
        hbType := s_hEquiv[ baseType ]
    ELSE
        hbType := baseType
    ENDIF

    rawHbType := Token( hbType, "<", 1 )

    SWITCH rawHbType
    CASE "HB_BOOL"
    CASE "bool"
        typeInfo := TType_Bool()
        EXIT
    CASE "HB_USHORT"
    CASE "HB_SHORT"
        typeInfo := TType_Short()
        EXIT
    CASE "HB_UINT"
    CASE "HB_INT"
    CASE "int"
        typeInfo := TType_Int()
        EXIT
    CASE "HB_ULONGLONG"
    CASE "HB_LONGLONG"
        typeInfo := TType_LongLong()
        EXIT
    CASE "ulong"
    CASE "long"
        typeInfo := TType_Long()
        EXIT
    CASE "double"
        typeInfo := TType_Double()
        EXIT
    CASE "void"
        typeInfo := TType_void()
        EXIT
    CASE "char"
    CASE "HB_UCHAR"
        typeInfo := TType_Char()
        EXIT
    CASE "QString"
        typeInfo := TType_QString()
        EXIT
    CASE "QHash"
        typeInfo := TType_QHash()
        EXIT
    CASE "QMap"
        typeInfo := TType_QMap()
        EXIT
    CASE "QVector"
        typeInfo := TType_QVector()
        EXIT
    CASE "QVariant"
        typeInfo := TType_QVariant()
        EXIT
    CASE "QList"
    CASE "QFileInfoList"
    CASE "QModelIndexList"
        typeInfo := TType_QList()
        typeInfo:QListTemplate := hbType
        EXIT
    OTHERWISE
        IF AScan( hClsTypes, {|e| e == hbType } ) = 0
            typeInfo := TType_Object()
        ELSE
            typeInfo := TType_Object()
        ENDIF
    ENDSWITCH

    typeInfo:hbType := hbType
    typeInfo:type := type
    typeInfo:baseType := baseType
    typeInfo:rawHbType := rawHbType
    typeInfo:qualConst := qualConst
    typeInfo:targetName := targetName
    typeInfo:isPointer := isPointer
    typeInfo:isReference := isReference
    typeInfo:isVirtual := isVirtual

    typeInfo:line := line
    IF paramParser != NIL
        typeInfo:paramParser := paramParser
        typeInfo:defValue := defValue
        typeInfo:paramIndex := Len( paramParser:aParams ) + 1
        typeInfo:paramIndexStr := LTrim( Str( typeInfo:paramIndex ) )
    ENDIF

RETURN typeInfo

/*
    Class TParamParser
    Teo. Mexico 2012
*/
CLASS TParamParser
PROTECTED:
    METHOD AddParamItem( param, defValue, qth_Flag )
EXPORTED:

    DATA aParams INIT {}
    DATA isConstructor
    DATA paramFooter INIT {}
    DATA paramHeader INIT {}
    DATA singleMethod
    DATA paramCheckList INIT ""
    DATA paramCount INIT 0
    DATA paramCountNoDef INIT 0
    DATA paramString INIT ""

    CONSTRUCTOR New

    METHOD GetParamsStr()

ENDCLASS

METHOD New( singleMethod ) CLASS TParamParser
    ::singleMethod := singleMethod
    ::isConstructor := ::singleMethod:returnParser:isConstructor == .T.
    ::GetParamsStr()
RETURN Self

METHOD PROCEDURE AddParamItem( param, defValue, qth_Flag ) CLASS TParamParser
    LOCAL singleParam
    
    singleParam := ParseTypeInfo( param, Self, defValue )
    
    singleParam:New()
    singleParam:qth_Flag := qth_Flag

    IF Empty( defValue )
        singleParam:BuildParameterSection()
    ELSE
        singleParam:BuildDefaultParameterSection()
    ENDIF

    AAdd( ::aParams, singleParam )

    IF !Empty( ::paramCheckList )
        ::paramCheckList += " && "
    ENDIF
    
    ::paramCheckList += singleParam:paramCheckString

    ++::paramCount
    ::paramString += singleParam:paramString

    IF defValue != NIL
        ::paramCountNoDef := NIL
    ELSE
        IF ::paramCountNoDef != NIL
            ++::paramCountNoDef
        ENDIF
    ENDIF

RETURN

METHOD PROCEDURE GetParamsStr() CLASS TParamParser
    LOCAL tk
    LOCAL paramSecc
    LOCAL c
    LOCAL param := ""
    LOCAL ptLevel := 0
    LOCAL lDone := .F.
    LOCAL defValue
    LOCAL line
    LOCAL tpLevel := 0
    LOCAL _qth_Flag
    LOCAL qth_Flag

    line := ::singleMethod:line

    tk := Token( line, "(", 1 )

    paramSecc := LTrim( RTrim( SubStr( line, Len( tk ) + 1 ) ) )

    FOR EACH c IN paramSecc

        IF c = "/"
            IF _qth_Flag = NIL
                _qth_Flag := .T.
                qth_Flag := ""
            ELSE
                _qth_Flag := NIL
            ENDIF
            LOOP
        ENDIF

        IF _qth_Flag == .T.
            qth_Flag += c
            LOOP
        ENDIF

        IF c = "="
            defValue := ""
            LOOP
        ENDIF

        IF defValue != NIL
            defValue += c
        ENDIF

        IF c = ">"
            --tpLevel
        ELSEIF c = "<"
            ++tpLevel
        ENDIF

        IF c = ")"
            --ptLevel
            IF ptLevel > 0
                LOOP
            ENDIF
            lDone := .T.
            IF defValue != NIL
                defValue := Left( defValue, Len( defValue ) - 1 )
            ENDIF
        ELSEIF c = "("
            ++ptLevel
            IF defValue = NIL
                ::paramString += c
            ENDIF
            LOOP
        ENDIF

        IF c $ ")," .AND. tpLevel = 0
            IF !Empty( param )
                IF defValue != NIL
                    IF c = ","
                        defValue := Left( defValue, Len( defValue ) - 1 )
                    ENDIF
                    defValue := LTrim( RTrim( defValue ) )
                ENDIF

                param := LTrim( RTrim( param ) )

                IF !Empty( param )
                    ::AddParamItem( param, defValue, qth_Flag )
                ENDIF

                param := ""
                defValue := NIL
                IF c = ")"
                    ::paramString += " "
                ENDIF
            ENDIF
            ::paramString += c
        ELSE
            IF defValue = NIL
                param += c
            ELSE
                //defValue += c
            ENDIF
        ENDIF

        IF lDone
            EXIT
        ENDIF

    NEXT

RETURN
/*
    EndClass TParamParser
*/

/*
    Class TType_Base
    Teo. Mexico 2012
*/
CLASS TType_Base
PROTECTED:
    METHOD idVarsString INLINE ::baseType + "::" + ::hbType + " "
EXPORTED:
    DATA _hb_checkType_ INIT "HB_IT_UNKOWN"
    METHOD _hb_par_ INLINE  "hb_par_" + ::baseType + "( " + ::paramIndexStr + " )"
    DATA _paramCheckString
    DATA _paramCheckString_Prefix
    DATA _paramStor INIT "hb_stor_UNKOWN( "
    DATA _paramString
    DATA baseType
    DATA classType INIT "classType_UNKOWN"
    DATA defValue
    DATA doNot     INIT NIL // if not NIL then it has the reason
    DATA hbType
    DATA indentStr INIT "    "
    DATA isConstructor
    DATA isPointer INIT .F.
    DATA isReference INIT .F.
    DATA isVirtual INIT .F.
    DATA line
    DATA paramIndex INIT 0
    DATA paramIndexStr INIT "0"
    DATA paramParser
    DATA qth_Flag
    DATA qualConst INIT .F.
    DATA rawHbType
    DATA retFooter INIT {}
    DATA retHeader INIT {}
    DATA retPrefix
    DATA retString INIT ""
    DATA retSuffix INIT " )"
    DATA targetName
    DATA type

    METHOD BuildDefaultParameterSection()
    METHOD BuildParamCheckString()
    METHOD BuildParamStorSection()
    METHOD BuildParameterSection()
    METHOD BuildReturnSection()
    METHOD enumType INLINE Token( ::hbType, "<", 1 )
    METHOD GetCastString()
    METHOD GetTargetName()
    METHOD IsParamByRef()
    METHOD paramCheckString
    METHOD paramString
    
    CONSTRUCTOR New()

ENDCLASS

METHOD New() CLASS TType_Base
    IF ::ClassName() == "TTYPE_BASE"
        ::_hb_checkType_ := "HB_IT_" + ::baseType
        ::_paramStor := "hb_stor_" + ::baseType + "( "
        ::classType := "classType_" + ::baseType
    ENDIF
RETURN Self

METHOD PROCEDURE BuildDefaultParameterSection() CLASS TType_Base
    LOCAL paramHeader
    
    ::BuildParamCheckString()

    IF ::_paramString = NIL

        IF ::IsParamByRef()
            ::_paramString := " &"
        ELSE
            ::_paramString := " "
        ENDIF

        ::_paramString += ::GetTargetName()

        paramHeader := iif( ::qualConst, "const ", "" )

        IF ::IsParamByRef()
            paramHeader += ::baseType
        ELSE
            paramHeader += ::type
        ENDIF

        paramHeader += " " + ::GetTargetName() + " = hb_param( " + ::paramIndexStr + ", " + ::_hb_checkType_ + " ) ? "

        paramHeader += ::GetCastString()

        paramHeader += ::_hb_par_ +  " : "
        IF ::IsDerivedFrom("TType_Object") .AND. ::defValue == "0"
            paramHeader += "( " + iif( "*" $ ::type, ::type, ::baseType ) + " ) "
        ENDIF
        paramHeader += ::defValue + ";"

        AAdd( ::paramParser:paramHeader, paramHeader )
        
        ::BuildParamStorSection()
        
    ELSE
        ::_paramString := ::GetCastString() + ::_paramString
    ENDIF

RETURN

METHOD PROCEDURE BuildParamCheckString() CLASS TType_Base
    LOCAL flags

    IF ::_paramCheckString = NIL

        flags := ""

        IF ::IsParamByRef()
            flags := "QTH_BYREF"
        ENDIF
        
        IF !Empty( ::defValue )
            flags += iif( !Empty( flags ), " | ", "" ) + "QTH_DEFAULT"
        ENDIF
        
        IF ::classType == "char" .AND. !::isPointer
            flags += iif( !Empty( flags ), " | ", "" ) + "QTH_SINGLECHAR"
        ENDIF

        IF !Empty( flags )
            flags := ", " + flags
        ENDIF
        
        flags += " )"

        IF ::_paramCheckString_Prefix = NIL
            ::_paramCheckString_Prefix := "qth_Is( " + ::paramIndexStr + ", "
            IF ::IsDerivedFrom("TType_Object")
                ::_paramCheckString_Prefix += E"\042" + ::classType + E"\042"
            ELSE
                ::_paramCheckString_Prefix += ::_hb_checkType_
            ENDIF
        ENDIF

        ::_paramCheckString := ::_paramCheckString_Prefix + flags

    ENDIF

RETURN

METHOD PROCEDURE BuildParameterSection() CLASS TType_Base
    LOCAL line

    ::BuildParamCheckString()
    
    IF ::_paramString = NIL
        ::_paramString := " " + ::_hb_par_
    ENDIF

    ::_paramString := ::GetCastString() + ::_paramString
    
    //::_paramString += " /* " + ::classType + " == " + ::baseType + " */"

    IF ::isReference
        line := ::baseType + " " + ::GetTargetName + " =" + ::_paramString + ";"
        AAdd( ::paramParser:paramHeader, line )
        ::_paramString := " " + ::GetTargetName()
    ELSEIF ::isPointer
        IF ::IsParamByRef()
            line := ::baseType + " " + ::GetTargetName + " =" + ::_paramString + ";"
        ELSE
            line := ::line + " =" + ::_paramString + ";"
        ENDIF
        IF "const[]" $ line // removes i.e.: const char* const[] xpm ...
            line := StrTran( line, "const[]", "" )
        ENDIF
        AAdd( ::paramParser:paramHeader, line )
        IF ::IsParamByRef()
            ::_paramString := " &" + ::GetTargetName()
        ELSE
            ::_paramString := " " + ::GetTargetName()
        ENDIF
    ENDIF

    ::BuildParamStorSection()

RETURN

METHOD PROCEDURE BuildParamStorSection() CLASS TType_Base
    IF ::IsParamByRef()
        AAdd( ::paramParser:paramFooter, "if( HB_ISBYREF( " + ::paramIndexStr + " ) )" )
        AAdd( ::paramParser:paramFooter, "{" )
        AAdd( ::paramParser:paramFooter, ::indentStr + ::_paramStor + ::targetName + ", " + ::paramIndexStr + " );" )
        AAdd( ::paramParser:paramFooter, "}" )
    ENDIF        
RETURN

METHOD PROCEDURE BuildReturnSection() CLASS TType_Base
    IF ::retPrefix = NIL
        ::retPrefix := "qth_errRT_PARAM(); //" + ::idVarsString
    ENDIF
RETURN

METHOD FUNCTION GetCastString() CLASS TType_Base
    LOCAL castString := ""

    IF !::classType == ::baseType
        IF ::IsParamByRef()
            castString := " (" + ::baseType + ") "
        ELSE
            castString := " (" + ::type + ") "
        ENDIF
    ENDIF        

RETURN castString

METHOD FUNCTION GetTargetName() CLASS TType_Base
    IF Empty( ::targetName )
        RETURN "p_" + Token( ::baseType, "<", 1 ) + ::paramIndexStr
    ENDIF
RETURN ::targetName

METHOD FUNCTION IsParamByRef() CLASS TType_Base
RETURN ::IsDerivedFrom( "TType_Scalar" ) .AND. ::classType != "char" .AND. ::isPointer

METHOD FUNCTION paramCheckString CLASS TType_Base
    IF ::_paramCheckString = NIL
        RETURN "DONT_KNOW_HOW_CHECK_PARAM_" + ::idVarsString
    ENDIF
RETURN ::_paramCheckString

METHOD FUNCTION paramString CLASS TType_Base
    IF ::_paramString = NIL
        RETURN " DONT_KNOW_HOW_TO_GET_PARAM_" + ::idVarsString
    ENDIF
RETURN ::_paramString
/*
    EndClass TType_Base
*/

/*
    Class TType_void
    Teo. Mexico 2012
*/
CLASS TType_void FROM TType_Base
    DATA classType INIT "void"
    METHOD _hb_par_
    METHOD BuildReturnSection()
    CONSTRUCTOR New()
ENDCLASS

METHOD New() CLASS TType_void
    IF ::isPointer
        ::_hb_checkType_ := "HB_IT_POINTER"
    ELSE
        ::_hb_checkType_ := "HB_IT_NIL"
    ENDIF
RETURN Self

METHOD FUNCTION _hb_par_ CLASS TType_void

    IF ::isPointer
        RETURN "hb_parptr( " + ::paramIndexStr + " )"
    ENDIF

RETURN ::super:_hb_par_

METHOD PROCEDURE BuildReturnSection() CLASS TType_void
    ::retPrefix := ""
    ::retSuffix := ""
    ::retFooter := "hb_ret();"
RETURN
/*
    EndClass TType_void
*/

/*
    Class TType_Base
    Teo. Mexico 2012
*/
CLASS TType_Scalar FROM TType_Base
PROTECTED:
EXPORTED:
ENDCLASS

/*
    EndClass TType_Scalar
*/

/*
    Class TType_Char
    Teo. Mexico 2012
*/
CLASS TType_Char FROM TType_Scalar
    DATA _hb_checkType_ INIT "HB_IT_STRING"
    DATA classType INIT "char"
    METHOD _hb_par_
    METHOD BuildReturnSection()
ENDCLASS

METHOD _hb_par_ CLASS TType_Char

    IF ::IsParamByRef() .OR. !::isPointer
        RETURN "hb_parc( " + ::paramIndexStr + " )[ 0 ]"
    ELSE
        RETURN "hb_parc( " + ::paramIndexStr + " )"
    ENDIF

RETURN ::super:_hb_par_

METHOD PROCEDURE BuildReturnSection() CLASS TType_Char
    IF ::isPointer
        ::retPrefix := "hb_retc( "
    ELSE
        ::retPrefix := ::baseType + " " + ::targetName + " = "
        ::retSuffix := ""
        ::retFooter := "hb_retclen( "
        IF !::classType == ::baseType
            ::retFooter += "(char *) "
        ENDIF
        ::retFooter += "&" + ::targetName + ", 1 );"
    ENDIF
    ::super:BuildReturnSection()
RETURN

/*
    EndClass TType_Char
*/

/*
    Class TType_Bool
    Teo. Mexico 2012
*/
CLASS TType_Bool FROM TType_Scalar
    DATA _hb_checkType_ INIT "HB_IT_LOGICAL"
    DATA _paramStor INIT "hb_storl( "
    METHOD _hb_par_ INLINE "hb_parl( " + ::paramIndexStr + " )"
    DATA classType INIT "bool"
    METHOD BuildReturnSection()
ENDCLASS

METHOD PROCEDURE BuildReturnSection() CLASS TType_Bool
    ::retPrefix := "hb_retl( "
    ::retSuffix := " == true )"
RETURN

/*
    EndClass TType_Bool
*/

/*
    Class TType_Numeric
    Teo. Mexico 2012
*/
CLASS TType_Numeric FROM TType_Scalar
    DATA _hb_checkType_ INIT "HB_IT_NUMERIC"
    METHOD _hb_par_ INLINE "hb_parn( " + ::paramIndexStr + " )"
ENDCLASS

/*
    EndClass TType_Numeric
*/

/*
    Class TType_Int
    Teo. Mexico 2012
*/
CLASS TType_Int FROM TType_Numeric
    DATA _hb_checkType_ INIT "HB_IT_INTEGER"
    METHOD _hb_par_
    DATA classType INIT "int"
    METHOD BuildReturnSection()
    CONSTRUCTOR New()
ENDCLASS

METHOD New() CLASS TType_Int
    IF ! ( ::baseType == "int" .OR. ::baseType == "uint" )
        ::_paramCheckString_Prefix := "qth_IsIntType( " + ::paramIndexStr + E", \042" + ::baseType + E"\042"
        IF Empty( ::defValue )
            ::_paramString := " qth_par_IntType( " + ::paramIndexStr + " )"
        ELSE
            ::_paramString := "qth_par_IntType( " + ::paramIndexStr + ", " + ::defValue + " )"
        ENDIF
    ENDIF
    ::_paramStor := "hb_storni( "
RETURN Self

METHOD FUNCTION _hb_par_ CLASS TType_Int

    IF ::baseType == "int" .OR. ::baseType == "uint"
        RETURN "hb_parni( " + ::paramIndexStr + " )"
    ENDIF

RETURN ""

METHOD PROCEDURE BuildReturnSection() CLASS TType_Int

    ::retPrefix := "hb_retni( "

RETURN

/*
    EndClass TType_Int
*/

/*
    Class TType_Short
    Teo. Mexico 2012
*/
CLASS TType_Short FROM TType_Numeric
    DATA _hb_checkType_ INIT "HB_IT_INTEGER"
    METHOD _hb_par_ INLINE "hb_parni( " + ::paramIndexStr + " )"
    DATA classType INIT "int"
    METHOD BuildReturnSection()
ENDCLASS

METHOD PROCEDURE BuildReturnSection() CLASS TType_Short

    ::retPrefix := "hb_retni( "

RETURN

/*
    EndClass TType_Short
*/

/*
    Class TType_Long
    Teo. Mexico 2012
*/
CLASS TType_Long FROM TType_Numeric
    DATA _hb_checkType_ INIT "HB_IT_LONG"
    METHOD _hb_par_ INLINE "hb_parnl( " + ::paramIndexStr + " )"
    DATA _paramStor INIT "hb_stornl( "
    DATA classType INIT "long"
    METHOD BuildReturnSection()
ENDCLASS

METHOD PROCEDURE BuildReturnSection() CLASS TType_Long

    ::retPrefix := "hb_retnl( "

RETURN

/*
    EndClass TType_Long
*/

/*
    Class TType_LongLong
    Teo. Mexico 2012
*/
CLASS TType_LongLong FROM TType_Numeric
    DATA _hb_checkType_ INIT "HB_IT_LONG"
    METHOD _hb_par_ INLINE "hb_parnll( " + ::paramIndexStr + " )"
    DATA _paramStor INIT "hb_stornll( "
    DATA classType INIT "longlong"
    METHOD BuildReturnSection()
ENDCLASS

METHOD PROCEDURE BuildReturnSection() CLASS TType_LongLong

    ::retPrefix := "hb_retnll( "

RETURN

/*
    EndClass TType_LongLong
*/

/*
    Class TType_Double
    Teo. Mexico 2012
*/
CLASS TType_Double FROM TType_Numeric
    DATA _hb_checkType_ INIT "HB_IT_DOUBLE"
    METHOD _hb_par_ INLINE "hb_parnd( " + ::paramIndexStr + " )"
    DATA _paramStor INIT "hb_stornd( "
    DATA classType INIT "double"
    METHOD BuildReturnSection()
ENDCLASS

METHOD PROCEDURE BuildReturnSection() CLASS TType_Double

    ::retPrefix := "hb_retnd( "

RETURN

/*
    EndClass TType_Double
*/

/*
    Class TType_QString
    Teo. Mexico 2012
*/
CLASS TType_QString FROM TType_Scalar
    DATA _hb_checkType_ INIT "HB_IT_STRING | HB_IT_OBJECT"
    DATA _paramStor INIT "qth_stor_QString( "
    DATA classType INIT "QString"
    METHOD _hb_par_ INLINE " qth_par_QString( " + ::paramIndexStr + " )"
    METHOD BuildReturnSection()
    CONSTRUCTOR New()
ENDCLASS

METHOD New() CLASS TType_QString
    ::_paramCheckString_Prefix := "qth_IsString( " + ::paramIndexStr
//    IF Empty( ::defValue )
//        ::_paramString := " qth_par_QString( " + ::paramIndexStr + " )"
//    ELSE
//        ::_paramString := " qth_par_QString( " + ::paramIndexStr + ", " + ::defValue + " )"
//    ENDIF
RETURN Self

METHOD PROCEDURE BuildReturnSection() CLASS TType_QString
    ::retPrefix := "qth_ret_QString( "
RETURN

/*
    EndClass TType_QString
*/

/*
    Class TType_Object
    Teo. Mexico 2012
*/
CLASS TType_Object FROM TType_Base
    DATA _hb_checkType_ INIT "HB_IT_OBJECT"
    METHOD _hb_par_
    METHOD BuildParameterSection()
    METHOD BuildReturnSection()
    CONSTRUCTOR New()
ENDCLASS

METHOD New() CLASS TType_Object
    ::classType := ::baseType
RETURN Self

METHOD FUNCTION _hb_par_ CLASS TType_Object
    LOCAL _hb_par_
    
    _hb_par_ := "qth_par" + iif( ::qualConst, "Const", "" ) + iif( ::isReference, "Ref", "" ) + iif( ::isPointer, "Ptr", "" )
    _hb_par_ += "<" + ::baseType + ">( " + ::paramIndexStr
    IF ::qth_Flag != NIL
        _hb_par_ += ", QTHI_" + Upper( ::qth_Flag ) + " "
    ENDIF
    _hb_par_ += " )"
    
RETURN _hb_par_

METHOD PROCEDURE BuildParameterSection() CLASS TType_Object
    LOCAL paramHeader

    IF ::baseType == "T"
        // type T ignored, is any type
        ::_paramCheckString := "true"
        ::_paramString := NIL
    ELSE
        ::_paramCheckString := "qth_IsObject( "
        ::_paramCheckString += ::paramIndexStr
        ::_paramCheckString += E", \042" + ::rawHbType + E"\042 )"

        IF ::qualConst
            ::_paramString := " " + ::GetTargetName()
            paramHeader := "const " + ::baseType + iif( ::isReference, " & ", " " ) + iif( ::isPointer, " * ", "" ) + ::GetTargetName() + " = "
            paramHeader += iif( ::isReference .OR. !::isPointer, "* ", "" )
            paramHeader += "static_cast<" + ::baseType + " *>"
            paramHeader += "( qth_par_QthObject( " + ::paramIndexStr
            IF ::qth_Flag != NIL
                paramHeader += ", QTHI_" + Upper( ::qth_Flag ) + " "
            ENDIF
            paramHeader += " ) );"
            AAdd( ::paramParser:paramHeader, paramHeader )
        ELSE
            IF ::isReference .OR. !::isPointer
                ::_paramString := " *"
            ELSE
                ::_paramString := ""
            ENDIF
            ::_paramString += " static_cast<" + ::baseType + " *>" + "( qth_par_QthObject( " + ::paramIndexStr
            IF ::qth_Flag != NIL
                ::_paramString += ", QTHI_" + Upper( ::qth_Flag ) + " "
            ENDIF
            ::_paramString += " ) )"
        ENDIF
    ENDIF

RETURN

METHOD PROCEDURE BuildReturnSection() CLASS TType_Object

    IF AScan( clsTypesList(), ::enumType ) > 0
        IF !DescendFrom( S_ClassName(), ::enumType )
            AddFunctionRequest( ::enumType )
        ENDIF
    ELSE
        ::doNot := "Don't know how to return type '" + ::enumType + "'"
    ENDIF

    IF !::isPointer .AND. !::isReference
        IF ::isConstructor == .T.
            ::retPrefix := "qth_itemPushReturn( QtH::" + ::GetTargetName() + ", new " + ::GetTargetName()
        ELSE
            ::retPrefix := "qth_itemPushNewReturn( QtH::" + ::enumType + ", new " + ::baseType + "( "
            ::retSuffix := E" ), \042" + ::baseType + E"\042 )"
        ENDIF
    ELSE
        ::retPrefix := "qth_itemReturn( (PCPP_OBJECT) "
        ::retPrefix += iif( ::isReference, " & ", "" )
        ::retSuffix := E", \042" + ::baseType + E"\042 )"
    ENDIF

RETURN

/*
    EndClass TType_Object
*/

/*
    Class TType_QHash
    Teo. Mexico 2012
*/
CLASS TType_QHash FROM TType_Object
    DATA QListTemplate
ENDCLASS

/*
    EndClass TType_QHash
*/

/*
    Class TType_QList
    Teo. Mexico 2012
*/
CLASS TType_QList FROM TType_Object
    DATA QListTemplate
ENDCLASS

/*
    EndClass TType_QList
*/

/*
    Class TType_QMap
    Teo. Mexico 2012
*/
CLASS TType_QMap FROM TType_Object
ENDCLASS

/*
    EndClass TType_QMap
*/

/*
    Class TType_QVector
    Teo. Mexico 2012
*/
CLASS TType_QVector FROM TType_Object
ENDCLASS

/*
    EndClass TType_QVector
*/

/*
    Class TType_QVariant
    Teo. Mexico 2012
*/
CLASS TType_QVariant FROM TType_Object
    DATA _hb_checkType_ INIT "HB_IT_ANY"
    METHOD _hb_par_ INLINE "qth_par_QVariant( " + ::paramIndexStr + " )"
    METHOD BuildParameterSection()
ENDCLASS

/*
    BuildParameterSection
    Teo. Mexico 2012
*/
METHOD PROCEDURE BuildParameterSection() CLASS TType_QVariant
    ::super:BuildParameterSection()
    ::_paramCheckString_Prefix := "qth_IsJuana( " + ::paramIndexStr
RETURN

/*
    EndClass TType_Double
*/

