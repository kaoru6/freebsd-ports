# New ports collection makefile for:	xasahi
# Date created:		29 Oct 2000
# Whom:			TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	xasahi
PORTVERSION=	2001.01.28
CATEGORIES=	audio ruby
MASTER_SITES=	http://www2.osk.3web.ne.jp/~kgt/Archive/
DISTNAME=	asahi-rb.current

MAINTAINER=	kaoru@kaisei.org

BUILD_DEPENDS=	libcdaudio-config:${PORTSDIR}/audio/libcdaudio
LIB_DEPENDS=	cdaudio:${PORTSDIR}/audio/libcdaudio
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/gtk.so:${PORTSDIR}/x11-toolkits/ruby-gtk \
		mpg123:${PORTSDIR}/audio/mpg123 \
		timidity:${PORTSDIR}/audio/timidity++

DIST_SUBDIR=	ruby
USE_GTK=	yes
WANT_ESOUND=	yes
WANT_IMLIB=	yes

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
RUBY_EXTCONF_SUBDIRS=	lib cdaudio
#USE_RUBY_SETUP=	yes

CONFIG_CMD?=	${GTK_CONFIG}

XASAHI_FILES=	mpg123.rb timidity.rb pcaudio.rb playlist.rb asahi.rb led.rb
EXAMPLE_DIR=	${PREFIX}/share/examples/ja/xasahi

.if defined(HAVE_ESOUND)
RUBY_EXTCONF_SUBDIRS+=	esd
XASAHI_FILES+=	esdaudio.rb
PLIST=		${PKGDIR}/pkg-plist.esd
.endif

post-patch:
	 ${PERL} -i -pe  's|gtk-config |${CONFIG_CMD} |g' ${WRKSRC}/lib/extconf.rb
	 ${PERL} -i -pe  's|BINDIRS[ \t]+=.*$$|BINDIRS = [\"${PREFIX}/bin\"] |g' ${WRKSRC}/setup.rb

pre-build:
.if defined(HAVE_ESOUND)
	cd ${WRKSRC} && ./setup.rb --esd
.else
	cd ${WRKSRC} && ./setup.rb
.endif

do-install:
	${MKDIR} ${RUBY_SITEARCHLIBDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/cdaudio/cdaudio.so	${RUBY_SITEARCHLIBDIR}
	${MKDIR} ${RUBY_SITEARCHLIBDIR}/xasahi
	${INSTALL_PROGRAM} ${WRKSRC}/lib/lfplib.so ${RUBY_SITEARCHLIBDIR}/xasahi
.if defined(HAVE_ESOUND)
	${INSTALL_PROGRAM} ${WRKSRC}/esd/esd.so	${RUBY_SITEARCHLIBDIR}
.endif
	${MKDIR} ${RUBY_SITELIBDIR}/xasahi
	cd ${WRKSRC} && \
		${INSTALL_SCRIPT} ${XASAHI_FILES} ${RUBY_SITELIBDIR}/xasahi
	${INSTALL_SCRIPT} ${WRKSRC}/xasahi	${PREFIX}/bin

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/disc_id ${PREFIX}/bin
#	${INSTALL_SCRIPT} ${WRKSRC}/tool/catalog.rb ${PREFIX}/bin
#	${INSTALL_SCRIPT} ${WRKSRC}/tool/voice.rb ${PREFIX}/bin
#	strip ${RUBY_SITEARCHLIBDIR}/cdaudio.so
#	strip ${RUBY_SITEARCHLIBDIR}/xasahi/lfplib.so
	${MKDIR} ${EXAMPLE_DIR}
	cd ${WRKSRC}/example &&	${CP} -R * ${EXAMPLE_DIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ja/xasahi
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ja/xasahi
.endif
.if !defined(BATCH)
	@ ${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
