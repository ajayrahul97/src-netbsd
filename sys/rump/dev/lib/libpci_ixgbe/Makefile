#	$NetBSD: Makefile,v 1.0 2018/01/01 00:00:00 none Exp $


RUMPTOP=${TOPRUMP}

.PATH:	${RUMPTOP}/../dev/pci
.PATH:	${RUMPTOP}/../dev/pci/ixgbe

LIB=	rumpdev_pci_ixgbe
COMMENT=ixgbe driver

IOCONF= PCI_IXGBE.ioconf
RUMP_COMPONENT=ioconf

SRCS+= ixgbe.c
SRCS+= ixgbe_phy.c
SRCS+= ixgbe_vf.c
SRCS+= ixgbe_mbx.c
SRCS+= ixgbe_osdep.c
SRCS+= if_sriov.c
SRCS+= ixgbe_api.c
SRCS+= if_bypass.c
SRCS+= if_fdir.c
SRCS+= ixgbe_common.c
SRCS+= ixgbe_netbsd.c
SRCS+= ixgbe_82599.c
SRCS+= ixgbe_netmap.c
SRCS+= ixv.c
SRCS+= ix_txrx.c
SRCS+= ixgbe_x550.c
SRCS+= ixgbe_x540.c
SRCS+= ixgbe_82598.c

CPPFLAGS+= -I${RUMPTOP}/librump/rumpkern

.include "${RUMPTOP}/Makefile.rump"
.include <bsd.lib.mk>
.include <bsd.klinks.mk>
