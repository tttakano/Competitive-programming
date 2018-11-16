//最大公約数
int gcd(int m,int n){
  if((m==0)||(n==0))return 0;

  while(m!=n){
    if(m>n)m=m-n;
    else n=n-m;
  }
  return m;
}

//最大公約数(再帰型、こっちのがはやい)
long long gcd(long long m,long long n){
    if(n == 0)return m;
    return gcd(n, m % n);
}

//最小公倍数
int lcm( int m, int n )
{
	if ( ( 0 == m ) || ( 0 == n ) )
		return 0;

	return ((m / gcd(m, n)) * n);
}
