# New ports collection makefile for:	pTeX JIS font metrics
# Date created:		20 Nov 2001
# Whom:			TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	ptex-jistfm
PORTVERSION=	1.1
CATEGORIES=	japanese print
DISTNAME=	jis-tfm
MASTER_SITES=	http://www.matsusaka-u.ac.jp/~okumura/texfaq/

MAINTAINER=	kaoru@kaisei.org

DIST_SUBDIR=	teTeX/ptex
NO_BUILD=	yes
USE_ZIP=	yes
WRKSRC=		${WRKDIR}

FORBIDDEN=      "Use japanese/makejvf instead.  makejvf included jistfm."

TEXMF=		${PREFIX}/share/texmf
FILES=		jis-v.tfm jis.tfm jisg-v.tfm jisg.tfm \
		jisgn-v.tfm jisgn.tfm jisn-v.tfm jisn.tfm

do-install:
	${MKDIR} ${TEXMF}/fonts/tfm/ptex
	cd ${WRKSRC} && ${INSTALL_DATA} ${FILES} ${TEXMF}/fonts/tfm/ptex
.if exists(${PREFIX}/share/texmf/ls-R)
	mktexlsr
.endif

.include <bsd.port.mk>
