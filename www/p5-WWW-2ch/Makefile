# New ports collection makefile for:	p5-WWW-2ch
# Date created:		2006-02-28
# Whom:			TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	WWW-2ch
PORTVERSION=	0.04
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	WWW
PKGNAMEPREFIX=	p5-

MAINTAINER=	kaoru@kaisei.org
COMMENT=	"Perl module for scraping of a popular bbs of Japan"

RUN_DEPENDS=	${SITE_PERL}/LWP/UserAgent.pm:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN3=		WWW::2ch.3	\
	WWW::2ch::Plugin::Base.3	\
	WWW::2ch::Res.3		\
	WWW::2ch::Subject.3	\
	WWW::2ch::Dat.3		\
	WWW::2ch::Plugin::Jbbs.3

.include <bsd.port.mk>
