#define HL_NAME(n) hello_##n

#include "lib.h"
#include <hl.h>

//------ get_string()

HL_PRIM vbyte *HL_NAME(get_string)(_NO_ARG) {

  const uchar *text = USTR("Hello from c! äöü : inline string");

  hl_buffer *b = hl_alloc_buffer();
  hl_buffer_str(b, text);
  vbyte *string = (vbyte *)hl_buffer_content(b, NULL);

  return string;
}

DEFINE_PRIM(_BYTES, get_string, _NO_ARG);

//------ get_string_from_chars()

HL_PRIM vbyte *HL_NAME(get_string_from_chars)(_NO_ARG) {
  const char *text = getString();
  const uchar *utext = (uchar *)text;

  hl_buffer *b = hl_alloc_buffer();
  hl_buffer_str(b, utext);
  vbyte *string = (vbyte *)hl_buffer_content(b, NULL);

  return string;
}

DEFINE_PRIM(_BYTES, get_string_from_chars, _NO_ARG);

//------ pass_string(text)

HL_PRIM void HL_NAME(pass_string)(vstring *text) {
  const char *ctext = hl_to_utf8(text->bytes);
  passString(ctext);
}

DEFINE_PRIM(_VOID, pass_string, _STRING)

//------ get_integer()

HL_PRIM int HL_NAME(get_integer)(_NO_ARG) {
  return getInteger();
}

DEFINE_PRIM(_I32, get_integer, _NO_ARG);

//------ pass_integer(integer)

HL_PRIM void HL_NAME(pass_integer)(int *integer) {
  passInteger(integer);
}

DEFINE_PRIM(_VOID, pass_integer, _I32);

// get_strings_static

HL_PRIM varray* HL_NAME(get_strings_static)(_NO_ARG) {
  int length;
  const char **strings = getStringsStatic(&length);
  printf("%d length of strings\n", length);

  varray* a = hl_alloc_array(&hlt_bytes, length);
	int i;
	for (i = 0; i < length; i++)
	{
    const char *text = strings[i];
    const uchar *utext = (uchar *)text;
    hl_buffer *b = hl_alloc_buffer();
    hl_buffer_str(b, utext);
		hl_aptr(a, vbyte*)[i] = (vbyte *)hl_buffer_content(b, NULL);
	}

	return a;
}

DEFINE_PRIM(_ARR, get_strings_static, _NO_ARG);