#include <iostream>
using namespace std;

void GUI(){
//post welcome message and instructions
    string welcome = "blah";
    cout << welcome;
//create loop that takes input and performs function based on input
    bool quit = false;
    do {
        string uInput;
        cin >> uInput;
        //test input for proper syntax, return error if not 
        //pull out first two characters of each input to gather instruction, store remaining numbers in another var.
        int test = parseInt(uInput[0] + uInput[1], 10);
        //switch/case for each instruction
        switch(test){
            case 10:
                Read();
                break;
            case 11:
                Write();
                break;
            case 20: 
                Load();
                break;
            case 21: 
                Store();
                break;
            case 30:
                Add();
                break;
            case 31:
                Subtract();
                break;
            case 32:
                Divide();
                break;
            case 33: 
                Multiply();
                break;
            case 40: 
                Branch();
                break;
            case 41: 
                BranchNeg();
                break;
            case 42: 
                BranchZero();
                break;
            case 43: 
                Halt();
                break;
        } while(!quit);
    }

}

