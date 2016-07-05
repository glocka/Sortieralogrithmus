// Der Arrayzugriff wurde aufgelöst und durch einen Pointer auf den Beginn
// auf das Array und dazu einenZahler welcher auf das aktuelle Element zeigt

#include <stdio.h>
int R0;
int R1;
int counter = 0;
int i;
int temp;
int temp2;
int j;
int speicher[20];
int diff1;
int diff2;
int diff3;
int diff4;
int* pointerstart;
int* pointer;
int* pointer2;

  
  
int main()
{
    pointerstart = speicher;                            //Erstellen des Pointers auf den Beginn des Arrays
start:
    pointer = pointerstart + counter;                   //Änderen des Pointer auf das aktuelle Element
    scanf ("%x",pointer);
    
    if (*pointer == 0 )
    {
      return 0;
    }
    
    if (*pointer == 0xFFFF )
    {
      printf("%04x\n",0);
      i = 0;
      
startprint:
      diff1 = counter-i;
      if (diff1 == 0)
      {
        goto start;
      }
      pointer = pointerstart + i;
      printf("%04x\n", *pointer);
      i++;
      goto startprint;
    }

    i = 1;
    
startsort:
    diff2 = counter - i ;
    diff2 = diff2 +1;
    if(diff2 == 0)
    {
      goto endsort;
    }
    pointer = pointerstart + i;
    temp = *pointer;
    j = i - 1;
    
startcopy:
      diff4 = j + 1;
      if (diff4 == 0)
      {
        goto endcopy;
      }
      pointer = pointerstart + j;
      diff3 = temp - *pointer;
      if (diff3 > 0)
      {
        goto endcopy;
      }
      temp2 = j+1;
      pointer = pointerstart + temp2;
      pointer2 = pointerstart + j;
      *pointer = *pointer2;
      j = j - 1;
      goto startcopy;
        
endcopy:
      temp2 = j+1;
      pointer = pointerstart + temp2;
      *pointer  = temp;
      i++;
      goto startsort;
      
endsort:
    counter ++;
    goto start;
}
