
//http://pekempey.hatenablog.com/entry/2015/12/09/000603

int p;
ll dp[30][2][2][3];

int main(){
  cin>>p;
  dp[0][0][0][0]=1;
  REP(i,p+1){
    REP(j,2){
      int lim;
      if(j==1)lim=9;
      else if(j==0&&i==0)lim=1;
      else lim=0;
      REP(k,2){
        REP(l,3){
          REP(m,lim+1){
            dp[i+1][j||m<lim][k||m==3][(l+m)%3]+=dp[i][j][k][l];
          }
        }
      }
    }
  }
  ll ans=0;
  REP(j,2)REP(k,2)REP(l,3){
    if(k==1||l==0){
      ans+=dp[p+1][j][k][l];
    }
  }
  print(ans-1);
}