// Primality Test (64-bit)
// TC -> O(log^2 (n))
using ll = long long;

ll mul_mod(ll a, ll b, ll mod) {
    return (__int128)a * b % mod;
}

ll binpow(ll a, ll b, ll mod) {
    ll res = 1;
    while (b) {
        if (b & 1) res = mul_mod(res, a, mod);
        a = mul_mod(a, a, mod);
        b >>= 1;
    }
    return res;
}

bool miller_rabin(ll n) {
    if (n < 2) return false;

    for (ll p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n % p == 0) return n == p;
    }

    ll d = n - 1, s = 0;
    while (d % 2 == 0) {
        d /= 2;
        s++;
    }

    // Deterministic bases for 64-bit integers
    for (ll a : {2LL, 325LL, 9375LL, 28178LL,
                 450775LL, 9780504LL, 1795265022LL}) {

        if (a % n == 0) continue;

        ll x = binpow(a % n, d, n);

        if (x == 1 || x == n - 1) continue;

        bool composite = true;

        for (ll r = 1; r < s; r++) {
            x = mul_mod(x, x, n);

            if (x == n - 1) {
                composite = false;
                break;
            }
        }

        if (composite) return false;
    }

    return true;
}
