
vector<int> enumdiv(int n){
  vector<int> s;
  for(int i=1;i*i<=n;i++){
    if(n%i==0){
      s.push_back(i);
      if(i*i!=n)s.push_back(n/i);
    }
  }
  sort(s.begin(),s.end());
  return s;
}
