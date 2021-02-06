#include <map> //Memory
#include <algorithm> //If needed
#include <iostream>

using namespace std;

class CPU {
public:
    //----------------
    // EXECUTION MODE
    //----------------
    int accumulator;
    map<int, string> memory;


    explicit CPU(map<int,string> inputMap) {
        memory = inputMap;
        accumulator = 0;

        for (int i = 0; i < 100; i++) {
            size_t opcode;
            string line = inputMap[i];

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

            // grabs operator from user input
            string instruction;
            instruction.push_back(line[1]);
            instruction.push_back(line[2]);
            int test = stoi(instruction);
            //cout << "Operator: " << test << endl;

            // grabs operand from user input
            string op1;
            op1.push_back(line[3]);
            op1.push_back(line[4]);
            int operand = stoi(op1);
            //cout << "Operand: " << operand << endl;
            

            inputMap[10] = "10";

            //switch/case for each instruction
            switch (test) {
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
                    cout << "ERROR: Invalid operation at line <" << i << ">.\n Ending program..." << endl;
                    i = 99;
                    break;
            }
            cout << "Accumulator: " << accumulator << endl;
        }
    }
};