# New ports collection makefile for:	txfonts
# Version required:	2.2 patch 1
# Date created:		29 November 2000
# Whom:			KANOU Hiroki <kanou@mil.allnet.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	txfonts
PORTVERSION=	3.1.1
CATEGORIES=	print
MASTER_SITES=	http://www.matsusaka-u.ac.jp/~okumura/texfaq/
#	${MASTER_SITE_TEX_CTAN}/fonts
DISTFILES=	txfonts-3_1_1b.zip
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	kaoru@kaisei.org

USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-oq
NO_BUILD=	yes

TEXMF_DIR=	${PREFIX}/share/texmf
FONTS_DIR=	${TEXMF_DIR}/fonts
PORTDOCDIR=	${PREFIX}/share/doc/txfonts
DOCFILES=	${WRKDIR}/doc/txfontsdoc${PAPERSIZE}.*
# PAPERSIZE=	A4

do-install:
#	${MKDIR} ${FONTS_DIR}
#	for dir in  afm tfm vf ; do \
#		${MKDIR} ${FONTS_DIR}/$$dir/txr ; \
#		${INSTALL_DATA} ${WRKDIR}/$$dir/* ${FONTS_DIR}/$$dir/txr ; done
#	${MKDIR} ${FONTS_DIR}/type1/txr
#	${INSTALL_DATA} ${WRKDIR}/pfb/* ${FONTS_DIR}/type1/txr
#	if [ -x ${PREFIX}/bin/mktexlsr -a -f ${TEXMF_DIR}/ls-R ] ; then mktexlsr ; fi
#	${MKDIR} ${TEXMF_DIR}/tex/latex/txr
#	${INSTALL_DATA} ${WRKDIR}/input/* ${TEXMF_DIR}/tex/latex/txr
#	${MKDIR} ${TEXMF_DIR}/dvips/config
#	${INSTALL_DATA} ${WRKDIR}/dvips/* ${TEXMF_DIR}/dvips/config
#	${INSTALL_DATA} ${WRKDIR}/dvips/* ${TEXMF_DIR}/dvips/config
	cd ${WRKDIR}; ${CP} -Rp dvips fonts tex ${TEXMF_DIR}

NOPORTDOCS=	YES

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PORTDOCDIR}
	${INSTALL_MAN} ${WRKDIR}/00update.txt ${DOCFILES} ${PORTDOCDIR}
.endif

.include <bsd.port.mk>
