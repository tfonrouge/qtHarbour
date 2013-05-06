/*
 * $Id: qthQt.wip 128 2011-04-14 15:49:46Z tfonrouge $
 *
 * File autogenerated by Wip utility v0.1-151
 * Do not edit this file.
 *
 * (C) 2012. qtHarbour     http://sourceforge.net/projects/qth/
 * (C) 2012. Teo Fonrouge  <tfonrouge/at/gmail/dot/com>
 *
 */

#include "qtharbour.h"

#include <Qt>

#define Alignment                               Qt::Alignment
#define AlignmentFlag                           Qt::AlignmentFlag
#define AnchorAttribute                         Qt::AnchorAttribute
#define AnchorPoint                             Qt::AnchorPoint
#define ApplicationAttribute                    Qt::ApplicationAttribute
#define ArrowType                               Qt::ArrowType
#define AspectRatioMode                         Qt::AspectRatioMode
#define Axis                                    Qt::Axis
#define BGMode                                  Qt::BGMode
#define BrushStyle                              Qt::BrushStyle
#define NoBrush                                 Qt::NoBrush
#define SolidPattern                            Qt::SolidPattern
#define Dense1Pattern                           Qt::Dense1Pattern
#define Dense2Pattern                           Qt::Dense2Pattern
#define Dense3Pattern                           Qt::Dense3Pattern
#define Dense4Pattern                           Qt::Dense4Pattern
#define Dense5Pattern                           Qt::Dense5Pattern
#define Dense6Pattern                           Qt::Dense6Pattern
#define Dense7Pattern                           Qt::Dense7Pattern
#define HorPattern                              Qt::HorPattern
#define VerPattern                              Qt::VerPattern
#define CrossPattern                            Qt::CrossPattern
#define BDiagPattern                            Qt::BDiagPattern
#define FDiagPattern                            Qt::FDiagPattern
#define DiagCrossPattern                        Qt::DiagCrossPattern
#define LinearGradientPattern                   Qt::LinearGradientPattern
#define ConicalGradientPattern                  Qt::ConicalGradientPattern
#define RadialGradientPattern                   Qt::RadialGradientPattern
#define TexturePattern                          Qt::TexturePattern
#define CaseSensitivity                         Qt::CaseSensitivity
#define CheckState                              Qt::CheckState
#define ClipOperation                           Qt::ClipOperation
#define ConnectionType                          Qt::ConnectionType
#define ContextMenuPolicy                       Qt::ContextMenuPolicy
#define CoordinateSystem                        Qt::CoordinateSystem
#define Corner                                  Qt::Corner
#define CursorShape                             Qt::CursorShape
#define DateFormat                              Qt::DateFormat
#define DayOfWeek                               Qt::DayOfWeek
#define DockWidgetArea                          Qt::DockWidgetArea
#define DockWidgetAreas                         Qt::DockWidgetAreas
#define DropAction                              Qt::DropAction
#define DropActions                             Qt::DropActions
#define EventPriority                           Qt::EventPriority
#define FillRule                                Qt::FillRule
#define FocusPolicy                             Qt::FocusPolicy
#define FocusReason                             Qt::FocusReason
#define GestureFlag                             Qt::GestureFlag
#define GestureFlags                            Qt::GestureFlags
#define GestureState                            Qt::GestureState
#define GestureType                             Qt::GestureType
#define GlobalColor                             Qt::GlobalColor
#define white                                   Qt::white
#define black                                   Qt::black
#define red                                     Qt::red
#define darkRed                                 Qt::darkRed
#define green                                   Qt::green
#define darkGreen                               Qt::darkGreen
#define blue                                    Qt::blue
#define darkBlue                                Qt::darkBlue
#define cyan                                    Qt::cyan
#define darkCyan                                Qt::darkCyan
#define magenta                                 Qt::magenta
#define darkMagenta                             Qt::darkMagenta
#define yellow                                  Qt::yellow
#define darkYellow                              Qt::darkYellow
#define gray                                    Qt::gray
#define darkGray                                Qt::darkGray
#define lightGray                               Qt::lightGray
#define transparent                             Qt::transparent
#define color0                                  Qt::color0
#define color1                                  Qt::color1
#define HitTestAccuracy                         Qt::HitTestAccuracy
#define ImageConversionFlag                     Qt::ImageConversionFlag
#define ImageConversionFlags                    Qt::ImageConversionFlags
#define InputMethodHint                         Qt::InputMethodHint
#define InputMethodHints                        Qt::InputMethodHints
#define InputMethodQuery                        Qt::InputMethodQuery
#define ItemDataRole                            Qt::ItemDataRole
#define ItemFlag                                Qt::ItemFlag
#define ItemFlags                               Qt::ItemFlags
#define ItemSelectionMode                       Qt::ItemSelectionMode
#define Key                                     Qt::Key
#define KeyboardModifier                        Qt::KeyboardModifier
#define KeyboardModifiers                       Qt::KeyboardModifiers
#define LayoutDirection                         Qt::LayoutDirection
#define MaskMode                                Qt::MaskMode
#define MatchFlag                               Qt::MatchFlag
#define MatchFlags                              Qt::MatchFlags
#define Modifier                                Qt::Modifier
#define MouseButton                             Qt::MouseButton
#define MouseButtons                            Qt::MouseButtons
#define NavigationMode                          Qt::NavigationMode
#define Orientation                             Qt::Orientation
#define Orientations                            Qt::Orientations
#define PenCapStyle                             Qt::PenCapStyle
#define PenJoinStyle                            Qt::PenJoinStyle
#define PenStyle                                Qt::PenStyle
#define ScrollBarPolicy                         Qt::ScrollBarPolicy
#define ShortcutContext                         Qt::ShortcutContext
#define SizeHint                                Qt::SizeHint
#define SizeMode                                Qt::SizeMode
#define SortOrder                               Qt::SortOrder
#define TextElideMode                           Qt::TextElideMode
#define TextFlag                                Qt::TextFlag
#define TextFormat                              Qt::TextFormat
#define TextInteractionFlag                     Qt::TextInteractionFlag
#define TextInteractionFlags                    Qt::TextInteractionFlags
#define TileRule                                Qt::TileRule
#define TimeSpec                                Qt::TimeSpec
#define ToolBarArea                             Qt::ToolBarArea
#define ToolBarAreas                            Qt::ToolBarAreas
#define ToolButtonStyle                         Qt::ToolButtonStyle
#define TouchPointState                         Qt::TouchPointState
#define TouchPointStates                        Qt::TouchPointStates
#define TransformationMode                      Qt::TransformationMode
#define UIEffect                                Qt::UIEffect
#define UI_AnimateMenu                          Qt::UI_AnimateMenu
#define UI_FadeMenu                             Qt::UI_FadeMenu
#define UI_AnimateCombo                         Qt::UI_AnimateCombo
#define UI_AnimateTooltip                       Qt::UI_AnimateTooltip
#define UI_FadeTooltip                          Qt::UI_FadeTooltip
#define UI_AnimateToolBox                       Qt::UI_AnimateToolBox
#define WhiteSpaceMode                          Qt::WhiteSpaceMode
#define WidgetAttribute                         Qt::WidgetAttribute
#define WindowFlags                             Qt::WindowFlags
#define WindowFrameSection                      Qt::WindowFrameSection
#define WindowModality                          Qt::WindowModality
#define WindowState                             Qt::WindowState
#define WindowStates                            Qt::WindowStates
#define WindowType                              Qt::WindowType

/*
 * Wip: Class Creation & Object Instantiation Section INIT
 */

HB_FUNC( QT );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( QTHBASE );
HB_FUNC_STATIC( S_REGISTERMETHODS );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_INITSTATICS();

HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_QT )
{ "QT", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( QT )}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "QTHBASE", { HB_FS_PUBLIC }, { HB_FUNCNAME( QTHBASE ) }, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "S_REGISTERMETHODS", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( S_REGISTERMETHODS )}, NULL },
{ "HCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "(_INITSTATICS_1)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_END( hb_vm_SymbolInit_QT )

HB_FUNC( QT )
{
    qthClassObjCreator( symbols, 1 );
}

HB_FUNC_INITSTATICS()
{
    qthInitStatics( symbols, 1 );
}
/*
 * Wip: Class Creation & Object Instantiation Section END
 */

/*
 * Wip: Method's Declaration Section INIT
 */
HB_FUNC( QT_E_UI_ANIMATEMENU )
{
    /*
     * _static_public_members_ : UI_AnimateMenu
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::UIEffect", "UI_AnimateMenu", UI_AnimateMenu );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_UI_FADEMENU )
{
    /*
     * _static_public_members_ : UI_FadeMenu
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::UIEffect", "UI_FadeMenu", UI_FadeMenu );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_UI_ANIMATECOMBO )
{
    /*
     * _static_public_members_ : UI_AnimateCombo
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::UIEffect", "UI_AnimateCombo", UI_AnimateCombo );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_UI_ANIMATETOOLTIP )
{
    /*
     * _static_public_members_ : UI_AnimateTooltip
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::UIEffect", "UI_AnimateTooltip", UI_AnimateTooltip );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_UI_FADETOOLTIP )
{
    /*
     * _static_public_members_ : UI_FadeTooltip
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::UIEffect", "UI_FadeTooltip", UI_FadeTooltip );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_UI_ANIMATETOOLBOX )
{
    /*
     * _static_public_members_ : UI_AnimateToolBox
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::UIEffect", "UI_AnimateToolBox", UI_AnimateToolBox );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_NOBRUSH )
{
    /*
     * _static_public_members_ : NoBrush
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::BrushStyle", "NoBrush", NoBrush );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_SOLIDPATTERN )
{
    /*
     * _static_public_members_ : SolidPattern
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::BrushStyle", "SolidPattern", SolidPattern );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_DENSE1PATTERN )
{
    /*
     * _static_public_members_ : Dense1Pattern
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::BrushStyle", "Dense1Pattern", Dense1Pattern );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_DENSE2PATTERN )
{
    /*
     * _static_public_members_ : Dense2Pattern
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::BrushStyle", "Dense2Pattern", Dense2Pattern );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_DENSE3PATTERN )
{
    /*
     * _static_public_members_ : Dense3Pattern
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::BrushStyle", "Dense3Pattern", Dense3Pattern );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_DENSE4PATTERN )
{
    /*
     * _static_public_members_ : Dense4Pattern
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::BrushStyle", "Dense4Pattern", Dense4Pattern );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_DENSE5PATTERN )
{
    /*
     * _static_public_members_ : Dense5Pattern
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::BrushStyle", "Dense5Pattern", Dense5Pattern );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_DENSE6PATTERN )
{
    /*
     * _static_public_members_ : Dense6Pattern
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::BrushStyle", "Dense6Pattern", Dense6Pattern );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_DENSE7PATTERN )
{
    /*
     * _static_public_members_ : Dense7Pattern
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::BrushStyle", "Dense7Pattern", Dense7Pattern );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_HORPATTERN )
{
    /*
     * _static_public_members_ : HorPattern
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::BrushStyle", "HorPattern", HorPattern );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_VERPATTERN )
{
    /*
     * _static_public_members_ : VerPattern
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::BrushStyle", "VerPattern", VerPattern );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_CROSSPATTERN )
{
    /*
     * _static_public_members_ : CrossPattern
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::BrushStyle", "CrossPattern", CrossPattern );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_BDIAGPATTERN )
{
    /*
     * _static_public_members_ : BDiagPattern
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::BrushStyle", "BDiagPattern", BDiagPattern );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_FDIAGPATTERN )
{
    /*
     * _static_public_members_ : FDiagPattern
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::BrushStyle", "FDiagPattern", FDiagPattern );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_DIAGCROSSPATTERN )
{
    /*
     * _static_public_members_ : DiagCrossPattern
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::BrushStyle", "DiagCrossPattern", DiagCrossPattern );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_LINEARGRADIENTPATTERN )
{
    /*
     * _static_public_members_ : LinearGradientPattern
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::BrushStyle", "LinearGradientPattern", LinearGradientPattern );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_CONICALGRADIENTPATTERN )
{
    /*
     * _static_public_members_ : ConicalGradientPattern
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::BrushStyle", "ConicalGradientPattern", ConicalGradientPattern );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_RADIALGRADIENTPATTERN )
{
    /*
     * _static_public_members_ : RadialGradientPattern
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::BrushStyle", "RadialGradientPattern", RadialGradientPattern );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_TEXTUREPATTERN )
{
    /*
     * _static_public_members_ : TexturePattern
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::BrushStyle", "TexturePattern", TexturePattern );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_WHITE )
{
    /*
     * _static_public_members_ : white
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::GlobalColor", "white", white );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_BLACK )
{
    /*
     * _static_public_members_ : black
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::GlobalColor", "black", black );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_RED )
{
    /*
     * _static_public_members_ : red
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::GlobalColor", "red", red );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_DARKRED )
{
    /*
     * _static_public_members_ : darkRed
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::GlobalColor", "darkRed", darkRed );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_GREEN )
{
    /*
     * _static_public_members_ : green
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::GlobalColor", "green", green );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_DARKGREEN )
{
    /*
     * _static_public_members_ : darkGreen
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::GlobalColor", "darkGreen", darkGreen );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_BLUE )
{
    /*
     * _static_public_members_ : blue
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::GlobalColor", "blue", blue );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_DARKBLUE )
{
    /*
     * _static_public_members_ : darkBlue
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::GlobalColor", "darkBlue", darkBlue );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_CYAN )
{
    /*
     * _static_public_members_ : cyan
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::GlobalColor", "cyan", cyan );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_DARKCYAN )
{
    /*
     * _static_public_members_ : darkCyan
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::GlobalColor", "darkCyan", darkCyan );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_MAGENTA )
{
    /*
     * _static_public_members_ : magenta
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::GlobalColor", "magenta", magenta );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_DARKMAGENTA )
{
    /*
     * _static_public_members_ : darkMagenta
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::GlobalColor", "darkMagenta", darkMagenta );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_YELLOW )
{
    /*
     * _static_public_members_ : yellow
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::GlobalColor", "yellow", yellow );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_DARKYELLOW )
{
    /*
     * _static_public_members_ : darkYellow
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::GlobalColor", "darkYellow", darkYellow );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_GRAY )
{
    /*
     * _static_public_members_ : gray
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::GlobalColor", "gray", gray );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_DARKGRAY )
{
    /*
     * _static_public_members_ : darkGray
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::GlobalColor", "darkGray", darkGray );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_LIGHTGRAY )
{
    /*
     * _static_public_members_ : lightGray
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::GlobalColor", "lightGray", lightGray );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_TRANSPARENT )
{
    /*
     * _static_public_members_ : transparent
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::GlobalColor", "transparent", transparent );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_COLOR0 )
{
    /*
     * _static_public_members_ : color0
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::GlobalColor", "color0", color0 );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

HB_FUNC( QT_E_COLOR1 )
{
    /*
     * _static_public_members_ : color1
     */
    if( hb_pcount() == 0 )
    {
        qth_registerClassEnum( hb_stackSelfItem(), "Qt::GlobalColor", "color1", color1 );
        hb_itemReturn( hb_stackSelfItem() );
        return;
    }
    qth_errRT_PARAM();
}

/*
 * Wip: Method's Declaration Section END
 */

/*
 * Wip: Register Harbour Method's Section INIT
 */
HB_FUNC_STATIC( S_REGISTERMETHODS )
{
    HB_USHORT uiClass = hb_itemGetNI( hb_param( 1, HB_IT_NUMERIC ) );

    hb_clsAdd( uiClass, "E_UI_ANIMATEMENU"        , HB_FUNCNAME( QT_E_UI_ANIMATEMENU         ) );
    hb_clsAdd( uiClass, "E_UI_FADEMENU"           , HB_FUNCNAME( QT_E_UI_FADEMENU            ) );
    hb_clsAdd( uiClass, "E_UI_ANIMATECOMBO"       , HB_FUNCNAME( QT_E_UI_ANIMATECOMBO        ) );
    hb_clsAdd( uiClass, "E_UI_ANIMATETOOLTIP"     , HB_FUNCNAME( QT_E_UI_ANIMATETOOLTIP      ) );
    hb_clsAdd( uiClass, "E_UI_FADETOOLTIP"        , HB_FUNCNAME( QT_E_UI_FADETOOLTIP         ) );
    hb_clsAdd( uiClass, "E_UI_ANIMATETOOLBOX"     , HB_FUNCNAME( QT_E_UI_ANIMATETOOLBOX      ) );
    hb_clsAdd( uiClass, "E_NOBRUSH"               , HB_FUNCNAME( QT_E_NOBRUSH                ) );
    hb_clsAdd( uiClass, "E_SOLIDPATTERN"          , HB_FUNCNAME( QT_E_SOLIDPATTERN           ) );
    hb_clsAdd( uiClass, "E_DENSE1PATTERN"         , HB_FUNCNAME( QT_E_DENSE1PATTERN          ) );
    hb_clsAdd( uiClass, "E_DENSE2PATTERN"         , HB_FUNCNAME( QT_E_DENSE2PATTERN          ) );
    hb_clsAdd( uiClass, "E_DENSE3PATTERN"         , HB_FUNCNAME( QT_E_DENSE3PATTERN          ) );
    hb_clsAdd( uiClass, "E_DENSE4PATTERN"         , HB_FUNCNAME( QT_E_DENSE4PATTERN          ) );
    hb_clsAdd( uiClass, "E_DENSE5PATTERN"         , HB_FUNCNAME( QT_E_DENSE5PATTERN          ) );
    hb_clsAdd( uiClass, "E_DENSE6PATTERN"         , HB_FUNCNAME( QT_E_DENSE6PATTERN          ) );
    hb_clsAdd( uiClass, "E_DENSE7PATTERN"         , HB_FUNCNAME( QT_E_DENSE7PATTERN          ) );
    hb_clsAdd( uiClass, "E_HORPATTERN"            , HB_FUNCNAME( QT_E_HORPATTERN             ) );
    hb_clsAdd( uiClass, "E_VERPATTERN"            , HB_FUNCNAME( QT_E_VERPATTERN             ) );
    hb_clsAdd( uiClass, "E_CROSSPATTERN"          , HB_FUNCNAME( QT_E_CROSSPATTERN           ) );
    hb_clsAdd( uiClass, "E_BDIAGPATTERN"          , HB_FUNCNAME( QT_E_BDIAGPATTERN           ) );
    hb_clsAdd( uiClass, "E_FDIAGPATTERN"          , HB_FUNCNAME( QT_E_FDIAGPATTERN           ) );
    hb_clsAdd( uiClass, "E_DIAGCROSSPATTERN"      , HB_FUNCNAME( QT_E_DIAGCROSSPATTERN       ) );
    hb_clsAdd( uiClass, "E_LINEARGRADIENTPATTERN" , HB_FUNCNAME( QT_E_LINEARGRADIENTPATTERN  ) );
    hb_clsAdd( uiClass, "E_CONICALGRADIENTPATTERN", HB_FUNCNAME( QT_E_CONICALGRADIENTPATTERN ) );
    hb_clsAdd( uiClass, "E_RADIALGRADIENTPATTERN" , HB_FUNCNAME( QT_E_RADIALGRADIENTPATTERN  ) );
    hb_clsAdd( uiClass, "E_TEXTUREPATTERN"        , HB_FUNCNAME( QT_E_TEXTUREPATTERN         ) );
    hb_clsAdd( uiClass, "E_WHITE"                 , HB_FUNCNAME( QT_E_WHITE                  ) );
    hb_clsAdd( uiClass, "E_BLACK"                 , HB_FUNCNAME( QT_E_BLACK                  ) );
    hb_clsAdd( uiClass, "E_RED"                   , HB_FUNCNAME( QT_E_RED                    ) );
    hb_clsAdd( uiClass, "E_DARKRED"               , HB_FUNCNAME( QT_E_DARKRED                ) );
    hb_clsAdd( uiClass, "E_GREEN"                 , HB_FUNCNAME( QT_E_GREEN                  ) );
    hb_clsAdd( uiClass, "E_DARKGREEN"             , HB_FUNCNAME( QT_E_DARKGREEN              ) );
    hb_clsAdd( uiClass, "E_BLUE"                  , HB_FUNCNAME( QT_E_BLUE                   ) );
    hb_clsAdd( uiClass, "E_DARKBLUE"              , HB_FUNCNAME( QT_E_DARKBLUE               ) );
    hb_clsAdd( uiClass, "E_CYAN"                  , HB_FUNCNAME( QT_E_CYAN                   ) );
    hb_clsAdd( uiClass, "E_DARKCYAN"              , HB_FUNCNAME( QT_E_DARKCYAN               ) );
    hb_clsAdd( uiClass, "E_MAGENTA"               , HB_FUNCNAME( QT_E_MAGENTA                ) );
    hb_clsAdd( uiClass, "E_DARKMAGENTA"           , HB_FUNCNAME( QT_E_DARKMAGENTA            ) );
    hb_clsAdd( uiClass, "E_YELLOW"                , HB_FUNCNAME( QT_E_YELLOW                 ) );
    hb_clsAdd( uiClass, "E_DARKYELLOW"            , HB_FUNCNAME( QT_E_DARKYELLOW             ) );
    hb_clsAdd( uiClass, "E_GRAY"                  , HB_FUNCNAME( QT_E_GRAY                   ) );
    hb_clsAdd( uiClass, "E_DARKGRAY"              , HB_FUNCNAME( QT_E_DARKGRAY               ) );
    hb_clsAdd( uiClass, "E_LIGHTGRAY"             , HB_FUNCNAME( QT_E_LIGHTGRAY              ) );
    hb_clsAdd( uiClass, "E_TRANSPARENT"           , HB_FUNCNAME( QT_E_TRANSPARENT            ) );
    hb_clsAdd( uiClass, "E_COLOR0"                , HB_FUNCNAME( QT_E_COLOR0                 ) );
    hb_clsAdd( uiClass, "E_COLOR1"                , HB_FUNCNAME( QT_E_COLOR1                 ) );
}
/*
 * Wip: Register Harbour Method's Section END
 */
