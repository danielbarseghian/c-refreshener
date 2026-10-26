#ifndef MAIN_H
#define MAIN_H

typedef struct node {
  char *str;
  int count;
  struct node *next;
} node;

node *initiate_frequencie(int size);
void print_freq(node *freq);
void check_freq(node **frequencies, char *pch);
void free_frequencies(struct node *frequencies); 

#endif
