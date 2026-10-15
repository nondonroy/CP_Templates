// Find the smallest n such that n*(n+1)/2 >= m, which block basically
ll findBlock(ll m) {
    return ceil((sqrtl(8.0L * m + 1) - 1) / 2);
}
// Find position of m inside its block
ll findPos(ll m, ll block) {
    return m - (block * (block - 1)) / 2;
}
