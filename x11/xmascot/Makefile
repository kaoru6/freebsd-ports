# New ports collection makefile for:	xmascot + leaffi
# Date created:		20 Nov 200
# Whom:			TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	xmascot+lf97
PORTVERSION= 	2.6a
CATEGORIES=	x11
MASTER_SITES=	ftp://cclub.tutcc.tut.ac.jp/pub/xmascot/ \
		http://cclub-flying.dsl.gr.jp/products/xmascot/
DISTNAME=	xmascot${PORTVERSION}

PATCH_SITES=	http://hoshina.denpa.org/
PATCHFILES=	xmascot26a-lf-patch.gz

MAINTAINER=	kaoru@kaisei.org

PATCH_WRKSRC=	${WRKDIR}
DIST_SUBDIR=	xmascot

USE_IMAKE=	yes
MAN1=		xmascot.1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ja/xmascot
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ja/xasahi
.endif
.if !defined(BATCH)
	@ ${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
