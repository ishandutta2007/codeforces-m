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
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=201000;
int n,x,a[N],b[N];

ll ans=0;

int main() {
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%d",a+i);
		int c=0;
		rep(j,0,a[i]) {
			scanf("%d",&x);
			c=max(c,x);
		}
		b[i]=c;
	}
	int c=*max_element(b,b+n);
	rep(i,0,n) {
		ans+=(ll)(c-b[i])*a[i];
	}
	printf("%lld\n",ans);
}