#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char temp[10];
char key[10];

void request(char *data) {
  printf("temp: %lx; key: %lx\n", (uintptr_t)temp, (uintptr_t)key);
  strcpy(key, "password");

  char *p = temp;
  while (*data != '\0') {
    *p = *data;
    data++;
    p++;
  }
  *p = '\0';
  printf("Data: %s\n", temp);
  printf("Password: %s\n", key);
}
