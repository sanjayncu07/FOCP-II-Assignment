#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.rbegin(), a.rend());

    long long alex = 0;
    long long bob = 0;
    set<int> alex_sugar;
    set<int> bob_sugar;

    int ptr = 0;
    bool alex_turn = true;

    while (ptr < n) {
        if (alex_turn) {
            while (ptr < n && alex_sugar.count(a[ptr])) {
                ptr++;
            }
            if (ptr < n) {
                alex += a[ptr];
                alex_sugar.insert(a[ptr]);
                ptr++;
            }
            alex_turn = false;
        } else {
            while (ptr < n && bob_sugar.count(a[ptr])) {
                ptr++;
            }
            if (ptr < n) {
                bob += a[ptr];
                bob_sugar.insert(a[ptr]);
                ptr++;
            }
            alex_turn = true;
        }
    }

    if (alex > bob) cout << "Alex" << endl;
    else cout << "Bob" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
