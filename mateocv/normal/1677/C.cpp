#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

/*----------------DSU------------------*/
const int MAXN=100005;
int pa[MAXN],sz[MAXN];
ll find_pa(ll pos){
	if(pa[pos]!=pos)pa[pos]=find_pa(pa[pos]);
	return pa[pos];
}
void join(int a, int b) {
	int x=find_pa(a),y=find_pa(b);
	if (x!=y) {
		if(sz[x]>=sz[y]) sz[x]+=sz[y],pa[y]=x;
		else sz[y]+=sz[x],pa[x]=y;
	}
}
void dsu_init(ll n){fore(i,0,n)pa[i]=i,sz[i]=1;}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> a(n),b(n);
		fore(i,0,n){
			cin>>a[i]; a[i]--;
		}
		fore(i,0,n){
			cin>>b[i]; b[i]--;
		}
		dsu_init(n);
		fore(i,0,n)join(a[i],b[i]);
		vector<ll> c(n);
		fore(i,0,n)c[find_pa(i)]++;
		ll k=0;
		fore(i,0,n)k+=(c[i]&1);
		ll res=0;
		fore(i,0,(n-k)/2){
			res+=n-2ll*i-1;
		}
		res*=2ll;
		cout<<res<<"\n";
	}
	
	return 0;
}