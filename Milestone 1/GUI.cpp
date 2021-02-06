//
// Created by santi on 2/5/2021.
//
//
// Created by santi on 2/5/2021.
//
#include <iostream>
#include <string>
#include <map>
#include "CPU.cpp"
using namespace std;

void GUI(){
//post welcome message and instructions
    cout << "**** Welcome to UV SIM! ****\n" <<
         "**** Please enter your program one instruction ****\n" <<
         "**** (or data word) at a time into the input   ****\n" <<
         "**** text field. I will display the location   ****\n" <<
         "**** and a question mark (?). You then         ****\n" <<
         "**** type the word for that location. Enter    ****\n" <<
         "**** -99999 to stop entering your program      ****" << endl;

    //initialize map
    map<size_t,string> inputMap;

    for(int i = 0; i < 100; i++){
        string line;
        if (i < 10) line = "0" + to_string(i);
        else line = i;
        cout << line + " ? ";

        //gather user input
        string uInput;
        cin >> uInput;

        //place user input into map
        inputMap[i] = uInput;

        //stop gathering if user types -99999
        if (uInput == "-99999") break;
    }

    /* test output
    for (auto input : inputMap){
        cout << input.first << ": " << input.second << endl;
    }

    int end;
    cin >> end;
    */

    /* pass to CPU
    CPU(inputMap);
    */
}



