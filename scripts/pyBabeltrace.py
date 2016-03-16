#!/usr/bin/python3
### This application reformates raw lttng ouput
### Usage: ./pyBabeltrace ~/lttng-traces/myConsoleSession-<DATEandTIME>/ust/uid/1000/64-bit
## See: http://diamon.org/babeltrace/docs/python/examples/#reader-api-examples

from datetime import datetime
from collections import Counter
import babeltrace
import sys

tracepointProviderToCatch = 'my_first_tracepoint'

# a trace collection holds one or more traces
col = babeltrace.TraceCollection()

# add the trace provided by the user (first command line argument)
# (LTTng traces always have the 'ctf' format)
if col.add_trace(sys.argv[1], 'ctf') is None:
    raise RuntimeError('Cannot add trace')

# this counter dict will hold execution times:
#
#   task command name -> total execution time (ns)
exec_times = Counter()

# this holds the last `sched_switch` timestamp
last_ts = None

# iterate on all LTTNG events
for event in col.events:
	#print all available keys (defined in the TRACEPOINT_EVENT's)
	#print(', '.join(event.keys()))

	#extract human readable timestamp
	readableTime = ''
	if 'timestamp_begin' in event:
		tmpTime = datetime.fromtimestamp(event.timestamp // 1000000000)
		readableTime = tmpTime.strftime('%H:%M:%S')
		readableTime += '.' + str(int(event.timestamp % 1000000000)).zfill(9)



	#for a fprint: timestamp_begin, pthread_id, msg
	#for a cas: rc, casData, timestamp_begin, position, pthread_id, threadAlias, k
	if tracepointProviderToCatch in event.name:
		print("[%s] tracepointProviderToCatchPrint: %s, %s" %
			(readableTime,
				event['my_string_field'], event['my_integer_field']
			))
		
		continue

	if 'tracef' in event.name:
		print("[%s] Msg: %s" % (readableTime, event['msg']))
		

		continue
