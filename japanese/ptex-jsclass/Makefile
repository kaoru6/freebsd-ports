# New ports collection makefile for:	pTeX js class files
# Date created:		14 Nov 2000
# Whom:			TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	ptex-jsclasses
PORTVERSION=	2001.02.26
CATEGORIES=	japanese print
MASTER_SITES=	http://www.matsusaka-u.ac.jp/~okumura/jsclasses/
DISTNAME=	jsclasses
EXTRACT_SUFX=	.lzh

MAINTAINER=	kaoru@kaisei.org

BUILD_DEPENDS=	lha:${PORTSDIR}/archivers/lha/ \
		qkc:${PORTSDIR}/japanese/qkc
#		platex:${PORTSDIR}/japanese/platex-euc

NO_BUILD=	yes
DIST_SUBDIR=	ptex

JSFILES=	jsarticle.cls jsbook.cls jsclasses.dtx jsclasses.ins jspf.cls \
		morisawa.dtx morisawa.ins morisawa.sty \
		okumacro.dtx okumacro.ins okumacro.sty \
		okuverb.dtx okuverb.ins okuverb.sty

JSDIR=		${PREFIX}/share/texmf/ptex/platex/js

do-extract:
	${MKDIR} ${WRKSRC}
	cd ${WRKSRC} && lha x ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}.lzh

do-patch:
	cd ${WRKSRC} && qkc -ju *

do-install:
	${MKDIR} ${JSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${JSFILES} ${JSDIR}
.if exists(${PREFIX}/share/texmf/ls-R)
	mktexlsr
.endif

.include <bsd.port.mk>
