#!/bin/sh
#
# Copyright (c) 1999 by Sun Microsystems, Inc.
# All rights reserved.
#
#ident	"@(#)IIim	1.9	99/08/30 SMI"

. /etc/rc.d/init.d/functions

case "$1" in
'start')
	if [ -x /usr/lib/im/htt ]; then
		/usr/lib/im/htt -port 9010 -syslog -message_locale C >/dev/null 2>&1 &
	fi
	;;

'stop')
	killproc /usr/lib/im/htt >/dev/null 2>&1
	;;

*)
	echo "Usage: $0 { start | stop }"
	exit 1
	;;
esac
exit 0
