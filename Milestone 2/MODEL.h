//Includes
#include "MemoryDump.h"
#include "CPU.h"
#include "VIEW.h"
#include "MEMORY.h"

class MODEL{

public:
    MEMORY memory;
    CPU cpu;
    MODEL& model;
    VIEW& view;
    MemDump& memDump;

    //variables
    string userNum;
    int currentPage;

    //functions
    bool hasMemory(){
        if(memory.inputMap[0] != " "){
            return true;
        }
    }

    ///TODO
    void runCPU(){
        runCPU();
        memDump.createDump((cpu));
    }

    ///not totally sure what this is supposed to accomplish yet. I think I got it though.
    void updateMenu(int page){
        if(page == 6){
            if(hasMemory() == true){
                view.ContinueEdit(memory);
            }
        }
        view.Display(page);


    };

    void loadMemory(MEMORY);  ///this function is probably not needed.

    void updateMemory(string uInput, int memLocation){
        ///this is going to call on memory.h to make things add to memory
        ///memlocation is going to be from 0-99
        memory.add(uInput, memLocation);
    }
};