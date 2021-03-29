//
// Created by Dan5h on 3/20/2021.
//

#ifndef MILESTONE_2_MEMORY_H
#define MILESTONE_2_MEMORY_H
class MEMORY{
public:
    //initialize map
    map<size_t, string> inputMap;

    void add(string uInput, int memLocation) {
        inputMap[memLocation] = uInput;
    };

    map<size_t, string> getMap(){
        return inputMap;
    }

};
#endif //MILESTONE_2_MEMORY_H
