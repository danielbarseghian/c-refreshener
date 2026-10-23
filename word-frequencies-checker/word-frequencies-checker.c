#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  int capacity = 16;
  size_t length = 0;
  char *buff = malloc(capacity);

  if (buff == NULL)
  {
    return 1;
  }

  int ch;
  char *tmp;

  printf("Please input a string: ");

  while((ch = getchar()) != '\n' && ch != EOF)
  {
    // if there is no room for this caracter + the null character
    if (length + 1 > capacity)
    {
      capacity *= 2;

      tmp = realloc(buff, capacity);
      if (tmp == NULL)
      {
        free(buff);
        return 1;
      }
      
      // swap
      buff = tmp;

    }

    buff[length] = ch;
    length++;
  }

  buff[length] = '\0';

  char *pch = strtok(buff, " ,.-");

  while (pch != NULL)
  {
    printf ("%s\n",pch);
    pch = strtok (NULL, " ,.-");
  }
  return 0;
}
