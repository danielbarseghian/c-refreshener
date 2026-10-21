#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  // take user input
  // while the input cant fit in the buffer
  // realloc the buffer
  
  char buff[100];

  printf("Enter a string: ");

  // Read input from the user
  fgets(buff, sizeof(buff), stdin); 
  
  size_t len = strlen(buff);
  if (buff[len - 1] != '\n') 
  {
    printf("String didn't fit\n");
  }

  else
  {
    printf("it did!\n");
  }

  printf("You entered: %s\n", buff);
  
  return 0; 
}
