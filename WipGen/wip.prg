/*
 * $Id: wip.prg 151 2012-12-20 21:53:28Z tfonrouge $
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

#define wipVer  "v0.1"
#define wipRev  "$Revision: 151 $"
#define wipFullVer  wipVer + "-" + Token( wipRev, " ", 2 )

#include "hbclass.ch"
#include "set.ch"
#include "dbinfo.ch"

#define QTH_ARGUMENT_ERROR  "qth_errRT_PARAM();"

REQUEST DBFCDX

STATIC s_aMethods := {}
STATIC s_bufferCPP := {}
STATIC s_clsName
STATIC s_cppClassName
STATIC s_Defines := {=>}
STATIC s_fnDD := "wip/db/qthdd.dbf"
STATIC s_fnTree := "wip/db/qthtree.dbf"
STATIC s_hEnums
STATIC s_hFunc
STATIC s_idString := ""
STATIC s_include
STATIC s_indentVal := "    "
STATIC s_index_Func_Extern_Requests
STATIC s_index_SymbolTable_Requests
STATIC s_maxFuncNameLen := 0
STATIC s_maxMethodNameLen := 0
STATIC s_numFuncs := 0
STATIC s_parentClass
STATIC s_requests := {}

STATIC s_sCredits := ;
    E" * (C) 2012. qtHarbour     http://sourceforge.net/projects/qth/\n" + ;
    E" * (C) 2012. Teo Fonrouge  <tfonrouge/at/gmail/dot/com>\n"

STATIC s_singleMethod
STATIC s_tkDelim := ":= "
STATIC s_type_Prototype
STATIC s_type_Prototype_Subtype
STATIC s_varName := "p_obj"
STATIC s_x, s_y

FUNCTION Main( arg, wipFile, cppFile )

    RddSetDefault( "DBFCDX" )
    Set( _SET_AUTOPEN, .T. )

    SWITCH arg
    CASE "-g"
    CASE "--generate"
        GenerateSource( wipFile, cppFile )
        EXIT
    CASE "--initialize"
        Create_Tmp_Includes()
        EXIT
    ENDSWITCH

RETURN NIL

FUNCTION GenerateSource( wipFile, cppFile )
    LOCAL aText
    LOCAL itm,line,lline
    LOCAL token
    LOCAL s
    LOCAL _dump_ := .F.
    LOCAL _public_types_ := .F.
    LOCAL _defined_types_ := .F.
    LOCAL _useAs_
    LOCAL inPrototypes := .F.
    LOCAL bufferToDump
    LOCAL e_Type, e_Value

#ifdef __HBDEBUG
    SetMode( 40, 100 )
#endif

    clsTypesList()

    s_hFunc := HB_HSetCaseMatch( HB_HSetOrder( { => }, .T. ), .F. )

    s_cppClassName := SubStr( HB_FNameName( wipFile ), 4 )

    IF !Empty( wipFile ) .AND. OpenTree() .AND. OpenDataDict()

        ? "Wip: generating bindings for " + wipFile + ",  method count: "

        s_x := Row()
        s_y := Col()

        aText := File2Array( wipFile )

        /* default namespaces used */
        IF !s_cppClassName == "Qt"
            Load_NameSpace( "namespace Qt" )
        ENDIF

        Load_NameSpace( "namespace " + s_cppClassName, .T. )

        FOR EACH itm IN aText

            line := RTrim( LTrim( itm ) )

            lline := Lower ( line )

            token := Token( lline, s_tkDelim, 1 )
            
            IF inPrototypes
                IF token == "#begindump"
                    bufferToDump := {}
                    LOOP
                ELSEIF token == "#enddump"
                    HB_HValueAt( s_hFunc, Len( s_hFunc ) ):bufferToDump := bufferToDump
                    bufferToDump := NIL
                    LOOP
                ELSEIF bufferToDump != NIL
                    AAdd( bufferToDump, itm )
                    LOOP
                ENDIF
                inPrototypes := Process_Prototypes( s_hFunc, lline, line )
                LOOP
            ENDIF

            SWITCH token
            CASE "class"
                IF "from" $ lline
                    s_clsName := LTrim( RTrim( Token( line, " ", 2 ) ) )
                    s_parentClass := SubStr( line, At( "FROM", line ) + 5 )
                    WriteClassDefinition()
                    LOOP
                ENDIF
            CASE "#varname"
                s := LTrim( RTrim( Token( line, s_tkDelim, 2 ) ) )
                IF !Empty( s )
                    s_varName := "p_" + s
                ENDIF
                LOOP
            CASE "#debug"
                AltD()
                LOOP
            CASE "#definclude"
                s_include := LTrim( RTrim( Token( line, s_tkDelim, 2 ) ) )
                LOOP
            CASE "namespace"
                Load_NameSpace( line )
                LOOP
            CASE "#begindump"
                WipWrite( E"/*\n * Wip: Dump Section INIT\n */\n\n" )
                _dump_ := .T.
                LOOP
            CASE "_begin_public_types_"
                _public_types_ := .T.
                LOOP
            CASE "_begin_defined_types_"
                _defined_types_ := .T.
                LOOP
            CASE "_public_functions_"
            CASE "_reimplemented_public_functions_"
            CASE "_public_slots_"
            CASE "_static_public_members_"
            CASE "_protected_functions_"
                Process_Prototypes( s_hFunc, lline, line )
                inPrototypes := .T.
                LOOP
            ENDSWITCH

            IF _dump_

                IF lline = "#enddump"
                    _dump_ := .F.
                    WipWrite( E"/*\n * Wip: Dump Section END\n */\n\n" )
                    LOOP
                ENDIF

                WipWrite( itm + E"\n" )

            ELSEIF _public_types_

                IF !Process_Public_Types( .T., lline, line, @_useAs_ )
                    _public_types_ := .F.
                ENDIF

                LOOP

            ELSEIF _defined_types_

                IF lline = "_end_defined_types_"
                    _defined_types_ := .F.
                    LOOP
                ENDIF

                equivList()[ Token( line, " ", 1 ) ] := Token( line, " ", 2 )

                LOOP

            ELSE

            ENDIF

        NEXT

        IF s_hEnums != NIL .AND. Len( s_hEnums["enums"] ) > 0

            s_type_Prototype := "_static_public_members_"
            s_type_Prototype_Subtype := "enum"

            FOR EACH e_Type IN s_hEnums["enums"]
                FOR EACH e_Value IN e_Type
                    Process_Prototypes( s_hFunc, Lower( e_Value ), e_Value, e_Type:__enumKey )
                NEXT
            NEXT

        ENDIF

        FOR EACH itm IN s_hFunc
            itm:WriteFunc()
        NEXT

        WipWrite( E"/*\n * Wip: Method's Declaration Section END\n */\n\n" )
        
        Write_RegisterMethods()
        
        ParseFunction_Requests()

        ?? "   Done."
        ?
        ?

        WriteBufferCPP( cppFile )

        UpdateQthNameSpace()

    ENDIF

RETURN .T.

PROCEDURE AddMethodName( funcName, fullFuncName )
    IF fullFuncName = NIL
        fullFuncName := funcName
    ENDIF
    AAdd( s_aMethods, { funcName, fullFuncName } )
    s_maxMethodNameLen := Max( s_maxMethodNameLen, Len( funcName ) + 2 )
    s_maxFuncNameLen := Max( s_maxFuncNameLen, Len( fullFuncName ) + 2 )
RETURN

PROCEDURE AddFunctionRequest( functionName )
    IF AScan( s_requests, functionName ) = 0
        AAdd( s_requests, functionName )
    ENDIF
RETURN

STATIC PROCEDURE Load_NameSpace( line, addEnums )
    LOCAL aLines
    LOCAL itm
    LOCAL lline
    LOCAL _useAs_
    LOCAL namespace
    LOCAL isInherited

    namespace := Token( line, " ", 2 )
    isInherited := Token( Lower( line ), " ", 3 ) == "inherited"

    IF addEnums == .T. .AND. !isInherited
        s_hEnums := {"lastToken"=>NIL,"enums"=>{=>}}
    ENDIF

    IF isInherited
        _useAs_ := namespace
    ENDIF

    aLines := File2Array( "wip/namespaces/" + namespace + ".namespace" )

    IF !Empty( aLines )
        FOR EACH itm IN aLines
            line := LTrim( RTrim( itm ) )
            lline := Lower( line )
            Process_Public_Types( addEnums, lline, line, @_useAs_, namespace )
        NEXT
    ENDIF

RETURN

STATIC FUNCTION OpenDataDict()

    IF !HB_FileExists( s_fnDD )

        DbCreate( s_fnDD, ;
            { { "CLSNAME"  , "C", 40, 0 },;
              { "FUNCNAME" , "C", 40, 0 },;
              { "CPROTO"   , "C", 80, 0 },;
              { "PROTECTED", "L",  1, 0 },;
              { "SCOPE"    , "C",  1, 0 } };
            )

        USE ( s_fnDD ) ALIAS QTHDD NEW

        INDEX ON Upper( FIELD->clsname ) + Upper( FIELD->funcname ) TAG X01

    ELSE

        USE ( s_fnDD ) ALIAS QTHDD NEW

    ENDIF

    QTHDD->( OrdSetFocus( "X01" ) )

    WHILE QTHDD->( DbSeek( Upper( PadR( s_cppClassName, 40 ) ) ) )
        QTHDD->clsname := ""
        QTHDD->funcname := ""
    ENDDO

RETURN .T.

FUNCTION OpenTree( create )

    IF create == .T.

        DbCreate( s_fnTree, ;
            { { "CLSNAME" , "C", 40, 0 },;
              { "PARENT"  , "C", 40, 0 } };
            )

        USE ( s_fnTree ) ALIAS QTHTREE NEW

        INDEX ON Upper( FIELD->clsname ) TAG X01
        INDEX ON Upper( FIELD->parent ) + Upper( FIELD->clsname ) TAG X02 ADDITIVE

        QTHTREE->( OrdSetFocus( "X01" ) )

    ELSE

        USE ( s_fnTree ) ALIAS QTHTREE NEW

        QTHTREE->( OrdSetFocus( "X01" ) )

    ENDIF

RETURN .T.

STATIC FUNCTION Process_Prototypes( s_hFunc, lline, line, enumMethod )
    LOCAL s

    IF !Empty( line )

        s := Token( lline, s_tkDelim, 1 )

        IF s_singleMethod = NIL
            s_singleMethod := TSingleMethod():New()
        ENDIF

        SWITCH s
        CASE "_public_functions_"
        CASE "_reimplemented_public_functions_"
        CASE "_public_slots_"
        CASE "_static_public_members_"
        CASE "_public_enum_types_"
        CASE "_protected_functions_"
            s_type_Prototype := s
            RETURN .T.
        ENDSWITCH

        s_singleMethod:type_Prototype := s_type_Prototype
        s_singleMethod:type_Prototype_Subtype := s_type_Prototype_Subtype
        s_singleMethod:_static_public_ := s_type_Prototype == "_static_public_members_"
        s_singleMethod:_protected_function_ := s_type_Prototype == "_protected_functions_"

        s_singleMethod:_enum_Method_ := enumMethod

        s_singleMethod:ProcessLine( line )

        IF s_singleMethod:returnParser != NIL

            /* ignore destructor */
            IF s_singleMethod:funcName = "~" .OR. s_singleMethod:funcName = "operator" .OR. line = "operator"
                s_singleMethod := NIL
                RETURN .T.
            ENDIF

            IF s_singleMethod:hasMethod
                IF Empty( enumMethod )
                    ++s_numFuncs
                ENDIF
                IF HB_HHasKey( s_hFunc, s_singleMethod:HBFuncName )
                    s_hFunc[ s_singleMethod:HBFuncName ]:AddMethod( s_singleMethod )
                ELSE
                    s_hFunc[ s_singleMethod:HBFuncName ] := TFuncStruct():New():AddMethod( s_singleMethod )
                ENDIF
                s_singleMethod := NIL
                @ s_x, s_y SAY Len( s_hFunc )
            ENDIF

        ENDIF

    ENDIF

RETURN .T.

STATIC FUNCTION Process_Public_Types( addEnums, lline, line, _useAs_, _namespace_ )
    LOCAL _cls_
    LOCAL _define_, _defineVal_
    LOCAL enumName
    LOCAL s

    IF !Empty( lline ) .AND. !lline = "//" .AND. !lline = "/*"

        IF lline = "_end_public_types_"
            RETURN .F.
        ENDIF

        _define_ := ""
        _defineVal_ := ""

        SWITCH Token( lline, " ", 1 )
        CASE "use"
            _useAs_ := Token( line, " ", 2 )
            RETURN .T.
        CASE "namespace"
            Load_NameSpace( line )
            RETURN .T.
        CASE "flags"
        CASE "enum"
            IF "::" $ line
                _defineVal_ := Token( line, " ", 2 )
                equivList()[ _defineVal_ ] := "int"
                _define_ := Token( line, ":", 2 )
                equivList()[ _define_ ] := "int"
            ELSE
                IF !Empty( _namespace_ )
                    _cls_ := _namespace_
                ELSE
                    _cls_ := s_cppClassName
                ENDIF
                _define_ := Token( line, " ", 2 )
                _defineVal_ := _cls_ + "::" + _define_
                equivList()[ _define_ ] := "int"
                equivList()[ _cls_ + "::" + Token( line, " ", 2 ) ] := "int"
            ENDIF
            EXIT
        OTHERWISE
            _define_ := Token( line, ": ", 2 )
            _defineVal_ := Token( line, " ", 1 )
        ENDSWITCH

        IF addEnums == .T. .AND. s_hEnums != NIL
            IF HB_HHasKey( s_hEnums, "addEnums" )
                IF lline = "}"
                    HB_HDel( s_hEnums, "addEnums" )
                    RETURN .T.
                ENDIF
                IF ! HB_HHasKey( s_hEnums["enums"], s_hEnums["addEnums"] )
                    s_hEnums["enums",s_hEnums["addEnums"]] := {} 
                ENDIF
                s := Token( line, " ", 1 )
                IF "::" $ line
                    enumName := Token( line, ": ", 2 )
                ELSE
                    enumName := s
                ENDIF
                AAdd( s_hEnums["enums",s_hEnums["addEnums"]], enumName )
            ELSE
                IF s_hEnums["lastToken"] = "enum" .AND. lline = "{"
                    s_hEnums["addEnums"] := iif( !Empty( _namespace_ ), _namespace_, "" ) + "::" + Token( s_hEnums["lastToken"], " ", 2 )
                    RETURN .T.
                ENDIF
                s_hEnums["lastToken"] := line
            ENDIF
        ENDIF

        IF !Empty( _useAs_ )
            _cls_ := _useAs_
        ELSE
            _cls_ := s_cppClassName
        ENDIF

        IF !Empty( _define_ ) .AND. Token( _defineVal_, ":", 1 ) == _cls_
            s_Defines[ _define_ ] := _defineVal_
            WipWrite( "#define " + PadR( _define_, 40 ) + _defineVal_ + E"\n" )
        ENDIF
    ENDIF

RETURN .T.

PROCEDURE qthDbAppend()
    LOCAL index
    
    index := OrdSetFocus( "X01" )

    IF DbSeek( " " )
        OrdSetFocus( index )
        RETURN
    ENDIF
    
    OrdSetFocus( index )
    
    DbAppend()

RETURN 

STATIC FUNCTION UpdateQthNameSpace()
    LOCAL fh
    LOCAL aNS
    LOCAL line,lline,itm
    LOCAL changed,aActual

    IF .F. //s_numFuncs > 0

        IF Upper( s_parentClass ) == "QTHBASE" .AND. s_numFuncs > 0

            /* update qth_castDeleteObj.inc */
            changed := .F.
            aActual := {}
            aNS := File2Array( ".tmp/qth_castDeleteObj.inc" )

            FOR EACH line IN aNS
                lline := LTrim( RTrim( line ) )
                itm := Token( lline, ":", 2 )

                QTHTREE->( OrdSetFocus( "X01" ) )

                QTHTREE->( DbSeek( Upper( PadR( itm, 40 ) ) ) )

                IF AScan( clsTypesList(), {|e| e == itm } ) = 0 .OR. !lline = "case QtH::" .OR. ! Upper( QTHTREE->parent ) = "QTHBASE"
                    line := ""
                    changed := .T.
                ELSE
                    AAdd( aActual, itm )
                ENDIF
            NEXT

            IF AScan( aActual, {|e| e == s_cppClassName } ) = 0
                AAdd( aActual, s_cppClassName )
                changed := .T.
            ENDIF

            IF changed
                ASort( aActual )
                fh := HB_FCreate( ".tmp/qth_castDeleteObj.inc" )
                FOR EACH itm IN aActual
                    FWrite( fh, "case QtH::" + itm + ": delete static_cast<" + itm + E" *> (cppObjectPtr); break;\n" )
                NEXT
                FClose( fh )
            ENDIF

        ENDIF

    ENDIF

RETURN .T.

/*
    WriteClassDefinition
    Teo. Mexico 2012
*/
STATIC PROCEDURE WriteClassDefinition()
    LOCAL i,s
    LOCAL aParentClass := {}
    LOCAL hbClsTpl
    LOCAL hTokens
    LOCAL line,token
    LOCAL numParentCls
    LOCAL _s_clsName := Upper( s_clsName )

    numParentCls := NumToken( s_parentClass, " ," )

    FOR i := 1 TO numParentCls
        s := Token( s_parentClass, " ,", i )
        AAdd( aParentClass, Upper( s ) )
    NEXT

    hTokens := ;
        { "@QTH_CLASSNAME@"     => _s_clsName, ;
          "@QTH_CLASSNAME_LEN@" => LTrim( Str( Len( _s_clsName ) ) ), ;
          "@NUM_PARENTCLS@"     => LTrim( Str( numParentCls ) ) }

    hbClsTpl := File2Array( "wip/templates/qth_HBClass.tpl" )

    WipWrite( E"\n" )

    WipWrite( E"/*\n * Wip: Class Creation & Object Instantiation Section INIT\n */\n" )

    FOR EACH line IN hbClsTpl

        FOR EACH token IN hTokens
            WHILE token:__enumKey $ line
                line := StrTran( line, token:__enumKey, token:__enumValue )
            ENDDO
        NEXT

        IF LTrim( line ) = "@FUNC_EXTERN_PARENTCLS@"
            FOR EACH s IN aParentClass
                WipWrite( "HB_FUNC_EXTERN( " + s + E" );\n" )
            NEXT
            LOOP
        ENDIF

        IF LTrim( line ) = "@SYMBOLTABLE_PARENTCLS@"
            FOR EACH s IN aParentClass
                WipWrite( E"{ \042" + s + E"\042, { HB_FS_PUBLIC }, { HB_FUNCNAME( " + s + E" ) }, NULL },\n" )
            NEXT
            LOOP
        ENDIF

        WipWrite( line + E"\n" )

    NEXT
    
    WipWrite( E"/*\n * Wip: Class Creation & Object Instantiation Section END\n */\n" )

    WipWrite( E"\n" )

    WipWrite( E"/*\n * Wip: Method's Declaration Section INIT\n */\n" )

RETURN

/*
    Write_RegisterMethods
    Teo. Mexico 2012
*/
STATIC PROCEDURE Write_RegisterMethods()
    LOCAL itm
    LOCAL indentLocal

    WipWrite( E"/*\n * Wip: Register Harbour Method's Section INIT\n */\n" )
    //WipWrite( E"static void s_registerMethods( HB_USHORT uiClass )\n" )
    WipWrite( E"HB_FUNC_STATIC( S_REGISTERMETHODS )\n" )
    WipWrite( E"{\n" )
    
    indentLocal := Replicate( s_indentVal, 1 )

    WipWrite( indentLocal + E"HB_USHORT uiClass = hb_itemGetNI( hb_param( 1, HB_IT_NUMERIC ) );\n\n" )

    FOR EACH itm IN s_aMethods
        WipWrite( indentLocal + E"hb_clsAdd( uiClass, " + PadR( E"\042" + itm[ 1 ] + E"\042", s_maxMethodNameLen ) + E", HB_FUNCNAME( " + PadR( itm[ 2 ], s_maxFuncNameLen - 2 ) + E" ) );\n" )
    NEXT

    WipWrite( E"}\n" )

    WipWrite( E"/*\n * Wip: Register Harbour Method's Section END\n */\n" )

RETURN

STATIC PROCEDURE WriteWipHeader()

    WipWrite( E"/*\n")
    WipWrite( s_idString + E"\n *\n" )
    WipWrite( E" * File autogenerated by Wip utility " + wipFullVer + E"\n * Do not edit this file.\n *\n" + s_sCredits + E" *\n */\n\n" )
    WipWrite( E"#include \042qtharbour.h\042\n\n" )

    IF s_include == NIL
        WipWrite( E"#include <" + s_cppClassName + E">\n\n" )
    ELSEIF !Empty( s_include )
        WipWrite( "#include " + s_include + E"\n\n" )
    ENDIF

RETURN

CLASS TSingleMethod
HIDDEN:
PROTECTED:
EXPORTED:

    DATA _enum_Method_
    DATA _static_public_ INIT .F.
    DATA _protected_function_ INIT .F.
    DATA hasMethod INIT .F.
    DATA line
    DATA list INIT {=>}
    DATA paramParser
    DATA parPrefix INIT {}
    DATA returnParser
    DATA type_Prototype INIT "?"
    DATA type_Prototype_Subtype

    METHOD funcName INLINE ::returnParser:targetName
    METHOD getList( type, nParam )
    METHOD HBFuncName
    METHOD isConstructor INLINE Upper( ::funcName ) == Upper( s_clsName )
    METHOD ParseLine( line )
    METHOD ProcessLine( line )
    METHOD retString BLOCK ;
        {|Self|
            LOCAL s := ""
            IF !::returnParser:isConstructor
                IF ::type_Prototype == "_static_public_members_"
                    s := s_clsName + "::"
                ELSE
                    s := s_varName + "->"
                ENDIF
                s += ::returnParser:targetName
            ENDIF
            RETURN s
        }

    METHOD setList( type, nParam, key, value )
    METHOD WriteStruct( funcStruct )

ENDCLASS

METHOD FUNCTION getList( type, nParam ) CLASS TSingleMethod
    IF !HB_HHasKey( ::list, type ) .OR. !HB_HHasKey( ::list[ type ], nParam )
        RETURN NIL
    ENDIF
RETURN ::list[ type, nParam ]

METHOD FUNCTION HBFuncName CLASS TSingleMethod
RETURN iif( ::_enum_Method_ == NIL, "", "E_" ) + ::funcName

METHOD PROCEDURE ParseLine( line ) CLASS TSingleMethod

    ::line := line

    ::returnParser := ParseTypeInfo( line ):New()
    ::returnParser:isConstructor := ::isConstructor
    ::returnParser:BuildReturnSection()

    IF ::returnParser != NIL
        ::paramParser := TParamParser():New( Self )
        ::hasMethod := .T.
    ENDIF

RETURN

METHOD PROCEDURE ProcessLine( line ) CLASS TSingleMethod
    LOCAL tk
    LOCAL i
    LOCAL aTk

    IF Empty( line ) .OR. line $ "{}" .OR. line = "//" .OR. line = "/*"

        RETURN

    ELSEIF line = "#"

        tk := RTrim( Token( line, "#"+s_tkDelim, 1 ) )

        SWITCH Lower( tk )
        CASE "if"
            ::setList( "if", 1, LTrim( RTrim( SubStr( line, 4 ) ) ) )
            EXIT
        CASE "param"
            ::setList( "params", LTrim( RTrim( Token( line, s_tkDelim, 2 ) ) ), LTrim( RTrim( Token( line, s_tkDelim, 3 ) ) ) )
            EXIT
        CASE "return"
            ::setList( "return", 1, LTrim( RTrim( Token( line, s_tkDelim, 2 ) ) ) )
            EXIT
        CASE "register"
            AddMethodName( Upper( LTrim( RTrim( Token( line, s_tkDelim, 2 ) ) ) ) )
            EXIT
        OTHERWISE
            aTk := Array( 3 )
            FOR i:=1 TO 3
                aTk[ i ] := Token( line, s_tkDelim, i + 1 )
            NEXT
            ::setList( tk, aTk[ 1 ], aTk[ 2 ], aTk[ 3 ] )
        ENDSWITCH

    ELSE

        ::ParseLine( line )

    ENDIF

RETURN

METHOD PROCEDURE setList( type, nParam, key, value ) CLASS TSingleMethod

    IF !HB_HHasKey( ::list, type )
        ::list[ type ] := {=>}
    ENDIF

    IF !HB_HHasKey( ::list[ type ], nParam )
        ::list[ type, nParam ] := HB_HSetCaseMatch( HB_HSetOrder( {=>}, .T. ), .F. )
    ENDIF

    ::list[ type, nParam, key ] := value

RETURN

METHOD PROCEDURE WriteStruct( funcStruct ) CLASS TSingleMethod
    LOCAL line
    LOCAL prefixDoNot
    LOCAL doNotMsg

    QTHDD->( qthDbAppend() )
    QTHDD->clsname := s_cppClassName
    QTHDD->funcname := ::funcName
    QTHDD->cproto := ::line
    QTHDD->protected := .F.
    
    IF ::returnParser:doNot != NIL
        prefixDoNot := "// "
        doNotMsg := ::returnParser:doNot
    ELSE
        prefixDoNot := ""
    ENDIF

    IF ::_enum_Method_ != NIL
        WipWrite( E"qth_registerClassEnum( hb_stackSelfItem(), \042" + ::_enum_Method_ + E"\042, \042" + ::funcName + E"\042, " + ::funcName + E" );\n" )
        WipWrite( Replicate( s_indentVal, funcStruct:indentLevel ) )
        WipWrite( E"hb_itemReturn( hb_stackSelfItem() );\n" )
    ELSE
        FOR EACH line IN ::parPrefix
            WipWrite( prefixDoNot + line )
            WipWrite( Replicate( s_indentVal, funcStruct:indentLevel ) )
        NEXT

        FOR EACH line IN ::paramParser:paramHeader
            WipWrite( prefixDoNot + line + E"\n" )
            WipWrite( Replicate( s_indentVal, funcStruct:indentLevel ) )
        NEXT

        IF doNotMsg != NIL
            WipWrite( prefixDoNot + "! " + doNotMsg + E"\n" )
            WipWrite( Replicate( s_indentVal, funcStruct:indentLevel ) )
        ENDIF

        IF !Empty( ::returnParser:retHeader )
            WipWrite( prefixDoNot + ::returnParser:retHeader + E"\n" )
            WipWrite( Replicate( s_indentVal, funcStruct:indentLevel ) )
        ENDIF

//        IF ::isConstructor
//            WipWrite( "qth_itemPushReturn( QtH::" + s_cppClassName + ", new " + ::funcName )
//        ELSE
//            WipWrite( ::returnParser:retPrefix + ::retString )
//        ENDIF

        WipWrite( prefixDoNot + ::returnParser:retPrefix + ::retString )

        IF !Empty( ::paramParser:paramString )
            WipWrite( ::paramParser:paramString )
        ENDIF

        WipWrite( ::returnParser:retSuffix + E";\n" )
        
        IF !Empty( ::returnParser:retFooter )
            WipWrite( Replicate( s_indentVal, funcStruct:indentLevel ) )
            WipWrite( prefixDoNot + ::returnParser:retFooter + E"\n" )
        ENDIF

        FOR EACH line IN ::paramParser:paramFooter
            WipWrite( Replicate( s_indentVal, funcStruct:indentLevel ) )
            WipWrite( prefixDoNot + line + E"\n" )
        NEXT
        
        IF ! prefixDoNot == ""
            WipWrite( Replicate( s_indentVal, funcStruct:indentLevel ) )
            WipWrite( E"qth_errRT_UNKNOWNOBJ( \042" + s_clsName + "::" + ::funcName + E"\042, \042" + doNotMsg + E"\042 ) " + E";\n" )
        ENDIF
        
    ENDIF

RETURN

CLASS TFuncStruct
HIDDEN:
PROTECTED:
    DATA tkReturnStr
    METHOD methodNamePrefix INLINE iif( ::_has_static_public_members_, Upper( s_clsName ) + "_", "" )
EXPORTED:

    DATA _enum_Method_
    DATA _has_static_public_members_ INIT .F.
    DATA _protected_function_ INIT .F.
    DATA _require_Object_ INIT .F.
    DATA bufferToDump
    DATA funcName
    DATA indentLevel
    DATA line
    DATA isConstructor INIT .F.
    DATA methodList
    DATA numStaticPublic INIT 0

    CONSTRUCTOR New

    METHOD AddMethod( singleMethod )
    METHOD WriteFunc()

ENDCLASS

METHOD New CLASS TFuncStruct
    ::methodList := HB_HSetOrder( { => }, .T. )
RETURN Self

METHOD AddMethod( singleMethod ) CLASS TFuncStruct
    ::funcName := singleMethod:funcName
    ::methodList[ singleMethod:line ] := singleMethod

    IF singleMethod:_protected_function_
        ::_protected_function_ := .T.
        ::line := singleMethod:line
    ENDIF

    IF !singleMethod:_static_public_ .AND. !::_require_Object_
        ::_require_Object_ := .T.
    ENDIF
    
    IF singleMethod:_static_public_
        ++::numStaticPublic
        ::_has_static_public_members_ := .T.
    ENDIF
    
    IF singleMethod:_enum_Method_ != NIL
        ::_enum_Method_ := singleMethod:_enum_Method_
    ENDIF
    
    IF !::isConstructor .AND. singleMethod:isConstructor
        ::isConstructor := .T.
    ENDIF
    
    IF ::isConstructor .AND. ::_require_Object_
        ::_require_Object_ := .F.
    ENDIF

RETURN Self

METHOD FUNCTION WriteFunc() CLASS TFuncStruct
    LOCAL singleMethod
    LOCAL itm
    LOCAL hIf
    LOCAL funcName
    LOCAL lCancel_Require_Object_brace
    LOCAL line

    IF ::_protected_function_
        QTHDD->( qthDbAppend() )
        QTHDD->clsname := s_cppClassName
        QTHDD->funcname := ::funcName
        QTHDD->cproto := ::line
        QTHDD->protected := .T.
        RETURN .T.
    ENDIF

    IF !Empty( ::funcName )

        funcName := iif( ::_enum_Method_ != NIL, "E_", "" ) + iif( ::isConstructor, "NEW", ::funcName )

        AddMethodName( Upper( funcName ), Upper( ::methodNamePrefix + funcName ) )

        IF ::_has_static_public_members_
            WipWrite( "HB_FUNC( " + Upper( s_clsName ) + "_" + Token( Upper( funcName ), " (", 1 ) + E" )\n" )
        ELSE
            WipWrite( "HB_FUNC_STATIC( " + Token( Upper( funcName ), " (", 1 ) + E" )\n" )
        ENDIF
        
        WipWrite( E"{\n" )

        /*
        IF ::isConstructor
            WipWrite( s_indentVal + E"if( qth_derivedConstructor() )\n" )
            WipWrite( s_indentVal + E"{\n" )
            WipWrite( s_indentVal + s_indentVal + E"return;\n" )
            WipWrite( s_indentVal + E"}\n" )
        ENDIF
        */

        IF ::_require_Object_
            WipWrite( s_indentVal + s_clsName + "* " + s_varName + " = static_cast<" + s_clsName + " *> ( qth_itemListGet_CPP( hb_stackSelfItem() ) );"+ E"\n\n" )
            WipWrite( s_indentVal + "if( " + s_varName + E" )\n" )
            WipWrite( s_indentVal + E"{\n" )
            ::indentLevel := 2
            lCancel_Require_Object_brace := .T.
        ELSE
            ::indentLevel := 1
            lCancel_Require_Object_brace := .F.
        ENDIF

        IF ::_has_static_public_members_
            ASort( ::methodList, , , {|x,y| !x:_static_public_ .AND. y:_static_public_ } )
        ENDIF

        FOR EACH singleMethod IN ::methodList
            
            IF singleMethod:_static_public_ .OR. ::isConstructor
                ::indentLevel := 1
            ELSE
                ::indentLevel := 2
            ENDIF

            hIf := singleMethod:getList( "if", 1 )

            IF !Empty( hIf )
                FOR EACH itm IN hIf
                    WipWrite( "#if " + itm:__enumKey() + E"\n" )
                NEXT
            ENDIF

            WipWrite( Replicate( s_indentVal, ::indentLevel ) )
            WipWrite( E"/*\n" )
            WipWrite( Replicate( s_indentVal, ::indentLevel ) )
            WipWrite( " * " + singleMethod:type_Prototype + " : " + singleMethod:__enumKey + E"\n" )
            WipWrite( Replicate( s_indentVal, ::indentLevel ) )
            WipWrite( E" */\n" )

            WipWrite( Replicate( s_indentVal, ::indentLevel ) )
            
            IF Empty( singleMethod:paramParser:paramCheckList )
                WipWrite( E"if( hb_pcount() == 0 )\n" )
            ELSE
                WipWrite( "if( " )
                IF !Empty( singleMethod:paramParser:paramCountNoDef )
                    WipWrite( "( hb_pcount() == " + LTrim( Str( singleMethod:paramParser:paramCountNoDef ) ) + " ) && " )
                ELSE
                    WipWrite( "( hb_pcount() <= " + LTrim( Str( singleMethod:paramParser:paramCount ) ) + " ) && " )
                ENDIF
                WipWrite( singleMethod:paramParser:paramCheckList + E" )\n" )
            ENDIF

            WipWrite( Replicate( s_indentVal, ::indentLevel ) + E"{\n" )
            WipWrite( Replicate( s_indentVal, ++::indentLevel ) )

            IF ::bufferToDump = NIL

                singleMethod:WriteStruct( Self )

                WipWrite( Replicate( s_indentVal, ::indentLevel ) + E"return;\n" )

            ELSE
                WipWrite( E"/* #begindump */\n")
                WipWrite( Replicate( s_indentVal, ::indentLevel ) )
                FOR EACH line IN ::bufferToDump
                    WipWrite( line + E"\n" )
                    WipWrite( Replicate( s_indentVal, ::indentLevel ) )
                NEXT
                WipWrite( E"/* #enddump */\n")
            ENDIF

            WipWrite( Replicate( s_indentVal, --::indentLevel ) + E"}\n" )

            IF !Empty( hIf )
                FOR EACH itm IN hIf DESCEND
                    WipWrite( E"#endif  /* " + itm:__enumKey() + E" */\n" )
                NEXT
            ENDIF
            
            IF lCancel_Require_Object_brace .AND. singleMethod:__enumIndex == ( Len( ::methodList ) - ::numStaticPublic )
                WipWrite( s_indentVal + E"}\n" )
            ENDIF

        NEXT

        WipWrite( Replicate( s_indentVal, 1 ) + QTH_ARGUMENT_ERROR + E"\n" )

        WipWrite( E"}\n\n" )

    ENDIF

RETURN .T.

FUNCTION File2Array( fileName )
    LOCAL a := {}
    LOCAL s
    LOCAL n
    LOCAL cText
    LOCAL nHeaders
    
    cText := HB_MemoRead( fileName )

    // solo LF como EOL
    cText := StrTran( cText, Chr(13)+Chr(10), Chr(10) )
    cText := StrTran( cText, Chr(9), "  " )

    WHILE !cText==""
        IF (n:=At( Chr(10), cText )) = 0
            n := Len( cText ) + 1
        ENDIF
        s := SubStr( cText, 1, n-1 )
        AAdd( a, s )
        IF LTrim( Lower( s ) ) = "// qthbegin"
            nHeaders := Len( a )
        ENDIF
        IF "$Id:" $ s
            s_idString := s
        ENDIF
        cText := SubStr( cText, n+1 )
    ENDDO
    
    IF nHeaders != NIL
        a := PreProcessWipFile( a, fileName )
    ENDIF

RETURN a

/*
    PreProcessWipFile : formats wip file with marked token between '// qthbegin' / '// qthend', rewrites file
    Teo. Mexico 2012
*/
STATIC FUNCTION PreProcessWipFile( a, fileName )
    LOCAL aTmp
    LOCAL inHeaders
    LOCAL inPublicTypes
    LOCAL line
    LOCAL lline
    LOCAL s
    LOCAL fhWIP
    LOCAL fhNamespace

    aTmp := {}
    inHeaders := .F.
    inPublicTypes := .F.

    FOR EACH line IN a

        line := RTrim( line )
        lline := LTrim( Lower( line ) )

        IF lline = "// qthbegin"
            inHeaders := .T.
            LOOP
        ENDIF

        IF lline = "// qthend"
            inHeaders := .F.
            LOOP
        ENDIF

        IF inHeaders
            IF !Empty( lline )

                SWITCH lline
                CASE "public types"
                    inPublicTypes := .T.
                    LOOP
                CASE "public functions"
                CASE "reimplemented public functions"
                CASE "public slots"
                CASE "static public members"
                CASE "protected functions"
                    s := "/* " + Replicate( " ", Len( lline ) ) + " */"
                    AAdd( aTmp, "" )
                    AAdd( aTmp, s )
                    AAdd( aTmp, "/* " + LTrim( line ) + E" */" )
                    AAdd( aTmp, s )
                    AAdd( aTmp, "" )
                    line := StrTran( line, " ", "_" )
                    AAdd( aTmp, "_" + line + "_" )
                    AAdd( aTmp, "" )
                    inPublicTypes := .F.
                    LOOP
                ENDSWITCH

                IF inPublicTypes
                    IF fhNamespace = NIL
                        fhNamespace := HB_FCreate( "wip/namespaces/" + SubStr( HB_FNameName( fileName ), 4 ) + ".namespace" )
                        FWrite( fhNamespace, E"\n" )
                    ENDIF
                    FWrite( fhNamespace, line + E"\n" )                
                ELSE
                    AAdd( aTmp, line )
                ENDIF

            ENDIF
        ELSE
            AAdd( aTmp, line )
        ENDIF
    NEXT
    
    IF fhNamespace != NIL
        FClose( fhNamespace )
    ENDIF

    fhWIP := HB_FCreate ( fileName )

    FOR EACH line IN aTmp
        FWrite( fhWIP, line + E"\n" )
    NEXT

    FClose( fhWIP )

RETURN aTmp

/*
    WipWrite
    Teo. Mexico 2012
*/
STATIC PROCEDURE WipWrite( line )
    STATIC headerWritten
    STATIC partLine
    LOCAL n
    
    IF headerWritten == NIL
        headerWritten := .T.
        WriteWipHeader()
    ENDIF
    
    WHILE ! line == ""
        IF line = "@FUNC_EXTERN_REQUESTS@"
            s_index_Func_Extern_Requests := Len( s_bufferCPP ) + 1
        ENDIF
        IF line = "@SYMBOLTABLE_REQUESTS@"
            s_index_SymbolTable_Requests := Len( s_bufferCPP ) + 1
        ENDIF
        n := At( E"\n", line )
        IF n > 0
            AAdd( s_bufferCPP, iif( partLine = NIL, "", partLine ) + SubStr( line, 1, n - 1 ) )
            IF partLine != NIL
                partLine := NIL
            ENDIF
            line := SubStr( line, n + 1 )
        ELSE
            IF partLine = NIL
                partLine := line
            ELSE
                partLine += line
            ENDIF
            EXIT
        ENDIF
    ENDDO

RETURN

/*
    WriteBufferCPP
    Teo. Mexico 2012
*/
STATIC PROCEDURE WriteBufferCPP( cppFile )
    LOCAL fhCPP
    LOCAL line

    fhCPP := HB_FCreate( cppFile )
    
    FOR EACH line IN s_bufferCPP
        FWrite( fhCPP, line + E"\n" )
    NEXT

    FClose( fhCPP )

RETURN

/*
    ParseFunction_Requests
    Teo. Mexico 2012
*/
STATIC PROCEDURE ParseFunction_Requests()
    LOCAL sReq
    LOCAL sComma

    HB_ADel( s_bufferCPP, s_index_Func_Extern_Requests, .T. )
    HB_ADel( s_bufferCPP, s_index_SymbolTable_Requests - 1, .T. )

    FOR EACH sReq IN s_requests
        IF sComma = NIL
            s_bufferCPP[ s_index_SymbolTable_Requests - 2 ] += ","
        ENDIF
        IF sReq:__enumIndex = 1
            sComma := " "
        ELSE
            sComma := ","
        ENDIF
        sReq := Upper( sReq )
        HB_AIns( s_bufferCPP, s_index_Func_Extern_Requests, E"HB_FUNC_EXTERN( " + sReq + E" ); // REQUEST'ed Class", .T. )
        HB_AIns( s_bufferCPP, s_index_SymbolTable_Requests++, E"{ \042" + sReq + E"\042, " + E"{HB_FS_PUBLIC}, {HB_FUNCNAME( " + sReq + " )}, NULL }" + sComma + " // REQUEST'ed Class", .T. )
    NEXT

RETURN

/*
    S_ClassName
    Teo. Mexico 2012
*/
FUNCTION S_ClassName
RETURN s_clsName
