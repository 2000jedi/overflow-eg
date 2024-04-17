#include <stdlib.h>
#include <string.h>

void request(char *data);

int main(int argc, char **argv) {
  char *req = strdup(argv[1]);
  request(req);
  return 0;
}
