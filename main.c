#include <stdlib.h>
#include <string.h>

void request(char *data);

#define SZ 2100

int main(int argc, char **argv) {
  char *req = malloc(SZ);
  for (int i = 0; i < SZ; ++i) {
    req[i] = 'A';
  }
  req[SZ - 1] = '\0';
  request(req);
  return 0;
}
