#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=210;
ll ans=1;
int ans2,n,a[N],pos[N];
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",a+i);
	rep(i,1,n+1) {
		memset(pos,0,sizeof(pos));
		int j=i,cnt=0;
		while (!pos[j]) {
			pos[j]=++cnt;
			j=a[j];
		}
		ll cl=(cnt+1-pos[j]);int pl=pos[j]-1;
		ans2=max(ans2,pl);
		ans*=cl/__gcd(ans,cl);
	}
	ll ret=ans;
	while (ret<ans2) ret+=ans;
	printf("%I64d\n",ret);
}