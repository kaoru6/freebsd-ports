# New ports collection makefile for:	Nemacs
# Date created:				14 Nov 2000
# Whom:					TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	platex-jsclasses
PORTVERSION=	2000.11.22
CATEGORIES=	japanese print
MASTER_SITES=	http://www.matsusaka-u.ac.jp/~okumura/jsclasses/
DISTNAME=	jsclasses
EXTRACT_SUFX=	.lzh

MAINTAINER=	kaoru@kaisei.org

NO_BUILD=	yes
BUILD_DEPENDS=	lha:${PORTSDIR}/archivers/lha/ \
		qkc:${PORTSDIR}/japanese/qkc
#		platex:${PORTSDIR}/japanese/platex-euc

JSFILES=	jsarticle.cls jsbook.cls jsclasses.dtx jsclasses.ins jspf.cls \
		morisawa.dtx morisawa.ins morisawa.sty \
		okumacro.dtx okumacro.ins okumacro.sty \
		okuverb.dtx okuverb.ins okuverb.sty

JSDIR=		${PREFIX}/share/texmf/ptex/platex/js

do-extract:
	${MKDIR} ${WRKSRC}
	cd ${WRKSRC} && lha x ${DISTDIR}/${DISTNAME}

do-patch:
	cd ${WRKSRC} && qkc -ju *

do-install:
	${MKDIR} ${JSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${JSFILES} ${JSDIR}
	mktexlsr

.include <bsd.port.mk>
