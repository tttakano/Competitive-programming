//隣接行列を使う例

int n,v,ox,oy;//n　要素数
int cost[210][210];//cost[i][j],(i,j)へのコスト
int d[210];//d[i] ,iまでにかかる最小コスト
bool used[210];//used[i],iを使ったかどうか
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};


//stからの最短経路を求める
void dijkstra(int st){
  REP(i,n)d[i]=mod;
  REP(i,n)used[i]=false;
  d[st]=0;
  while(true){
    int v=-1;
    REP(u,n){
      if(!used[u]&&(v==-1||d[u]<d[v]))v=u;
    }
    if(v==-1)break;
    used[v]=true;

    REP(u,n){
      d[u]=min(d[u],d[v]+cost[v][u]);
    }
  }
}

//stからgoへの最短経路を復元する(辞書順最小)
//一番遠い点からもとめる？
VE trace(int st, int go){
  VE ve;
  int now=st;
  while(now!=go){
    REP(i,n){
      if(d[now]-cost[now][i]==d[i]){
        ve.push_back(i);
        now=i;
        break;
      }
    }
  }
  return ve;
}


int h, w; //h: height, w: width;
int cost[210][210];//cost[i][j],(i,j)へのコスト
int d[210][210];//d[i][j],(i,j)までにかかる最小コスト
bool used[210];//used[i],iを使ったかどうか
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};


//priority_queを使う例（高速、メモリ消費少ない)

//https://beta.atcoder.jp/contests/soundhound2018-summer-qual/tasks/soundhound2018_summer_qual_d (途中

int m, st, go;
ll a[100002], b[100002], u[10002], v[100002];


int n;//number of element
const ll MAX_N = 100002;
vector<pair<ll, ll> > g[MAX_N]; //first は行き先、secondはcost　関数に入る前にiから伸びる辺をg[i]にいれておく。
ll d[MAX_N];

void dijkstra(int s){
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>> > que; //first は最短距離、secondは頂点番号
  REP(i, n + 1)d[i] = mod;
  d[s] = 0;
  que.push(make_pair(0, s));

  while(!que.empty()){
    auto p = que.top(); que.pop();
    ll v = p.second;
    if(d[v] < p.first)continue;
    REP(i, g[v].size()){
      auto e = g[v][i];
      if(d[e.first] > d[v] + e.second){
        d[e.first] = d[v] + e.second;
        que.push(make_pair(d[e.first], e.second));
      }
    }
  }
}

int main(){
  cin >> n >> m >> st >> go;
  REP(i, m){
    cin >> u[i] >> v[i] >> a[i] >> b[i];
    g[u[i]].push_back(make_pair(v[i], a[i]));
    g[v[i]].push_back(make_pair(u[i], a[i]));
  }
  dijkstra(st);

  return 0;
}

//2次元ダイクストラ
//define only cost[i][j] before start function
int diskstra(int y,int x){ //start in (y, x)
  REP(i,h)REP(j,w)d[i][j]=mod;
  priority_queue<V,vector<V>,greater<V> >que;
  que.push(make_pair(0,make_pair(y,x)));
  d[y][x]=0;
  while(!que.empty()){
    auto c=que.top().first;
    auto now=que.top().second;
    que.pop();

    REP(i,4){
      int ny=now.first+dy[i];
      int nx=now.second+dx[i];
      if(ny<0||ny>=h||nx<0||nx>=w)continue;
      if(d[ny][nx]<=c+cost[ny][nx])continue;
      d[ny][nx]=c+cost[ny][nx];
      que.push(make_pair(d[ny][nx],make_pair(ny,nx)));
    }
  }
}


//2次元ダイクストラ(h, wが小さい時用) + 2分探索
//https://beta.atcoder.jp/contests/abc020/tasks/abc020_c

l h, w, m;
char t[102][102];
ll dp[102][102];
bool u[102][102];
ll cost;
int sx, sy, gx, gy;
ll dx[4] = {1, 0, -1, 0};
ll dy[4] = {0, 1, 0, -1};

ll dfs(ll yy, ll xx){
  priority_queue<Pi, vector<Pi>, greater<Pi> >bfs;
  bfs.push(mp(0, yy * w + xx));//x, yを1次元で表す

  while(!bfs.empty()){
    ll z = bfs.top().second, c = bfs.top().first;
    int y = z / w, x = z % w;
    bfs.pop();
    if(dp[y][x] != mod)continue;
    dp[y][z] = c;
    REP(i, 4){
      ll ny = y + dy[i], nx = x + dx[i];
      if(ny < 0 || nx < 0 || nx >= w || ny >= h)continue;
      ll sum = 1;
      if(t[ny][nx] == '#')sum = cost;
      bfs.push(mp(c + sum, ny * w + nx));
    }
  }
}

int main(){
  cin >> w >> h >> m;
  REP(i, h)REP(j, w)cin >> t[i][j];
  REP(i, h)REP(j, w){
    if(t[i][j] == 'S'){sy = i, sx = j;}
    if(t[i][h] == 'G'){gy = i, gx = j;}
  }
  REP(i, h)REP(j, w)dp[i][j] = mod;
  ll l = 1, r = mod, mid = (r + l) / 2;
  while(r - l > 1){
    cost = mid;
    REP(i, h)REP(j, w)dp[i][j] = mod;
    ll ret = dfs(sy, sx);
    if(ret > m)r = mid;
    else l = mid;
    mid = (r + l) / 2;
  }
  print(l);
}