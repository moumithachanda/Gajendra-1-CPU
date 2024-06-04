/*++++++++++++++++++++++++++++++++++++++++++
+++	GAJENDRA-1 CONTROL ROM WORDS	+++++
+++++++++++++++++++++++++++++++++++++++++++*/

#include <stdio.h>

int main(void){
	unsigned int ZERO_F = 15;
	unsigned int PC_INC 	= 14;
	unsigned int PC_OUT	= 13;
	unsigned int PC_LOAD	= 12;
	unsigned int MEM_IN	= 11;
	unsigned int MEM_OUT	= 10;
	unsigned int IR_IN	= 9;
	unsigned int IR_OUT	= 8;
	unsigned int MAR_IN	= 7;
	unsigned int REGA_IN	= 6;
	unsigned int REGA_OUT	= 5;
	unsigned int REGB_IN	= 4;
	unsigned int REGB_OUT	= 3;
	unsigned int REGC_IN	= 2;
	unsigned int REGC_OUT	= 1;
	unsigned int ALU_OUT	= 0;
	
	int control_words[] = {
		1<<PC_OUT|1<<MAR_IN,	1<<PC_INC|1<<MEM_OUT|1<<IR_IN,  0,			0,		       0,		0,0,0,	//NOP 0000
		1<<PC_OUT|1<<MAR_IN,	1<<PC_INC|1<<MEM_OUT|1<<IR_IN,  1<<IR_OUT|1<<MAR_IN, 1<<MEM_OUT|1<<REGA_IN, 0,		0,0,0,	//LDA 0001
		1<<PC_OUT|1<<MAR_IN,	1<<PC_INC|1<<MEM_OUT|1<<IR_IN,  1<<IR_OUT|1<<MAR_IN, 1<<MEM_IN|1<<REGA_OUT, 0,		0,0,0,	//STA 0010
		1<<PC_OUT|1<<MAR_IN,	1<<PC_INC|1<<MEM_OUT|1<<IR_IN,  1<<IR_OUT|1<<MAR_IN, 1<<MEM_OUT|1<<REGB_IN, 1<<ALU_OUT|1<<REGA_IN,	0,0,0,	//ADD 0011
		1<<PC_OUT|1<<MAR_IN,	1<<PC_INC|1<<MEM_OUT|1<<IR_IN,  1<<IR_OUT|1<<MAR_IN, 1<<MEM_OUT|1<<REGB_IN, 1<<ALU_OUT|1<<REGA_IN,	0,0,0,	//SUB 0100
		1<<PC_OUT|1<<MAR_IN,	1<<PC_INC|1<<MEM_OUT|1<<IR_IN,  1<<IR_OUT|1<<REGA_IN,0,0,0,0,0,   //LDI 0101
		1<<PC_OUT|1<<MAR_IN,	1<<PC_INC|1<<MEM_OUT|1<<IR_IN,  1<<PC_LOAD|1<<IR_OUT,0,0,0,0,0,    //JMP 0110
		1<<PC_OUT|1<<MAR_IN,	1<<PC_INC|1<<MEM_OUT|1<<IR_IN,  1<<REGA_OUT|1<<REGB_IN, 1<<REGC_OUT|1<<REGA_IN , 1<<REGB_OUT|1<<REGC_IN,0,0,0,  //SWAP 0111
		1<<PC_OUT|1<<MAR_IN,	1<<PC_INC|1<<MEM_OUT|1<<IR_IN,  1<<PC_LOAD|1<<IR_OUT,0,0,0,0,0,                   //JNZ 1000
		1<<PC_OUT|1<<MAR_IN,	1<<PC_INC|1<<MEM_OUT|1<<IR_IN,  1<<REGA_OUT|1<<REGC_IN , 0,0,0,0,0,              //MOVAC  1001
		1<<PC_OUT|1<<MAR_IN,	1<<PC_INC|1<<MEM_OUT|1<<IR_IN,  1<<REGB_OUT|1<<REGA_IN , 0,0,0,0,0,              //MOVBA  1010
		1<<PC_OUT|1<<MAR_IN,	1<<PC_INC|1<<MEM_OUT|1<<IR_IN,  1<<REGC_OUT|1<<REGB_IN , 0,0,0,0,0,              //MOVCB  1011
		1<<PC_OUT|1<<MAR_IN,	1<<PC_INC|1<<MEM_OUT|1<<IR_IN,  1<<REGA_OUT|1<<REGB_IN , 0,0,0,0,0,              //MOVAB  1100
		1<<PC_OUT|1<<MAR_IN,	1<<PC_INC|1<<MEM_OUT|1<<IR_IN,  1<<REGC_OUT|1<<REGA_IN , 0,0,0,0,0,              //MOVCA  1101
		1<<PC_OUT|1<<MAR_IN,	1<<PC_INC|1<<MEM_OUT|1<<IR_IN,  1<<REGB_OUT|1<<REGC_IN , 0,0,0,0,0,              //MOVBC  1110
		1<<PC_OUT|1<<MAR_IN,	1<<PC_INC|1<<MEM_OUT|1<<IR_IN,  1<<ZERO_F    ,0,0,0,0,0                          //HLT    1111
	};

	int INST = 0;
	int TSTATE = 0;
	
	for(INST=0; INST<16; INST++) {
		for(TSTATE=0; TSTATE<8; TSTATE++) { 	
			printf("0x%04X,", control_words[INST*8 + TSTATE]);
		}
		printf("\n");
	}
	
	return 0;
}
