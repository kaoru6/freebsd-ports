# New ports collection makefile for:	GNU Backgammon
# Date created:		8 Dec 2002
# Whom:			TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	gnubg
PORTVERSION=	0.12.030105
CATEGORIES=	games
MASTER_SITES=	ftp://alpha.gnu.org/gnu/gnubg/snapshots/ \
		ftp://alpha.gnu.org/gnu/gnubg/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/0.12.//}
DISTFILES=	${DISTNAME}.tar.gz gnubg.weights-0.12b.gz \
		gnubg_ts0.bd.gz gnubg_os0.bd.gz
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	kaoru@kaisei.org

WRKSRC=		${WRKDIR}/${PORTNAME}

MAN6=	gnubg.6

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
WANT_GTK=	yes
WANT_ESOUND=	yes

do-patch:
	${CP} ${FILESDIR}/ja.po  ${WRKSRC}/po/
	${GUNZIP_CMD} --stdout ${DISTDIR}/${DIST_SUBDIR}/gnubg_ts0.bd.gz > ${WRKSRC}/gnubg_ts0.bd
	${GUNZIP_CMD} --stdout ${DISTDIR}/${DIST_SUBDIR}/gnubg_os0.bd.gz > ${WRKSRC}/gnubg_os0.bd
	${GUNZIP_CMD} --stdout ${DISTDIR}/${DIST_SUBDIR}/gnubg.weights-0.12b.gz > ${WRKSRC}/gnubg.weights

.include <bsd.port.mk>
