#include "CONTROLLER.h"
#include <stdexcept>
#include <iostream>

int main(){
    VIEW view;
    MODEL model(view);
    CONTROLLER controller(model, view);
    try{controller.StartSimulator();}
    catch (std::runtime_error &err) {
        std::cout << err.what() << "\nEXITING...\n";
    }
    return 0;
}

