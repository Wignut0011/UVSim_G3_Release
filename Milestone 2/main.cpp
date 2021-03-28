#include "CONTROLLER.h"
#include <stdexcept>
#include <iostream>

int main(){
    VIEW view;
    MODEL model((VIEW&)view);
    CONTROLLER controller((MODEL&)model, (VIEW&)view);
    try{controller.StartSimulator();}
    catch (std::runtime_error &err) {
        std::cout << "\nFATAL ERROR: " << err.what() << "\nEXITING...\n";
    }
    return 0;
}

