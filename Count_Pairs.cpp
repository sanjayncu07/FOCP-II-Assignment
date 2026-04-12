#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const int MAX = 10000000;
    vector<int> cnt(MAX + 1, 0);

    for (int i = 2; i <= MAX; i++) {
        if (cnt[i] == 0) {
            for (int j = i; j <= MAX; j += i) {
                cnt[j]++;}
        }
    }
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        cout << (1 << cnt[n]) << '\n';
    }
    return 0;
}
