# New ports collection makefile for:	asterisk16-sounds-ja
# Date created:		2009-10-09
# Whom:			TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	asterisk16-sounds-ja
PORTVERSION=	1.6
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.voip-info.jp/asterisk/sounds/${PORTVERSION:S|.|_|}/
DISTNAME=	asterisk-sound-jp_${PORTVERSION:S|.||}_pre

MAINTAINER=	kaoru@kaisei.org
COMMENT=	Japanese sound files for Asterisk 1.6

RUN_DEPENDS=	asterisk:${PORTSDIR}/net/asterisk16

NO_BUILD=	yes
ASTERISKSDIR=	${LOCALBASE}/share/asterisk/sounds

do-install:
	@-${MKDIR} ${ASTERISKSDIR}
	@${CP} -pR ${WRKDIR}/ja ${ASTERISKSDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${CP} -pv ${WRKDIR}/ja/README.txt ${DOCSDIR}
.endif

post-install:
	@cd ${WRKDIR} && ${FIND} ./ja -type f -o -type l | ${SED} -e 's,^\.,${ASTERISKSDIR:S|${LOCALBASE}/||},' > ${TMPPLIST}
	@cd ${WRKDIR} && ${FIND} ./ja -type d -depth  | ${SED} -e 's,^\.,@dirrm ${ASTERISKSDIR:S|${LOCALBASE}/||},' >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${ECHO} ${DOCSDIR:S|${LOCALBASE}/||}/README.txt >> ${TMPPLIST}
	@${ECHO} "@dirrm" ${DOCSDIR:S|${LOCALBASE}/||}  >> ${TMPPLIST}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
