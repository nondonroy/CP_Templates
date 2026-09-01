const int N = 1e5 + 5;
vector<int> graph[N];
int par[N];

// DFS to store the parent of every node
void dfs(int vertex, int p) {
    par[vertex] = p;

    for(auto child : graph[vertex]) {
        // Skip the parent node
        if(child == p) continue;

        dfs(child, vertex);
    }
}
// Find the path from root to node v
vector<int> path(int v) {
    vector<int> ans;
    while(v != -1) {
        ans.push_back(v);
        v = par[v];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int v1, v2;
        cin >> v1 >> v2;
      
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    // Root the tree at node 1
    dfs(1, -1);

    int x, y;
    cin >> x >> y;

    // Get paths from root to x and y
    vector<int> path_x = path(x);
    vector<int> path_y = path(y);

    int len = min(path_x.size(), path_y.size());

    int lca = -1;
    // Find the last common node
    for(int i = 0; i < len; i++) {
        if(path_x[i] == path_y[i]) lca = path_x[i];
        else break;
    }
    cout << lca << endl;
}
