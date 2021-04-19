#ifndef TEST_DRIVER_H
#define TEST_DRIVER_H
#include <iostream>
#include <sstream>
#include <thread>
#include <string>
#include "test.h"
#include "VIEW.h"
#include "CONTROLLER.h"

using namespace std::chrono_literals;

enum MenuOptions :size_t{README_MEN = 1, EDIT_MEN = 2, LOAD_MEN = 3, SAVE_MEN = 4, EXEC_MEN = 5, EXIT_MEN = 6};
enum SubMenus :size_t{COPY_MEN = 1, CUT_MEN = 2, PASTE_MEN = 3, INSERT_MEN = 4, DELETE_MEN = 5};

string clipboard;
VIEW view(clipboard);
stringstream input;

/*
                            TESTING METHODOLOGY
  -------------------------------------------------------------------------
  Due to simulator relying on cin for input, cin buffer will be replaced with
  a controlled ostream. VIEW.h and MemoryDump.h will be the repurposed for
  relaying information to the test diver, thus, they are dummy repurposed
  classes.

  * DO NOT REPLACE VIEW.h OR MemoryDump.h WITH THE REAL VERSIONS! IF YOU DO
  * BY ACCIDENT, RE-DOWNLOAD FROM DEV OR danBranch OR ASK ME (Daniel) ON
  * DISCORD

  TESTED CLASSES
  -CONTROLLER
  -CPU

  TESTS
  	CONTROLLER
		-Execute StartSimulator and test if at main menu
		 Controller attempts to update view at appropriate times
		    -Requests readme fine
            -Requests Edit fine
		     Error when entering without memory staged or save file present...
		        -Load
		        -Save
		        -Execute
		 Check if Controller loads and saves correctly
			-Save menu is accessed after memory is staged
			-Correct data is displayed in save menu
			-Correct message is displayed when save is successful
			-File has correct data saved
			-Correct message is displayed when staged memory is erased
			-Correctly displays message when load is successful
			-Load was successful
        Check if edit mode sub-menus operate correctly
            -Cut last line
            -Insert to line before last
            -Copy last line
            -Delete last line
            -Paste to last line

	CPU
        -Execute a halt program and check if results are accurate
        -Execute an addition program and check if results are accurate
            9000+1000 = 0001_0000
		 Check if execution is sending correct errors and warnings to VIEW
		    -Overflow warning
		    -Invalid opcode

 */

void testing(){
    MODEL model((VIEW&) view);
    CONTROLLER controller((MODEL&)model, (VIEW&)view, (string&) clipboard);
};

void type(string str){
    std::this_thread::sleep_for(200ms); //Sleep to not run into thread fighting
    input << str << std::endl;
}

int main(){

    const string saveFile = "Save.mem";


    //Change cin buffer for testing
    std::streambuf *CIN_OLD;
    CIN_OLD = std::cin.rdbuf();
    std::cin.rdbuf(input.rdbuf());

    //Init Simulator thread
    std::thread sim (testing);

    ///                    Testing Start
    ///                     CONTROLLER
    ///------------------------------------------------------------


    ///Execute StartSimulator and test if at main menu
    test_(view.currMenu == MAIN);

    //Controller attempts to update view at appropriate times
    //Go to readme
    type(to_string(README_MEN));
    test_(view.currMenu == README_1); ///Requests readme
    type("1"); //Exit Readme

    //Go to edit
    type(to_string(EDIT_MEN));
    test_(view.currMenu == EDIT); ///Requests Edit
    type("-99999");

    //Check if Controller is sending errors to view in...
    //Go to load
    type(to_string(LOAD_MEN));
    test_(view.currMenu == MAIN
            && view.s_Display == to_string(LOAD)+" false"); ///Load Deny
    type("2");

    //Go to save
    type(to_string(SAVE_MEN));
    test_(view.currMenu == MAIN
            && view.s_Display == to_string(SAVE)+" false"); ///Save Deny

    //Go to execute
    type(to_string(EXEC_MEN));
    test_(view.currMenu == MAIN
            && view.s_Display == to_string(EXEC)+" false"); ///Execute Deny

    //Check if Controller loads and saves correctly
    //Go to edit and create one line +4300, exit with +9999, and test hasMemory() by going to save menu
    type(to_string(EDIT_MEN));
    type("+4300");
    type("-99999");
    type(to_string(SAVE_MEN));

    test_(view.currMenu == SAVE); ///Save Allowed

    //Check displayed save contents
    test_(view.s_Display == "+4300"); ///Save Display
    type("1");

    //Save file has correct information
    string saveTest;
    ifstream save(saveFile, ios::in);
    if (save.is_open()) {
        save >> saveTest;
        test_(saveTest == "+4300"); ///File Correctly Saved
    }
    else
        test_(save.is_open()); ///FILE COULD NOT OPEN
    save.close();

    //Change staged memory to check load
    type(to_string(LOAD_MEN));
    test_(view.s_Display == "+4300"); ///Load display
    type("3");
    test_(view.s_Display == "EMTPY"); ///Correct message when erased memory
    type(to_string(EDIT_MEN));
    type("+0000");
    type("-99999");
    type(to_string(LOAD_MEN));
    type("1");
    test_(view.s_Display == (to_string(LOAD) + " true")); ///Load message
    type(to_string(EDIT_MEN));
    test_(view.s_Display == "+4300"); ///Load was correct

    //Check if edit mode sub-menus operate correctly
    type("+0000");
    type("+0001");

    //Cut last line
    type(to_string(CUT_MEN));
    type("02");
    test_(view.clipboard == "+0001" && view.s_Display == "+0000"); /// Test Cut (Line is Only in Clipboard)

    //Insert to line before last
    type(to_string(INSERT_MEN));
    type("01");
    test_(view.s_Display == "+0000"); ///Test Insert (Shifted Lines)

    //Copy last line
    type(to_string(COPY_MEN));
    type("02");
    test_(view.clipboard == "+0000"); ///Test Copy

    //Delete last line
    type(to_string(DELETE_MEN));
    type("02");
    test_(view.s_Display == "+0001"); ///Test Delete

    //Paste to last line
    type("+0000");
    type(to_string(PASTE_MEN));
    type("02");
    test_(view.s_Display == "+0001"); ///Test Paste (Overwrite Line)

    type("-9999");
    type(to_string(LOAD_MEN));
    type("1");

    ///                         CPU
    ///------------------------------------------------------------


    //Execute, and test if result passed
    type(to_string(EXEC_MEN));
    std::this_thread::sleep_for(200ms);
    input << std::endl << std::endl;

    test_((view.s_Display == "END"
            && n_accumulator == 0
            && n_opcode == 43
            && n_operand == 0
            && n_IC == 0
            && n_IR == "+4300")); ///Halt program executed correctly

    std::this_thread::sleep_for(200ms);
    input << std::endl << std::endl;

    //Go to load, erase staged memory, then go to edit
    type(to_string(LOAD_MEN));
    type("3");
    type(to_string(EDIT_MEN));

    //Input addition program and save
    type("+1007"); //0
    type("+1008"); //1
    type("+2007"); //2
    type("+3008"); //3
    type("+2109"); //4
    type("+1109"); //5
    type("+4300"); //6
    type("-99999");

    //Go to execute and compare dump
    type(to_string(EXEC_MEN));
    type("9000");
    type("1000");
    std::this_thread::sleep_for(200ms);
    input << std::endl;

    //CHECK WITH ANTHONY ON IMPLEMENTATION
    test_(n_result[7] == "+9000"
            && n_result[8] == "++1000"
            && n_result[9] == "++0001"
            && n_result[10] == "+0000"); ///Addition Program executed correctly

    //Repeat creating an addition program but put in an warnings and end in an error
    std::this_thread::sleep_for(200ms);
    input << std::endl;
    type(to_string(LOAD_MEN));
    type("3");
    type(to_string(EDIT_MEN));

    type("+1007"); //0
    type("+1008"); //1
    type("+2007"); //2
    type("+3308"); //3
    type("+2109"); //4
    type("+1109"); //5
    type("+1000"); //6
    type("-99999");

    //Execute, check if errors and warnings were attempted to be displayed
    type(to_string(EXEC_MEN));
    type("1000");
    type("1000");
    test_(view.s_Display == "3 0 0"); ///Overflow
    type("0");
    test_(view.s_Display == "2 7 0"); ///Invalid opcode

    //Exit simulator, testing done
    std::this_thread::sleep_for(200ms);
    input << std::endl;
    type("6");

    sim.join();
    results_();

    if (remove(saveFile.c_str()) != 0)
        cout << "SAVE FILE COULD NOT BE ERASED, ERASE Save.mem BEFORE NEXT TEST"
             << std::endl;

    std::cin.rdbuf(CIN_OLD); //Return cin buffer to normal
    cin.get();
    return 0;
}
#endif