#include <stdio.h>
#include <stdlib.h>
#include <string.h> // for memcmp()

#include "orka-utils.h"
#include "json-actor.h"

int main(int argc, char *argv[])
{
  if (argc != 2) {
    fprintf(stderr, "%s <file>", argv[0]);
    return 0;
  }

  size_t size = 0;
  char * str = orka_load_whole_file(argv[1], &size);

  fprintf(stderr, "raw string size\t%zu\n", size);
  size_t new_size = 0;
  char * estr = json_string_escape(&new_size, str, size);

  fprintf(stderr, "escaped size\t%zu\n", new_size);
  //fprintf(stderr, "escaped string %.*s\n", new_size, estr);

  size_t unstr_size = 0;
  char * unstr = NULL;
  json_string_unescape(&unstr, &unstr_size, estr, new_size);

  fprintf(stderr, "unescaped size\t%zu\n", unstr_size);

  if (0 != memcmp(str, unstr, size)) {
    fprintf(stderr, "escaping/unescaping failed\n");
  }

  char s [100] = {'\\', 'u', 'd', '8', '3', 'd',
                  '\\', 'u', 'd', 'c', 'a', 'c',
                  0};

  fprintf (stderr, "%s\n", s);
  json_string_unescape(&unstr, &unstr_size, s, strlen(s));
  estr = json_string_escape(&new_size, unstr, unstr_size);

  fprintf(stderr, "%s\n", unstr);
  fprintf(stderr, "%s\n", estr);
  fprintf(stderr, "%c\n", 0x1F);
  return 0;
}
