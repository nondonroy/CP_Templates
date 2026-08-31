#define ll long long int
const ll M = 1e9 + 7;

// pre calculate fact and inverse fact
ll fact[N], ifact[N];
void prec() {
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i % M;
  }
  ifact[N - 1] = binpow(fact[N - 1], M - 2, M);
  for (int i = N - 2; i >= 0; i--) {
    ifact[i] = ifact[i + 1] * (i + 1) % M;
  }
}

// nCr
ll nCr(ll n, ll r) {
    if(n < r) return 0;
    ll ans = (((fact[n] * ifact[n-r]) % M) * ifact[r]) % M;
    return ans;
}

// nPr
ll nPr(ll n, ll r) {
    if(n < r) return 0;
    ll ans = (((fact[n] * ifact[n-r]) % M)) % M;
    return ans;
}

