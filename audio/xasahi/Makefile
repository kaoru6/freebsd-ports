# New ports collection makefile for:	xasahi
# Date created:		29 Oct 2000
# Whom:			TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	xasahi
PORTVERSION=	2000.11.26
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
WANT_ESOUND=	yes
WANT_IMLIB=	yes

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
RUBY_EXTCONF_SUBDIRS=	lib cdaudio
#USE_RUBY_SETUP=	yes

XASAHI_FILES=	mpg123.rb timidity.rb pcaudio.rb playlist.rb asahi.rb led.rb
EXAMPLE_FILES=	cddb config
PLAYLIST_FILES=	all default favorite rippers test test2
CDDB_FILES=	4E232E0C0325C73000E6200D5C022C2331327513 \
		57312ED80027A4013266211B1E21254003071D11 \
		5D111069120A533133FB310B140218100010AF32 \
		8A231577330AE80300C220291F31281E2320D330 \
		A4013951112ACB323AFF3323A6233107322B2731 \
		FB331176221FBC021F0B33164D111688000FAD13

pre-build:
	cd ${WRKSRC} && ./setup.rb

post-build:
	cd ${WRKSRC} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} dot-xasahi.tar.gz ${EXTRACT_AFTER_ARGS}

do-install:
	${MKDIR} ${RUBY_SITEARCHLIBDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/cdaudio/cdaudio.so	${RUBY_SITEARCHLIBDIR}
	${MKDIR} ${RUBY_SITEARCHLIBDIR}/xasahi
	${INSTALL_PROGRAM} ${WRKSRC}/lib/lfplib.so ${RUBY_SITEARCHLIBDIR}/xasahi
	${MKDIR} ${RUBY_SITELIBDIR}/xasahi
	for file in ${XASAHI_FILES}; do \
		${INSTALL_SCRIPT} ${WRKSRC}/"$$file" \
			${RUBY_SITELIBDIR}/xasahi ; \
	done
	${INSTALL_SCRIPT} ${WRKSRC}/xasahi	${PREFIX}/bin

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/disc_id ${PREFIX}/bin
#	${INSTALL_SCRIPT} ${WRKSRC}/tool/catalog.rb ${PREFIX}/bin
#	${INSTALL_SCRIPT} ${WRKSRC}/tool/voice.rb ${PREFIX}/bin
#	strip ${RUBY_SITEARCHLIBDIR}/cdaudio.so
#	strip ${RUBY_SITEARCHLIBDIR}/xasahi/lfplib.so
	${MKDIR} ${PREFIX}/share/examples/ja/xasahi
	for file in ${EXAMPLE_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/dot-xasahi/"$$file" \
			${PREFIX}/share/examples/ja/xasahi ; \
	done
	${MKDIR} ${PREFIX}/share/examples/ja/xasahi/play_list
	for file in ${PLAYLIST_FILES} ${CDDB_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/dot-xasahi/play_list/"$$file" \
			${PREFIX}/share/examples/ja/xasahi/play_list ; \
	done
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ja/xasahi
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ja/xasahi
.endif
.if !defined(BATCH)
	@ ${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
