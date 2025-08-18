#define HL_NAME(n) hello_##n

#include "lib.h"
#include <hl.h>

//------ get_greeting()

HL_PRIM vbyte *HL_NAME(get_greeting)(_NO_ARG) {

  const uchar *text = USTR("Hello from c! äöü : inline string");

  hl_buffer *b = hl_alloc_buffer();
  hl_buffer_str(b, text);
  vbyte *greeting = (vbyte *)hl_buffer_content(b, NULL);

  return greeting;
}

DEFINE_PRIM(_BYTES, get_greeting, _NO_ARG);

//------ get_greeting_from_chars()

HL_PRIM vbyte *HL_NAME(get_greeting_from_chars)(_NO_ARG) {
  const char *text = getGreeting();
  const uchar *utext = (uchar *)text;

  hl_buffer *b = hl_alloc_buffer();
  hl_buffer_str(b, utext);
  vbyte *greeting = (vbyte *)hl_buffer_content(b, NULL);

  return greeting;
}

DEFINE_PRIM(_BYTES, get_greeting_from_chars, _NO_ARG);

//------ greet_me(text)

HL_PRIM void HL_NAME(greet_me)(vstring *text) {
  const char *ctext = hl_to_utf8(text->bytes);
  greetMe(ctext);
}

DEFINE_PRIM(_VOID, greet_me, _STRING)

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