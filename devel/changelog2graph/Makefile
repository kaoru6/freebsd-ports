# New ports collection makefile for:	changelog2graph
# Date created:		20 Nov 2000
# Whom:			TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	changelog2graph
PORTVERSION=	1.0
CATEGORIES=	misc
MASTER_SITES=	http://namazu.org/~satoru/attic/
DISTFILES=	changelog2graph

MAINTAINER=	kaoru@kaisei.org

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Chart/PNGgraph.pm:${PORTSDIR}/graphics/p5-Chart-PNGgraph

EXTRACT_ONLY=
NO_BUILD=	yes
USE_PERL5=	yes

do-extract:
	${MKDIR} ${WRKSRC}
	cp ${DISTDIR}/${PORTNAME} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/changelog2graph ${PREFIX}/bin

.include <bsd.port.mk>
