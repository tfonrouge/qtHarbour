/*
 * $Id: wip.prg 98 2011-03-22 09:42:55Z tfonrouge $
 *
 * Generates C++ sources from SIGNALS/SLOTS methods in Harbour prgs
 *
 * (C) 2011. qtHarbour     http://sourceforge.net/projects/qth/
 * (C) 2011. Teo Fonrouge  <tfonrouge/at/gmail/dot/com>
 *
 */

#ifdef __HBDEBUG
#pragma debuginfo=on
#endif

#include "hbclass.ch"

STATIC s_aFile
STATIC idString
STATIC s_fhCpp
STATIC s_FileName
STATIC s_FileName_Cpp
STATIC s_FileName_Moc
STATIC s_nLine
STATIC s_ClassStruct
STATIC s_parentClass
STATIC s_hCls := {=>}
STATIC s_hParentCls := {=>}

#define cIndent     "    "

FUNCTION Main( qthFile, cppFile, mocFile )
    LOCAL line,lline

    s_aFile := File2Array( qthFile )

    IF Len( s_aFile ) > 0

        s_nLine := 1
        
        s_FileName := HB_FNameName( qthFile )

        IF !Empty( cppFile )
            s_FileName_Cpp := cppFile
        ELSE
            s_FileName_Cpp := "qthmoc_" + s_FileName + ".cpp"
        ENDIF

        IF !Empty( mocFile )
            s_FileName_Moc := mocFile
        ELSE
            s_FileName_Moc := "qthmoc_" + s_FileName + ".moc"
        ENDIF

        s_fhCpp := HB_FCreate( s_FileName_Cpp )

        WHILE s_nLine <= Len( s_aFile )
            IF GetValidLine( @line )
                lline := Lower( line )
                IF lline = "q_class"
                    ProcessClassSection( line )
                ENDIF
            ENDIF
            ++s_nLine
        ENDDO
        
        WriteCppFile()

        FClose( s_fhCpp )
        
        CreateQthMocFile()

    ENDIF

RETURN NIL

STATIC PROCEDURE CreateQthMocFile()

    HB_RUN( "moc " + s_FileName_Cpp + " > " + s_FileName_Moc )

RETURN

STATIC FUNCTION GetValidLine( line )

    line := LTrim( RTrim( s_aFile[ s_nLine ] ) )
    
    IF Empty( line )
        RETURN .F.
    ENDIF
    
RETURN .T.

STATIC PROCEDURE ProcessClassSection( line )

    s_ClassStruct := TClassStruct():New( line )

    ++s_nLine
    
    WHILE s_nLine <= Len( s_aFile )
        IF GetValidLine( @line )
        ENDIF
        ++s_nLine
    ENDDO

RETURN

STATIC FUNCTION File2Array( fileName )
    LOCAL a := {}
    LOCAL s
    LOCAL n
    LOCAL cText
    
    cText := HB_MemoRead( fileName )

    // solo LF como EOL
    cText := StrTran( cText, Chr( 13 )+Chr(10), Chr(10) )
    cText := StrTran( cText, Chr(9), "  " )

    WHILE !cText==""
        IF (n:=At( Chr(10), cText )) = 0
            n := Len( cText ) + 1
        ENDIF
        s := SubStr( cText, 1, n-1 )
        AAdd( a, s )
        IF "$Id:" $ s
            idString := s
        ENDIF
        cText := SubStr( cText, n+1 )
    ENDDO

RETURN a

STATIC PROCEDURE WriteCppFile()
    LOCAL itm
    LOCAL line
    
    FWrite( s_fhCpp, E"\n" )

    FOR EACH itm IN s_hParentCls
        FWrite( s_fhCpp, "#include <" + itm:__enumKey + E">\n" )
    NEXT
    
    FWrite( s_fhCpp, E"\n" )

    FOR EACH itm IN s_hCls
        FOR EACH line IN itm
            FWrite( s_fhCpp, line + E"\n" )
        NEXT
    NEXT
    
    FWrite( s_fhCpp, E"\n#include \042" + s_FileName_Moc + E"\042\n" )

RETURN

CLASS TClassStruct
EXPORTED:
    CONSTRUCTOR New
ENDCLASS

METHOD New( line ) CLASS TClassStruct
    LOCAL clsName
    LOCAL i
    
    clsName := Token( line, " ", 2 )
    s_parentClass := SubStr( line, At( "FROM", line ) + 5 )
    
    FOR i:=1 TO NumToken( s_parentClass, " ," )
        s_hParentCls[ Token( s_parentClass, " ,", i ) ] := NIL
    NEXT
    
    s_hCls[ clsName ] := {}
    
    AAdd( s_hCls[ clsName ], "class " + Token( line, " ", 2 ) + " : public " + s_parentClass )
    AAdd( s_hCls[ clsName ], "{" )

    AAdd( s_hCls[ clsName ], cIndent + "Q_OBJECT" )

    AAdd( s_hCls[ clsName ], "};" )

RETURN Self

CLASS TSingleMethod
ENDCLASS
