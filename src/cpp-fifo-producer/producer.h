#ifndef CPP_FIFO_PUBLISHER
#define CPP_FIFO_PUBLISHER

#include <iostream>
#include <fstream>
#include <string>

class Producer {
        std::string node;
        void prepare();
    public:
        Producer(std::string node);
        virtual ~Producer();

        void write(std::string value);
};

#endif         // CPP_FIFO_PUBLISHER