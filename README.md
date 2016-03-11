# lttng_cmake_basics
lttng-ust integrated with CMake - the basic setup

# following the lttng-ust man page
https://lttng.org/man/3/lttng-ust/
lttng create myConsoleSession
lttng enable-event -u --tracepoint tpProvider:*
lttng enable-event -u --tracepoint lttng_ust_tracef:*
lttng add-context -u --type pthread_id
lttng start
<execute Command>
lttng stop

One command for all
CMD=./mainToBeTraced SESSION=myConsoleSession; lttng destroy $SESSION;lttng create $SESSION; lttng enable-event -u --tracepoint tpProvider:*; lttng enable-event -u --tracepoint lttng_ust_tracef:*; lttng add-context -u --type pthread_id; lttng start; $CMD; lttng stop; lttng view

## further links
http://lttng.org/docs/#doc-liblttng-ust-cyg-profile
