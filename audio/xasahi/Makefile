# New ports collection makefile for:	xasahi
# Date created:				29 Oct 2000
# Whom:					TAKAHASHI Kaoru
#
# $FreeBSD$
#

PORTNAME=	xasahi
PORTVERSION=	20001108
CATEGORIES=	audio
MASTER_SITES=	http://www2.osk.3web.ne.jp/~kgt/Archive/
DISTNAME=	asahi-rb.current

MAINTAINER=	kaoru@kaisei.org

BUILD_DEPENDS=	libcdaudio-config:${PORTSDIR}/audio/libcdaudio \
		gtk12-config:${PORTSDIR}/x11-toolkits/ruby-gtk
LIB_DEPENDS=	cdaudio:${PORTSDIR}/audio/libcdaudio
RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123 \
		timidity:${PORTSDIR}/audio/timidity++

NO_INSTALL=	yes
USE_GTK=	yes
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
RUBY_EXTCONF_SUBDIRS=	lib cdaudio

do-build:
	cd ${WRKSRC}/lib && make
	cd ${WRKSRC}/cdaudio && make

post-build:
	cd ${WRKSRC} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} dot-xasahi.tar.gz ${EXTRACT_AFTER_ARGS}

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ja/xasahi
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ja/xasahi
.endif

.include <bsd.port.mk>
