// strcopy(s, ct, n) copy at most n characters of string ct to s, return s. Pad with \0's if ct has fewer that n characters
// strcat(s, ct, n) concatenate at most n characters of string ct to string s, terminate s with \0, 
// strcmp(cs, ct, n) compare at most n characters of string cs to string ct;
  // return <0 if cs < ct, 0 if cs == ct, or > if cs > ct.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void strcopyAJ(char *s, char *ct, int n);
void strcatAJ(char *s, char *ct, int n);
int strcmpAJ(char *cs, char *ct, int n);


char src[50] = " World! the rest of which is cancled";
char dst[50] = {0}; // initialize all elements to 0
char stra[] = "Hello";
char strb[] = "Hellp.";

void main()
{
  //strcopyAJ(dst, src, 12);
  //strcatAJ(stra, src, 7);
  
  printf("Results: ");
  printf("%d", strcmpAJ(stra, strb, 7));

  //printf("DST: "); printf(dst);
  //printf("\t");
  //printf("stra: "); printf(stra);
  
}

void strcopyAJ(char *s, char *ct, int n)
{
  int ctLen = strlen(ct);
  for (int i = 0; i < n; i++)
    {
      if (n > ctLen) *s++ = '\0';
      else *s++ = *ct++; 
    }
}

// strcat(s, ct, n) concatenate at most n characters of string ct to string s, terminate s with \0, 
void strcatAJ(char *s, char *ct, int n)
{
  int ctLen = strlen(ct);
  while (*s) s++; // go to the end of s

  for (int i = 0; i < n; i++)
    {
      if (n > ctLen) *s++ = '\0';
      else *s++ = *ct++;
    }
  *s = '\0'; // terminate with \0
}

int strcmpAJ(char *cs, char *ct, int n)
{
  for (int i = 0; i < n; i++)
    {
      int val = *cs++ - *ct++;
      if (val < 0) return -1;
      if (val > 0) return 1;
    }
  return 0;
}