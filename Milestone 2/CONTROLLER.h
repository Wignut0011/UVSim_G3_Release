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
        //Landing Page
        loadMenu();

        /// Switch statement to control which menu page
        bool done = false;
        while(!done)
        {
            string in;
            cin >> in;
            int page = stoi(in);
            switch (page)
            {
                case 1: view.Display(MAIN);
                    break;
                case 2: view.Display(README);
                    break;
                case 3: view.Display(EDIT);
                    break;
                case 4: view.Display(LOAD);
                    break;
                case 5: view.Display(SAVE);
                    break;
                case 6: view.Display(EXEC);
                    break;
                case 7: view.Display(DUMP);
                    break;
                case 8: done = true;
                    break;
                default: view.DisplayInvalid();

            }



        }
        if (readUserInput())
        {
            executeMode();
        }
    }

    // Gathers user input
    bool readUserInput()
    {
        bool done = false;
        const string STOP = "-99999";
        const string PAUSE = "+99999";
        for (size_t i = 0; i < 100; i++) {
            if (!done) {
                string line;
                if (i < 10) line = "0" + to_string(i);
                else line = to_string(i);
                cout << line << " ? "; cout.flush();

                //gather user input
                string uInput;
                cin >> uInput;

                if (uInput.length() == 6)
                {
                    //stop gathering if user types -99999
                    if (uInput == STOP)
                    {
                        done = true;
                        uInput = "+0000";
                    }
                    else if (uInput == PAUSE)
                    {
                        done = true;
                        uInput = "+0000";
                        /// save memory and load main menu
                        save();
                        loadMenu();
                    }
                    else view.DisplayError();
                }

                // Check user input for errors
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

        return done;
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
        cout << "\nSaved file as: ";
        cin >> saveFile;

        /// Save copy of current memory into a text file with the name provided
    }

    // Loads a specified program
    bool load()
    {
        cout << "\nLoad which file?: ";
        cin >> loadFile;

        /// Load specified text file into current memory
    }

    // If an error is detected, tells view to display the correct error message
    void error()
    {

    }

private:
    string saveFile;
    string loadFile;

};