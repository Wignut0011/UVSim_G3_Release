//Includes
#include "MODEL.h"

class CONTROLLER{
    MODEL model;
    VIEW view;

public:
    //Constructor
    CONTROLLER(MODEL &m, VIEW &v): model(m), view(v)
    {
        saveFile = "";
        loadFile = "";
    };


    /// TODO
    /*
     Add 5 digit code to switch from edit mode to main menu.
     save and load functionality
     reformat readUserInput to check for errors and 5 digit codes
     readUserInput only gathers input for edit mode, input to change pages is handled elsewhere
     */

    //Start of program
    void StartSimulator()
    {
        loadMenu();
        if (readUserInput())
        {
            executeMode();
        }
    }

    // Gathers user input
    bool readUserInput()
    {
        bool done = false;
        for (size_t i = 0; i < 100; i++) {
            if (!done) {
                string line;
                if (i < 10) line = "0" + to_string(i);
                else line = to_string(i);
                cout << line << " ? "; cout.flush();

                //gather user input
                string uInput;
                cin >> uInput;

                //stop gathering if user types -99999
                if (uInput == "-99999"){
                    done = true;
                    uInput = "+0000";
                }


                /// Check user input for errors
                if ((uInput[0] != '+') || (uInput.length() != 5) || (uInput[0] != '-'))
                {
                    view.DisplayError();
                    i--;
                }

                /// Send user input to MODEL to store in memory
                else model.updateMemory(uInput, i);
            }

                // Format rest of empty cells
            else

                /// Tell MODEL the remaining cells are empty
                model.updateMemory("+0000", i);
        }

        return true;
    }

    // Starts execution mode
    void executeMode()
    {
        view.Display(EXEC);
        model.runCPU();
    }


    // Loads a specified menu page
    void loadMenu()
    {
        view.Display(MAIN);
    }

    // Saves the current program
    bool save()
    {
        cout << "Save file as: ";
        cin >> saveFile;

        /// Save copy of current memory into a text file with the name provided
    }

    // Loads a specified program
    bool load()
    {
        cout << "Load which file?: ";
        cin >> loadFile;

        /// Load specified text file into current memory
    }

    // If an error is detected, tells view to display the correct error message
    void error()
    {

    }

private:
    const int MainMenu = 0;
    const int ExecPage = 1;
    const int EditPage = 2;
    string saveFile;
    string loadFile;

};