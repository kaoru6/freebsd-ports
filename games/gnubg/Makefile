# New ports collection makefile for:	GNU Backgammon
# Date created:		8 Dec 2002
# Whom:			TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD: ports/games/gnubg/Makefile,v 1.1 2003/07/28 10:28:59 maho Exp $
#

PORTNAME=	gnubg
PORTVERSION=	0.13.0
CATEGORIES=	games
MASTER_SITES=	ftp://alpha.gnu.org/gnu/gnubg/
DISTFILES=	${DISTNAME}.tar.gz	\
		gnubg.weights-${GNUBG_WEIGHTS_VERSION}.gz	\
		gnubg_ts0.bd.gz gnubg_os0.bd.gz
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	kaoru@kaisei.org
COMMENT=	GNU Backgammon

MAN6=	gnubg.6

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS += --disable-nls
.else
CONFIGURE_ARGS += --enable-nls
LIB_DEPENDS+=	intl.4:${PORTSDIR}/devel/gettext
.endif


.if defined(WITH_GUILE)
CONFIGURE_ARGS += --with-guile
BUILD_DEPENDS=	guile:${PORTSDIR}/lang/guile
.endif

.include <bsd.port.pre.mk>

.if defined(WITHOUT_SOUND)
CONFIGURE_ARGS += --without-sound
.else
CONFIGURE_ARGS += --with-sound
.if ${HAVE_GNOME:Mesound}!=""
USE_GNOME+=     esound
.endif
.if defined(WITH_NAS)
CONFIGURE_ARGS += --enable-nas
LIB_DEPENDS+=   audio.2:${PORTSDIR}/audio/nas
HAVE_NAS=	yes
.endif
.endif

GNUBG_WEIGHTS_VERSION=0.13b

do-patch:
	${GUNZIP_CMD} --stdout ${DISTDIR}/${DIST_SUBDIR}/gnubg_ts0.bd.gz > ${WRKSRC}/gnubg_ts0.bd
	${GUNZIP_CMD} --stdout ${DISTDIR}/${DIST_SUBDIR}/gnubg_os0.bd.gz > ${WRKSRC}/gnubg_os0.bd
	${GUNZIP_CMD} --stdout ${DISTDIR}/${DIST_SUBDIR}/gnubg.weights-${GNUBG_WEIGHTS_VERSION}.gz > ${WRKSRC}/gnubg.weights

.include <bsd.port.post.mk>
