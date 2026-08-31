#define ll long long int
ll binpow(ll a, ll b, ll M) {
    a = a % M;
    ll ans = 1;
    while(b) {
        if(b&1) ans = (ans * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }
    return ans;
}
