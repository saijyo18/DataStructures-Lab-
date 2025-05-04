//Program to implement using a binay tree
#include <iostream>
#include <set>
#include <vector>

using namespace std;

void findWinners(vector<int>& a, int n) {
    set<int> players;
    for (int i = 1; i <= n; i++) {
        players.insert(i); // Initialize all players
    }
    
    bool eliminated = true;
    while (eliminated) {
        eliminated = false;
        set<int> toRemove;
        
        for (int num : a) {
            auto it = players.begin();
            advance(it, num - 1); // Move iterator to the num-th position if possible
            if (distance(players.begin(), it) == num - 1 && it != players.end()) {
                toRemove.insert(*it);
                eliminated = true;
            }
        }
        
        for (int rem : toRemove) {
            players.erase(rem);
        }
    }
    
    cout << players.size() << endl;
}

int main() {
    int k, n, q;
    cin >> k; // Length of sequence a
    vector<int> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    
    cin >> q;
    while (q--) {
        cin >> n;
        findWinners(a, n);
    }
    
    return 0;
}
