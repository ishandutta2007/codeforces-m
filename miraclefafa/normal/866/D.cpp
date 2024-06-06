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

int n,w;
ll s;
multiset<int> hs;
int main() {
	scanf("%d",&n);
//	dp[0]=0;
	rep(i,0,n) {
		scanf("%d",&w);
		hs.insert(w); hs.insert(w);
		hs.erase(hs.begin());
		s-=w;
	}
	for (auto p:hs) s+=p;
	printf("%lld\n",s);
}