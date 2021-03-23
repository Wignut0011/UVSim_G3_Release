#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class MenuStrings {
    //width 120, height 30.
    stringstream pages[10];
    string pageNames[10] = {"MainMenu.txt","Readme1.txt","Readme2.txt","Readme3.txt","Readme4.txt","Readme5.txt","EditMode.txt","ExecuteMode.txt","Save.txt","Load.txt"};
public:
    MenuStrings(){
        setupMenus();
    };
    stringstream getMenu(int pageNum){
        return pages[pageNum];
    }
private:
    void setupMenus(){
        for (int i = 0; i < pages.size(); i++){
            string line;
            stringstream text;
            ifstream file("/Pages/".append(pageNames[i]));
            if (file.is_open()){
                while( getline(file,line)){
                    text << line << "\n";
                }
                file.close();
            }
            else text = "unable to open file";
            pages[i] = text;
        }
    }
};