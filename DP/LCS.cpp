#include <bits/stdc++.h>
#define ll long long int
#define en '\n'
using namespace std;

const ll N = 3005;
ll dp[N][N];
string a, b;
ll n, m;
string s;

ll func(ll i, ll j) {
    if(i >= n || j >= m) return 0;
    ll &ans = dp[i][j];
    if(ans != -1) return ans;

    ans = max(ans, func(i + 1, j));
    ans = max(ans, func(i, j + 1));
    if(a[i] == b[j]) ans = max(ans, func(i + 1, j + 1) + 1);

    return ans;
}

void path(ll i, ll j) {
    if(i >= n || j >= m) return;

    ll ans1 = 0, ans2 = 0, ans3 = 0;

    ans1 = func(i + 1, j);
    ans2 = func(i, j + 1);
    if(a[i] == b[j]) ans3 = func(i + 1, j + 1) + 1;

    ll mx = max({ans1, ans2, ans3});
    if(ans1 == mx) path(i + 1, j);
    else if(ans2 == mx) path(i, j + 1);
    else {
        s += a[i];
        path(i + 1, j + 1);
    }

}

void solve() {
    cin >> a;
    cin >> b;
    
    n = a.length();
    m = b.length();

    memset(dp, -1, sizeof(dp));

    ll tt = func(0, 0);
    path(0, 0);
    
    cout << s << endl;
}
int main() {
    ios_base::sync_with_stdio(NULL); 
    cin.tie(NULL);

    int tt = 1;
    // cin >> tt;
    for(int i = 1; i <= tt; i++) {
        // cout << "Case " << i << ": ";
        solve();
    }
    return 0;   
}
