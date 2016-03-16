#define TRACEPOINT_CREATE_PROBES
#define TRACEPOINT_DEFINE
#include "hello_lttng.h"

#include <lttng/tracef.h>
#include <iostream>
#include "LttngUST_RAII.h"



void sampleTraceCalls(int argc, char *const *argv) {
	/*
	 * A tracepoint() call. Arguments, as defined in hello-tp.h:
	 *
	 *     1st: provider name (always)
	 *     2nd: tracepoint name (always)
	 *
	 *    Every element following now is custom defined in hello_lttng.h::TRACEPOINT_EVENT
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
	auto prepareLttngEnvironment = LttngUST_RAII(); //Automatically starts and stops lttng

	tracef("main is up and running %d", 42);
	sampleTraceCalls(argc, argv);

	std::cout << "Quitting now!" << std::endl;
	return 0;
}

