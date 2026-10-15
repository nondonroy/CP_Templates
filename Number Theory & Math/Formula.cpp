// Find the smallest n such that n*(n+1)/2 >= m
ll findBlock(ll m) {
    return ceil((sqrtl(8.0L * m + 1) - 1) / 2);
}
