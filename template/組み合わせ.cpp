ll ncr[10010][10010];

//nCnまで計算
void nCr(int n){
  REP(i,n+1)REP(j,i+1){
    if(j==0)ncr[i][j]=1;
    else ncr[i][j]=ncr[i-1][j]+ncr[i-1][j-1];
  }
}

ll nPn(int n){
  ll sum=1;
  rep(i,1,n+1){
    sum*=i;
    sum%=mod;
  }
  return sum;
}