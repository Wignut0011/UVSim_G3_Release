#include <map>
using namespace std;

void CPU(map<size_t,string> inputMap){
    //create loop that takes input and performs function based on input
    for(int i = 0; i < 100; i++){

        string line = inputMap[i];
        //stop gathering if user types -99999
        if (line == "-99999") break;
        
        string instruction = line[1] + line[2];
        int test = stoi(instruction);
        //switch/case for each instruction
        switch(test){
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