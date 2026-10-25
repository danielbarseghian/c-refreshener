#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

  // initiate the first node of the linked list
  node *frequencies = NULL;
  
  char *pch = strtok(buff, " ,.-");

  while (pch != NULL)
  {
    check_freq(&frequencies, pch);
    pch = strtok (NULL, " ,.-");
  }

  print_freq(frequencies);
  return 0;
}

node *initiate_frequencie(int size)
{ 
  node *tmp = malloc(sizeof(node) * size);
  if (tmp == NULL)
    return NULL;

  tmp->str = NULL;
  tmp->count = 0;
  tmp->next = NULL;
  
  return tmp;
}

void print_freq(node *freq)
{
  if (freq->str != NULL)
  {
    printf("%s %i times\n", freq->str, freq->count);
  }

  if (freq->next != NULL)
  {
    print_freq(freq->next);
  }
}

void check_freq(node **frequencies, char *pch)
{
  // if its the first time
  if ((*frequencies) == NULL)
  {
    node *new = initiate_frequencie(sizeof(pch));

    new->str = pch;
    new->count++;

    *frequencies = new;
  }
  // if its him 
  else if (strcmp((*frequencies)->str, pch) == 0)
  {
    (*frequencies)->count++;
    return;
  }
  // else we need to search or create a new one
  else 
  {
    if ((*frequencies)->next != NULL)
    {
      // always goes next
      check_freq(&(*frequencies)->next, pch);
    }
    // we neeed to create a new one 
    else 
    {
      node *tmp = initiate_frequencie(sizeof(pch));

      tmp->str = pch;
      tmp->count++;

      node *t = tmp;

      // swap
      tmp->next = *frequencies;
      *frequencies = t;
    }
  }
}
