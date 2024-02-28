#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>

using namespace::std;

class Userdata {
    public:
        string username;
        string password;
        

        void UserEntry(const string &s) {
           
            username = s;
        }
        void PassEntry(const string &s1) {
            password = s1;
        }
           void Getdata() {
        ifstream datatext("registration.txt");
        bool userExists = false;

      
        if (!datatext.is_open()) {
            cout << "Error opening file." << endl;
            return;
        }

   
        string word;
        while (datatext >> word) {
            if (word == username) { 
                cout << "User is already Registered. Please Login." << endl;
                userExists = true;
                break;
            }
           
            datatext.ignore(numeric_limits<streamsize>::max(), '\n');
        }

 
        datatext.close();

        
        if (!userExists) {
            ofstream outfile("registration.txt", ios::app);
            if (!outfile.is_open()) {
                cerr << "Error opening file for appending." << endl;
                return;
            }
            outfile << username << " " << password << endl; 
            cout << "User registered successfully." << endl;
        }
    }

};
int main() {
    string choice;
    cout << "Type Login if you have an account or type register if you don't have a accont" << endl;
    cin >> choice;
    if (choice == "Login") {
        system("login.exe");
    }
    else if(choice == "Register") {
        Userdata main;
        cout << "Enter Your Username" << endl;
        string user_name;
        string user_pass;
        cin >> user_name;
        main.UserEntry(user_name);
        cout << "Enter Your Password" << endl;
        cin >> user_pass;
        main.PassEntry(user_pass);
        main.Getdata();
    }
    else {
        cout << "Command Not Recognized" << endl;
    }

return 0;
}