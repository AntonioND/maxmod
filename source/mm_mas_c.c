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

#include "maxmod.h"

#include "mm_mas.h"
#include "mp_mas_structs.h"

#if defined(SYS_GBA)
#include "mm_mixer_gba.h"
#elif defined(SYS_NDS)
#include "mm_mixer_ds.h"
#include "mm_mixer_super.h"
#endif

// Suspend main module and associated channels.
void mpp_suspend(void)
{
    mm_active_channel *act_ch = &mm_achannels[0];

#ifdef SYS_NDS
    mm_mixer_channel *mix_ch = &mm_mix_channels[0];
#endif
#ifdef SYS_GBA
    mm_mixer_channel *mix_ch = &mm_mixchannels[0];
#endif

    for (mm_word count = mm_num_ach; count != 0; count--, act_ch++, mix_ch++)
    {
        if ((act_ch->flags >> 6) != 0)
            continue;

#ifdef SYS_GBA
        mix_ch->freq = 0;
#else
        mix_ch->freq = 0;
        mix_ch->vol = 0;
#endif
    }
}

// Pause module playback.
void mmPause(void)
{
    if (mmLayerMain.valid == 0)
        return;

    mmLayerMain.isplaying = 0;

    mpp_suspend();
}

// Resume module playback.
void mmResume(void)
{
    if (mmLayerMain.valid == 0)
        return;

    mmLayerMain.isplaying = 1;
}

// Returns true if module is playing.
mm_bool mmActive(void)
{
    return mmLayerMain.isplaying;
}

// Returns true if a jingle is playing.
mm_bool mmActiveSub(void)
{
    return mmLayerSub.isplaying;
}

// Set master module volume.
//
// volume : 0->1024
void mmSetModuleVolume(mm_word volume)
{
    // Clamp volume 0->1024
    if (volume > 1024)
        volume = 1024;

    mmLayerMain.volume = volume;
}

// Set master jingle volume.
//
// volume : 0->1024
void mmSetJingleVolume(mm_word volume)
{
    // Clamp volume 0->1024
    if (volume > 1024)
        volume = 1024;

    mmLayerSub.volume = volume; // mpp_layerB
}
