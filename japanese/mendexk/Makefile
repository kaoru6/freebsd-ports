# New ports collection makefile for:    mendexk-euc
# Date created:         1 Dec 1997
# Whom:                 Makoto WATANABE <watanabe@zlab.phys.nagoya-u.ac.jp>
#
# $FreeBSD: ports/japanese/mendexk-euc/Makefile,v 1.6 2000/04/11 14:15:03 knu Exp $
#

PORTNAME=	mendexk
PORTVERSION=	2.4f
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.ascii.co.jp/pub/TeX/ascii-ptex/mendex/
PKGNAMEPREFIX=	ja-
PKGNAMESUFFIX=	-euc
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	kaoru@kaisei.org

#DEPENDS=	${PORTSDIR}/print/teTeX:extract

USE_GMAKE=	yes
DIST_SUBDIR=	ptex

MANLANG=	ja
MAN1=		mendex.1

KPATHSEA_PARENT=	${PORTSDIR}/print/teTeX/work/teTeX-1.0/texk

pre-configure:
	@( cd ${PORTSDIR}/print/teTeX ; make extract )
	@( cd ${KPATHSEA_PARENT}/kpathsea ; \
	    ./configure --prefix=${PREFIX} )

do-build:
	@( cd ${KPATHSEA_PARENT}/kpathsea ; ${GMAKE} )
	@( cd ${WRKSRC} ; ${MAKE} kpathsea_parent=${KPATHSEA_PARENT} )

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/mendex ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/man/${MANLANG}/man1
	@${INSTALL_MAN} ${WRKSRC}/mendex.1 ${PREFIX}/man/${MANLANG}/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/mendex
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/mendex
.endif

.include <bsd.port.mk>
