# New ports collection makefile for:	xasahi
# Date created:				29 Oct 2000
# Whom:					TAKAHASHI Kaoru
#
# $FreeBSD$
#

PORTNAME=	xasahi
PORTVERSION=	20001112
CATEGORIES=	audio
MASTER_SITES=	http://www2.osk.3web.ne.jp/~kgt/Archive/
DISTNAME=	asahi-rb.current

MAINTAINER=	kaoru@kaisei.org

BUILD_DEPENDS=	libcdaudio-config:${PORTSDIR}/audio/libcdaudio \
		gtk12-config:${PORTSDIR}/x11-toolkits/gtk12
LIB_DEPENDS=	cdaudio:${PORTSDIR}/audio/libcdaudio \
		gtk12:${PORTSDIR}/x11-toolkits/gtk12
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/gtk.so:${PORTSDIR}/x11-toolkits/ruby-gtk \
		mpg123:${PORTSDIR}/audio/mpg123 \
		timidity:${PORTSDIR}/audio/timidity++

USE_GTK=	yes
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
RUBY_EXTCONF_SUBDIRS=	lib cdaudio

pre-build:
	cd ${WRKSRC} && ./setup.rb

post-build:
	cd ${WRKSRC} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} dot-xasahi.tar.gz ${EXTRACT_AFTER_ARGS}

#do-install:
#	-${MKDIR} ${RUBY_SITEARCHLIBDIR}
#	${CP} -p ${WRKSRC}/cdaudio/cdaudio.so	${RUBY_SITEARCHLIBDIR}
#	-${MKDIR} ${RUBY_SITEARCHLIBDIR}/xasahi
#	${CP} -p ${WRKSRC}/lib/lfplib.so	${RUBY_SITEARCHLIBDIR}/xasahi
#	-${MKDIR} ${RUBY_SITELIBDIR}/xasahi
#	${INSTALL_DATA} ${WRKSRC}/mpg123.rb	${RUBY_SITELIBDIR}/xasahi
#	${INSTALL_DATA} ${WRKSRC}/timidity.rb	${RUBY_SITELIBDIR}/xasahi
#	${INSTALL_DATA} ${WRKSRC}/pcaudio.rb	${RUBY_SITELIBDIR}/xasahi
#	${INSTALL_DATA} ${WRKSRC}/playlist.rb	${RUBY_SITELIBDIR}/xasahi
#	${INSTALL_DATA} ${WRKSRC}/asahi.rb	${RUBY_SITELIBDIR}/xasahi
#	${INSTALL_SCRIPT} ${WRKSRC}/xasahi	${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ja/xasahi
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ja/xasahi
.endif

.include <bsd.port.mk>
