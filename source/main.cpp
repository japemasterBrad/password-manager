#include <iostream> //prints to the console
#include <iomanip>
#include <istream>
#include <string>
#include <sys/wait.h>
#include <dirent.h>
#include <filesystem>

#include "addNewEntry.cpp"
#include "readFile.cpp"

using namespace std;

void view_entry() {
    system("clear");
    string service_name;
    
    cout << "What service would you like the password to?" << endl;
    cout << "> ";
    cin >> service_name;

    /*
        CODE BLOCK TO GET SERVICE NAME AND CREDENTIALS STORED IN SERVICE NAME
    */
}

void addNewEntry() {
    string service;
    string username;
    string password;
    
    cout << "Enter the service" << endl;
    cin >> service;

    cout << "Enter your username" << endl;
    cin >> username;

    cout << "Enter your password" << endl;
    cin >> password;

    AddNewEntry(service, username, password);
}

void viewSingleEntry(string fileName) {
    // string serviceInput;

    // cout << "Type Twitch:" << endl;
    // cout << "> ";
    // cin >> serviceInput;
    
    cout << "The thing you're looking for is " << ReadFile(ReadFile(fileName)).getFinishedPassword();
}

void viewAllEntries() {
    string fileChoice;
    DIR* dir = opendir("../txt files/");
    
    if (dir == NULL) {
        cerr << "Directory not found" << endl;
    }

    struct dirent* entity;
    entity = readdir(dir);
    
    while (entity != NULL) {
        cout << entity -> d_name << endl;
        entity = readdir(dir);
    }
    
    cout << "\nName the file you want to access?\n>" << endl;
    cin >> fileChoice;

    viewSingleEntry(fileChoice);
    closedir(dir);
}

void deleteEntrySearch() {
    string fileToDelete;
    // call function to list all files

string fileChoice;
    DIR* dir = opendir("../txt files/");
    
    if (dir == NULL) {
        cerr << "Directory not found" << endl;
    }

    struct dirent* entity;
    entity = readdir(dir);
    
    while (entity != NULL) {
        cout << entity -> d_name << endl;
        entity = readdir(dir);
    }

    cout << "\nWhat file do you want to delete?" << endl;
    cin >> fileToDelete;

    /*
        CODE TO DELETE FILES (THROUGH BASH?)
    */
   if(remove("../txt files/twitch.txt") == 0) {
       cout << "file deleted successfully!" << endl;
   } else {
       cerr << "Couldn't find file" << endl;
   }


}
void mainMenu() {
    system("clear");
    int menu_choice;
    bool menu_view = true;

    while(menu_view) { // SEND ALL THIS TO MENU FUNCTION
        cout << "Welcome to Epoxy! Password Manager C++\n" << endl;
        cout << "What do you want to do?\n1) Add new entry\n2) View entry\n3) View all entries\n4) Delete entry\n" << endl;
        
        cout << "> ";
        cin >> menu_choice;

        if (menu_choice == 1) {
            cout << "Entering the new class ..." << endl;
            addNewEntry();
            menu_view = false;
        } else if (menu_choice == 2) {
            menu_view = false;

            string serviceInput;

            cout << "Type Twitch:" << endl;
            cout << "> ";
            cin >> serviceInput;
        
            viewSingleEntry(serviceInput);
        } else if (menu_choice == 3) {
            menu_view = false;
            viewAllEntries();
        }else if (menu_choice == 4) {
            menu_view = false;
            deleteEntrySearch();
        } else {
            cout << "Didn't recognise that, please try again" << endl;
            continue;
        }
    }
}

int main() {
    mainMenu();

    return 0;
}
/*

- make delete algorithm
- move add, read and delete into one single class

*/