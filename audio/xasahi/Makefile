# New ports collection makefile for:	xasahi
# Date created:				29 Oct 2000
# Whom:					TAKAHASHI Kaoru
#
# $FreeBSD$
#

PORTNAME=	xasahi
PORTVERSION=	20001105
CATEGORIES=	audio
MASTER_SITES=	http://www2.osk.3web.ne.jp/~kgt/Archive/
DISTNAME=	asahi-rb.current
# DISTNAME=	asahi-rb.alpha3

MAINTAINER=	kaoru@kaisei.org

BUILD_DEPENDS=	ibcdaudio-config:${PORTSDIR}/audio/libcdaudio
LIB_DEPENDS=	cdaudio:${PORTSDIR}/audio/libcdaudio
RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123 \
		timidity:${PORTSDIR}/audio/timidity++

USE_GTK=	yes
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
RUBY_EXTCONF_SUBDIRS=	cdaudio

do-build:
	cd ${WRKSRC}/lib && ./extconf.rb && make
#	cd ${WRKSRC}/lib && make
	cd ${WRKSRC}/cdaudio && make

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ja/xasahi
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ja/xasahi
.endif

.include <bsd.port.mk>
