# New ports collection makefile for:	armond
# Date created:		11 Nov 2004
# Whom:			TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	armond
PORTVERSION=	1.0.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.on-sky.net/~hs/soft/images/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ARAID99 1000 monitor daemon

CONFIGURE=	no

MAN8=		armond.8
MANLANG=	ja
PLIST_FILES=	sbin/armond

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/armond ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/armond.8 ${PREFIX}/man/ja/man8

.include <bsd.port.mk>
