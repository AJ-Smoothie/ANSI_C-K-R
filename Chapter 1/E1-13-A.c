#include <stdio.h>

// This program prints out a histogram of the lengths of words

int main()
{ 
  int c = 0, wordLen = 0, wordCount = 0;
  int histogram[10]; // indexes correpsond to word lengths
  for (int i = 0; i < 10; i++) histogram[i] = 0;

  while ((c = getchar()) != EOF)
    {
      // only increment wordlen if we are revieving characters
      if (c != '\t' && c != '\n' && c != ' ') 
        wordLen++;

      if (c == '\n' || c == ' ')
        {
          histogram[wordLen - 1]++;
          wordLen = 0;
        }
      
      if (c == '\t')
        {
          printf("Histogram Array: \n");
          for (int i = 0; i < 10; i++)
            {
              printf("Word Length: "); printf("%d", i+1);
              printf(" x "); printf("%d", histogram[i]);
              printf(" -> ");

              int j = histogram[i];                
              while (j-- > 0) printf("|");
              printf("\n");
            } 
        } 
    }
}