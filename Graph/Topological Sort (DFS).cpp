#define pb push_back
void dfs(int node, vector<int> &vis, stack<int> &st, vector<vector<int>> &adj) {

    vis[node] = 1;
    for(auto it : adj[node]) {
        if(!vis[it]) {
            dfs(it, vis, st, adj);
        }
    }

    st.push(node);
}

vector<int> topSort(int n, vector<vector<int>> &adj) {

    vector<int> vis(n + 1, 0);
    stack<int> st;

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs(i, vis, st, adj);
        }
    }

    vector<int> ans;

    while(!st.empty()) {
        ans.pb(st.top());
        st.pop();
    }

    return ans;
}
