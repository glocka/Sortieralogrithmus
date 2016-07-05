// Alle Schleifen aus 1530438_1.c wurden in while Schleifen umgeschrieben
// und danach durch if- Abfragen und goto Befehle ersetzt
#include <stdio.h>

int counter = 0;
int i;
int temp;
int j;
int speicher[20];
int diff1;
int diff2;
int diff3;
int diff4;
  
  
int main()
{
start:
    scanf ("%x",&speicher[counter]);
    if (speicher[counter] == 0 )
    {
      return 0;
    }
    
    if (speicher[counter] == 0xFFFF )
    {
      printf("%04x\n",0);
      i = 0;
      
startprint:
      diff1 = counter-i;
      if (diff1 == 0)
      {
        goto start;
      }
      printf("%04x\n", speicher[i]);
      i++;
      goto startprint;
    }

    i = 1;
    
startsort:
    diff2 = counter - i + 1;
    if(diff2 == 0)
    {
      goto endsort;
    }
    
    temp = speicher[i];
    j = i - 1;
    
startcopy:
      diff4 = j +1;
      if (diff4 == 0)
      {
        goto endcopy;
      }
      
      diff3 = temp - speicher[j];
      if (diff3 > 0)
      {
        goto endcopy;
      }
      speicher[j+1] = speicher[j];
      j = j - 1;
      goto startcopy;
        
endcopy:
      speicher[j+1]  = temp;
      i++;
      goto startsort;
      
endsort:
    counter ++;
    goto start;
}
