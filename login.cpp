#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace::std;

class UserInfo {
    public:
        string username;
        string password;
        string userrecieve;
        string passrecieve;
        string usercheck;
        string passcheck;

        void userUpdate(const string &s) {
            username = s;
        }
        void pswUpdate(const string &s) {
            password = s;
        }
        void Check() {
    ifstream data("registration.txt");
    bool found = false;
    while (getline(data, userrecieve)) {
        istringstream iss(userrecieve);
        iss >> usercheck;
        iss >> passcheck;

        if (usercheck == username) {
            found = true;
            if (passcheck == password) {
                cout << "Redirecting You. Please Stand By." << endl;
                system("main.exe");
                return;
            } else {
                cout << "Incorrect Password" << endl;
                return;
            }
        }
    }
    if (!found) {
        cout << "Username Not Recognized. Please Register First" << endl;
    }
}
};

int main() {
    UserInfo login;
    string userinput;
    string passinput;
    cout <<"Enter Your Username" <<endl;
    cin >> userinput;  
    login.userUpdate(userinput);
    cout << "Enter Your Password" << endl;
    cin >> passinput;
    login.pswUpdate(passinput);
    login.Check();


return 0;
}