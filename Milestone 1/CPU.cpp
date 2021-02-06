//
// Created by santi on 2/5/2021.
//
//
// Created by santi on 2/5/2021.
//
#include <map>
#include <iostream>

using namespace std;

void CPU(map<size_t,string> inputMap){ //size_t = key   string = data
    int accumulator;
    string userNum;

    //create loop that takes input and performs function based on input
    for(int i = 0; i < 100; i++){

        string line = inputMap[i];
        //stop gathering if user types -99999
        if (line == "-99999") break;

        //==========================================================
        //   Gets the instruction code to be used in the switch
        string instruction = to_string(line[1] + line[2]);
        int test = stoi(instruction);
        //==========================================================
        //   Gets the data code to be used in the switch
        string op1 = to_string(line[3] + line[4]);
        int operand = stoi(op1);
        //=========================================================
        //   Possibly a code block to find the location of each
        //      operand as we are going through the code.
        //=========================================================

        //key of map is integer
        //switch/case for each instruction
        switch(test){
            case 10:
                //Read();
                //1007 = grab first input from the user and put it into desired memory location
                    cout << "Enter an integer: ";
                    cin >> userNum;
                    inputMap[operand] = userNum;
                cout << "read";
                break;
            case 11:
                //Write();
                //write command; take memory location 09 and give it to the screen to print.
                cout << "Contents of " << operand << "is " << inputMap[operand];
                cout << "Write";
                break;
            case 20:
                //Load();    Load a word from a specific location in memory into the accumulator
                //load command; integer from location 07 is loaded into accumulator
                accumulator = stoi(inputMap[operand]);
                cout << "Load";
                break;
            case 21:
                //Store();   Store a word from the accumulator into a specific location in memory
                //store command; take the added number and store it in the memory location 09
                inputMap[operand] = to_string(accumulator);
                cout << "Store";
                break;
            case 30:
                //Add();
                cout << "Add";
                break;
            case 31:
                //Subtract();
                cout << "Subtract";
                break;
            case 32:
                //Divide();
                cout << "Divide";
                break;
            case 33:
                //Multiply();
                cout << "Multiply";
                break;
            case 40:
                //Branch();
                cout << "Branch";
                break;
            case 41:
                //BranchNeg();
                cout << "BranchNeg";
                break;
            case 42:
                //BranchZero();
                cout << "BranchZero";
                break;
            case 43:
                //Halt();
                cout << "Halt";
                break;
        }
    }

}

