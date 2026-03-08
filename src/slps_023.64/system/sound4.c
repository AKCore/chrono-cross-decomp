#include "common.h"
#include "psyq/libspu.h"
#include "system/sound.h"

//----------------------------------------------------------------------------------------------------------------------
void unk_Sound_80055a10()
{
    if( g_Sound_80094FA0.VoicesInUseFlags != 0 )
    {
        SpuSetIRQ( NULL );
        SpuSetIRQCallback( NULL );
        SetVoiceKeyOff( g_Sound_80094FA0.VoicesInUseFlags );
        SetVoiceRepeatAddr( g_Sound_80094FA0.VoiceIndex, 0x1030U );
        SetVoiceRepeatAddr( g_Sound_80094FA0.VoiceIndex + 1, 0x1030U );
        g_Sound_VoiceSchedulerState.ReverbVoiceFlags &= ~g_Sound_80094FA0.VoicesInUseFlags;
        g_Sound_80094FA0.VoicesInUseFlags = 0;
        g_Sound_GlobalFlags.UpdateFlags |= 0x100;
    }
}

//----------------------------------------------------------------------------------------------------------------------
INCLUDE_ASM("asm/slps_023.64/nonmatchings/system/sound4", unk_Sound_80055ab0);

INCLUDE_ASM("asm/slps_023.64/nonmatchings/system/sound4", unk_Sound_80055b40);

INCLUDE_ASM("asm/slps_023.64/nonmatchings/system/sound4", Sound_Cmd_E2_80055cfc);

INCLUDE_ASM("asm/slps_023.64/nonmatchings/system/sound4", Sound_Cmd_E4_SetVolumeStereoPair);

INCLUDE_ASM("asm/slps_023.64/nonmatchings/system/sound4", Sound_Cmd_E5_80055d8c);

INCLUDE_ASM("asm/slps_023.64/nonmatchings/system/sound4", unk_Sound_80055e0c);

INCLUDE_ASM("asm/slps_023.64/nonmatchings/system/sound4", unk_Sound_80055e60);

INCLUDE_ASM("asm/slps_023.64/nonmatchings/system/sound4", unk_Sound_8005600c);

INCLUDE_ASM("asm/slps_023.64/nonmatchings/system/sound4", unk_Sound_800560d4);

INCLUDE_ASM("asm/slps_023.64/nonmatchings/system/sound4", unk_Sound_80056144);

INCLUDE_ASM("asm/slps_023.64/nonmatchings/system/sound4", unk_Sound_800562a0);

INCLUDE_ASM("asm/slps_023.64/nonmatchings/system/sound4", unk_Sound_800562d0);

INCLUDE_ASM("asm/slps_023.64/nonmatchings/system/sound4", Sound_Cmd_E8_80056308);
