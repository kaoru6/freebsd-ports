
$FreeBSD: ports/net/asterisk/files/patch-main::frame.c,v 1.1 2007/04/13 08:06:05 sobomax Exp $

--- main/frame.c.orig	Wed Jan 25 13:22:43 2006
+++ main/frame.c	Wed Jan 25 13:21:25 2006
@@ -1170,7 +1170,7 @@ static int g723_len(unsigned char buf)
 {
 	switch(buf & TYPE_MASK) {
 	case TYPE_DONTSEND:
-		return 0;
+		return 2;
 		break;
 	case TYPE_SILENCE:
 		return 4;
