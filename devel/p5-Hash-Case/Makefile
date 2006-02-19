# New ports collection makefile for:	p5-Hash-Case
# Date created:		2006-02-18
# Whom:			TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	Hash-Case
PORTVERSION=	1.003
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Hash
PKGNAMEPREFIX=	p5-

MAINTAINER=	kaoru@kaisei.org
COMMENT=	"base class for hashes with key-casing requirements"

PERL_CONFIGURE=	yes

MAN3=		Hash::Case.3 \
	Hash::Case::Lower.3 \
	Hash::Case::Preserve.3 \
	Hash::Case::Upper.3

do-patch:
	${RM} ${WRKSRC}/lib/Hash/Makefile.PL

.include <bsd.port.mk>
