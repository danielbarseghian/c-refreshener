#include "main.h"
#include <stdio.h>

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

  while (fgets(line, sizeof(line), fptr))
  {
    printf("%s\n", line);
  }

  fclose(fptr);


}
