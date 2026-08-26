// How many integers from 1 to n are coprime with n.
int phi(int n) {
    int ans = n;

    for (int p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            while (n % p == 0)
                n /= p;
            ans -= ans / p;
        }
    }
  
    if (n > 1)  ans -= ans / n;
    return ans;
}
