//あり本 p135

#include <iostream>
#include "bits/stdc++.h"
using namespace std;
#define print(x) cout<<x<<endl;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a) for(int i=0;i<a;i++)
#define debug int debug = 0;
#define RREP(i,a) for(int i=a-1;i>=0;i--)
#define rrep(i,a,b) for(int i=a-1;i>=b;i--)
#define printall(n,array) {for(int i=0;i<n;i++){cout<<array[i]<<" ";}cout<<endl;}
#define U() cout<<endl;
typedef long long ll;
typedef pair<int, int> PI;
typedef pair<int, PI> V;
typedef vector<int> VE;
const ll mod = 1000000007; //10^9+7

int n, S;
int a[100002];

void solve(){
    int res = n + 1;
    int s = 0, t = 0, sum = 0;
    while(true){
        while(t < n && sum < S){
            sum += a[t++];
        }
        if(sum < S) break;
        res = min(res, t - s);
        sum -= a[s++];
    }
    if(res > n){
        res = 0;
    }
    print(res);
}

int main(){
    cin >> n;
    cin >> S;
    REP(i, n){
        cin >> a[i];
    }
    solve();
}
