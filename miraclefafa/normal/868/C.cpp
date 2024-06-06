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

int n,k,cnt[20],x;
int main() {
	scanf("%d%d",&n,&k);
	rep(i,0,n) {
		int s=0;
		rep(j,0,k) {
			scanf("%d",&x);
			s=s*2+x;
		}
		cnt[s]++;
	}
	rep(i,0,(1<<k)) rep(j,0,(1<<k)) if (cnt[i]>0&&cnt[j]>0&&((i&j)==0)) {
		puts("YES");
		return 0;
	}
	puts("NO");
}