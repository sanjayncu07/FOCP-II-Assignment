#include <iostream>
using namespace std;

int main() {
    int L, R;
    cin >> L >> R;

    int odd_count = (R + 1) / 2 - (L / 2);

    if (odd_count % 2 == 0)
        cout << "even";
    else
        cout << "odd";

    return 0;
}
