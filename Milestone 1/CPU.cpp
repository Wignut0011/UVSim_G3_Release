#include <map> //Memory
#include <algorithm> //If needed
#include <iostream>

using namespace std;

class CPU{
public:
    //----------------
    // EXECUTION MODE
    //----------------

private:
    //----------------
    //   OPERATIONS
    //----------------

    // IO

    // Read/Write

    // Arithmetic

    // Branches

    //Branch
    void Branch(int operand, size_t &PC){
        //Branch to address in operand
        PC = abs(operand)-1;
    }

    //BranchNeg
    void BranchNeg(int operand, size_t &PC){
        if(accumulator < 0) //If accumulator is negative, branch to address
            PC = abs(operand)-1;
    }

    //BranchZero
    void BranchZero(int operand, size_t &PC){
        switch (accumulator) {
            case 0: //If accumulator is 0, branch to address
                PC = abs(operand)-1;
                break;

            default: //If not 0, then return 0
                break;
        }
    }

    //Halt
    void Halt(size_t &PC) {
        PC = 99; //Skip to end of memory to end program
    }
};