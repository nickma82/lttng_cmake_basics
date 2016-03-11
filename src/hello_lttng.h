#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER hello_world


#if !defined(_HELLO_TP_H) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define _HELLO_TP_H

#include <lttng/tracepoint.h>

TRACEPOINT_EVENT(
	/* tracepoint provider name */
	hello_world,

	/* tracepoint/event name */
	my_first_tracepoint,
	/* list of tracepoint arguments */
    TP_ARGS(
        int, my_integer_arg,
        char*, my_string_arg
    ),
	/* list of fields of eventual event  */
    TP_FIELDS(
        ctf_string(my_string_field, my_string_arg) //NOTE that there are no commas separating TP_FIELDS
        ctf_integer(int, my_integer_field, my_integer_arg)
    )
)

#endif /* _HELLO_TP_H */

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "hello_lttng.h"

#include <lttng/tracepoint-event.h>
