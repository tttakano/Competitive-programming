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

int main(){
  int n;
  cin>>n;
  int a[1502];
  int b[1502];
  priority_queue<PI, vector<PI>, greater<PI> > pque;
  REP(i,n){
    cin>>a[i];
    pque.push(make_pair(a[i],0));
  }
  REP(i,n)cin>>b[i];
  int min_=mod;
  REP(i,n){
    int max_=(-1)*mod;
    auto cp=pque;
    REP(j,n){
      int enemy=(i+j)%n;
      PI now=cp.top();
      cp.pop();
      now.first+=b[enemy]/2;
      now.second++;
      cp.push(make_pair(now.first,now.second));
    }
    while(!cp.empty()){
      PI s=cp.top();
      cp.pop();
      max_=max(max_,s.second);
    }
    min_=min(min_,max_);
  }
  print(min_);
}