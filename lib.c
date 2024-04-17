#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char temp[10];

void request(char *data) {
  printf("Data: %p\n", temp);
  char *p = temp;
  while (*data != '\0') {
    *p = *data;
    data++;
    p++;
  }
  *p = '\0';
  printf("Data: %s\n", temp);
}
