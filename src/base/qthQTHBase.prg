/*
 * $Id: qthQTHBase.prg 142 2012-08-06 17:50:54Z tfonrouge $
 *
 * (C) 2011. qtHarbour     http://sourceforge.net/projects/qth/
 * (C) 2011. Teo Fonrouge  <tfonrouge/at/gmail/dot/com>
 *
 */

#include "qtHarbour.ch"

REQUEST QOUT
REQUEST QQOUT

CLASS QTHBASE /* base for all qth classes */
    DATA e_enumName
    DATA e_enumType
    DATA e_enumValue
PROTECTED:
    METHOD SetEnum( type, name, value )
EXPORTED:
//    CONSTRUCTOR New
    DESTRUCTOR OnDestruct()
    METHOD E_GetEnumName INLINE ::e_enumName
    METHOD E_GetEnumType INLINE ::e_enumType
    METHOD E_GetEnumValue INLINE ::e_enumValue
    METHOD CObjectPtr
ENDCLASS

//METHOD New CLASS QTHBASE
//RETURN ::IsVirtual()

METHOD PROCEDURE OnDestruct() CLASS QTHBASE
    qth_BaseDestruct( Self )
RETURN

METHOD FUNCTION SetEnum( type, name, value ) CLASS QTHBASE
    ::e_enumType := type
    ::e_enumName := name
    ::e_enumValue := value
RETURN Self
