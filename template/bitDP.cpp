//https://yukicoder.me/problems/no/286

#include "bits/stdc++.h"
using namespace std;
#define print(x) cout<<x<<endl;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a) for(int i=0;i<a;i++)
#define printall(n,array) for(int i=0;i<n;i++){cout<<array[i]<<" ";}cout<<endl;
#define U() cout<<endl;
typedef long long ll;
typedef pair<int, int> PI;
typedef pair<int, PI> V;
typedef vector<int> VE;
const ll mod = 1000000007; //10^9+7

int n;
int m[16];
int dp[500000];

int main(){
  cin>>n;
  REP(i,n)cin>>m[i];
  REP(i,50000)dp[i]=mod;
  dp[0]=0;
  rep(i,1,1<<n){
    REP(j,n){
      if((1<<j)&i){
        int red=0;
        REP(k,n){
          if(i-(1<<j)&1<<k)red=(red+m[k])%1000;
        }
        dp[i]=min(dp[i],dp[i-(1<<j)]+max(0,m[j]-red));
      }
    }
  }
  int a=pow(2,n);
  print(dp[a-1]);
}