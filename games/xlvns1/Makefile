# New ports collection makefile for:	xlvns1
# Date created:		Tue May 30 11:07:06 JST 2000
# Whom:			Yuuki SAWADA <samy@goldmoon.org>
#
# $FreeBSD: $
#

PORTNAME=	xlvns1
PORTVERSION=	1.6b
CATEGORIES=	emulators
MASTER_SITES=	http://leafbsd.denpa.org/

MAINTAINER=	samy@goldmoon.org

USE_X_PREFIX=	yes
USE_IMAKE=	yes

NO_INSTALL_MANPAGES= yes

post-install:
.if !defined(BATCH)
	@${CAT} ${FILESDIR}/post-install-notes
.endif

.include <bsd.port.mk>
