# New ports collection makefile for:	changelog2graph
# Date created:		15 Nov 2000
# Whom:			TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	changelog2graph
PORTVERSION=	0.0.20000429
CATEGORIES=	misc
MASTER_SITES=	http://0xcc.net/attic/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	kaoru@kaisei.org
COMMENT=	ChangeLog visualiser

RUN_DEPENDS=	${SITE_PERL}/Chart/PNGgraph.pm:${PORTSDIR}/graphics/p5-Chart-PNGgraph \
		${SITE_PERL}/GD/Graph.pm:${PORTSDIR}/graphics/p5-GD-Graph

NO_BUILD=	yes
USE_PERL5=	yes

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${PORTNAME} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/changelog2graph ${PREFIX}/bin

.include <bsd.port.mk>
