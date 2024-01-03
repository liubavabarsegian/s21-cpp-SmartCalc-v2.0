#ifndef SRC_SMART_CALC_DIJKSTRA_H_
#define SRC_SMART_CALC_DIJKSTRA_H_

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE 1

typedef struct stack {
  char *token;
  struct stack *prev;

} stack;

typedef struct rpn {
  char *token;
  struct rpn *next;
} rpn;

int isfunc(char *str);
int isdelim(char c);
char *get_token(char *token, char *prog, int *i);
int dijkstra(char *input, rpn **rpn_head);

#endif  // SRC_SMART_CALC_DIJKSTRA_H_