
$FreeBSD: ports/net/asterisk16/files/patch-channels::chan_sip.c,v 1.13 2009/08/02 19:34:55 mezz Exp $

--- channels/chan_sip.c
+++ channels/chan_sip.c
@@ -611,7 +611,7 @@
 #define DEFAULT_MOHINTERPRET    "default"
 #define DEFAULT_MOHSUGGEST      ""
 #define DEFAULT_VMEXTEN 	"asterisk"
-#define DEFAULT_CALLERID 	"asterisk"
+#define DEFAULT_CALLERID 	"Unknown"
 #define DEFAULT_NOTIFYMIME 	"application/simple-message-summary"
 #define DEFAULT_ALLOWGUEST	TRUE
 #define DEFAULT_CALLCOUNTER	FALSE
