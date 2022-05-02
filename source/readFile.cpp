#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>

using namespace std;

class ReadFile {
    ReadFile() = default;

    private:
        string service;
        string username;
        string password;
        string encryptedPass;
        string decryptedPass;
        string filepath = "/run/media/japemaster_brad/ZEUS/DEV/C++/password_manager/txt files/";
        string fileline1;
        string fileline2;
        string fileline3;
        ifstream readingFile;
        

        int lines = 3;

    public:
        ReadFile(string cService) {
            service = cService;
            string filename = cService + ".txt";
            
            system("clear");
            
            cout << "Looking for " + filename + " in " + (filepath + filename) + "..." << endl;
            cout << "File found!" << endl;
            readingFile.open(filepath + filename, ifstream::in);

            if (!readingFile.is_open()) {
                cerr << "Error opening file" << endl << endl;
            } else {
                encryptedPass = getLines();
                decryptedPass = decrypter(encryptedPass);
            }

            cout << "Your decryped password is " + decryptedPass << endl;
            
        }

        string getLines() {
            string encryptedPass;
            cout << "Reading file now" << endl << endl;
            
            cout << "------------------------------" << endl;
            getline(readingFile, fileline1);
            cout << "1 " << fileline1 << endl;
            getline(readingFile, fileline2);
            cout << "2 " << fileline2 << endl;
            getline(readingFile, fileline3);
            cout << "3 " << fileline3 << endl;
            cout << "------------------------------" << endl;
            
            return fileline3;
        }

        string decrypter(string encryptedPass) {
            string decryptedPass;
            char decrypted_pass_characters;
            
            cout << "Decrypting file now..." << endl;

            for(int i = 0; i < encryptedPass.length(); i++) {
                if (i % 2 != 0) {
                    decrypted_pass_characters = (static_cast<char>(int(encryptedPass[i]) + 5));
                } else {
                    decrypted_pass_characters = (static_cast<char>(int(encryptedPass[i]) - 5));
                }
                
                decryptedPass += decrypted_pass_characters;
            }

            string finishedPass;

            for (int j = 10; j < decryptedPass.length(); j++) {
                finishedPass += decryptedPass[j];
            }
            
            return finishedPass;
        }

        string getFinishedPassword() {
            return decryptedPass;
        }
};

/*
    
- list all the file names

= return password from index[10]

*/