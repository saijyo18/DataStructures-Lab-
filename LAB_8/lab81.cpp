#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> towers(n);
    
    for (int i = 0; i < n; i++) {
        cin >> towers[i];
    }

    long long max_blocks = towers[0]; // Initially, tower 1's blocks
    for (int i = 1; i < n; i++) {
        if (towers[i] > towers[0]) {
            max_blocks += towers[i];
        }
    }
    
    cout << max_blocks << endl;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
