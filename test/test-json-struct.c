#include <stdio.h>
#include <string.h>

#include "json-struct.c"
#include "json-scanf.h"

int main (int argc, char **argv)
{
  char *spec = \
    "{ |disabled|:false,\n"
      "|namespace|: [ |A|, |B| ],\n"
      "|comment|: |url|,\n"
      "|defs|:\n"
      "[\n"
      "  {\n"
      "    |namespace|:[|C|],\n"
      "    |struct|:|dati|,\n"
      "    |fields|:\n"
      "    [\n"
      "      { |name|:|f1_str|, |type|:{ |base|:|char|, |dec|:|*| }, |comment|:| this is field f1 | },\n"
      "      { |name|:|f2_str|, |type|:{ |base|:|char|, |dec|:|*| } },\n"
      "      { |name|:|f3_int|, |type|:{ |base|:|int|, |c_base|:|code| } },\n"
      "      { |name|:|fx_todo|, |todo|:true, |type|:{ |base|:|int|, |c_base|:|code| } },\n"
      "      { |name|:|f4|, |type|:{ |base|:|s_as_u64| } },\n"
      "      { |name|:|c_f5|, |json_key|:|f5 asdfasdf |, |type|:{ |base|:|char|, |dec|:|*| } },\n"
      "      { |name|:|f6_carray|, |type|:{ |base|:|char|, |dec|:|[10]| } },\n"
      "      { |name|:|f7_ntl|, |type|:{ |base|:|int|, |dec|:|ntl| } },\n"
      "      { |name|:|f8_ntl|, |type|:{ |base|:|emoji::dati|, |dec|:|ntl| } },\n"
      "      { |name|:|f9_todo|, |todo|:true, |type|:{ |base|:|emoji::dati|, |dec|:|ntl| } },\n"
      "      { |name|:|f10|, |todo|:false, |type|:{ |base|:|emoji::dati|, |dec|:|*| } },\n"
      "      { |name|:|f11|, |type|:{ |base|:|char|, |dec|:|*|, |converter|:|iso8601| } },\n"
      "      { |name|:|f12|, |type|:{ |base|:|char|, |dec|:|*|}, |inject_if_not|:null },\n"
      "      { |name|:|f13|, |type|:{ |base|:|char|, |dec|:|[12]|}, |inject_if_not|:|| },\n"
      "      { |name|:|f14|, |type|:{ |base|:|char|, |dec|:|*|, |converter|:|iso8601|}, |inject_if_not|:10 },\n"
      "    ]\n"
      "  }\n"
      " ,{"
      "    |namespace|:[|C|],"
      "    |namespaces|:[[|A|], [|B|]],"
      "    |enum|:|enum1|,"
      "    |items|:"
      "    ["
      "      { |name|:|e1|, |value|:1 },"
      "      { |name|:|e2| },"
      "      { |name|:|e4|, |value|:100 },"
      "      { |name|:|e5| },"
      "      { |name|:|e6| },"
      "    ]"
      "  }"
      "]"
      "}";

  char *s;
  size_t len=0;
  if (argc == 2) {
    s = cee_load_whole_file(argv[1], &len);
  }
  else {
    json_asprintf(&s, spec);
    len = strlen(s);
  }

  struct jc_definition d;
  memset(&d, 0, sizeof(d));
  spec_name = "<string>";
  spec_buffer.start = s;
  spec_buffer.size = len;
  definition_from_json(s, len, &d);
  print_definition(stderr, &d);
  struct emit_option eo = { .type = FILE_SINGLE_FILE };
  gen_definition(NULL, "", &eo, &d);

  char *ns ="["
    "[\"A\", \"B\"],"
    "[\"A\", \"B\"],"
    "[\"1\", \"2\"]"
    "]";

  NTL_T(NTL_T(name_t)) namespaces=NULL;
  struct ntl_deserializer d0_alias = {
    .elem_size = sizeof(void*),
    .elem_from_buf = (vcpsvp)namespace_from_json,
    .init_elem = NULL,
    .ntl_recipient_p = (ntl_t *)&namespaces
  };
  extract_ntl_from_json(ns, strlen(ns), &d0_alias);
  fprintf(stderr, "%zu\n", ntl_length((ntl_t)namespaces));
  fprintf(stderr, "%zu\n", ntl_length((ntl_t)*(namespaces[0])));

  return 0;
}
