/****************************************************************************
 *                                                          __              *
 *                ____ ___  ____ __  ______ ___  ____  ____/ /              *
 *               / __ `__ \/ __ `/ |/ / __ `__ \/ __ \/ __  /               *
 *              / / / / / / /_/ />  </ / / / / / /_/ / /_/ /                *
 *             /_/ /_/ /_/\__,_/_/|_/_/ /_/ /_/\____/\__,_/                 *
 *                                                                          *
 *      Copyright (c) 2021, Antonio Niño Díaz (antonio_nd@outlook.com)      *
 *         Copyright (c) 2008, Mukunda Johnson (mukunda@maxmod.org)         *
 *                                                                          *
 * Permission to use, copy, modify, and/or distribute this software for any *
 * purpose with or without fee is hereby granted, provided that the above   *
 * copyright notice and this permission notice appear in all copies.        *
 *                                                                          *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES *
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF         *
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  *
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES   *
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN    *
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  *
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.           *
 ****************************************************************************/

#ifndef MM_MIXER_GBA_H
#define MM_MIXER_GBA_H

#include "mp_mixer_gba.h"

#define REG_SOUNDCNT_L  *(volatile uint16_t *)0x4000080
#define REG_SOUNDCNT_H  *(volatile uint16_t *)0x4000082
#define REG_SOUNDCNT_X  *(volatile uint16_t *)0x4000084

#define REG_TM0CNT      *(volatile uint32_t *)0x4000100

#define REG_DMA1SAD     *(volatile uint32_t *)0x40000BC
#define REG_DMA1DAD     *(volatile uint32_t *)0x40000C0
#define REG_DMA1CNT     *(volatile uint32_t *)0x40000C4
#define REG_DMA1CNT_H   *(volatile uint16_t *)0x40000C6

#define REG_DMA2SAD     *(volatile uint32_t *)0x40000C8
#define REG_DMA2DAD     *(volatile uint32_t *)0x40000CC
#define REG_DMA2CNT     *(volatile uint32_t *)0x40000D0
#define REG_DMA2CNT_H   *(volatile uint16_t *)0x40000D2

#define REG_DMA3SAD     *(volatile uint32_t *)0x40000D4
#define REG_DMA3DAD     *(volatile uint32_t *)0x40000D8
#define REG_DMA3CNT     *(volatile uint32_t *)0x40000DC

#define REG_SGFIFOA     (volatile uint32_t *)0x40000A0
#define REG_SGFIFOB     (volatile uint32_t *)0x40000A4
#define REG_VCOUNT      *(volatile uint16_t *)0x4000006

extern mm_word mm_mixlen;

extern mm_word mm_mixbuffer;
extern mm_mixer_channel *mm_mixchannels;
extern mm_word mm_wavebuffer;
extern mm_word mm_mixlen;
extern mm_word mm_mixch_count;
extern mm_word mm_mixch_end;
extern mm_word mm_ratescale;
extern mm_word mm_timerfreq;

extern mm_word mm_bpmdv;


void mmMixerInit(mm_gba_system* setup);
void mmMixerSetRead(int channel, mm_word value);

#endif // MM_MIXER_GBA_H
