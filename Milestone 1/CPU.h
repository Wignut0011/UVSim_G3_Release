#include <map> //Memory
#include <string>
#include <algorithm> //If needed
#include <iostream>

using namespace std;

#ifndef MILESTONE_1_CPU_H
#define MILESTONE_1_CPU_H

class CPU {
    int accumulator; //The singular register
    string userNum; //String for user I/O prompts
    //map<std::size_t , string> memory; //Our memory <line#, instruction>

public:
    //----------------
    // EXECUTION MODE
    //----------------

    explicit CPU(map<size_t ,string> &memory){

        accumulator = 0;

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
            opcode = abs(stoi(line.substr(1,2))); //Extract opcode substring
            //==========================================================
            //   Gets the data code to be used in the switch
            operand = stoi(line.substr(3)); //Extract operand substring
            // Put sign in operand
            if (line[0] == '-')
                operand *= -1;

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

                    //Add sign to input if user did not
                    if (userNum[0] != '+' && userNum[0] != '-')
                        userNum.insert(0, "+");

                    memory[operand] = userNum;
                    break;

                case 11:
                    //Write();
                    //write command; take memory location 09 and give it to the screen to print.
                    cout << "Contents of " << operand << " is " << StrToInt(memory[operand]) << endl;
                    break;

                case 20:
                    //Load();    Load a word from a specific location in memory into the accumulator
                    //load command; integer from location 07 is loaded into accumulator
                    accumulator = StrToInt(memory[operand]);
                    break;

                case 21:
                    //Store();   Store a word from the accumulator into a specific location in memory
                    //store command; take the added number and store it in the memory location 09
                    memory[operand] = to_string(accumulator);

                    //Add sign to word
                    if (accumulator >= 0)
                        memory[operand].insert(0, "+");

                    break;

                case 30:
                    //Add();
                    //Extract number with sign
                    if (sign) accumulator += StrToInt(memory[operand]);
                    else accumulator -= StrToInt(memory[operand]);
                    break;

                case 31:
                    //Subtract();
                    //Extract number with sign
                    if (sign) accumulator -= StrToInt(memory[operand]);
                    else accumulator += StrToInt(memory[operand]);
                    break;

                case 32:
                    //Divide();
                    accumulator /= StrToInt(memory[operand]);
                    if (!sign) accumulator *= -1;
                    break;

                case 33:
                    //Multiply();
                    accumulator *= StrToInt(memory[operand]);
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
                    //If accumulator is 0, branch to address
                    if (!accumulator)
                        i = abs(operand) - 1;
                    break;

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
            //cout << "Accumulator: " << accumulator << endl;
        }
    }

    // Returns signed int from string
    //*stoi() doesn't like strings that have '+' or '-'
    int StrToInt(string word){
        int y = stoi(word.substr(1));
        if (word[0] == '-') //Grab number sign
            return(y * -1);
        return y;
    };
};

#endif //MILESTONE_1_CPU_H
