# lttng CMake basics
lttng-ust integrated with CMake - A basic setup

This project should provide a kind of first steps how to, to lttng.

# following the lttng-ust man page
https://lttng.org/man/3/lttng-ust/

lttng create myConsoleSession </br>
lttng enable-event -u --tracepoint tpProvider:* </br>
lttng enable-event -u --tracepoint lttng_ust_tracef:* </br>
lttng add-context -u --type pthread_id </br>
lttng start </br>
\<execute Command> </br>
lttng stop

One command cobinig all above </br>
CMD=./mainToBeTraced SESSION=myConsoleSession; lttng destroy $SESSION;lttng create $SESSION; lttng enable-event -u --tracepoint tpProvider:*; lttng enable-event -u --tracepoint lttng_ust_tracef:*; lttng add-context -u --type pthread_id; lttng start; $CMD; lttng stop; lttng view

## further links
http://lttng.org/docs/#doc-liblttng-ust-cyg-profile

## preConditions
http://lttng.org/docs/#doc-installing-lttng

Debian:
apt-get install liblttng-ust-dev python3-babeltrace


## Building
To build it, change into a build directory [mkdir build; cd build] setup cmake [cmake ../src] and build it [make]
