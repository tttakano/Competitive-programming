#include <iostream>
#include "bits/stdc++.h"
using namespace std;
#define print(x) cout<<x<<endl;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a) for(int i=0;i<a;i++)
#define jkl int debug = 0;
#define RREP(i,a) for(int i=a-1;i>=0;i--)
#define rrep(i,a,b) for(int i=a-1;i>=b;i--)
#define printall(n,array) {for(int i=0;i<n;i++){cout<<array[i]<<" ";}cout<<endl;}
#define U() cout<<endl;
typedef long long ll;
typedef pair<int, int> Pi;
typedef pair<int, Pi> V;
typedef vector<ll> VE;
const ll mod = 1e9 + 7; //10^9+7

//https://beta.atcoder.jp/contests/abc034/tasks/abc034_c
//x^p%modを計算する
ll modpow(int x, int p){
    if(p == 0) return 1;
    if(p % 2) return  x * modpow(x, p - 1) % mod;
    else {
        ll res = modpow(x, p / 2);
        return res * res % mod;
    }
}