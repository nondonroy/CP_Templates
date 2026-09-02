const int N = 1e5 + 5;

vector<int> rnk(N, 0);
vector<int> par(N);
vector<int> sz(N, 1);

int findpar(int node) {
    if (node == par[node]) return node;
    return par[node] = findpar(par[node]);
}

void unionByrank(int u, int v) {
    int ulp_u = findpar(u);
    int ulp_v = findpar(v);

    if (ulp_u == ulp_v) return;

    if (rnk[ulp_u] < rnk[ulp_v]) {
        par[ulp_u] = ulp_v;
    }
    else if (rnk[ulp_u] > rnk[ulp_v]) {
        par[ulp_v] = ulp_u;
    }
    else {
        par[ulp_v] = ulp_u;
        rnk[ulp_u]++;
    }
}

void unionBysize(int u, int v) {
    int ulp_u = findpar(u);
    int ulp_v = findpar(v);
  
    if (ulp_u == ulp_v) return;
    if (sz[ulp_u] < sz[ulp_v]) {
        par[ulp_u] = ulp_v;
        sz[ulp_v] += sz[ulp_u];
    }
    else {
        par[ulp_v] = ulp_u;
        sz[ulp_u] += sz[ulp_v];
    }
}

void solve() {
    for (int i = 0; i < N; i++) par[i] = i; // initialize parent 
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        unionByrank(u, v); // choose one way of union
    }
}
