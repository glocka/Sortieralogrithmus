                                                                        ;#include <stdio.h>
                                                                        ;int R0;
                                                                        ;int R1;
                                                                        ;int R2; //counter
                                                                        ;int R3; //i
                                                                        ;int R4; //temp2
                                                                        ;int R5; //temp
                                                                        ;int R6; //diff2
                                                                        ;int R7; //diff3
                                                                        ;int R8; //diff4
                                                                        ;int* R9; // Pointerstart
                                                                        ;int* RA; //pointer2
                                                                        ;int* RB; //Pointer
                                                                        ;int RC; //j
                                                                        ;int RD; //diff1

                                                                        ;int speicher[20];

                                                                          
                                                                          
                                                                        ;int main()
    LDA R1 1                                                            ;{
    LDA R2 0                                                            ;R2 = 0;
    LDA R3 0
    LDA R9 speicher                                                     ;R9 = speicher;
L1  ADD RB R9 R2                                                        ;RB = R9 + R2;
    LD R5 0xFF                                                          ;scanf ("%d",RB);
    STI R5 RB
    BZ R5 L7                                                           ;if (*RB == 0 )
                                                                        ;{
                                                                        ; goto L7;
                                                                        ;}
    LDI R5 RB
    BP R5 L3                                                            ;if (R5 > 0)
                                                                        ;{
                                                                        ;  goto L3;
                                                                        ;}
    ADD RF R5 R1                                                        ;R5 = *RB;
                                                                        ;RF = R5 +1
    BP RF L3                                                            ;if (RF == 0 )
                                                                        ;{
    ST R0 0xFF                                                          ;printf("0| ");
    LDA R3 0                                                            ;  R3 = 0;
      
L2  SUB RD R2 R3                                                        ;RD = R2-R3;
    BZ RD L1                                                            ;if (RD == 0)
                                                                        ;{
                                                                        ; printf("\n");
                                                                        ;goto L1;
                                                                        ;}
    ADD RB R9 R3                                                        ;RB = R9 + R3;
    LDI RE RB
    ST RE 0xFF                                                          ;printf("%d| ", *RB);
    ADD R3 R3 R1                                                        ;R3 = R3 +1;
    BZ R0 L2                                                            ;goto L2;
                                                                        ;}

    LDA R3 R1                                                           ;R3 = 1;
    
L3  SUB R6 R2 R3                                                        ; R6 = R2 - R3 ;
    ADD R6 R6 R1                                                        ; R6 = R6 +1;
    BZ R6 L6                                                            ;if(R6 == 0)
                                                                        ;{
                                                                        ;  goto L6;
                                                                        ;}
    ADD RB R9 R3                                                        ;RB = R9 + R3;
    STI R5 RB                                                           ;R5 = *RB;
    SUB RC R3 R1                                                        ;RC = R3 - 1;
    
L4  ADD R8 RC R1                                                        ;R8 = RC + 1;
    BZ R8 L5                                                            ;if (R8 == 0)
                                                                        ;{
                                                                        ;  goto L5;
                                                                        ;}
    ADD RB R9 RC                                                        ;RB = R9 + RC;
    LDI R7 RB
    SUB R7 R5 R7                                                        ;  R7 = R5 - *RB;
    BP R7 L5                                                            ;if (R7 > 0)
                                                                        ;{
                                                                        ;  goto L5;
                                                                        ;}
    ADD R4 RC R1                                                        ;R4 = RC+1;
    ADD RB R9 R4                                                        ;RB = R9 + R4;
    ADD RA R9 RC                                                        ;RA = R9 + RC;
    LDI RD RA                                                           ; RD = * RA
    STI RD RB                                                           ;*RB = Rd;
    SUB RC RC R1                                                        ;RC = RC - 1;
    BZ R0 L4                                                            ;  goto L4;
        
L5  ADD R4 RC R1                                                        ;R4 = RC+1;
    ADD RB R9 R4                                                        ;RB = R9 + R4;
    STI R5 RB                                                           ;*RB  = R5;
    ADD R3 R3 R1                                                        ;R3 = R3 +1;
    BZ R0 L3                                                            ;goto L3;
      
L6  ADD R2 R2 R1                                                        ;  R2 = R2 + 1;
    BZ R0 L1                                                            ;goto L1;
L7  HLT                                                                        ;}
speicher DUP 20
