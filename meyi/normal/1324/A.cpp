#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a,m,n,t_case;
bool flag[2];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		flag[0]=flag[1]=false;
		for(ri i=1;i<=n;++i)scanf("%d",&a),flag[a&1]=true;
		puts((flag[0]^flag[1])?"YES":"NO");
	}
	return 0;
}