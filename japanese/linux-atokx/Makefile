# New ports collection makefile for:	ATOK X
# Date created:				26 Sep 2000
# Whom:                 		TAKAHASHI Kaoru
#
# $FreeBSD$
#

PORTNAME=	atokx
PORTVERSION=	1.0.1
CATEGORIES=	japanese
DISTFILES=	${PORTNAME}-1.0-1.i386.tgz \
		iiimf.tgz

MAINTAINER=	kaoru@kaisei.org

IGNOREFILES=	${DISTFILES}
RESTRICTED=     "You should buy from Justsystem Co., Ltd."
NO_CDROM=       "You should buy from Justsystem Co., Ltd."
NO_PACKAGE=     "You should buy from Justsystem Co., Ltd."
NO_BUILD=       yes

WRKATOK=	${WRKSRC}/usr/lib/locale/ja/atokserver
WRKIIIM=	${WRKSRC}/usr/lib/im

ATOKDIR=	${PREFIX}/lib/atokx
IIIMDIR=	${PREFIX}/lib/im

do-fetch:
	@${DO_NADA}
fetch-list:
	@${DO_NADA}

do-install:
	${INSTALL_PROGRAM} ${WRKATOKSERVER} ${PREFIX}/bin

.include <bsd.port.mk>
