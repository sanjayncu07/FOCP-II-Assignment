#include <bits/stdc++.h>
using namespace std;

class MovieTicket {
private:
    static const int MAX_SLOTS = 100;
    // movie_id -> set of customer IDs
    unordered_map<string, unordered_set<string>> bookings;

    void initMovie(const string& movie_id) {
        if (bookings.find(movie_id) == bookings.end()) {
            bookings[movie_id] = unordered_set<string>();
        }
    }

public:
    bool BOOK(const string& customer_id, const string& movie_id) {
        initMovie(movie_id);
        auto& booked = bookings[movie_id];

        if (booked.count(customer_id)) return false;  // already booked
        if ((int)booked.size() >= MAX_SLOTS) return false;  // sold out

        booked.insert(customer_id);
        return true;
    }

    bool CANCEL(const string& customer_id, const string& movie_id) {
        initMovie(movie_id);
        auto& booked = bookings[movie_id];

        if (!booked.count(customer_id)) return false;  // not booked

        booked.erase(customer_id);
        return true;
    }

    bool IS_BOOKED(const string& customer_id, const string& movie_id) {
        initMovie(movie_id);
        return bookings[movie_id].count(customer_id) > 0;
    }

    int AVAILABLE_TICKETS(const string& movie_id) {
        initMovie(movie_id);
        return MAX_SLOTS - (int)bookings[movie_id].size();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin >> Q;

    MovieTicket system;

    while (Q--) {
        string query;
        cin >> query;

        if (query == "BOOK") {
            string X, Y;
            cin >> X >> Y;
            cout << (system.BOOK(X, Y) ? "true" : "false") << "\n";
        }
        else if (query == "CANCEL") {
            string X, Y;
            cin >> X >> Y;
            cout << (system.CANCEL(X, Y) ? "true" : "false") << "\n";
        }
        else if (query == "IS_BOOKED") {
            string X, Y;
            cin >> X >> Y;
            cout << (system.IS_BOOKED(X, Y) ? "true" : "false") << "\n";
        }
        else if (query == "AVAILABLE_TICKETS") {
            string Y;
            cin >> Y;
            cout << system.AVAILABLE_TICKETS(Y) << "\n";
        }
    }

    return 0;
}