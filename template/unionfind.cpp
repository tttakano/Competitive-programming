int par[10002]; //親を表す
int myrank[10002];  //木の深さを表す

void init(int n){   //初期化
  REP(i,n){
    par[i]=i;
    myrank[i]=0;
  }
}

int find(int x){    //親を見つける
  if(par[x]==x){
    return x;
  }else{
    return par[x]=find(par[x]);
  }
}

void unit(int x, int y){    //x,yを併合
  x=find(x);
  y=find(y);
  if(x==y)return;

  if(myrank[x]<myrank[y]){
    par[x]=y;
  }else{
    par[y]=x;
    if(myrank[x]==myrank[y])myrank[x]++;
  }
}

bool same(int x, int y){    //x,yが同じグループか判定
  return find(x)==find(y);
}

int size(int x, int n){     //xのグループの要素数を求める
  int group=find(x);
  int size=0;
  rep(i,1,n+1)if(find(i)==group)size++;
  return size;
}

int main(){

}