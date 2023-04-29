#	$NetBSD: Makefile,v 1.0 2018/01/01 00:00:00 none Exp $


RUMPTOP=${TOPRUMP}

.PATH:	${RUMPTOP}/../dev/pci ${RUMPTOP}/../dev/ic \
		${RUMPTOP}/../dev

LIB=	rumpdev_pci_nvme
COMMENT=NVMe driver

IOCONF= PCI_NVME.ioconf
RUMP_COMPONENT=ioconf

SRCS+= nvme_pci.c
SRCS+= nvme.c

CPPFLAGS+= -I${RUMPTOP}/librump/rumpkern

.include "${RUMPTOP}/Makefile.rump"
.include <bsd.lib.mk>
.include <bsd.klinks.mk>
