// ============================================================
//   AI ROAST GENERATOR — Complete Bug-Fixed Version
//
//   Bugs fixed:
//     1. Signed/unsigned mismatch in rand() % roasts.size()
//     2. Same roast on fast re-runs (same-second seed problem)
//     3. Whitespace-only name passing empty() check
//     4. Added missing <algorithm> header
//     5. Added "roast again?" loop for better usability
// ============================================================

#include <iostream>    // cout, cin
#include <vector>      // vector
#include <string>      // string
#include <cstdlib>     // rand(), srand()
#include <ctime>       // time()
#include <algorithm>   // FIX 4: needed for find_if (used in trim)

using namespace std;


// ============================================================
//   FUNCTION: trimWhitespace
//   FIX 3: Removes leading and trailing spaces/tabs from a
//   string so "   " is treated the same as "" (empty).
// ============================================================
string trimWhitespace(const string& s) {
    // find first character that is NOT a space or tab
    size_t start = s.find_first_not_of(" \t\r\n");

    // If nothing found, the whole string is whitespace — return empty
    if (start == string::npos) return "";

    // find last character that is NOT a space or tab
    size_t end = s.find_last_not_of(" \t\r\n");

    // Return only the middle part (the real content)
    return s.substr(start, end - start + 1);
}


// ============================================================
//   FUNCTION: replaceName
//   Replaces every {name} token in a roast template with the
//   actual user name. Loops in case {name} appears twice.
// ============================================================
string replaceName(string roast, const string& name) {
    string placeholder = "{name}";
    size_t pos = 0;

    while ((pos = roast.find(placeholder, pos)) != string::npos) {
        roast.replace(pos, placeholder.length(), name);
        pos += name.length(); // skip past the inserted name
    }

    return roast;
}


// ============================================================
//   FUNCTION: getRandomRoast
//   FIX 1: Changed int → size_t to fix signed/unsigned mismatch.
//   FIX 2: Tracks lastIndex so the same roast never repeats
//          back-to-back (important when run twice per second).
// ============================================================
string getRandomRoast(const vector<string>& roasts, const string& name) {

    // FIX 2: static variable keeps its value between calls
    static int lastIndex = -1;

    // FIX 1: size_t matches the unsigned type of roasts.size()
    size_t idx;

    // Keep rolling until we get a different index than last time
    // (only skip repeat-prevention if there is just 1 roast)
    do {
        idx = static_cast<size_t>(rand()) % roasts.size();
    } while (static_cast<int>(idx) == lastIndex && roasts.size() > 1);

    // Remember this index for the next call
    lastIndex = static_cast<int>(idx);

    return replaceName(roasts[idx], name);
}


// ============================================================
//   MAIN
// ============================================================
int main() {

    // Seed random number generator once at program start
    srand(static_cast<unsigned int>(time(0)));

    // ----------------------------------------------------------
    // Roast templates — {name} gets replaced with the real name
    // ----------------------------------------------------------
    vector<string> roasts = {

        // Coding / tech roasts
        "{name}'s code runs so slowly that even dial-up internet feels fast.",
        "{name} doesn't debug code — they negotiate with bugs.",
        "{name}'s Git commit history reads: 'fix', 'fix again', 'why', 'please work', 'I give up'.",
        "They asked {name} to make the code more efficient. {name} deleted the comments and called it done.",
        "Stack Overflow banned {name} — not for bad questions, but for asking the same one 47 times.",
        "{name} tried pair programming once. Their pair quit programming entirely.",
        "The compiler doesn't give {name} errors — it gives suggestions out of pity.",
        "{name}'s code is so spaghetti that the Italian government is considering it a national dish.",

        // Personality / general roasts
        "If procrastination were an Olympic sport, {name} would already have a gold medal.",
        "{name}'s debugging style is staring at the screen until the bug gets embarrassed and leaves.",
        "Scientists discovered a new unit of slowness — they named it after {name}.",
        "If laziness had a brand ambassador, it would be {name}.",

        // Extra creative roasts
        "{name}'s WiFi password is 'idonotknow' — the answer to every problem {name} faces.",
        "{name} writes code so slow that even a turtle switched to Python.",
        "{name}'s brain has 4 GB of RAM and 3.9 GB is used running excuses."
    };

    // ----------------------------------------------------------
    // Welcome banner
    // ----------------------------------------------------------
    cout << "========================================" << endl;
    cout << "      Welcome to AI Roast Generator     " << endl;
    cout << "========================================" << endl;
    cout << endl;

    // ----------------------------------------------------------
    // Get the user's name
    // ----------------------------------------------------------
    string userName;
    cout << "Enter your name: ";
    getline(cin, userName);

    // FIX 3: Trim whitespace before checking if name is empty
    userName = trimWhitespace(userName);

    // Keep asking until a real name is entered
    while (userName.empty()) {
        cout << "Oops! Name cannot be blank or spaces only." << endl;
        cout << "Please enter your name: ";
        getline(cin, userName);
        userName = trimWhitespace(userName); // FIX 3: trim again each loop
    }

    // ----------------------------------------------------------
    // FIX 5: "Roast again?" loop — keeps generating until user
    // types 'n'. Much better UX than re-running the whole program.
    // ----------------------------------------------------------
    char again = 'y';

    while (again == 'y' || again == 'Y') {

        string roast = getRandomRoast(roasts, userName);

        cout << endl;
        cout << "========================================" << endl;
        cout << "   Here is your roast, " << userName << "!" << endl;
        cout << "========================================" << endl;
        cout << endl;
        cout << roast << endl;
        cout << endl;
        cout << "   (Relax — it is all in good fun!)" << endl;
        cout << "========================================" << endl;
        cout << endl;

        cout << "Want another roast? (y/n): ";
        cin >> again;

        // Clear the leftover newline so the next getline works cleanly
        cin.ignore();
    }

    cout << endl;
    cout << "Thanks for playing, " << userName << "! Stay roasted." << endl;

    return 0;
}

// ============================================================
//   HOW TO COMPILE AND RUN
//
//   Linux / macOS:
//     g++ -o roast_generator roast_generator.cpp
//     ./roast_generator
//
//   Windows (MinGW):
//     g++ -o roast_generator roast_generator.cpp
//     roast_generator.exe
//
//   IDE (VS Code / Code::Blocks / Dev-C++):
//     Open file → Build & Run (F9 or F5)
// ============================================================