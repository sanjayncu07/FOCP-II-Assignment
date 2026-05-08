// ============================================================
//  Student Excuse Generator - FINAL CORRECTED VERSION
//
//  BUG 1 FIXED : int pos  -->  size_t pos
//  BUG 2 FIXED : single find()  -->  while loop for all {name}
//  BUG 3 FIXED : no npos check  -->  string::npos guard added
//  BUG 4 FIXED : no empty check  -->  name.empty() validation
//  BUG 5 FIXED : srand(time(0))  -->  static_cast<unsigned int>
//  BUG 6 FIXED : rand()%size()  -->  cast size() to int
//  BUG 7 FIXED : cramped output  -->  proper spacing added
//  BUG 8 FIXED : hardcoded 6  -->  placeholder.length() used
// ============================================================

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// -------------------------------------------------------
//  Safe replace function - fixes BUG 1, 2, 3, 8
// -------------------------------------------------------
string replaceName(string excuse, const string& name) {

    string placeholder = "{name}";

    // BUG 1 FIX : size_t instead of int
    size_t pos = 0;

    // BUG 2 FIX : while loop replaces ALL {name} in template
    // BUG 3 FIX : string::npos check is built into while condition
    while ((pos = excuse.find(placeholder, pos)) != string::npos) {

        // BUG 8 FIX : placeholder.length() instead of hardcoded 6
        excuse.replace(pos, placeholder.length(), name);
        pos += name.length();
    }

    return excuse;
}

int main() {

    // BUG 5 FIX : proper cast to unsigned int
    srand(static_cast<unsigned int>(time(0)));

    vector<string> excuses = {
        "{name} couldn't complete the assignment because the laptop battery died.",
        "{name} tried finishing the homework, but the internet stopped working.",
        "{name} was ready to submit the assignment when the file disappeared.",
        "{name} had the homework done but the printer ran out of ink.",
        "{name} lost all work when the computer suddenly shut down.",
        "{name} could not submit because the school website kept crashing.",
        "{name} finished the task but accidentally deleted the file.",
        "{name} had the assignment ready but the dog chewed the notebook.",
        "{name} was typing the last answer when the keyboard stopped working.",
        "{name} completed the homework but forgot the notebook at home."
    };

    string name;

    // BUG 7 FIX : proper spacing in output
    cout << "\n===================================" << endl;
    cout << "    STUDENT EXCUSE GENERATOR       " << endl;
    cout << "===================================\n" << endl;
    cout << "Enter your name: ";
    getline(cin, name);

    // BUG 4 FIX : empty name validation
    if (name.empty()) {
        cout << "\n[ERROR] Name cannot be empty!" << endl;
        cout << "Please restart the program.\n" << endl;
        return 1;
    }

    // BUG 6 FIX : cast size() to int to avoid size_t vs int warning
    int index = rand() % static_cast<int>(excuses.size());

    // Call safe replace function (fixes BUG 1,2,3,8)
    string excuse = replaceName(excuses[index], name);

    // BUG 7 FIX : neat readable output with spacing
    cout << "\n-----------------------------------" << endl;
    cout << "  YOUR EXCUSE:                     " << endl;
    cout << "-----------------------------------" << endl;
    cout << "\n  " << excuse << "\n" << endl;
    cout << "===================================\n" << endl;

    return 0;
}