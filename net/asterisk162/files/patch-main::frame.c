
$FreeBSD: ports/net/asterisk16/files/patch-main::frame.c,v 1.3 2009/08/02 19:34:55 mezz Exp $

--- main/frame.c
+++ main/frame.c
@@ -1260,7 +1260,7 @@
 
 	switch(type) {
 	case TYPE_DONTSEND:
-		return 0;
+		return 2;
 		break;
 	case TYPE_SILENCE:
 		return 4;
