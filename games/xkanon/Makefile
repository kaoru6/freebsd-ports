# New ports collection makefile for:	xkanon
# Date created:		Mon May 22 08:16:19 JST 2000
# Whom:			Yuki Sawada <samy@goldmoon.org>
#
# $FreeBSD: $
#

PORTNAME=	xkanon
PORTVERSION=	b13
CATEGORIES=	emulators games x11
MASTER_SITES=	http://www.creator.club.ne.jp/~jagarl/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/b/beta/g}

MAINTAINER=	samy@goldmoon.org

LIB_DEPENDS=	gtkmm-1.2.0:${PORTSDIR}/x11-toolkits/gtk--

USE_X_PREFIX=	yes
USE_NEWGCC=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

.if defined(WITH_FREETYPE)
LIB_DEPENDS+=	ttf.4:${PORTSDIR}/print/freetype
CONFIGURE_ARGS+= --with-freetype \
		--with-freetype-includedir=${LOCALBASE}/include/freetype \
		--with-freetype-lib=${LOCALBASE}/lib
.endif

.if !defined(WITH_FREETYPE)
pre-fetch:
	@${ECHO}
	@${ECHO} "If you want to compile with FreeType support,"
	@${ECHO} "add \"WITH_FREETYPE=yes\" to argument of make."
	@${ECHO}
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/xayusys ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/xkanon ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/xkanon-all ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/xkanon-install ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/xkanon-all-install ${PREFIX}/bin

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGDIR}/MESSAGE
.endif

.include <bsd.port.mk>
