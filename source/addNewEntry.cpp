#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>

using namespace std;

class AddNewEntry {
    private:
        string service;
        string username;
        string password;
    public:
        AddNewEntry(string cService, string cUsername, string cPassword) {
            system("clear");

            service = cService;
            username = cUsername;
            password = cPassword;
    
            string encryptedPass;
            ofstream newCredentialFile;
            string filename = service + ".txt";
            string filepath = "/run/media/japemaster_brad/ZEUS/DEV/C++/password_manager/txt files/";

            char encrypted_pass_characters;

            cout << "Password received: " << password << endl << "Encrypting now" << endl;
            
            for(int i = 0; i < password.length(); i++) {
                if (i % 2 != 0) {
                    encrypted_pass_characters = (static_cast<char>(int(password[i]) - 5));
                } else {
                    encrypted_pass_characters = (static_cast<char>(int(password[i]) + 5));
                }
                
                    encryptedPass += encrypted_pass_characters;
            }

            cout << "Your password has encrypted to " << encryptedPass << endl;
            cout << "Writing to database..." << endl;
            
            newCredentialFile.open(filepath + filename);
            
            if (newCredentialFile.fail()) {
                cerr << "Error opening file" << endl;
                exit(1);
            }

            newCredentialFile << "SERVICE: " << service << endl;
            newCredentialFile << "USERNAME: " << username << endl;
            newCredentialFile << "PASSWORD: " << encryptedPass << endl;
            newCredentialFile.close();
        }
};
