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

#ifndef MP_DEFS_H
#define MP_DEFS_H

// Song 'mode' can be one of the following:
#define MPP_PLAY_LOOP   0
#define MPP_PLAY_ONCE   1
#define MPP_PLAY_JINGLE 2


#ifdef SYS_GBA

// Number of bits used in fractional part of sample reading
#define SAMPFRAC        12

#endif


#define MP_SCHANNELS    4

// Callback parameters

#define MMCB_SONGREQUEST    0x1A // nds9
#define MMCB_SAMPREQUEST    0x1B // nds9
#define MMCB_DELETESONG     0x1C // nds9
#define MMCB_DELETESAMPLE   0x1D // nds9

// #define MPCB_SAMPMEMORY     0x1E // ---
// #define MPCB_SONGMEMORY     0x1F // ---
#define MMCB_BANKMEMORY     0x1E // nds9

#define MPCB_SONGMESSAGE    0x2A // gba/nds7 song playback
#define MPCB_SONGFINISHED   0x2B // gba/nds7

#endif // MP_DEFS_H
