<<<<<<< HEAD
#include <map> //Memory
#include <string>
#include <algorithm> //If needed
#include <iostream>

using namespace std;

class CPU {
    int accumulator; //The singular register
    string userNum; //String for user I/O prompts
    map<int, string> memory; //Our memory <line#, instruction>

public:
    //----------------
    // EXECUTION MODE
    //----------------

    explicit CPU(map<int,string> inputMap): memory(std::move(inputMap)) {
		
        accumulator = 0;


    //Constructor
    CPU(map<int,string> inputMap): memory(std::move(inputMap)) {

        //For loop to imitate a cpu clock
        for (int i = 0; i < 100; i++) {
            size_t opcode;
            int operand;

            string line = memory.at(i);
            //stop gathering if user types -99999
            if (line == "-99999") break;
			
			// grabs Integer sign
            bool sign;
            if (line[0] == '+') sign = true;
            else if (line[0] == '-') sign = false;
            else
            {
                cout << "Invalid sign at line: " << i << endl;
                break;
            }
            //cout << "Sign: " << sign << endl;

            //==========================================================
            //   Gets the instruction code to be used in the switch
            opcode = abs(stoi(line.substr(0,1))); //Extract opcode substring
            //==========================================================
            //   Gets the data code to be used in the switch
            operand = stoi(line.substr(2)); //Extract operand substring
            //=========================================================
            //   Possibly a code block to find the location of each
            //      operand as we are going through the code.
            //=========================================================

            //switch/case for each instruction
            switch (opcode) {
                case 10:
                    //Read();
                    //1007 = grab first input from the user and put it into desired memory location
                    cout << "Enter an integer: ";
                    cin >> userNum;
                    inputMap[operand] = userNum;
                    break;
					
                case 11:
                    //Write();
					//write command; take memory location 09 and give it to the screen to print.
                    cout << "Contents of " << operand << "is " << inputMap[operand];
                    break;

                case 20:
                    //Load();    Load a word from a specific location in memory into the accumulator
                    //load command; integer from location 07 is loaded into accumulator
                    accumulator = stoi(inputMap[operand]);
                    break;
					
                case 21:
                    //Store();   Store a word from the accumulator into a specific location in memory
                    //store command; take the added number and store it in the memory location 09
                    inputMap[operand] = to_string(accumulator);
                    break;
					
                case 30:
                    //Add();
                    if (sign) accumulator += stoi(inputMap[operand]);
                    else accumulator -= stoi(inputMap[operand]);
                    break;
					
                case 31:
                    //Subtract();
                    if (sign) accumulator -= stoi(inputMap[operand]);
                    else accumulator += stoi(inputMap[operand]);
                    break;
					
                case 32:
                    //Divide();
                    accumulator /= stoi(inputMap[operand]);
                    if (!sign) accumulator *= -1;
                    break;
					
                case 33:
                    //Multiply();
                    accumulator *= stoi(inputMap[operand]);
                    if (!sign) accumulator *= -1;
                    break;

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
                            i = 99;
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
            cout << "Accumulator: " << accumulator << endl;
        }
    }
};
