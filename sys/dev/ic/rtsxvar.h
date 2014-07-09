/*	$NetBSD: rtsxvar.h,v 1.1 2014/03/19 15:26:41 nonaka Exp $	*/
/*	$OpenBSD: rtsxvar.h,v 1.2 2013/11/06 13:51:02 stsp Exp $	*/

/*
 * Copyright (c) 2006 Uwe Stuehler <uwe@openbsd.org>
 * Copyright (c) 2012 Stefan Sperling <stsp@openbsd.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _RTSXVAR_H_
#define _RTSXVAR_H_

#include <sys/bus.h>
#include <sys/device.h>
#include <sys/pmf.h>
#include <sys/mutex.h>
#include <sys/condvar.h>

/* Number of registers to save for suspend/resume in terms of their ranges. */
#define RTSX_NREG ((0XFDAE - 0XFDA0) + (0xFD69 - 0xFD32) + (0xFE34 - 0xFE20))

struct rtsx_softc {
	device_t	sc_dev;

	device_t	sc_sdmmc;	/* generic SD/MMC device */

	bus_space_tag_t	sc_iot;		/* host register set tag */
	bus_space_handle_t sc_ioh;	/* host register set handle */
	bus_size_t      sc_iosize;
	bus_dma_tag_t	sc_dmat;	/* DMA tag from attachment driver */
	bus_dmamap_t	sc_dmap_cmd;	/* DMA map for command transfer */

	struct kmutex	sc_host_mtx;
	struct kmutex	sc_intr_mtx;
	struct kcondvar sc_intr_cv;

	uint32_t 	sc_intr_status;	/* soft interrupt status */

	uint8_t		sc_regs[RTSX_NREG]; /* host controller state */
	uint32_t	sc_regs4[6];	/* host controller state */

	uint32_t	sc_flags;
#define	RTSX_F_CARD_PRESENT	__BIT(0)
#define	RTSX_F_SDIO_SUPPORT	__BIT(1)
#define	RTSX_F_5209		__BIT(2)
#define	RTSX_F_5229		__BIT(3)
#define	RTSX_F_5229_TYPE_C	__BIT(4)
};

/* Host controller functions called by the attachment driver. */
int	rtsx_attach(struct rtsx_softc *, bus_space_tag_t,
	    bus_space_handle_t, bus_size_t, bus_dma_tag_t, int);
int	rtsx_detach(struct rtsx_softc *, int);
bool	rtsx_suspend(device_t, const pmf_qual_t *);
bool	rtsx_resume(device_t, const pmf_qual_t *);
bool	rtsx_shutdown(device_t, int);
int	rtsx_intr(void *);

#endif	/* _RTSXVAR_H_ */
