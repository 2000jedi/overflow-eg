#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void request(char *data) {
  char *buffer = malloc(10);
  char *password = malloc(10);

  printf("password: %x; buffer: %x\n", password, buffer);

  strcpy(password, "password");
  char *p = buffer;
  while (*data != '\0') {
    *p = *data;
    data++;
    p++;
  }
  *p = '\0';
  printf("Data: %s\n", buffer);
  printf("Password: %s\n", password);
}
