#include <bits/stdc++.h>
#define ll long long int
#define en '\n'
using namespace std;


void solve() {
    ll n;
    cin >> n;

    cout << "? 1 " << n << endl; // querry
    
    ll x;
    cin >> x; // input jusge ans
    if(x == -1) exit(0); // exit immedietly
    if(x == n || x == 0) {
        cout << "! NO" << endl;  // ouput my ans
        return;
    }

    cout << "? " << x + 1 << " " << n << endl; // can use the input of judge as my output querry
    cin >> x;

    if(x == -1) exit(0);
    if(x == 0) {
        cout << "! NO" << endl;
        return;
    }

    cout << "? 2 " << n << endl;
    cin >> x;

    if(x == -1) exit(0);
    if(x == 0) {
        cout << "! NO" << endl;
        return;
    }

    cout << "? 1 " << n - 1 << endl;
    cin >> x;
    if(x == -1) exit(0);
    if(x == n - 1) {
        cout << "! NO" << endl;
        return;
    }
    cout << "! YES" << endl;   
}
int main() {
    ios_base::sync_with_stdio(NULL); 
    cin.tie(NULL);

    ll t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;   
}
