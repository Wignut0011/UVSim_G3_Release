#include <iostream>
#include <string>
#include <map>
#include "CPU.cpp"
using namespace std;

void MemDump(map<size_t,string> inputMap){
    cout << "       00     01     02     03     04     05     06     07     08     09" << endl;
    string line;
    for (int i = 0; i < 100; i++){
        if (i % 10 == 0){
            if (i == 0){
                line = "00";
            }
            else {
                line = to_string(i);
            }
        }
        string memory = inputMap[i];
        int addZero =  5 - int(memory.length());
        for(int j = 0; j < addZero; j++){
            memory.insert(0,"0");
        }
        line += "  " + memory;
        if (i % 10 == 9){
            cout << line << endl;
        }
    }
}

void GUI () {
//post welcome message and instructions
    cout << "**** Welcome to UV SIM! ****\n" <<
         "**** Please enter your program one instruction ****\n" <<
         "**** (or data word) at a time into the input   ****\n" <<
         "**** text field. I will display the location   ****\n" <<
         "**** and a question mark (?). You then         ****\n" <<
         "**** type the word for that location. Enter    ****\n" <<
         "**** -99999 to stop entering your program      ****" << endl;
    //initialize map
    map<size_t, string> inputMap;
    for (int i = 0; i < 100; i++) {
        string line;
        if (i < 10) line = "0" + to_string(i);
        else line = to_string(i);
        cout << line + " ? ";
        //gather user input
        string uInput;
        cin >> uInput;
        //stop gathering if user types -99999
        if (uInput == "-99999") break;

        //place user input into map
        inputMap[i] = uInput;

        //stop gathering if user types -99999
        if (uInput == "-99999") break;
    }

    //call CPU and send inputMap to it.

    MemDump(inputMap);
}