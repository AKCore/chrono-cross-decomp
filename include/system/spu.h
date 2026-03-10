#ifndef _SPU_H
#define _SPU_H

/**
 * Root Counter 2 runs at one-eighth of the PS1 system clock.
 *
 * PS1 CPU clock:         33.8688 MHz
 * RCntCNT2 clock:        33.8688 MHz / 8
 *                      =  4.2336 MHz
 *                      =  4,233,600 ticks/second
 *
 * Sound timer target:    0x44E8
 *                      =  17640 ticks
 *
 * Interrupt rate:        4,233,600 / 17,640
 *                      =  240 Hz
 *
 * So this sets up the sound driver main timer as a 240 Hz periodic interrupt.
 */
#define PSX_CPU_CLOCK_HZ            ( 33868800 )
#define PSX_RCNT2_CLOCK_DIVISOR     ( 8 )
#define PSX_RCNT2_CLOCK_HZ          ( PSX_CPU_CLOCK_HZ / PSX_RCNT2_CLOCK_DIVISOR ) 

#define SOUND_TIMER_TARGET          ( 17640 ) // 0x44E8
#define SOUND_TIMER_RATE_HZ         ( PSX_RCNT2_CLOCK_HZ / SOUND_TIMER_TARGET ) // 240 Hz

#define SPU_DECODE_DATA_START       ( 0x0000 )
#define SPU_DECODE_DATA_SIZE        ( 0x1000 )

#define SPU_IRQ_CLEAR_BLOCK_START   SPU_DECODE_DATA_SIZE
#define SPU_IRQ_CLEAR_BLOCK_SIZE    ( 0x0010 )
#define SPU_IRQ_CLEAR_BLOCK_END     ( SPU_IRQ_CLEAR_BLOCK_START + SPU_IRQ_CLEAR_BLOCK_SIZE )

#define SPU_WAVEFORM_DATA_START     SPU_IRQ_CLEAR_BLOCK_END

#endif // _SPU_H
