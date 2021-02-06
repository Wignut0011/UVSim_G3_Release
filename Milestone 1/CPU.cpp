//
// Created by santi on 2/5/2021.
//
//
// Created by santi on 2/5/2021.
//
#include <map>
#include <iostream>
#include <string>
using namespace std;

void CPU(map<size_t,string> inputMap){  //here is the map.
    //create loop that takes input and performs function based on input
    for(int i = 0; i < 100; i++){

        string line = inputMap[i];
        //stop gathering if user types -99999
        if (line == "-99999") break;

        string instruction = to_string(line[1] + line[2]);
        int test = stoi(instruction);
        //switch/case for each instruction
        switch(test){
            case 10:
                //Read();  Read a word from the keyboard into a specific location in memory
                //From TestCase 1
                //read command; integer 29 into memory location 07

                //read command; integer 34 into memory location 08
                cout << "read";
                break;
            case 11:
                //Write();   Write a word from a specific location in memory to screen
                //write command; take memory location 09 and give it to the screen to print.
                cout << "Write";
                break;
            case 20:
                //Load();    Load a word from a specific location in memory into the accumulator
                //load command; integer from location 07 is loaded into accumulator
                // ===== we then have the add command to memory location 08
                cout << "Load";
                break;
            case 21:
                //Store();   Store a word from the accumulator into a specific location in memory
                //store command; take the added number and store it in the memory location 09
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

