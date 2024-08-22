#include <stdio.h>

char a[50] = "Help ";
char *b = "beat life";

void strcatAJ(char* s, char*t); // always make prototypes for whatever reason

int main()
{
  strcatAJ(a, b);

  printf("%s", a);
}

void strcatAJ(char *s, char *t) // copies string t to the end of s
{
  while (*s) s++; // increment until s is point to the \0
  while (*s++ = *t++) ; // copy t onto the end of s until you reach \0
}