#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

map<ll,int> w;
ll r[200005];
int n;

int main(){
	scanf("%d",&n);
	fore(_,0,n){
		ll a,b;
		scanf("%lld%lld",&a,&b);b++;
		w[a]++;w[b]--;
	}
	ll l=-1;int s=0;
	for(auto p:w){
		r[s]+=p.fst-l;
		s+=p.snd;
		l=p.fst;
	}
	fore(i,1,n+1)printf("%lld%c",r[i]," \n"[i==n]);
	return 0;
}