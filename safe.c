#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int iv_domain_lib;
int iv_domain_main;

#define ISONAME lib
#define ISOSAFE 1
#include "iso.h"
#include "iso_xcall.h"

char ISO_DATA temp[10];

void ISO_CODE request(char *data) {
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

ISO_ENTRY(request);

#include "iso_align.h"
#include "iso_end.h"
#include "iso_init.h"

#define ISONAME main
#define ISOSAFE 1
#include "iso.h"
#include "iso_xcall.h"
#include "isoalloc.h"

char ISO_DATA key[10] = "password";
#define SZ 0x3100 //(0xd100-0xa000)
char req[SZ];

int ISO_CODE main() {
  printf("key: %p\n", key);
  for (int i = 0; i < SZ; ++i) {
    req[i] = 'A';
  }
  req[SZ - 1] = '\0';
  xcall(lib, request, req); /* XCALL determined by PCG */
  printf("key: %s\n", key);
  return 0;
}

ISO_ENTRY(main);

#include "iso_align.h"
#include "iso_end.h"
#include "iso_init.h"
