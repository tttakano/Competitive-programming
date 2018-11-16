#include "bits/stdc++.h"
using namespace std;
#define print(x) cout<<x<<endl;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a) for(int i=0;i<a;i++)
#define printall(n,array) for(int i=0;i<n;i++){cout<<array[i]<<" ";}cout<<endl;
typedef long long ll;
typedef pair<int, int> PI;
typedef pair<int, PI> V;
typedef vector<int> VE;
const ll mod = 1000000007; //10^9+7



int dp[102][100003];
int main(){
  int n; cin>>n;
  int v[1002],w[1002];
  REP(i,n)cin>>v[i]>>w[i];
  int W; cin>>W;
  REP(i,n+1)REP(j,W+2)dp[i][j]=0;
  for(int i=n-1;i>=0;i--){
    REP(j,W+1){
      if(j<w[i]){
        dp[i][j]=dp[i+1][j];
      }else{
        dp[i][j]=max(dp[i+1][j],dp[i+1][j-w[i]]+v[i]);
      }
    }
  }
  print(dp[0][W]);
}