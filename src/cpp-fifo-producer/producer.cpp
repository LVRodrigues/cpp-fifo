#include "producer.h"

#include <iostream>
#include <sys/stat.h>
#include <unistd.h>

Producer::Producer(std::string node) {
    this->node = node;
    this->prepare();
}

Producer::~Producer() {
    unlink(this->node.c_str());
}

void Producer::write(std::string value) {
    std::ofstream pipe = std::ofstream(this->node, std::ofstream::out);
    pipe << value;
    pipe.flush();
    pipe.close();
}

void Producer::prepare() {
    struct stat stats;
    int result = stat(this->node.c_str(), &stats);
    if (result >= 0) {
        std::cout << "Arquivo de comunicação " << this->node << " já existe. Utilizando-o..." << std::endl;
        return;
    }   
    result = mkfifo(this->node.c_str(), S_IRUSR | S_IWUSR);
    if (result == 0) {
        std::cout << "Arquivo de comunicação " << this->node << " criado com sucesso." << std::endl;
        return;
    }
    throw new std::runtime_error("Falha ao criar o arquivo de comunicação.");
}