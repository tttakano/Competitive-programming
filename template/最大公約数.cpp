int gcd(int m,int n){
  if((m==0)||(n==0))return 0;

  while(m!=n){
    if(m>n)m=m-n;
    else n=n-m;
  }
  return m;
}
