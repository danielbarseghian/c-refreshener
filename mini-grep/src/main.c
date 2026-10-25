#include "main.h"
#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[])
{
  if (argc != 3)
  {
    printf("Usage: ./minigrep name-of-file pattern\n");
    return 1;
  }

  FILE* fptr;

  fptr = fopen(argv[1], "r");

  if (fptr == NULL)
  {
    printf("The file coudnt be opened make sure the file is existante! \n");
  }

  char line[256];
  int count = 0;

  while (fgets(line, sizeof(line), fptr))
  {
    count = get_count(line, count, argv[2]);
  }
  
  printf("found %s %i times.\n", argv[2], count);
  fclose(fptr);
}

int get_count(char line[256], int count, char *word)
{
  char *pch = strtok(line, " ");

  while (pch != NULL)
  {
    pch = strtok(NULL, " ");
    
    if (pch != NULL && strcmp(pch, word) == 0) 
      count++;
  }
  
  return count;
 
  // cut the string 
  // then strcmp
}
