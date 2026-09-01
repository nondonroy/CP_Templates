const int N = 1e5 + 5;
vector<int> graph[N];
bool vis[N];
vector<vector<int>> cc;
vector<int> cur_cc;

void dfs(int vertex) {
    vis[vertex] = true;
    cur_cc.push_back(vertex);

    for(auto child : graph[vertex]) {
        if(vis[child]) continue;

        dfs(child);
    }
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

    int cnt = 0;

    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;

        cur_cc.clear();
        dfs(i);
        cc.push_back(cur_cc);
        cnt++;
    }

    cout << cnt << endl;
}
