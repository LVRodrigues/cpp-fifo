#include "consumer.h"

#include <iostream>
#include <sys/stat.h>
#include <unistd.h>

Consumer::Consumer(std::string node) {
    this->node = node;
}

Consumer::~Consumer() {
    unlink(this->node.c_str());
}

std::string Consumer::read() {
    static std::string result = "";
    std::ifstream pipe = std::ifstream(this->node, std::ifstream::in);
    getline(pipe, result);
    pipe.close();
    return result;
}