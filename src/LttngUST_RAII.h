#ifndef EFFICIENT_LF_BST_LTTNGUST_RAII_H
#define EFFICIENT_LF_BST_LTTNGUST_RAII_H

#include <string>

class LttngUST_RAII {
    const std::string _sessionName = "myConsoleSession";
    const std::string _tracePointName = "tpProvider";
public:
    LttngUST_RAII();

    ~LttngUST_RAII();
};

#endif //EFFICIENT_LF_BST_LTTNGUST_RAII_H
