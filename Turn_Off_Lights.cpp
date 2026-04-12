#include <iostream>
using namespace std;

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    for (int L = 1; L <= n; L++) {
        int ops = 0;

        for (int i = 0; i < n;) {
            if (s[i] == '1') {
                ops++;
                i += L;   
            } else { i++;  }  
			}
        if (ops <= k) {
            cout << L;
            break;
        }
    }
}
