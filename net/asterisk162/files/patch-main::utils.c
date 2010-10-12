
$FreeBSD: ports/net/asterisk16/files/patch-main::utils.c,v 1.8 2009/08/02 19:34:55 mezz Exp $

--- main/utils.c
+++ main/utils.c
@@ -936,8 +936,8 @@
 		pthread_attr_init(attr);
 	}
 
-#ifdef __linux__
-	/* On Linux, pthread_attr_init() defaults to PTHREAD_EXPLICIT_SCHED,
+#if defined(__linux__) || defined(__FreeBSD__)
+	/* On Linux and FreeBSD, pthread_attr_init() defaults to PTHREAD_EXPLICIT_SCHED,
 	   which is kind of useless. Change this here to
 	   PTHREAD_INHERIT_SCHED; that way the -p option to set realtime
 	   priority will propagate down to new threads by default.
