#include <stdio.h>

#define TRACEPOINT_CREATE_PROBES
#define TRACEPOINT_DEFINE
#include "hello_lttng.h"



void sampleTraceCalls(int argc, char *const *argv) {
	/*
	 * A tracepoint() call. Arguments, as defined in hello-tp.h:
	 *
	 *     1st: provider name (always)
	 *     2nd: tracepoint name (always)
	 *     3rd: my_integer_arg (first user-defined argument)
	 *     4th: my_string_arg (second user-defined argument)
	 *
	 * Notice the provider and tracepoint names are NOT strings;
	 * they are in fact parts of variables created by macros in
	 * hello-tp.h.
	 */
	tracepoint(tpProvider, my_first_tracepoint, 23, "hi there!");

	int x;
	for (x = 0; x < argc; ++x) {
		tracepoint(tpProvider, my_first_tracepoint, x, argv[x]);
	}

	tracepoint(tpProvider, my_first_tracepoint, x * x, "x^2");
}

int main(int argc, char *argv[]) {

	//puts("Hello, World!\nPress Enter to continue...");

	/*
	 * The following getchar() call is only placed here for the purpose
	 * of this demonstration, for pausing the application in order for
	 * you to have time to list its events. It's not needed otherwise.
	 */
	//getchar();

	sampleTraceCalls(argc, argv);

	puts("Quitting now!");

	return 0;
}

