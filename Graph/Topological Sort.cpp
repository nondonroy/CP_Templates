#define ll long long int
#define endl '\n'
#define pb push_back

void dfs(ll node, vector<ll> &vis, stack<ll> &st, vector<vector<ll>> &adj) {

    vis[node] = 1;
    for(auto it : adj[node]) {
        if(!vis[it]) {
            dfs(it, vis, st, adj);
        }
    }

    st.push(node);
}

vector<ll> topSort(ll n, vector<vector<ll>> &adj) {

    vector<ll> vis(n + 1, 0);
    stack<ll> st;

    for(ll i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs(i, vis, st, adj);
        }
    }

    vector<ll> ans;

    while(!st.empty()) {
        ans.pb(st.top());
        st.pop();
    }

    return ans;
}
