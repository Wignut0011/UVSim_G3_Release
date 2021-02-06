#include <map> //Memory
#include <algorithm> //If needed
#include <iostream>
#include <string>

using namespace std;

class CPU {
    int accumulator; //The singular register
    map<int, string> memory; //Our memory <line#, instruction>

public:
    //----------------
    // EXECUTION MODE
    //----------------


    //Constructor
    CPU(map<int,string> inputMap): memory(std::move(inputMap)) {

        //For loop to imitate a cpu clock
        for (int i = 0; i < 100; i++) {
            size_t opcode;
            int operand;

            string line = memory.at(i);
            //stop gathering if user types -99999
            if (line == "-99999") break;

            opcode = abs(stoi(line.substr(0,1))); //Extract opcode substring
            operand = stoi(line.substr(2)); //Extract operand substring

            //switch/case for each instruction
            switch (opcode) {
                case 10:
                    //Read();
                    cout << "read";
                    break;
                case 11:
                    //Write();
                    cout << "Write";
                    break;
                case 20:
                    //Load();
                    cout << "Load";
                    break;
                case 21:
                    //Store();
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
                    //Branch

                //BRANCH
                case 40:
                    //Branch to address in operand
                    i = abs(operand) - 1;
                    break;

                //BRANCHNEG
                case 41:
                    if (accumulator < 0) //If accumulator is negative, branch to address
                        i = abs(operand) - 1;
                    break;

                //BRANCHZERO
                case 42:
                    switch (accumulator) {
                        case 0: //If accumulator is 0, branch to address
                            i = abs(operand) - 1;
                            break;

                        default:
                            break;//If not 0, then return 0
                    }

                //HALT
                case 43:
                    i = 99;
                    break;

                //INVALID OPCODE
                default:
                    cout << "ERROR: Invalid operation '" << opcode << "' at line" << i << ". "<<
                    "Please review valid instructions in readme.txt\nEnding program..." << endl;
                    i = 99;
                    break;
            }
        }
    }
};