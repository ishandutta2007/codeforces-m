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
#define SZ(x) ((int)x.size())
#define mset(x,a) (memset((x),(a),sizeof(x)))
#define mcpy(x,y) (memcpy((x),(y),sizeof(x)))
using namespace std;
typedef long long ll;

pair<ll,ll> x[200005];
int n;

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		ll a,w;
		scanf("%lld%lld",&a,&w);
		x[i]=mp(a+w,a-w);
	}
	sort(x,x+n);
	ll l=-(1LL<<40);
	int r=0;
	fore(i,0,n)if(x[i].snd>=l)l=x[i].fst,r++;
	printf("%d\n",r);
	return 0;
}