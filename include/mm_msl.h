/****************************************************************************
 *                                                          __              *
 *                ____ ___  ____ __  ______ ___  ____  ____/ /              *
 *               / __ `__ \/ __ `/ |/ / __ `__ \/ __ \/ __  /               *
 *              / / / / / / /_/ />  </ / / / / / /_/ / /_/ /                *
 *             /_/ /_/ /_/\__,_/_/|_/_/ /_/ /_/\____/\__,_/                 *
 *                                                                          *
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

// MAXMOD SOUNDBANK FORMAT DEFINITIONS

#ifndef MM_MSL_H
#define MM_MSL_H

#include "mm_types.h"

typedef struct tmslhead
{
	mm_hword	sampleCount;
	mm_hword	moduleCount;
	mm_word		reserved[2];
	mm_addr		sampleTable[]; // [MSL_NSAMPS];
	//mm_addr	moduleTable[MSL_NSONGS];
} msl_head;

// sample structure......................................
#define C_SAMPLE_LEN        0
#define C_SAMPLE_LOOP       4
#define C_SAMPLE_POINT      12
#define C_SAMPLE_DATA       16

#define C_SAMPLEN_LSTART    0
#define C_SAMPLEN_LEN       4
#define C_SAMPLEN_FORMAT    8
#define C_SAMPLEN_REP       9
#define C_SAMPLEN_POINT     12
#define C_SAMPLEN_DATA      16

#define C_SAMPLEC_DFREQ     10

#endif

