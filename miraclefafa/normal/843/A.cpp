#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
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
// head

const int N=201000;
int n,vis[N];
vector<VI> ret;
PII p[N];
int main() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",&p[i].fi),p[i].se=i;
	sort(p,p+n);
	rep(i,0,n) if (!vis[i]) {
		int x=i;
		VI cyc;
		while (1) {
			cyc.pb(x);
			vis[x]=1;
			x=p[x].se;
			if (x==i) break;
		}
		ret.pb(cyc);
	}
	printf("%d\n",SZ(ret));
	for (auto &p:ret) {
		printf("%d ",SZ(p));
		sort(all(p));
		for (auto q:p) printf("%d ",q+1); puts("");
	}
}