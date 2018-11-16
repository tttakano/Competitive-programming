//https://yukicoder.me/problems/no/67

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

int n;
ll l[202020];
ll k;

int main(){
  cin>>n;
  ll big=0;
  REP(i,n){
    cin>>l[i];
    big=max(big,l[i]);
  }
  cin>>k;
  sort(l,l+n);
  double right=big;
  double left=0;
  double max_=0;
  REP(q,101){
    double mid=(left+right)/2;
    ll val=0;
    REP(i,n){
      val+=l[i]/mid;
    }
    if(val<k)right=mid;
    else if(val>=k)left=mid;
  }
  printf("%.10f",left);
  print("");
}