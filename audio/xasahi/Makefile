# New ports collection makefile for:	leafpak
# Date created:				29 Oct 2000
# Whom:                 		TAKAHASHI Kaoru
#
# $FreeBSD$
#

PORTNAME=	xasahi
PORTVERSION=	0.3
CATEGORIES=	graphics
MASTER_SITES=	http://www2.osk.3web.ne.jp/~kgt/Archive/
DISTNAME=	asahi-rb.alpha3

MAINTAINER=	kaoru@kaisei.org

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USE_GTK=	yes

LIB_DEPEND=	lcdaudio.1:${PORTSDIR}/audio/libcdaudio

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ja/xasahi
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ja/xasahi
.endif

.include <bsd.port.mk>
