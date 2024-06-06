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

const int N=501000;
int n,u,v,w,_,sz[N];
ll f1,f2;
vector<PII> e[N];
void dfs(int u,int f) {
	sz[u]=1;
	for (auto p:e[u]) {
		int v=p.fi;
		if (v==f) continue;
		dfs(v,u);
		sz[u]+=sz[v];
		f1+=(sz[v]%2)*p.se;
		f2+=(ll)min(sz[v],n-sz[v])*p.se;
	}
}

void solve() {
	scanf("%d",&n);
	n*=2;
	rep(i,1,n+1) e[i].clear();
	f1=0,f2=0;
	rep(i,1,n) {
		scanf("%d%d%d",&u,&v,&w);
		e[u].pb(mp(v,w));
		e[v].pb(mp(u,w));
	}
	dfs(1,0);
	printf("%lld %lld\n",f1,f2);
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}