const ll N=1e5+5;
vector<ll> graph[N];
bool vis[N];

void dfs(ll vertex) {
    /* take ation on vertex ater
    entering the vertex */
    // if(vis[vertex])  return;
    vis[vertex] = true;
    for(auto child: graph[vertex]) {
        if(vis[child]) continue;
        /* take action on child before
        entering the child node */
        dfs(child);
        /*take action on child after
        exciting child node */
    }
    /*take action on vertex before
    exciting the vertex */
}//TC -> (V+E);
