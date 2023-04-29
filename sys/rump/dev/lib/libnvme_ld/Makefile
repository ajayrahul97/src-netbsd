#	$NetBSD: Makefile,v 1.0 2018/01/01 00:00:00 none Exp $
#

RUMPTOP=${TOPRUMP}

.PATH:	${RUMPTOP}/../dev	\
	${RUMPTOP}/../dev/ic

LIB=	rumpdev_nvme_ld
COMMENT=NVMe block device driver

IOCONF=	NVME_LD.ioconf

SRCS=	ld_at_nvme.c
SRCS+=	ld_nvme.c

# XXX: ld.c does not really belong here, but placing it in libdisk
# requires revamping config to be more modular in how CFDRIVER() is
# used.  moving ld up in the component tree later to libdisk won't
# create problems, so just put it here for now.  the excessive
# dependencies of nvme_ld should prevent anyone from want to
# provide ld via this component ...
SRCS+=	ld.c

.include "${RUMPTOP}/Makefile.rump"
.include <bsd.lib.mk>
.include <bsd.klinks.mk>
