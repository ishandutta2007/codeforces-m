#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=101000;
int n,_;
char s[N];
void solve() {
	scanf("%d",&n);
	scanf("%s",s);
	int l=n/2,r=n/2;
	char md=s[l];
	while (l-1>=0&&s[l-1]==md) --l;
	while (r+1<n&&s[r+1]==md) ++r;
	printf("%d\n",r-l+1);
}
int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}