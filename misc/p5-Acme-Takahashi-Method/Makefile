# New ports collection makefile for:	p5-Acme-Takahashi-Method
# Date created:		14 June 2005
# Whom:	    		TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	Acme-Takahashi-Method
PORTVERSION=	0.01
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Acme
PKGNAMEPREFIX=	p5-

MAINTAINER=	kaoru@kaisei.org
COMMENT=	Slides accordingly to the Takahashi Method

PERL_CONFIGURE=	yes

MAN3=		Acme::Takahashi::Method.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	@${PERL} -pi -e 's/^our (\S+)/use vars qw($$1); $$1/' \
		${WRKSRC}/lib/Acme/Takahashi/Method.pm
.endif

.include <bsd.port.post.mk>
