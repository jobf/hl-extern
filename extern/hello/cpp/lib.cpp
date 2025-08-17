
// #ifdef HASHLINK using this guard did not work, I couldn't get the define through to the compile via build.xml

#define HL_NAME(n) hello_##n

#include <hl.h>

HL_PRIM vbyte* HL_NAME(get_greeting)(_NO_ARG)
{
	hl_buffer* b = hl_alloc_buffer();
	hl_buffer_str(b, USTR("hello from C"));

	vbyte* greeting = (vbyte*)hl_buffer_content(b, NULL);

	return greeting;

}

DEFINE_PRIM(_BYTES, get_greeting, _NO_ARG);

// #endif