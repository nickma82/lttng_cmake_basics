# lttng_cmake_basics
lttng-ust integrated with CMake - the basic setup

# following the lttng-ust man page
# https://lttng.org/man/3/lttng-ust/
lttng create myConsoleSession
lttng enable-event -u --tracepoint hello_world:*
lttng add-context --userspace --type pthread_id
lttng start
<execute Command>
lttng stop

## further links
http://lttng.org/docs/#doc-liblttng-ust-cyg-profile
