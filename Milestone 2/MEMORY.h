//
// Created by Dan5h on 3/20/2021.
//

#ifndef MILESTONE_2_MEMORY_H
#define MILESTONE_2_MEMORY_H
class MEMORY{
public:
    //initialize map
    map<size_t, string> inputMap;


    ///size_t is an int value, and that acts as the key for our map 0-99
    void add(string uInput, int memLocation) {
        inputMap[memLocation] = uInput;
    };

    ///need to figure out this error.
    map getMap(){
        return inputMap;
    }

};
#endif //MILESTONE_2_MEMORY_H
