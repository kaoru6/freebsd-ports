# New ports collection makefile for:	xasahi
# Date created:				29 Oct 2000
# Whom:					TAKAHASHI Kaoru
#
# $FreeBSD$
#

PORTNAME=	xasahi
PORTVERSION=	0.a3
CATEGORIES=	audio
MASTER_SITES=	http://www2.osk.3web.ne.jp/~kgt/Archive/
DISTNAME=	asahi-rb.alpha3

MAINTAINER=	kaoru@kaisei.org

BUILD_DEPENDS=	ibcdaudio-config:${PORTSDIR}/audio/libcdaudio
LIB_DEPENDS=	cdaudio:${PORTSDIR}/audio/libcdaudio
RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123 \
		timidity:${PORTSDIR}/audio/timidity++

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
RUBY_EXTCONF_SUBDIRS=	lib cdaudio
USE_GTK=	yes

NO_BUILD=	yes

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ja/xasahi
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ja/xasahi
.endif

.include <bsd.port.mk>
