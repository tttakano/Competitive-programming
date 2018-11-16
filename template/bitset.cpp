//https://cpprefjp.github.io/reference/bitset.html

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
  bitset<8> bs1(131LL); //131を2進数変換
  print(bs1);
  if(bs1[1])print("1st"); //1bit目が1か判定
  bs1.set(2);// 2ビット目を１にする
  print(bs1);
  bs1.reset(2);//2ビット目を０に戻す
  print(bs1);
  if(bs1.any())print("any");//いずれかが1か判定

  bitset<8> and_bits=bs1&bitset<8>("10000001");//論理積
  bitset<8> or_bits=bs1|bitset<8>("00010100");//論理和
  bitset<8> xor_bits=bs1^bitset<8>("00100011");//排他的論理和
  print(and_bits);
  print(or_bits);
  print(xor_bits);
}
