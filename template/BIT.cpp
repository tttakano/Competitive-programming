//https://yukicoder.me/problems/no/59

int n,k;
int w[1000003];
int check[1000003];

int bit[1000003];

//i番目までの合計を求める
//sum(t)-sum(s-1)で区間(s,t)の合計が出る
int sum(int i){
  int s=0;
  while(i>0){
    s+=bit[i];
    i-=i&-i;
  }
  return s;
}

//i番目にxをたす
void add(int i,int x){
  while(i<=1000003){
    bit[i]+=x;
    i+=i&-i;
  }
}

int main(){
  cin >> n >> k;
  REP(i,1000003)bit[i]=0;
  REP(i,n){
    int w;cin>>w;
    if(w>0){
      if(sum(1000003)-sum(w-1)<k){
        add(w,1);
      }
    }else{
      if(sum(-w)-sum(-w-1)>=1){
        add(-w,-1);
      }
    }
  }
  print(sum(1000003));
}