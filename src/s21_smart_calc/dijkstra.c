#include "dijkstra.h"

int isfunc(char *str) {
  if (strcmp(str, "sin") == 0 || strcmp(str, "cos") == 0 ||
      strcmp(str, "tan") == 0 || strcmp(str, "asin") == 0 ||
      strcmp(str, "acos") == 0 || strcmp(str, "atan") == 0 ||
      strcmp(str, "sqrt") == 0 || strcmp(str, "log") == 0 ||
      strcmp(str, "ln") == 0)
    return 1;
  return 0;
}

int isdelim(char c) {
  if (strchr(" +-/*%^=()", c) || c == 9 || c == '\r' || c == 0) return 1;
  return 0;
}

int get_operator_priority(char *op) {
  if (strcmp(op, "(") == 0)
    return 3;
  else if (strcmp(op, "^") == 0)
    return 2;
  else if (isfunc(op))
    return 2;
  else if (strcmp(op, "*") == 0 || strcmp(op, "/") == 0 || strcmp(op, "%") == 0)
    return 1;
  else if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0)
    return 0;
  else
    return -1;  // error: unknown operator
}

char *get_token(char *token, char *prog, int *i) {
  register char *temp;
  temp = token;
  *temp = '\0';

  if (!*prog) return NULL;
  while (isspace(*prog)) {
    ++prog;
    ++(*i);
  }
  if (strchr("+-*/%^()", *prog)) {
    *temp++ = *prog++;
    ++(*i);
  } else if (isalpha(*prog)) {
    while (!isdelim(*prog)) {
      *temp++ = *prog++;
      ++(*i);
    }
  } else if (isdigit(*prog)) {
    while (!isdelim(*prog)) {
      *temp++ = *prog++;
      ++(*i);
    }
  }
  *temp = '\0';
  return token;
}

int put_in_rpn(rpn **rpn_output, rpn **rpn_head, stack **stack_for_delims,
               char *token) {
  if (isdelim(token[0]) || isfunc(token)) {
    if ((*stack_for_delims) == NULL) {
      (*stack_for_delims) = malloc(sizeof(stack));
      (*stack_for_delims)->token = malloc(strlen(token) + 1);
      strcpy((*stack_for_delims)->token, token);
      (*stack_for_delims)->prev = NULL;
    } else {
      // close brace
      if (strcmp(token, ")") == 0) {
        if (!(*rpn_output) || !(*stack_for_delims)) return FAILURE;
        while ((*stack_for_delims) && (*stack_for_delims)->token &&
               strcmp((*stack_for_delims)->token, "(") != 0) {
          rpn *new = malloc(sizeof(rpn));
          new->token = malloc(strlen(token) + 1);
          new->next = NULL;
          strcpy(new->token, (*stack_for_delims)->token);
          new->token[strlen(new->token)] = '\0';
          (*rpn_output)->next = new;
          (*rpn_output) = new;
          stack *temp = (*stack_for_delims);
          (*stack_for_delims) = (*stack_for_delims)->prev;
          free(temp->token);
          free(temp);
        }
        if (*stack_for_delims) {
          stack *temp = (*stack_for_delims);
          (*stack_for_delims) = (*stack_for_delims)->prev;
          free(temp->token);
          free(temp);
        }

      } else {
        if (get_operator_priority((*stack_for_delims)->token) == -1 ||
            get_operator_priority(token) == -1)
          return FAILURE;
        //пока приоритет О2 выше О1, перекладываем из стека в опн
        while ((*stack_for_delims) &&
               (strcmp((*stack_for_delims)->token, "(") != 0) &&
               get_operator_priority((*stack_for_delims)->token) >=
                   get_operator_priority(token)) {
          rpn *new = malloc(sizeof(rpn));
          new->token = malloc(strlen(token) + 1);
          new->next = NULL;
          strcpy(new->token, (*stack_for_delims)->token);
          new->token[strlen(new->token)] = '\0';
          (*rpn_output)->next = new;
          (*rpn_output) = new;
          stack *temp = (*stack_for_delims);
          (*stack_for_delims) = (*stack_for_delims)->prev;
          free(temp->token);
          free(temp);
        }
        stack *new = malloc(sizeof(stack));
        new->token = malloc(strlen(token) + 1);
        strcpy(new->token, token);
        new->token[strlen(new->token)] = '\0';
        new->prev = (*stack_for_delims);
        (*stack_for_delims) = new;
      }
    }
  } else {
    if ((*rpn_output) == NULL) {
      (*rpn_output) = malloc(sizeof(rpn));
      (*rpn_output)->token = malloc(strlen(token) + 1);
      strcpy((*rpn_output)->token, token);
      (*rpn_output)->next = NULL;
      (*rpn_head) = (*rpn_output);
    } else {
      rpn *new = malloc(sizeof(rpn));
      new->token = malloc(strlen(token) + 1);
      new->next = NULL;
      strcpy(new->token, token);
      new->token[strlen(new->token)] = '\0';
      (*rpn_output)->next = new;
      (*rpn_output) = new;
    }
  }
  return SUCCESS;
}

int dijkstra(char *input, rpn **rpn_head) {
  int flag = SUCCESS;
  int i = 0;
  char token[255] = "";
  rpn *rpn_output = NULL;
  stack *stack_for_delims = NULL;
  if (!input)
    flag = FAILURE;
  else {
    while (input[i]) {
      get_token(token, input + i, &i);
      if (strlen(token) == 0 ||
          put_in_rpn(&rpn_output, rpn_head, &stack_for_delims, token) ==
              FAILURE) {
        while (stack_for_delims) {
          stack *temp = stack_for_delims;
          stack_for_delims = temp->prev;
          free(temp->token);
          free(temp);
        }
        while (*rpn_head) {
          rpn *temp = *rpn_head;
          *rpn_head = temp->next;
          free(temp->token);
          free(temp);
        }
        return FAILURE;
      }
    }
    while (stack_for_delims) {
      rpn *new = malloc(sizeof(rpn));
      new->token = malloc(strlen(stack_for_delims->token) + 1);
      if (!new || !new->token)
        flag = FAILURE;
      else if (rpn_output) {
        new->next = NULL;
        strcpy(new->token, stack_for_delims->token);
        new->token[strlen(new->token)] = '\0';
        rpn_output->next = new;
        rpn_output = new;
      }
      stack *temp = stack_for_delims;
      stack_for_delims = stack_for_delims->prev;
      free(temp->token);
      free(temp);
    }
  }
  return flag;
}
