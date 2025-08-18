#define HL_NAME(n) hello_##n

#include <hl.h>
#include "lib.h"

//------ get_greeting()

HL_PRIM vbyte* HL_NAME(get_greeting)(_NO_ARG)
{

	const uchar* text = USTR("Hello from c! äöü : inline string");

	hl_buffer* b = hl_alloc_buffer();
	hl_buffer_str(b, text);
	vbyte* greeting = (vbyte*)hl_buffer_content(b, NULL);

	return greeting;
}

DEFINE_PRIM(_BYTES, get_greeting, _NO_ARG);

//------ get_greeting_from_chars()

HL_PRIM vbyte* HL_NAME(get_greeting_from_chars)(_NO_ARG)
{
	const char* text = getGreeting();
	const uchar* utext = (uchar*)text;

	hl_buffer* b = hl_alloc_buffer();
	hl_buffer_str(b, utext);
	vbyte* greeting = (vbyte*)hl_buffer_content(b, NULL);

	return greeting;
}

DEFINE_PRIM(_BYTES, get_greeting_from_chars, _NO_ARG);

//------ greet_me(text)

HL_PRIM void HL_NAME(greet_me)(vstring *text)
{
	char *ctext = hl_to_utf8(text->bytes);
	greetMe(ctext);
}

DEFINE_PRIM(_VOID, greet_me, _STRING)
