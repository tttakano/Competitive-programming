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

//x^p%modを計算
ll modpow(int x, int p){
    if(p == 0) return 1;
    if(p % 2) return  x * modpow(x, p - 1) % mod;
    else {
        ll res = modpow(x, p / 2);
        return res * res % mod;
    }
}

//nCrを計算(nが大きいとき
ll comb(ll n, int r){
    ll mul = 1;
    ll div1, div2;
    rep(i, 1, n + 1){
        mul *= i;
        mul %= mod;
        if(i == r) div1 = modpow(mul, mod - 2);
        if(i == n - r) div2 = modpow(mul, mod - 2);
    }
    return mul * div1 % mod * div2 % mod;
}

int main(){
    ll w, h;
    cin >> w >> h;
    print(comb((ll)w + h - 2, w - 1));
    return 0;
}