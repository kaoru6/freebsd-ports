# New ports collection makefile for:	GNU Backgammon
# Date created:		8 Dec 2002
# Whom:			TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	gnubg
PORTVERSION=	0.12.021207
CATEGORIES=	games
MASTER_SITES=	ftp://alpha.gnu.org/gnu/gnubg/snapshots/ \
		ftp://alpha.gnu.org/gnu/gnubg/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/0.12.//}
DISTFILES=	${DISTNAME}.tar.gz gnubg.weights-0.12.gz
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}.tar.gz

WRKSRC=		${WRKDIR}/${PORTNAME}

MAINTAINER=	kaoru@kaisei.org

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
WANT_GTK=	yes
WANT_ESOUND=	yes

.include <bsd.port.mk>
