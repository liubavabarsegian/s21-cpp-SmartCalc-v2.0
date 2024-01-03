#include "scan_rpn.h"

int sum(stack **result) {
  char sum[255] = "";
  if (!(*result) || !(*result)->token || !(*result)->prev ||
      !(*result)->prev->token)
    return FAILURE;
  if (strchr((*result)->token, ',') ||
      ((*result)->prev->token && (strchr((*result)->prev->token, ','))))
    sprintf(sum, "%lf", atof((*result)->token) + atof((*result)->prev->token));
  else if (strchr((*result)->token, '.') ||
           ((*result)->prev->token && (strchr((*result)->prev->token, '.'))))
    sprintf(sum, "%lf", atof((*result)->token) + atof((*result)->prev->token));
  else
    sprintf(sum, "%d", atoi((*result)->token) + atoi((*result)->prev->token));
  stack *temp = *result;
  *result = (*result)->prev;
  free(temp->token);
  free(temp);
  free((*result)->token);
  (*result)->token = malloc(strlen(sum) + 1);
  strcpy((*result)->token, sum);
  return SUCCESS;
}

int division(stack **result) {
  if (!(*result) || !(*result)->token || !(*result)->prev ||
      !(*result)->prev->token)
    return FAILURE;
  char res[255] = "";
  sprintf(res, "%lf", atof((*result)->prev->token) / atof((*result)->token));
  stack *temp = *result;
  *result = (*result)->prev;
  free(temp->token);
  free(temp);
  free((*result)->token);
  (*result)->token = malloc(strlen(res) + 1);
  strcpy((*result)->token, res);
  return SUCCESS;
}

int multiplication(stack **result) {
  char res[255] = "";
  if (!(*result) || !(*result)->token || !(*result)->prev ||
      !(*result)->prev->token)
    return FAILURE;
  if (strchr((*result)->token, ',') ||
      ((*result)->prev->token && (strchr((*result)->prev->token, ','))))
    sprintf(res, "%lf", atof((*result)->prev->token) * atof((*result)->token));
  else if (strchr((*result)->token, '.') ||
           ((*result)->prev->token && (strchr((*result)->prev->token, '.'))))
    sprintf(res, "%lf", atof((*result)->prev->token) * atof((*result)->token));
  else
    sprintf(res, "%d", atoi((*result)->prev->token) * atoi((*result)->token));
  stack *temp = *result;
  *result = (*result)->prev;
  free(temp->token);
  free(temp);
  free((*result)->token);
  (*result)->token = malloc(strlen(res) + 1);
  strcpy((*result)->token, res);
  return SUCCESS;
}

int difference(stack **result) {
  char res[255] = "";
  if (!(*result) || !(*result)->token || !(*result)->prev ||
      !(*result)->prev->token)
    return FAILURE;
  if (strchr((*result)->token, ',') ||
      ((*result)->prev->token && (strchr((*result)->prev->token, ','))))
    sprintf(res, "%lf", atof((*result)->prev->token) - atof((*result)->token));
  else if (strchr((*result)->token, '.') ||
           ((*result)->prev->token && (strchr((*result)->prev->token, '.'))))
    sprintf(res, "%lf", atof((*result)->prev->token) - atof((*result)->token));
  else
    sprintf(res, "%d", atoi((*result)->prev->token) - atoi((*result)->token));
  stack *temp = *result;
  *result = (*result)->prev;
  free(temp->token);
  free(temp);
  free((*result)->token);
  (*result)->token = malloc(strlen(res) + 1);
  strcpy((*result)->token, res);
  return SUCCESS;
}

int mod(stack **result) {
  char res[255] = "";
  if (!(*result) || !(*result)->token || !(*result)->prev ||
      !(*result)->prev->token)
    return FAILURE;
  if (strchr((*result)->token, ',') ||
      ((*result)->prev->token && (strchr((*result)->prev->token, ','))))
    sprintf(res, "%f",
            fmod(atof((*result)->prev->token), atof((*result)->token)));
  else if (strchr((*result)->token, '.') ||
           ((*result)->prev->token && (strchr((*result)->prev->token, '.'))))
    sprintf(res, "%f",
            fmod(atof((*result)->prev->token), atof((*result)->token)));
  else
    sprintf(res, "%d", atoi((*result)->prev->token) % atoi((*result)->token));
  stack *temp = *result;
  *result = (*result)->prev;
  free(temp->token);
  free(temp);
  free((*result)->token);
  (*result)->token = malloc(strlen(res) + 1);
  strcpy((*result)->token, res);
  return SUCCESS;
}

int power(stack **result) {
  char res[255] = "";
  if (!(*result) || !(*result)->token || !(*result)->prev ||
      !(*result)->prev->token)
    return FAILURE;
  if (strchr((*result)->token, ',') ||
      ((*result)->prev->token && (strchr((*result)->prev->token, ','))))
    sprintf(res, "%lf",
            pow(atof((*result)->prev->token), atof((*result)->token)));
  else if (strchr((*result)->token, '.') ||
           ((*result)->prev->token && (strchr((*result)->prev->token, '.'))))
    sprintf(res, "%lf",
            pow(atof((*result)->prev->token), atof((*result)->token)));
  else
    sprintf(res, "%lf",
            pow(atoi((*result)->prev->token), atoi((*result)->token)));
  stack *temp = *result;
  *result = (*result)->prev;
  free(temp->token);
  free(temp);
  free((*result)->token);
  (*result)->token = malloc(strlen(res) + 1);
  strcpy((*result)->token, res);
  return SUCCESS;
}

int sinus(stack **result) {
  char res[255] = "";
  if (!(*result) || !(*result)->token) return FAILURE;
  if (strchr((*result)->token, ','))
    sprintf(res, "%lf", sin(atof((*result)->token)));
  else if (strchr((*result)->token, '.'))
    sprintf(res, "%lf", sin(atof((*result)->token)));
  else
    sprintf(res, "%lf", sin(atoi((*result)->token)));
  free((*result)->token);
  (*result)->token = malloc(strlen(res) + 1);
  strcpy((*result)->token, res);
  return SUCCESS;
}

int cosinus(stack **result) {
  char res[255] = "";
  if (!(*result) || !(*result)->token) return FAILURE;
  if (strchr((*result)->token, ','))
    sprintf(res, "%lf", cos(atof((*result)->token)));
  else if (strchr((*result)->token, '.'))
    sprintf(res, "%lf", cos(atof((*result)->token)));
  else
    sprintf(res, "%lf", cos(atoi((*result)->token)));
  free((*result)->token);
  (*result)->token = malloc(strlen(res) + 1);
  strcpy((*result)->token, res);
  return SUCCESS;
}

int tangent(stack **result) {
  char res[255] = "";
  if (!(*result) || !(*result)->token) return FAILURE;
  if (strchr((*result)->token, ','))
    sprintf(res, "%lf", tan(atof((*result)->token)));
  else if (strchr((*result)->token, '.'))
    sprintf(res, "%lf", tan(atof((*result)->token)));
  else
    sprintf(res, "%lf", tan(atoi((*result)->token)));
  free((*result)->token);
  (*result)->token = malloc(strlen(res) + 1);
  strcpy((*result)->token, res);
  return SUCCESS;
}

int atangent(stack **result) {
  char res[255] = "";
  if (!(*result) || !(*result)->token) return FAILURE;
  if (strchr((*result)->token, ','))
    sprintf(res, "%lf", atan(atof((*result)->token)));
  else if (strchr((*result)->token, '.'))
    sprintf(res, "%lf", atan(atof((*result)->token)));
  else
    sprintf(res, "%lf", atan(atoi((*result)->token)));
  free((*result)->token);
  (*result)->token = malloc(strlen(res) + 1);
  strcpy((*result)->token, res);
  return SUCCESS;
}

int asinus(stack **result) {
  char res[255] = "";
  if (!(*result) || !(*result)->token) return FAILURE;
  if (strchr((*result)->token, ','))
    sprintf(res, "%lf", asin(atof((*result)->token)));
  else if (strchr((*result)->token, '.'))
    sprintf(res, "%lf", asin(atof((*result)->token)));
  else
    sprintf(res, "%lf", asin(atoi((*result)->token)));
  free((*result)->token);
  (*result)->token = malloc(strlen(res) + 1);
  strcpy((*result)->token, res);
  return SUCCESS;
}

int acosinus(stack **result) {
  char res[255] = "";
  if (!(*result) || !(*result)->token) return FAILURE;
  if (strchr((*result)->token, ','))
    sprintf(res, "%lf", acos(atof((*result)->token)));
  else if (strchr((*result)->token, '.'))
    sprintf(res, "%lf", acos(atof((*result)->token)));
  else
    sprintf(res, "%lf", acos(atoi((*result)->token)));
  free((*result)->token);
  (*result)->token = malloc(strlen(res) + 1);
  strcpy((*result)->token, res);
  return SUCCESS;
}

int square(stack **result) {
  char res[255] = "";
  if (!(*result) || !(*result)->token) return FAILURE;
  if (strchr((*result)->token, ','))
    sprintf(res, "%lf", sqrt(atof((*result)->token)));
  else if (strchr((*result)->token, '.'))
    sprintf(res, "%lf", sqrt(atof((*result)->token)));
  else
    sprintf(res, "%lf", sqrt(atoi((*result)->token)));
  free((*result)->token);
  (*result)->token = malloc(strlen(res) + 1);
  strcpy((*result)->token, res);
  return SUCCESS;
}

int ln_func(stack **result) {
  char res[255] = "";
  if (!(*result) || !(*result)->token) return FAILURE;
  if (strchr((*result)->token, ','))
    sprintf(res, "%lf", log(atof((*result)->token)));
  else if (strchr((*result)->token, '.'))
    sprintf(res, "%lf", log(atof((*result)->token)));
  else
    sprintf(res, "%lf", log(atoi((*result)->token)));
  free((*result)->token);
  (*result)->token = malloc(strlen(res) + 1);
  strcpy((*result)->token, res);
  return SUCCESS;
}

int log_func(stack **result) {
  char res[255] = "";
  if (!(*result) || !(*result)->token) return FAILURE;
  if (strchr((*result)->token, ','))
    sprintf(res, "%lf", log10(atof((*result)->token)));
  else if (strchr((*result)->token, '.'))
    sprintf(res, "%lf", log10(atof((*result)->token)));
  else
    sprintf(res, "%lf", log10(atoi((*result)->token)));
  free((*result)->token);
  (*result)->token = malloc(strlen(res) + 1);
  strcpy((*result)->token, res);
  return SUCCESS;
}

int count_function(rpn **rpn_ready, stack **result) {
  int flag = SUCCESS;
  if (strcmp((*rpn_ready)->token, "+") == 0) {
    flag = sum(result);
  } else if (strcmp((*rpn_ready)->token, "/") == 0) {
    flag = division(result);
  } else if (strcmp((*rpn_ready)->token, "*") == 0) {
    flag = multiplication(result);
  } else if (strcmp((*rpn_ready)->token, "-") == 0) {
    flag = difference(result);
  } else if (strcmp((*rpn_ready)->token, "%") == 0) {
    flag = mod(result);
  } else if (strcmp((*rpn_ready)->token, "^") == 0) {
    flag = power(result);
  } else if (strcmp((*rpn_ready)->token, "sin") == 0) {
    flag = sinus(result);
  } else if (strcmp((*rpn_ready)->token, "cos") == 0) {
    flag = cosinus(result);
  } else if (strcmp((*rpn_ready)->token, "tan") == 0) {
    flag = tangent(result);
  } else if (strcmp((*rpn_ready)->token, "atan") == 0) {
    flag = atangent(result);
  } else if (strcmp((*rpn_ready)->token, "acos") == 0) {
    flag = acosinus(result);
  } else if (strcmp((*rpn_ready)->token, "asin") == 0) {
    flag = asinus(result);
  } else if (strcmp((*rpn_ready)->token, "sqrt") == 0) {
    flag = square(result);
  } else if (strcmp((*rpn_ready)->token, "ln") == 0) {
    flag = ln_func(result);
  } else if (strcmp((*rpn_ready)->token, "log") == 0) {
    flag = log_func(result);
  }
  if (strchr((*result)->token, ',') || strchr((*result)->token, '.')) {
    int i = strlen((*result)->token) - 1;
    while ((*result)->token[i] == '0') {
      char *copy = malloc(i + 1);
      strncpy(copy, (*result)->token, i);
      free((*result)->token);
      (*result)->token = malloc(i + 1);
      if ((*result)->token) {
        strncpy((*result)->token, copy, i);
        (*result)->token[i] = '\0';
      }
      i--;
      if (copy) free(copy);
    }
    // i--;
    // i = strlen((*result)->token) - 1;
    if ((*result)->token[i] == '.' || (*result)->token[i] == ',') {
      char *copy = malloc(i + 1);
      strncpy(copy, (*result)->token, i);
      free((*result)->token);
      (*result)->token = malloc(i + 1);
      if ((*result)->token) {
        strncpy((*result)->token, copy, i);
        (*result)->token[i] = '\0';
      }
      if (copy) free(copy);
    }
  }
  return flag;
}

int count_chars(char *str, char c) {
  int i = 0;
  int count = 0;
  while (str[i]) {
    if (str[i] == c) count++;
    i++;
  }
  return count;
}

int calculate(rpn **rpn_ready, stack **result) {
  int flag = SUCCESS;
  while (*rpn_ready) {
    if (*rpn_ready && (*rpn_ready)->token &&
        (count_chars((*rpn_ready)->token, ',') > 1 ||
         count_chars((*rpn_ready)->token, '.') > 1)) {
      flag = FAILURE;
      while (*result) {
        stack *temp = *result;
        *result = temp->prev;
        free((*result)->token);
        free(*result);
      }
      // while(*rpn_ready)
      // {
      //   rpn *temp = *rpn_ready;
      //   *rpn_ready = temp->next;
      //   free((*rpn_ready)->token);
      // }
      break;
    } else if (*result == NULL && !isdelim((*rpn_ready)->token[0]) &&
               !isfunc((*rpn_ready)->token)) {
      *result = malloc(sizeof(stack));
      (*result)->token = malloc(strlen((*rpn_ready)->token) + 1);
      (*result)->prev = NULL;
      strcpy((*result)->token, (*rpn_ready)->token);
    } else if (isdelim((*rpn_ready)->token[0]) || isfunc((*rpn_ready)->token)) {
      flag = count_function(rpn_ready, result);
      if (flag == FAILURE) break;
    } else {
      stack *new = malloc(sizeof(stack));
      if (new) {
        new->token = malloc(strlen((*rpn_ready)->token) + 1);
        if (!new->token) {
          free(new);
          flag = FAILURE;
        } else {
          strcpy(new->token, (*rpn_ready)->token);
          new->token[strlen(new->token)] = '\0';
          new->prev = *result;
          *result = new;
        }
      } else {
        flag = FAILURE;
      }
    }
    if (flag != FAILURE) {
      rpn *temp;
      temp = *rpn_ready;
      (*rpn_ready) = (*rpn_ready)->next;
      free(temp->token);
      free(temp);
    }
  }
  // if (flag == FAILURE)
  // {
  //   while(rpn_ready)
  //   {
  //     rpn *temp;
  //     temp = *rpn_ready;
  //     (*rpn_ready) = (*rpn_ready)->next;
  //     free(temp->token);
  //     free(temp);
  //   }
  //   // free((*result)->token);
  //   // free(*result);
  // }
  return flag;
}

int unaries(char *input, char *dest) {
  int flag = SUCCESS;
  char token[255] = "", prev_token[255] = "", copy[255] = "";
  int i = 0, j = 0, prev_i;
  while (input[i]) {
    prev_i = i;
    get_token(token, input + i, &i);
    if (prev_i == i) break;
    if (strlen(token) == 0) flag = FAILURE;
    if ((strlen(prev_token) == 0 ||
         (isdelim(prev_token[0]) && strcmp(prev_token, ")"))) &&
        (strcmp(token, "+") == 0 || strcmp(token, "-") == 0)) {
      if (strcmp(prev_token, "+") == 0 && (strcmp(token, "+") == 0))
        return FAILURE;
      else if (strcmp(prev_token, "+") == 0 && strcmp(token, "-") == 0)
        return FAILURE;
      else if (strcmp(prev_token, "-") == 0 && strcmp(token, "+") == 0)
        return FAILURE;
      else if (strcmp(prev_token, "-") == 0 && strcmp(token, "-") == 0)
        return FAILURE;
      else {
        copy[j] = '(';
        copy[j + 1] = '0';
        copy[j + 2] = token[0];
        get_token(token, input + i, &i);
        if (isfunc(token)) {
          copy[j + 3] = '1';
          copy[j + 4] = ')';
          copy[j + 5] = '*';
          j += 6;
          strcpy(copy + j, token);
          j += strlen(token);
        } else {
          j += 3;
          strcpy(copy + j, token);
          j += strlen(token);
          copy[j] = ')';
          j++;
        }
      }
    } else {
      strcpy(copy + j, token);
      j += strlen(token);
    }
    strcpy(prev_token, token);
  }
  strcpy(dest, copy);
  return flag;
}

int scan_rpn(char *inp, char *result) {
  int flag = SUCCESS;
  if (strlen(inp) == 0)
    flag = FAILURE;
  else if (!result)
    flag = FAILURE;
  else if (count_chars(inp, '(') != count_chars(inp, ')'))
    flag = FAILURE;
  else {
    rpn *rpn_ready = NULL;
    char input[255] = "";
    if (unaries(inp, input) == FAILURE)
      flag = FAILURE;
    else {
      if (dijkstra(input, &rpn_ready) == FAILURE) {
        while (rpn_ready) {
          rpn *temp = rpn_ready;
          rpn_ready = temp->next;
          free(rpn_ready->token);
          free(rpn_ready);
        }
        flag = FAILURE;
      } else {
        stack *res_stack = NULL;
        if (calculate(&rpn_ready, &res_stack) == FAILURE)
          flag = FAILURE;
        else if (res_stack)
          strcpy(result, res_stack->token);
        if (strlen(result) == 0) flag = FAILURE;
        if (res_stack && res_stack->token) free(res_stack->token);
        if (res_stack) free(res_stack);
        while (rpn_ready) {
          rpn *temp = rpn_ready;
          rpn_ready = rpn_ready->next;
          free(temp->token);
          free(temp);
        }
        free(rpn_ready);
      }
    }
  }
  return flag;
}

// int main()
// {
//  char input[] = "1 # 3";
//  char result_s21[255] = "";
//  printf("%s\n", result_s21);
//  printf("%d\n", scan_rpn(input, result_s21));
// }
