#!/bin/sh

case "$1" in

    start)

        echo -n "Starting ATOK X server:"

        if [ -x /usr/lib/locale/ja/atokserver/atokmngdaemon ];then
                daemon /usr/lib/locale/ja/atokserver/atokmngdaemon
        fi

	echo

	touch /var/lock/subsys/atokx

	;;

    stop)

	killproc /usr/lib/locale/ja/atokserver/atokmngdaemon >/dev/null 2>&1

	rm -f /var/lock/subsys/atokx

	;;

    *)

	echo "Usage: atokx { start | stop }"
	exit 1
	;;

esac

exit 0

