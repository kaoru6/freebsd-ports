# New ports collection makefile for:	Nemacs
# Date created:				14 Nov 2000
# Whom:					TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	ptex-jistfm
PORTVERSION=	1.0
CATEGORIES=	japanese print
MASTER_SITES=	http://www.matsusaka-u.ac.jp/~okumura/texfaq/
DISTNAME=	jis-tfm
EXTRACT_SUFX=	.zip

MAINTAINER=	kaoru@kaisei.org

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

NO_BUILD=	yes

TEXMF=		${PREFIX}/share/texmf
FILES=		jis-v.tfm jis.tfm jisg-v.tfm jisg.tfm \
		jisgn-v.tfm jisgn.tfm jisn-v.tfm jisn.tfm

do-extract:
	${MKDIR} ${WRKSRC}
	cd ${WRKSRC} && unzip ${DISTDIR}/${DISTNAME}

do-install:
	${MKDIR} ${TEXMF}/fonts/tfm/ptex
	for file in ${FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/"$$file" ${TEXMF}/fonts/tfm/ptex ; \
	done
.if exists(${PREFIX}/share/texmf/ls-R)
	mktexlsr
.endif

.include <bsd.port.mk>
