const int N = 1e7 + 5; // total primes 664579
vector<bool> isPrime(N, true);

void sieve() {
    isPrime[0] = isPrime[1] = false;

    for (ll i = 2; i * i < N; i++) {
        if (isPrime[i]) {
            for (ll j = i * i; j < N; j += i) {
                isPrime[j] = false;
            }
        }
    }
}
