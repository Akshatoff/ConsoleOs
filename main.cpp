#include <iostream>
#include <string>
#include <fstream>
#include <chrono>

using namespace::std;
using namespace::chrono;



class Options {
    public:
    string options;
    string reply;

  

    void Get(const string &s) {
        options = s;
        if (options == "Code")
        {
            reply = "Getting things ready";
            int exitcode = system("Code.exe");

        }
        else if (options == "Browser")
        {
            reply = "Opening up Browser";
            system("brave.exe");
        }
        else if(options == "Journal" || options=="journal") {
           
           system_clock::time_point now = system_clock::now();
            time_t now_time = system_clock::to_time_t(now);
            tm now_tm = *gmtime(&now_time);

            int year = now_tm.tm_year + 1900;
            int month = now_tm.tm_mon + 1;
            int date = now_tm.tm_mday;

            ofstream outfile("journal.txt", ios::app);

            
            outfile << "Date -: \n" << "/" << date << "/" << month << "/" << year << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Input Your journal entry for today"<<endl;
            string entry;
            getline(cin, entry);
            outfile << "\t\t" <<entry <<endl;
            
        }
        
        
    }
    void Show() {
        cout<<reply<<endl;
    }
};

int main() {
    for (int i = 0; i < 25; i++)
    {
        cout<<"--";
    }
    cout<<" Console Os";
    for (int j = 0; j < 25; j++)
    {
        cout<<"--";
    }

    Options main;
    cout<<"Welcome Master Please Specify your Task"<<endl;
    string userresponse;
    cin >> userresponse;
    main.Get(userresponse);
    main.Show();

    

    
return 0;
}