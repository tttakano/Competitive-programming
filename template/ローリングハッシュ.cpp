
const ll mod = 1000000007; //10^9+7

//aはbにいくつ含まれるかcount

int contain(string a,string b){
  int al=a.length(),bl=b.length();
  if(al>bl)return false;
  ll t=1;
  REP(i,al)t*=mod;
  ll ah=0,bh=0;
  REP(i,al)ah=ah*mod+a[i];
  REP(i,al)bh=bh*mod+b[i];

  int cnt=0;
  for(int i=0;i+al<=bl;i++){
    if(ah==bh)cnt++;
    if(i+al<bl)bh=bh*mod+b[i+al]-b[i]*t;
  }
  return cnt;
}

int main(){
  string s;
  int m;
  string c[5010];
  cin>>s;
  cin>>m;
  REP(i,m)cin>>c[i];
  ll ans=0;
  REP(i,m)ans+=contain(c[i],s);
  print(ans);
}