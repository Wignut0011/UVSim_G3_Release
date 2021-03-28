//Includes
#include "MenuStrings.h"
#include "MEMORY.h"
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

//Global constants
enum resolution :size_t{WIDTH = 120, HEIGHT = 30, PRINT_LINE = 4}; //Resolution line consts
enum mainPages :size_t{MAIN = 0, README_1 = 1, README_2 = 2, README_3 = 3, README_4 = 4, README_5 = 5,
        EDIT = 6, EXEC = 7, SAVE = 8, LOAD = 9, DUMP = 10};
const char LINE_TOKEN[] = "%l", PAGE_TOKEN[] = "%p", ADDR_TOKEN[] = "%a", VAL_TOKEN[] = "%v", DUMP_TOKEN[] = "%d"; // String token consts

class VIEW{
public:
    //Constructor
    VIEW() = default;

    VIEW(VIEW const &view) {}

//Displays a requested page
    void Display(const int& p){
        currPage.str(menus.getMenu(p)); //Get menu page from library facade

        //Check if loaded page is right resolution of 120x30 chars
        Validate(stringstream(currPage.str()));

        //Check which page was loaded to put fist page num
        if(p == EDIT || p == LOAD || p == EXEC)
            currPage.str(regex_replace(currPage.str(), regex(PAGE_TOKEN), to_string(1)));

        cout << regex_replace(currPage.str(), regex(LINE_TOKEN), ""); //Update View
        cout.flush();
    }

    //Display line on screen
    void DispLine(string line){
        currPage.str(regex_replace(currPage.str(), regex(LINE_TOKEN), line)); //Update line

        cout << regex_replace(currPage.str(), regex(LINE_TOKEN), ""); //Update View
        cout.flush();
    }

    //Continues the memory state of Edit Mode
    void ContinueEdit(MEMORY mem){
        currPage.str(menus.getMenu(EDIT)); //Load up the Edit Page
        size_t page =  mem.getMap.size()/13; //What page?
        currPage.str(regex_replace(currPage.str(), regex(PAGE_TOKEN), to_string(page))); //Put page no

        for(size_t i = mem.getMap.size() % page; i < mem.getMap().size(); i++){ // Replace line tokens with memory
            currPage.str(regex_replace(currPage.str(), regex(LINE_TOKEN), mem.getMap.at(i)));
        }
        cout << regex_replace(currPage.str(), regex(LINE_TOKEN), ""); //Update View
        cout.flush();
    }

    //User's input is invalid, print message on view
    void DisplayInvalid(){
        //Check if an error is already on the page
        if (currPage.str().find(INV_MESSAGE) > 0) { //Just reprint page, same error
            cout << regex_replace(currPage.str(), regex(LINE_TOKEN), ""); //Update View
            cout.flush();
            return;
        }

        else if (currPage.str().find(ERROR_TEMPLATE) > 0) //Err error, replace
            currPage.str(regex_replace(currPage.str(), regex(ERROR_TEMPLATE), INV_MESSAGE));

        else //No error currently on screen, just print
            currPage << INV_MESSAGE;

        Validate(stringstream(currPage.str())); //Check if page is valid

        cout << regex_replace(currPage.str(), regex(LINE_TOKEN), ""); //Update View
        cout.flush();
    }

    //User created an error, print message on view
    void DisplayError(){
        //Check if an error is already on the page
        if (currPage.str().find(ERROR_TEMPLATE) > 0) //Just return, same error
            return;

        else if (currPage.str().find(INV_MESSAGE) > 0) //Inv error, replace
            currPage.str(regex_replace(currPage.str(), regex(INV_MESSAGE), ERROR_TEMPLATE));

        else //No error currently on screen, just print
            currPage << ERROR_TEMPLATE;

        Validate(stringstream(currPage.str())); //Check if page is valid

        cout << regex_replace(currPage.str(), regex(LINE_TOKEN), ""); //Update View
        cout.flush();
    }

    //Display the write message on the Exec page
    void DisplayWrite(const int& addr, const int& value){
        //Make message template
        string output = WRITE_TEMPLATE;
        output = regex_replace(output, regex(ADDR_TOKEN), to_string(addr));
        output = regex_replace(output, regex(VAL_TOKEN), to_string(value));

        //If max line has been reached, add new page
        lineSpace++;
        if (lineSpace >= HEIGHT){
            execPages.push_back(currPage); //Push to page vector
            currPage.str(menus.getMenu(61));
            currPage.str(regex_replace(currPage.str(), regex(PAGE_TOKEN), to_string(execPages.size())));
            lineSpace = PRINT_LINE+1;
        }

        currPage.str(regex_replace(currPage.str(), regex(LINE_TOKEN), output)); //Put write message in page
        Validate(stringstream(currPage.str())); //Check if page is valid

        cout << regex_replace(currPage.str(), regex(LINE_TOKEN), ""); //Update View
        cout.flush();
    }

    //Display the read message on the Exec page
    void DisplayRead(){
        //If max line has been reached, add new page
        lineSpace++;
        if (lineSpace >= HEIGHT){
            execPages.push_back(currPage); //Push to page vector
            currPage.str(menus.getMenu(61));
            currPage.str(regex_replace(currPage.str(), regex(PAGE_TOKEN), to_string(execPages.size())));
            lineSpace = PRINT_LINE+1;
        }

        currPage.str(regex_replace(currPage.str(), regex(LINE_TOKEN), READ_TEMPLATE)); //Put read message in page
        Validate(stringstream(currPage.str())); //Check if page is valid

        cout << regex_replace(currPage.str(), regex(LINE_TOKEN), ""); //Update View
        cout.flush();
    }

    //End of execution, display dump and reset exec variables
    /// CHECK WITH TEAM FOR IMPLEMENTATION
//    void DisplayDump(const string& dump){
//        lineSpace = PRINT_LINE; //Reset line counter
//        execPages.clear(); //Clear execution page history.
//
//        stringstream dumpPage(menus.getMenu(71));
//        dumpPage.str(regex_replace(dumpPage.str(), regex(DUMP_TOKEN), dump));
//
//        currPage.str(dumpPage.str()); //Is now current page
//        Validate(stringstream(currPage.str())); //Check if page is valid
//
//        cout << regex_replace(currPage.str(), regex(LINE_TOKEN), ""); //Update View
//        cout.flush();
//    }

private:
    MenuStrings menus;
    stringstream currPage; //What is currently displayed on the view
    vector<stringstream> execPages; //Page history in Execution mode
    int lineSpace = PRINT_LINE; //Keep track of line space in

    //CONST string templates
    const string INV_MESSAGE = "ERROR: Invalid Option, try again. >";
    const string ERROR_TEMPLATE = "Error: Please try again. >";
    const string WRITE_TEMPLATE = "Memory location %a currently has %v"; //Contains Regex tokens
    const string READ_TEMPLATE = "Please input a number: ";


    //Check if the currPage stream is valid for the console
    void Validate(stringstream check){
//        string page = currPage.str();
        string lines[29];

        //Grab strings
        for(std::size_t i = 0; i < HEIGHT; i++)
            if (check.rdbuf()->in_avail() != 0) {
                getline(check, lines[i]);
                if (lines[i].length() > WIDTH) //Check width
                    throw logic_error(string("Page output is incorrect width resolution at line ", i));
            }

        //Check if there are still lines in the stream
        if (check.rdbuf()->in_avail() != 0)
            throw logic_error("Page output is incorrect height resolution");

        //Validation passed
    }
};