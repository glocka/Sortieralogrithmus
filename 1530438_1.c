#include <stdio.h>
  int counter;
  int i;
  int temp;
  int j;
  int speicher[20] ;
  
//-----------------------------------------------------------------------------
/// Mainfunction
/// - read number from Stdin
/// - Checks if special numbers are given (0 for halt or -1 for print)
/// - sorts the given number in the existing array
///   Possible inputs:
///   - A integer number
///
/// @return 0 : programm ended because a 0 was entered
///
//
int main()
{
  for (counter = 0;; counter++)
  {
    scanf ("%x",&speicher[counter]);          // Einlesen vom Standard In in die letzte Stelle des Arrays
    
    if (speicher[counter] == 0 )              //Check ob der Haltebefehl gegeben wurde
    {
      return 0;
    }
    
    if (speicher[counter] == 0xFFFF )             //Check ob der Printbefehl gegeben wurde
    {
      printf("%04x\n",0);                          //Ausgabe von 0 gefolgt von dem sortierten Array. Zwischen den Zahlen steht ein | und nach jeder ausgabe ein neue zeile zur besseren übersicht.
      for (i = 0; i < counter; i++)
      {
        printf("%04x\n", speicher[i]);
      }
      counter --;                             //Löschen der letzten eingelesen (-1) Zahl
      continue;                               //Rücksprung zum beginn der Schleife
    }
    
    for (i = 1; i <= counter; i++)            //Einsortieren der eingelesenen Zahl in das Array durch Insertsort (funktionsweise von 711.021 Grundlagen der Informatik)
    {
      temp = speicher[i];
      j = i - 1;
      while ((temp < speicher[j]) && (j >=0))
      {
        speicher[j+1] = speicher[j];
        j = j - 1;
      }
      speicher[j+1]  = temp;
    }
  }
}
