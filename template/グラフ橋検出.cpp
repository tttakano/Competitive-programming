//無向グラフの橋(取ると連結成分が増えるのも)を検出
//https://beta.atcoder.jp/contests/abc075/tasks/abc075_c

bool visited[52];
ll n, m, cnt = 0;
ll a[52], b[52], graph[52][52] = {};

int dfs(int u){
    visited[u] = true;
    rep(i, 1, n + 1){
        if(graph[u][i] == 0 || visited[i])continue;
        dfs(i);
    }
    return 0;
}

int main(){
    cin >> n >> m;
    REP(i, m){
        cin >> a[i] >> b[i];
        graph[a[i]][b[i]] = graph[b[i]][a[i]] = 1;

    }
    bool bridge;
    REP(i, m){
        bridge = false;
        rep(i, 1, n + 1)visited[i] = false;
        graph[a[i]][b[i]] = graph[b[i]][a[i]] = 0;
        dfs(1);
        rep(i, 1, n + 1)if(visited[i] == 0)bridge = true;
        if(bridge)cnt++;
        graph[a[i]][b[i]] = graph[b[i]][a[i]] = 1;
    }
    print(cnt);
}