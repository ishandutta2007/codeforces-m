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

const int N=1010;
VI e[N];
int n,p[N];
bool val;
bool dfs(int u,int f) {
	int lef=0; int sn=0;
	for (auto v:e[u]) if (v!=f) {
		lef+=dfs(v,u);
		sn++;
	}
	if (sn==0) return 1;
	if (lef<3) val=0;
	return 0;
}
int main() {
	scanf("%d",&n);
	rep(i,2,n+1) {
		scanf("%d",&p[i]);
		e[p[i]].pb(i);
	}
	val=1;
	dfs(1,0);
	if (val) {
		puts("Yes");
		return 0;
	}
	puts("No");
}