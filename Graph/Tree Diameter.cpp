const int N = 1e5 + 5;

vector<int> graph[N];
int depth[N];

void dfs(int vertex, int par) {
  
    for(auto child : graph[vertex]) {
        if(child == par) continue;
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
    }
  
}

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i < n - 1; i++) {
        int v1, v2;
        cin >> v1 >> v2;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    // Find the max depth node from node 1
    dfs(1, -1);

    int mx_depth = -1;
    int mx_depth_node;

    for(int i = 1; i <= n; i++) {
        if(depth[i] > mx_depth) {
            mx_depth = depth[i];
            mx_depth_node = i;
        }
        depth[i] = 0;
    }
    // Find the diameter starting from the max depth node node
    dfs(mx_depth_node, -1);

    mx_depth = -1;
    for(int i = 1; i <= n; i++) {
        if(depth[i] > mx_depth) {
            mx_depth = depth[i];
        }
    }

    cout << mx_depth << endl;
}
