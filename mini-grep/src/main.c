#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main (int argc, char *argv[])
{
  if (argc == 2 && strcmp(argv[1], "--help") == 0)
  {
    printf("Usage:\n");
    printf("./minigrep [OPTION] PATTERN FILE\n");
    printf("\nOptions: \n");
    printf("--help will show you how to use\n");
    printf("\nThis program is for the terra program organized by hackclub!\n");
    printf("The project is under the MIT license\n");
    return 0;
  }

  if (argc != 3)
  {
    printf("Use ./minigrep --help to get more info on how to use this! \n");
    return 1;
  }

  FILE* fptr;

  fptr = fopen(argv[2], "r");

  if (fptr == NULL)
  {
    printf("The file coudnt be opened make sure the file existe\n");
    return 1;
  }

  char line[256];
  int count = 0;

  while (fgets(line, sizeof(line), fptr))
  {
    count += search(line, argv[1]);
  }
  
  printf("found %s %i times.\n", argv[1], count);
  fclose(fptr);
}

int search(char *line, char *pattern)
{
  int matched_size = strlen(pattern);
  int i = 0, j = 0;
  int curr_matching = 0;
  int matched = 0;

  while (line[i] != '\0')
  {
    if (pattern[j] == line[i])
    {
      curr_matching++;
      j++;
  
      if (j == matched_size)
      {
        matched++;
        curr_matching = 0;
      }
    }

    else if (pattern[j] != line[i] && curr_matching != 0)
    {
      j = 0;
    }

    i++;
  }

  return matched;
}

