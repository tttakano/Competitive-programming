//d[i][j]はi,j間の移動コスト、d[i][i]=0,存在しない場合はd[i][j]=mod;
void warshall_floyd(){
  REP(k,n){
    REP(i,n){
      REP(j,n){
        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        d[j][i]=d[i][j];
      }
    }
  }
}