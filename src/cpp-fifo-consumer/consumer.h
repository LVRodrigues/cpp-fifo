#ifndef CPP_FIFO_CONSUMER
#define CPP_FIFO_CONSUMER

#include <iostream>
#include <fstream>
#include <string>

class Consumer {
        std::string node;
    public:
        Consumer(std::string node);
        virtual ~Consumer();
        std::string read();
};

#endif          // CPP_INFO_CONSUMER