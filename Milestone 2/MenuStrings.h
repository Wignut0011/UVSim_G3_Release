#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class MenuStrings {
    //width 120, height 30.
    vector<stringstream> pages;
    string pageNames[10] = {"MainMenu.txt","Readme1.txt","Readme2.txt","Readme3.txt","Readme4.txt","Readme5.txt","EditMode.txt","ExecuteMode.txt","Save.txt","Load.txt"};
public:
    MenuStrings(){
        setupMenus();
    };
    string getMenu(int pageNum){
        return pages[pageNum].str();
    }
private:
    void setupMenus(){
        for (int i = 0; i < pages.size(); i++){
            string line;
            stringstream text;
            ifstream file(string("/Pages/" + pageNames[i]));
            if (file.is_open()){
                while( getline(file,line)){
                    text << line << "\n";
                }
                file.close();
            }
            else text.str("unable to open file");
            pages[i].str(text.str());
        }
    }
};