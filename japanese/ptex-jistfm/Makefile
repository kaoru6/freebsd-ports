# New ports collection makefile for:	pTeX JIS font metics
# Date created:		14 Nov 2000
# Whom:			TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	jis-tfm
PORTVERSION=	1.0
CATEGORIES=	japanese print
DISTNAME=	${PORTNAME}
MASTER_SITES=	http://www.matsusaka-u.ac.jp/~okumura/texfaq/

MAINTAINER=	kaoru@kaisei.org

DIST_SUBDIR=	ptex
NO_BUILD=	yes
USE_ZIP=	yes

TEXMF=		${PREFIX}/share/texmf
FILES=		jis-v.tfm jis.tfm jisg-v.tfm jisg.tfm \
		jisgn-v.tfm jisgn.tfm jisn-v.tfm jisn.tfm

do-install:
	${MKDIR} ${TEXMF}/fonts/tfm/ptex
	for file in ${FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/"$$file" ${TEXMF}/fonts/tfm/ptex ; \
	done
.if exists(${PREFIX}/share/texmf/ls-R)
	mktexlsr
.endif

.include <bsd.port.mk>
