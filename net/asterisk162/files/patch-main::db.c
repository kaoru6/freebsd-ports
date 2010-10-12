
$FreeBSD: ports/net/asterisk16/files/patch-main::db.c,v 1.3 2009/08/02 19:34:55 mezz Exp $

--- main/db.c
+++ main/db.c
@@ -36,6 +36,7 @@
 #include <sys/time.h>
 #include <signal.h>
 #include <dirent.h>
+#include <db.h>
 
 #include "asterisk/channel.h"
 #include "asterisk/file.h"
@@ -46,7 +47,6 @@
 #include "asterisk/utils.h"
 #include "asterisk/lock.h"
 #include "asterisk/manager.h"
-#include "db1-ast/include/db.h"
 
 static DB *astdb;
 AST_MUTEX_DEFINE_STATIC(dblock);
