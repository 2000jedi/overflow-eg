#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char key[10];

void request(char *data);

#define SZ 2100

int main(int argc, char **argv) {
  printf("key: %p\n", key);
  strcpy(key, "password");
  char *req = malloc(SZ);
  for (int i = 0; i < SZ; ++i) {
    req[i] = 'A';
  }
  req[SZ - 1] = '\0';
  request(req);
  printf("key: %s\n", key);
  return 0;
}
