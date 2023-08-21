#include <cstdlib>
#include <csignal>
#include <iostream>
#include <chrono>
#include <thread>

#include "consumer.h"

bool active = true;

void signal_callback(int handle) {
    std::cout << "Signal: " << handle << "." << std::endl;
    active = false;
}

int main(int argc, char const *argv[]) {
    std::cout << "CPP FIFO Consumer" << std::endl;
    if (argc < 2) {
        std::cerr << "Informe o nome do arquivo de comunicação." << std::endl;
        return EXIT_FAILURE;
    }

    Consumer consumer(argv[1]);
    while (active) {
        std::string readed = consumer.read();
        std::cout << readed << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return EXIT_SUCCESS;
}
