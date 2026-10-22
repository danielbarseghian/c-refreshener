#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  // take user input
  // while the input cant fit in the buffer
  // realloc the buffer
  size_t capacity = 100;
  char *buff = malloc(capacity * sizeof(char));
  char *tmp = NULL;

  printf("Enter a string: ");
  
  // Read input from the user
  while(fgets(buff, capacity, stdin))
  {
    printf("loop\n");

    size_t len = strlen(buff);
    
    // it isn't enough space
    if (buff[len - 1] != '\n') 
    {
      len += 1;
      tmp = realloc(buff, len);
      printf("reallocted\n");
      if (tmp != NULL)
      {
        printf("NULL");
        free(buff);
        return 1;
      }

      buff = tmp;
      printf("changed\n");
    }
    
    // it is enough space
    else
    {
      printf("break\n");
      break;
    }
  }

  printf("Now: %s", buff);
}

