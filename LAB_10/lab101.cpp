//Program to find the minium places to shift left to get a unique subarray

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve(){
    int n ;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n ; i++){
        cin >> a[i];
    }

    vector<int> freq(n+1,0);
    int start = 0 , max_unique = 0;

    for(int end = 0 ; end < n ; end++){
        freq[a[end]]++;
        while(freq[a[end]] > 1){
            freq[a[start]]--;
            start++;
        }
        max_unique = max(max_unique, end - start + 1);
    }
    cout << (n - max_unique) << "\n";
}


int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}