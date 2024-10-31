#include <stdio.h>

char a[] = "Sentence of mi home";
char b[] = "hoee";

// returns 1 if string b is at the end of string a, otherwise return 0
int strend(char *a, char *b);

void main()
{
 
  printf("Results: "); printf("%d", strend(a, b));

}

int strend(char *a, char *b)
{
  int lenB = 0; 
  while (*b) { lenB++; b++; } // figure out how long string b is
  while (*a) a++;

  a -= lenB; // subtract the len of stringB from stringA
  b -= lenB; // set b pointing back to the beginning of its string
  while (*a) // well now compare the strings
    {
      if (*a++ != *b++) return 0;
    }
  return 1;

  //printf("A: "); printf(a);
  //printf("%d", lenB);

}

