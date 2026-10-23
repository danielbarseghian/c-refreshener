#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node {
  char *str;
  int count;
  struct node *next;
} node;

bool *check_pch(node *frequencies, char *pch);
void initiate_frequencie(node *frequencie);
void print_freq(node *freq);

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
  node *frequencies = malloc(sizeof(node));
  initiate_frequencie(frequencies);
  
  char *pch = strtok(buff, " ,.-");

  while (pch != NULL)
  {
    printf ("%s\n",pch);
    
    check_pch(frequencies, pch);
    pch = strtok (NULL, " ,.-");
  }

  print_freq(frequencies);
  return 0;
}

void initiate_frequencie(node *frequencie)
{ 
  frequencie->str = NULL;
  frequencie->count = 0;
  frequencie->next = NULL;
}

void print_freq(node *freq)
{
  printf("%s\n", freq->str);

  if (freq->next != NULL)
  {
    print_freq(freq->next);
  }
}

bool *check_pch(node *frequencies, char *pch)
{
  if (frequencies == NULL || pch == NULL) 
    return false;

  if (frequencies->str == NULL)
  {
    printf("Create\n");
    // create a new node and add thoses values
    node *tmp = malloc(sizeof(node));
    if (tmp == NULL)
    {
      return false;
    }
    initiate_frequencie(tmp);

    // put the variables
    tmp->str = malloc(sizeof(char) * strlen(pch));
    strcpy(tmp->str, pch);
    tmp->count++;

    frequencies->next = tmp;
  }
  else if (frequencies->next != NULL)
  {
    check_pch(frequencies->next, pch);
  }
  else if (strcmp(pch, frequencies->str) == 0)
  {
    frequencies->count++;
  }
}
