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
    
    std::cout << "What service would you like the password to?" << endl;
    std::cout << "> ";
    std::cin >> service_name;

    /*
        CODE BLOCK TO GET SERVICE NAME AND CREDENTIALS STORED IN SERVICE NAME
    */
}

void addNewEntry() {
    string service;
    string username;
    string password;
    
    std::cout << "Enter the service" << endl;
    std::cin >> service;

    std::cout << "Enter your username" << endl;
    std::cin >> username;

    std::cout << "Enter your password" << endl;
    std::cin >> password;

    AddNewEntry(service, username, password);
}

void viewSingleEntry(string fileName) {
    // string serviceInput;

    // std::cout << "Type Twitch:" << endl;
    // std::cout << "> ";
    // std::cin >> serviceInput;
    
    std::cout << "The thing you're looking for is " << ReadFile(ReadFile(fileName)).getFinishedPassword();
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
        std::cout << entity -> d_name << endl;
        entity = readdir(dir);
    }
    
    // viewSingleEntry(fileChoice); // 
    closedir(dir);
}

void deleteEntrySearch() {
    string fileToDelete;
    const char * filepath = "../txt files/";
    string fileChoice;
    DIR* dir = opendir("../txt files/");
    
    // call function to list all files
    
    if (dir == NULL) {
        cerr << "Directory not found" << endl;
    }

    struct dirent* entity;
    entity = readdir(dir);
    
    while (entity != NULL) {
        std::cout << entity -> d_name << endl;
        entity = readdir(dir);
    }

    std::cout << "\nWhat file do you want to delete?" << endl;
    std::cin >> fileToDelete;
}



void mainMenu() {
    system("clear");
    int menu_choice;
    bool menu_view = true;

    while(menu_view) { // SEND ALL THIS TO MENU FUNCTION
        std::cout << "Welcome to Epoxy! Password Manager C++\n" << endl;
        std::cout << "What do you want to do?\n1) Add new entry\n2) View entry\n3) View all entries\n4) Delete entry\n" << endl;
        
        std::cout << "> ";
        std::cin >> menu_choice;

        if (menu_choice == 1) {
            std::cout << "Entering the new class ..." << endl;
            addNewEntry();
            menu_view = false;
        } else if (menu_choice == 2) {
            menu_view = false;

            string serviceInput;

            std::cout << "Type Twitch:" << endl;
            std::cout << "> ";
            std::cin >> serviceInput;
        
            viewSingleEntry(serviceInput);
        } else if (menu_choice == 3) {
            menu_view = false;
            viewAllEntries();
        }else if (menu_choice == 4) {
            menu_view = false;
            deleteEntrySearch();
        } else {
            std::cout << "Didn't recognise that, please try again" << endl;
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