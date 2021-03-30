//Includes
#include "MODEL.h"
#include <fstream>

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
    /// readUserInput() should add new input at the end of memory to avoid overwriting data
    /// navigation between readme pages
    /// update view through model.updateMenu()

    //Start of program
    void StartSimulator()
    {
        //Landing Page
        loadMenu();
    }

    // Gathers user input
    bool readUserInput()
    {
        bool done = false;
        for (size_t i = 0; i < 100; i++) {
            if (!done)
            {
                string line;
                if (i < 10) line = "0" + to_string(i);
                else line = to_string(i);
                cout << line << " ? "; cout.flush();

                //gather user input
                string uInput;
                cin >> uInput;

                //stop gathering if user types -99999
                if (uInput.length() == 6)
                {
                    if (uInput == "-99999")
                    {
                        done = true;
                        uInput = "+0000";
                    }
                    else if (uInput == "+99999")
                    {
                        return false;
                    }
                    else
                    {
                        view.DisplayError();
                        i--;
                    }
                }

                // Check user input for errors
                else if ((uInput[0] != '+') || (uInput.length() != 5) || (uInput[0] != '-'))
                {
                    view.DisplayError();
                    i--;
                }

                // Send user input to MODEL to store in memory
                else model.updateMemory(uInput, i);
            }
                // Format rest of empty cells
            else
                // Tell MODEL the remaining cells are empty
                model.updateMemory("+0000", i);
        }
        return done;
    }

    // Starts execution mode
    void executeMode()
    {
        /// ask user if they wish to execute with current memory
        view.Display(EXEC);
            model.runCPU();

            // After execution, user can enter "1" to return to main menu
            string in;
            cin >> in;
            if (in == "1") loadMenu();
    }


    // Loads a specified menu page
    void loadMenu()
    {
        view.Display(MAIN);

        string in;
        cin >> in;
        int page = stoi(in);
        switch (page)
        {
            case 1: loadMenu();
                break;
            case 2: view.Display(README);
                break;
            case 3: view.Display(EDIT);
                if (readUserInput()) executeMode();
                else loadMenu();
                break;
            case 4: view.Display(LOAD);
            load();
            //loadMenu();
                break;
            case 5: view.Display(SAVE);
            save();
            //loadMenu();
                break;
            case 6: executeMode();
                break;
            case 7: view.Display(DUMP);
                break;
            default: view.DisplayInvalid();
                // user can enter "1" to return to main menu
                string line;
                cin >> line;
                if (line == "1") loadMenu();

        }
    }

    // Saves the current program
    bool save()
    {
        view.Display(SAVE);
        cout << "\nSave file as: ";
        cin >> saveFile;

        /// Save copy of current memory into a text file with the name provided

        ofstream file (saveFile);
        if (file.is_open())
        {
            for(int i = 0; i < model.memory.inputMap.size(); i++)
            {

                file << model.memory[i] << endl;
            }
            file.close();
            cout << "File saved successfully\n";
        }
        else cout << "Error creating save file!\n";


    }

    // Loads a specified program
    bool load()
    {
        view.Display(LOAD);
        cout << "\nLoad which file?: ";
        cin >> loadFile;

        /// Load specified text file into current memory

        string line;
        ifstream file (loadFile);
        if(file.is_open())
        {
            int i = 0;
            while(getline(file, line))
            {
                model.updateMemory(line, i++);
            }
            file.close();
            cout << "File loaded successfully\n";
        }
        else cout <<"Unable to open file!\n";
    }

    // If an error is detected, tells view to display the correct error message
    void error()
    {

    }

private:
    string saveFile;
    string loadFile;

};