# New ports collection makefile for:	leafpak
# Date created:				25 Sep 2000
# Whom:                 		TAKAHASHI Kaoru
#
# $FreeBSD$
#

PORTNAME=	leafpak
PORTVERSION=	1.1
CATEGORIES=	graphics
MASTER_SITES=	http://hoshina.denpa.org/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	kaoru@kaisei.org

WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/leafpak ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/leafpak2 ${PREFIX}/bin

.include <bsd.port.mk>
