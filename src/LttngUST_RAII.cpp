
#include "LttngUST_RAII.h"

#include <lttng/tracef.h>
#include <vector>

LttngUST_RAII::LttngUST_RAII() {
    std::vector<std::string> initSequence{
            "lttng destroy " + _sessionName,
            "lttng create " + _sessionName,
            "lttng enable-event --userspace --tracepoint " + _tracePointName + ":*",
            //register tracef listener
            "lttng enable-event --userspace --tracepoint lttng_ust_tracef:*",
            "lttng add-context --userspace --type pthread_id",
            "lttng start"
    };

    for (auto each: initSequence) {
        std::system(each.c_str());
    }
    tracef("lttng setup");
}

LttngUST_RAII::~LttngUST_RAII() {
    //tearDown
    tracef("lttng tearing down");

    std::system(std::string("lttng stop " + _sessionName).c_str());
}
