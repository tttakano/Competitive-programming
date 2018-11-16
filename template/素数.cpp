//素数判定

bool is_prime(int n){
  for(int i=2;i*i<=n;i++){
    if(n%i==0)return false;
  }
  return n!==1;
}

//エラストテネスの篩

vector<int> prime;
bool is_prime[10002];

int sieve(int n){
  int p=0;
  REP(i,n+1)is_prime[i]=true;
  is_prime[0]=is_prime[1]=false;
  rep(i,2,n+1){
      if(is_prime[i]){
        prime.push_back(i);
        for(int j=2*i;j<=n;j+=i) is_prime[j]=false;
    }
  }
  return p;
}

//素因数分解
map<int, int>prime_factor(int n){
  map<int,int>res;
  for(int i=2;i*i<=n;i++){
    while(n%i==0){
      ++res[i];
      n/=i;
    }
  }
  if(n!=1)res[n]=1;
  return res;
}





