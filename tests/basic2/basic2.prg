
FUNCTION Main()
  LOCAL time

  time := QTime():New()

  ? "time:", time:fromString( "12:50:59", "h:m:s" ):toString()

RETURN NIL
