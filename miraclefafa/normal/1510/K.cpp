#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

int n,p[2010],q[2010];
int main() {
	scanf("%d",&n);
	rep(i,0,2*n) {
		p[i]=i;
		scanf("%d",q+i);
		--q[i];
	}
	int prd=-1,pos=-1,k=0;
	while (1) {
		++k;
		if (k%2==0) {
			for (int i=0;i<2*n;i+=2) swap(p[i],p[i+1]);
		} else {
			rep(i,0,n) swap(p[i],p[i+n]);
		}
		int c1=0,c2=0;
		rep(i,0,2*n) c1+=(p[i]==i),c2+=p[i]==q[i];
		if (c2==2*n) {
			pos=k;
		}
		if (c1==2*n) {
			prd=k;
			break;
		}
	}
	pos=min(pos,prd-pos);
	printf("%d\n",pos);
}