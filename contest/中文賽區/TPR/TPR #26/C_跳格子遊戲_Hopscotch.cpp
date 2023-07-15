#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
ll x,m,n,k,j,q;
char a[27],b[27],c[27];
ll mod;
ll fastpow(ll a, ll b){
  ll ans=1, res=a;
  while (b!=0) {
      if (b&1) ans = (ans*res)%MOD;
      res = (res*res)%MOD;
      b/=2;
  }
  return ans;
}

int main() {
	cin>>x>>n;
	for(ll i=0;i<n;i++) cin>>a[i];
	cin>>m;
	for(ll i=0;i<m;i++) cin>>b[i];
	cin>>k;
	for(ll i=0;i<k;i++) cin>>c[i];
	
	j=26-m-n-2*k;
	q=fastpow(fastpow(26,x),(MOD-2)); //q=q^-1
	mod=fastpow(j,x)*q%MOD;
	cout<<mod<<"\n";
	return 0;
}