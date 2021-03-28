//Includes
#include "MemoryDump.h"
#include "CPU.h"
#include "VIEW.h"

class MODEL{
    VIEW view;

public:
    MODEL(VIEW &v): view(v){};

    //variables
    string userNum;
    int currentPage;

    //functions
    bool hasMemory(){
        for(pair<size_t, string> element : inputMap){
            if(element.first != NULL){
                return true;
            }
        }
    }
    void updateMenu(int);

    void loadMemory(MEMORY);
    void updateMemory(string opcode, int memLocation){
        Memory.add(opcode, memLocation);
    }
};

class MEMORY{
public:
    MEMORY(){
        map<size_t, string> inputMap;
    };
    //variables
    bool done = false;
    int mapSize = 100;
    string uInput;
    string line;

    //functions
    void remove(int){
        for(pair<size_t, string> element : inputMap){
            if(element.second == int){ ///typecast issue
                element.first = ""; ///typecast issue
            }
        }
    };

    void add(string uInput, int memLocation){
        for(pair<size_t, string> element : inputMap){
            if(element.first == " "){
                element.first = uInput;
                element.second = memLocation;
            }
        }
    };

    map getter(){
        return map;
    }

private:

};