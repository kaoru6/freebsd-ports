# New ports collection makefile for:	ezmlm-idx
# Date created:		28 November 1998
# Whom:			Neil Blakey-Milner <nbm@rucus.ru.ac.za>
#
# $FreeBSD: ports/mail/ezmlm-idx/Makefile,v 1.20 2003/04/21 16:14:26 tom Exp $
#

PORTNAME=	ezmlm-idx
PORTVERSION=	0.40
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.ezmlm.org/pub/patches/ \
		ftp://gd.tuwien.ac.at/infosys/mail/qmail/ezmlm-patches/ \
		http://gd.tuwien.ac.at/infosys/mail/qmail/ezmlm-patches/ \
		ftp://ftp.eos.hokudai.ac.jp/pub/mail/qmail/ezmlm-idx/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		ezmlm-${EZMLM_VERSION}${EXTRACT_SUFX}

PATCHFILES=	ezmlm-cgi.patch
PATCH_SITES=	${MASTER_SITES}

MAINTAINER=	tom@FreeBSD.org
COMMENT=	Improved version of the ezmlm-0.53 mailing list management software

# QMAIL_DIR is the directory where qmail is installed
QMAIL_DIR?=	/var/qmail

# LANGUAGE is the ISO code for the language to use in ezmlmrc
LANGUAGE?=	jp

RUN_DEPENDS=	${QMAIL_DIR}/bin/qmail-send:${PORTSDIR}/mail/qmail

# If WITH_MYSQL is defined, build with MySQL extensions
.if defined(WITH_MYSQL)
ALL_TARGET=	mysql it ${LANGUAGE}
LIB_DEPENDS+=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client
EXTRACT_INCLUDE+=	-I${PREFIX}/include/mysql
EXTRACT_LIB+=	-L${PREFIX}/lib/mysql -lmysqlclient -lm
.elif defined(WITH_POSTGRESQL)
ALL_TARGET=	pgsql it ${LANGUAGE}
POSTGRESQL_PORT?=	databases/postgresql7
LIB_DEPENDS+=	pq.3:${PORTSDIR}/${POSTGRESQL_PORT}
EXTRACT_INCLUDE+=	-I${PREFIX}/include/pgsql
EXTRACT_LIB+=	-L${PREFIX}/lib -lpq -lcrypt
.else
ALL_TARGET=	it ${LANGUAGE}
.endif

NO_PACKAGE=	Unsure of djb's license

WRKSRC=		${WRKDIR}/ezmlm-${EZMLM_VERSION}

MAN1=	ezmlm-accept.1 ezmlm-archive.1 ezmlm-cgi.1 ezmlm-check.1 \
	ezmlm-clean.1 ezmlm-cron.1 ezmlm-gate.1 ezmlm-get.1 \
	ezmlm-glconf.1 ezmlm-idx.1 ezmlm-issubn.1 ezmlm-limit.1 \
	ezmlm-list.1 ezmlm-make.1 ezmlm-manage.1 ezmlm-mktab.1 \
	ezmlm-moderate.1 ezmlm-reject.1 ezmlm-request.1 \
	ezmlm-return.1 ezmlm-send.1 ezmlm-split.1 ezmlm-store.1 \
	ezmlm-sub.1 ezmlm-test.1 ezmlm-tstdig.1 ezmlm-unsub.1 \
	ezmlm-warn.1 ezmlm-weed.1
MAN5=	ezmlm.5 ezmlmglrc.5 ezmlmrc.5 ezmlmsubrc.5

DIFF_MSG=	Cannot Make and Install with different PREFIX or QMAIL_DIR

MY_PROGRAMS=	archive cgi clean cron gate get idx issubn limit \
		list make manage moderate request reject return \
		send split store sub tstdig unsub warn weed

MY_SCRIPTS=	accept check glconf mktab test

MY_CONFIG=	ezmlmglrc ezmlmrc ezmlmsubrc

EZMLM_VERSION=	0.53

pre-patch:
	@${MV} -f ${WRKDIR}/ezmlm-idx-${PORTVERSION}/* ${WRKSRC}
	@cd ${WRKSRC} && ${PATCH} ${PATCH_ARGS} < idx.patch

post-patch:
	@${ECHO_CMD} ${PREFIX}/bin > ${WRKSRC}/conf-bin
	@${ECHO_CMD} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	@${ECHO_CMD} ${CC} -s > ${WRKSRC}/conf-ld
.if defined(WITH_MYSQL)
	@${ECHO_CMD} ${EXTRACT_INCLUDE} > ${WRKSRC}/sub_mysql/conf-sqlcc
	@${ECHO_CMD} ${EXTRACT_LIB} > ${WRKSRC}/sub_mysql/conf-sqlld
.elif defined(WITH_POSTGRESQL)
	@${ECHO_CMD} ${EXTRACT_INCLUDE} > ${WRKSRC}/sub_pgsql/conf-sqlcc
	@${ECHO_CMD} ${EXTRACT_LIB} > ${WRKSRC}/sub_pgsql/conf-sqlld
.endif
	@${ECHO_CMD} ${PREFIX}/man > ${WRKSRC}/conf-man
	@${ECHO_CMD} ${QMAIL_DIR} > ${WRKSRC}/conf-qmail
	@${ECHO_CMD} ${PREFIX} > ${WRKDIR}/.PPREFIX
	@${ECHO_CMD} ${QMAIL_DIR} >> ${WRKDIR}/.PPREFIX
	@${ECHO_CMD} ${NOPORTDOCS} ${WITH_MYSQL} ${WITH_POSTGRESQL}>> ${WRKDIR}/.PPREFIX
	@${MV} ${WRKSRC}/idx.h ${WRKSRC}/idx.h.orig
	@${SED} -e 's#/etc/ezmlm/#'${PREFIX}'/etc/ezmlm/#' \
		< ${WRKSRC}/idx.h.orig > ${WRKSRC}/idx.h

pre-install:
	@${ECHO_CMD} ${PREFIX} > ${WRKDIR}/.IPREFIX
	@${ECHO_CMD} ${QMAIL_DIR} >> ${WRKDIR}/.IPREFIX
	@${ECHO_CMD} ${NOPORTDOCS} ${WITH_MYSQL} ${WITH_POSTGRESQL}>> ${WRKDIR}/.IPREFIX
	@diff ${WRKDIR}/.[PI]PREFIX || (${ECHO} ${DIFF_MSG} && exit 1)

do-install:
.for file in ${MY_PROGRAMS}
	@${INSTALL_PROGRAM} ${WRKSRC}/ezmlm-${file} ${PREFIX}/bin
.endfor
.for file in ${MY_SCRIPTS}
	@${INSTALL_SCRIPT} ${WRKSRC}/ezmlm-${file} ${PREFIX}/bin
.endfor
	@${MKDIR} ${PREFIX}/etc/ezmlm
.for file in ${MY_CONFIG}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/etc/ezmlm/${file}.sample
.endfor
.for file in ${MAN1}
	@${INSTALL_MAN} ${WRKSRC}/${file} ${PREFIX}/man/man1
.endfor
.for file in ${MAN5}
	@${INSTALL_MAN} ${WRKSRC}/${file} ${PREFIX}/man/man5
.endfor
.if !defined(NOPORTDOCS)
	@${ECHO} "===>  Copying documents to ${PREFIX}/share/doc/ezmlm-idx"
	@${MKDIR} ${PREFIX}/share/doc/ezmlm-idx
.for file in CHANGES.idx DOWNGRADE.idx FAQ.idx INSTALL.idx README.idx UPGRADE.idx
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/ezmlm-idx
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
