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
node *initiate_frequencie(int size);
void print_freq(node *freq);
void check_freq(node **frequencies, char *pch);

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
    printf ("%s\n",pch);
    
    check_freq(&frequencies, pch);
    pch = strtok (NULL, " ,.-");
  }
  printf("out\n");

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
  printf("entered\n");
  if (freq->str != NULL)
  {
    printf("print\n");
    printf("%s %i times\n", freq->str, freq->count);
  }
  else 
  {
    printf("nonono\n");
  }
  if (freq->next != NULL)
  {
    printf("next\n");
    print_freq(freq->next);
  }
}

void check_freq(node **frequencies, char *pch)
{
  printf("enter\n");

  // if its the first time
  if ((*frequencies) == NULL)
  {
    printf("create\n");
    node *new = initiate_frequencie(sizeof(pch));

    new->str = pch;
    new->count++;

    *frequencies = new;
  }
  // if its him 
  else if (strcmp((*frequencies)->str, pch) == 0)
  {
    printf("bro is him\n");
    (*frequencies)->count++;
    return;
  }
  // else we need to search or create a new one
  else 
  {
    printf("else\n");
    if ((*frequencies)->next != NULL) 
      check_freq(frequencies, pch);
    // we neeed to create a new one 
    else 
    {
      printf("creating new node");
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
