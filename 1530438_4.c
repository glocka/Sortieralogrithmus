//Die Variabelnamen wurde in Registernahmen der Toy CPU umgewandelt
//R0 und R1 wurden für die Werte 0 (Standard in der Toy CPU) und 1 reseviert
//R2 - RD wurden für die bestehenden Variablen genutzt. Umschreibung siehe bei der Initialisierung.
// Weiters wurden anpassungen durchgeführt um c direkt in asm übersetzen zu können. 

#include <stdio.h>
int R0;
int R1;
int R2; //counter
int R3; //i
int R4; //temp2
int R5; //temp
int R6; //diff2
int R7; //diff3
int R8; //diff4
int* R9; // Pointerstart
int* RA; //pointer2
int* RB; //Pointer
int RC; //j
int RD; //diff1
int RE;
int RF;

int speicher[20];

  
  
int main()
{
  R2 = 0;
  R9 = speicher;
L1:
    RB = R9 + R2;
    scanf ("%x",RB);
    
    if (*RB == 0 )
    {
      goto L7;
    }
    R5 = *RB;
    if (R5 > 0 && R5 < 65535)
    {
      goto L3;
    }
    
    RF = R5 + 1;
    if (RF == 65536 )
    {
      printf("%04x\n",0);
      R3 = 0;
      
L2:
      RD = R2-R3;
      if (RD == 0)
      {
        goto L1;
      }
      RB = R9 + R3;
      RE = *RB;
      printf("%04x\n", RE);
      R3 = R3 +1;
      goto L2;
    }

    R3 = 1;
    
L3:
    R6 = R2 - R3 ;
    R6 = R6 +1;
    if(R6 == 0)
    {
      goto L6;
    }
    RB = R9 + R3;
    R5 = *RB;
    RC = R3 - 1;
    
L4:
    R8 = RC + 1;
    if (R8 == 0)
    {
      goto L5;
    }
    RB = R9 + RC;
    R7 = *RB;
    R7 = R5 - R7;
      if (R7 > 0)
      {
        goto L5;
      }
    R4 = RC+1;
    RB = R9 + R4;
    RA = R9 + RC;
    RD = *RA;
    *RB = RD;
    RC = RC - 1;
    goto L4;
        
L5:
    R4 = RC+1;
    RB = R9 + R4;
    *RB  = R5;
    R3 = R3 +1;
    goto L3;
      
L6:
    R2 = R2 + 1;
    goto L1;
L7: return 0;
}
