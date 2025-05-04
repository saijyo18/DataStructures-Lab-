//Program 
#include<iostream>
#include<vector>
#include<map>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<string>> words(3, vector<string>(n));
    map<string ,int> freq;

    for(int i = 0 ; i < 3 ; i++){
        for(int j =0 ; j < n ; j++){
            cin >> words[i][j];
            freq[words[i][j]]++;
        }
    }

    vector<int> scores(3,0);

    for( int i =0 ; i < 3 ; i++){
        for(int j = 0 ; j < n ; j++){
            if( freq[words[i][j]] == 1){
                scores[i] += 3;
            } else if( freq[words[i][j]] == 2){
                scores[i] += 1;
            }
        }
    }

    cout << scores[0] << " " << scores[1] << " " << scores[2] << endl;

}

int main() {
    int tc;
    cin >> tc;
    while( tc--) {
        solve();
    }

    return 0;
}