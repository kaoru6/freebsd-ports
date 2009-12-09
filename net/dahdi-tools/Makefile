# New ports collection makefile for:	DAHDI Tools
# Date created:				2009-12-10
# Whom:					TAKAHASHI Kaoru
#
# $FreeBSD$
#

PORTNAME=	dahdi-tools
PORTVERSION=	0.0.361
CATEGORIES=	net
MASTER_SITES=	http://triaez.kaisei.org/~kaoru/asterisk/

MAINTAINER=	kaoru@kaisei.org
COMMENT=	DAHDI Tools with kernel module

USE_RC_SUBR=	dahdi
MAKE_ENV=	KMODDIR=${PREFIX}/lib/dahdi
#WRKSRC=		${WRKDIR}/${DISTNAME}

pre-install:
	${MKDIR} ${PREFIX}/lib/dahdi

.include <bsd.port.mk>
