//*****************************************************************************
// A fun little song by joe at 120BPM to match the 1MHz clock
//*****************************************************************************

/*
 * ======== Standard MSP430 includes ========
 */
#include <msp430.h>

/*
 * ======== Grace related includes ========
 */
#include <ti/mcu/msp430/Grace.h>

/*
 *  ======== main ========
 */

#include <C:\Users\Joseph\workspace_v5_5\GraceTest\noteTable.h>

void note(unsigned int period_cycles, unsigned int duty_cycle, unsigned int time) {
	/* 1,000,000 cycles is a half note ----------- time = 16
	 * 500,000   cycles is a quarter note -------- time = 8
	 * 250,000   cycles is a eighth note --------- time = 4
	 * 125,000   cycles is a sixteenth note ------ time = 2
	 * 62,500    cycles is a thirty-second note -- time = 1
	 * == Duty Cycles ==
	 * 50%   = 2
	 * 25%   = 4
	 * 12.5% = 8
	 * =================                                  */
	if (period_cycles != 0) {
		TACTL |= TACLR;						 // Clear the timer's TAR/Mode/Divider
		TACTL |= MC_3 + ID_0;				 // Set the timer to up mode and divider to 1
		TACCR0 = period_cycles;    			 // Set note
		TACCR1 = period_cycles/duty_cycle;   // and set Duty Cycle
	}
	int i;
	for(i=time; i>0; i--) {
		__delay_cycles(62500);
	}
	TACTL &= ~(MC1 + MC0); // Stop the timer (and the note)
}

void intro(void) {
	note(C4,	2, 2);
	note(DS4,	2, 2);
	note(G4,	2, 2);
	note(C5,	2, 2);
	note(G4,	2, 2);
	note(DS4,	2, 2);

	note(C4,	8, 2);
	note(DS4,	8, 2);
	note(G4,	8, 2);
	note(C5,	8, 2);
	note(G4,	8, 2);
	note(DS4,	8, 2);

	note(C4,	2, 2);
	note(DS4,	2, 2);
	note(G4,	2, 2);
	note(AS4,	2, 2);
	note(G4,	2, 2);
	note(DS4,	2, 2);

	note(C4,	8, 2);
	note(DS4,	8, 2);
	note(G4,	8, 2);
	note(AS4,	8, 2);
	note(G4,	8, 2);
	note(DS4,	8, 2);

	note(C4,	2, 2);
	note(DS4,	2, 2);
	note(F4,	2, 2);
	note(A4,	2, 2);
	note(F4,	2, 2);
	note(A4,	2, 2);

	note(C5,	2, 2);
	note(A4,	2, 2);
	note(C5,	2, 2);
	note(DS5,	2, 2);
	note(D5,	2, 2);
	note(DS5,	2, 2);

	note(F5,	4, 1);
	note(REST,	2, 1);
	note(F5,	2, 1);
	note(REST,	2, 1);
	note(F5,	4, 1);
	note(REST,	2, 1);
	note(F5,	2, 2);

	note(DS5,	2, 2);
	note(C5,	2, 2);
	note(DS5,	2, 4);

	note(F5,	2, 2);
	note(D5,	2, 2);
	note(C5,	2, 2);
	note(AS4,	2, 2);

}

void verse(void) {
	note(GS5,	8, 4);
	note(GS5,	8, 2);

	note(F5,	8, 4);
	note(F5,	8, 2);

	note(GS5,	8, 2);
	note(G5,	8, 2);
	note(F5,	8, 2);
	note(REST,	8, 2);
	note(DS5,	8, 2);
	note(F5,	8, 2);

	note(G5,	8, 2);
	note(FS5,	8, 2);
	note(G5,	8, 2);
	note(DS5,	8, 2);
	note(D5,	8, 2);
	note(DS5,	8, 2);

	note(C5,	8, 4);
	note(G4,	8, 4);
	note(C5,	8, 4);
	note(B4,	8, 2);
	note(REST,	8, 2);
	note(D5,	8, 2);
	note(REST,	8, 2);
	note(F5,	8, 2);
	note(REST,	8, 2);
	note(GS5,	8, 2);
	note(REST,	8, 2);
	note(F5,	8, 2);
	note(REST,	8, 2);
	note(GS5,	8, 2);
	note(REST,	8, 2);
	note(C6,	8, 4);
	note(C6,	8, 2);

	note(G5,	8, 1);
	note(C6,	8, 1);
	note(D6,	8, 1);
	note(G5,	8, 1);
	note(C6,	8, 1);
	note(D6,	8, 1);

	note(G5,	8, 1);
	note(B5,	8, 1);
	note(D6,	8, 1);
	note(G5,	8, 1);
	note(B5,	8, 1);
	note(D6,	8, 1);

	note(REST,	1, 4);
	note(REST,	1, 2);

}



int main(void)
{
    Grace_init();                   /* Run Grace-generated initialization */
    TACCR0 = 49999;       // Approx 2hz (mostly for testing) [ready tone I guess you could call it]
    TACTL |= MC_3 + ID_0; // Start timer in up mode with the divisor at 1 (fastest)
    while (1) {

    /*	if (!(P1IN & BIT3)) {
    		P1OUT ^= BIT0;
    		__delay_cycles(100000);
    	} else if (P1IN != BIT3) {
    		P1OUT = 0x0000;
    	}	*/

    	if (!(P1IN & BIT3)) {
    		// note(note, duty, length);
    		intro();
    		intro();
    		verse();

    	}

    }



}






