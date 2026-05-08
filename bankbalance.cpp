#include <bits/stdc++.h>
using namespace std;

class Bank {
private:
    // user_id -> balance
    unordered_map<string, long long> accounts;

public:
    bool CREATE(const string& user_id, long long amount) {
        if (accounts.find(user_id) != accounts.end()) {
            accounts[user_id] += amount;  // user exists, just add balance
            return false;
        }
        accounts[user_id] = amount;  // new account created
        return true;
    }

    bool DEBIT(const string& user_id, long long amount) {
        if (accounts.find(user_id) == accounts.end()) return false;  // user not found
        if (accounts[user_id] < amount) return false;                // insufficient balance

        accounts[user_id] -= amount;
        return true;
    }

    bool CREDIT(const string& user_id, long long amount) {
        if (accounts.find(user_id) == accounts.end()) return false;  // user not found

        accounts[user_id] += amount;
        return true;
    }

    long long BALANCE(const string& user_id) {
        if (accounts.find(user_id) == accounts.end()) return -1;  // user not found
        return accounts[user_id];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin >> Q;

    Bank bank;

    while (Q--) {
        string query;
        cin >> query;

        if (query == "CREATE") {
            string X;
            long long Y;
            cin >> X >> Y;
            cout << (bank.CREATE(X, Y) ? "true" : "false") << "\n";
        }
        else if (query == "DEBIT") {
            string X;
            long long Y;
            cin >> X >> Y;
            cout << (bank.DEBIT(X, Y) ? "true" : "false") << "\n";
        }
        else if (query == "CREDIT") {
            string X;
            long long Y;
            cin >> X >> Y;
            cout << (bank.CREDIT(X, Y) ? "true" : "false") << "\n";
        }
        else if (query == "BALANCE") {
            string X;
            cin >> X;
            cout << bank.BALANCE(X) << "\n";
        }
    }

    return 0;
}