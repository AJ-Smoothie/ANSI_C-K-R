#include <stdio.h>

int main()
{ 
  int c = 0, wordLen = 0, wordCount = 0;
  int histogram[10]; // indexes correpsond to word lengths
  for (int i = 0; i < 10; i++) histogram[i] = 0;

  while ((c = getchar()) != EOF)
    {
      if (c == '\n')
        {
          histogram[wordLen - 1]++; // if the word was 4 long, it increases the count at index 4

          wordLen = 0;
        }
      else if (c == '\t')
        {
          printf("Histogram Array: \n");
          for (int i = 0; i < 10; i++)
            printf("%d\t", histogram[i]);
        }
      else
        {
          wordLen++; // we don't want wordlen increasing unless it's a not \t
        }
      
      
    }
}