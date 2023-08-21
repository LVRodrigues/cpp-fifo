#include <cstdlib>
#include <csignal>
#include <iostream>
#include <chrono>
#include <thread>

bool active = true;

void signal_callback(int handle) {
    std::cout << "Signal: " << handle << "." << std::endl;
    active = false;
}

int main(int argc, char const *argv[]) {
    std::cout << "CPP FIFO Producer" << std::endl;

    while (active) {
    
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return EXIT_SUCCESS;
}
