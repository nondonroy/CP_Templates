// nCr mod Prime
// M is Prime
#define ll long long int
ll lucas(ll n, ll r) {
    ll ans = 1;
    while(n || r) {
        ll ni = n % M;
        ll ri = r % M;
        if(ri > ni) return 0;
        n /= M;
        r /= M;
        ans = (ans * nCr(ni, ri)) % M;
    }
    return ans;
}
