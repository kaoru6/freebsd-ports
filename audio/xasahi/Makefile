# New ports collection makefile for:	xasahi
# Date created:		29 Oct 2000
# Whom:			TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	xasahi
PORTVERSION=	2002.12.30
CATEGORIES=	audio ruby
MASTER_SITES=	http://www.kokone.to/~kgt/Archive/
DISTNAME=	asahi-rb.current

MAINTAINER=	kaoru@kaisei.org

BUILD_DEPENDS=	libcdaudio-config:${PORTSDIR}/audio/libcdaudio
LIB_DEPENDS=	cdaudio:${PORTSDIR}/audio/libcdaudio
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/gtk.so:${PORTSDIR}/x11-toolkits/ruby-gtk 
#		mpg123:${PORTSDIR}/audio/mpg123
#		timidity:${PORTSDIR}/audio/timidity++

DIST_SUBDIR=	ruby
USE_GTK=	yes
WANT_ESOUND=	yes
WANT_IMLIB=	yes

USE_RUBY=	yes
#USE_RUBY_SETUP=	yes

CONFIG_CMD?=	${GTK_CONFIG}

XASAHI_FILES=	mpg123.rb timidity.rb playlist.rb asahi.rb led.rb
EXAMPLE_DIR=	${PREFIX}/share/examples/ja/xasahi

.include <bsd.port.pre.mk>

.if defined(HAVE_ESOUND)
USE_ESOUND=	yes
RUBY_SETUP=	setup.rb --esd
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/esd.so:${PORTSDIR}/audio/ruby-esound
XASAHI_FILES+=	esdaudio.rb
PLIST_SUB+=	ESD="" PCM="@comment "
.else
RUBY_SETUP=	setup.rb
XASAHI_FILES+=	pcaudio.rb
PLIST_SUB+=	ESD="@comment " PCM=""
.endif

post-patch:
	 ${PERL} -i -pe  's|gtk-config |${CONFIG_CMD} |g' ${WRKSRC}/lib/extconf.rb
	 ${PERL} -i -pe  's|BINDIRS[ \t]+=.*$$|BINDIRS = [\"${PREFIX}/bin\"] |g' ${WRKSRC}/setup.rb

do-configure:
	cd ${WRKSRC} && ./${RUBY_SETUP}

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xasahi ${WRKSRC}/disc_id ${PREFIX}/bin
#	${MKDIR} ${RUBY_SITELIBDIR}/xasahi
#	cd ${WRKSRC} && \
#		${INSTALL_SCRIPT} ${XASAHI_FILES} ${RUBY_SITELIBDIR}/xasahi
#	${MKDIR} ${RUBY_SITEARCHLIBDIR}/xasahi
#	${INSTALL_PROGRAM} ${WRKSRC}/cdaudio/cdaudio.so ${RUBY_SITEARCHLIBDIR}
#	${INSTALL_PROGRAM} ${WRKSRC}/lib/lfplib.so ${RUBY_SITEARCHLIBDIR}/xasahi
	${MKDIR} ${EXAMPLE_DIR}
	cd ${WRKSRC}/example &&	${CP} -R * ${EXAMPLE_DIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ja/xasahi
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ja/xasahi
.endif
.if !defined(BATCH)
	@ ${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
