#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		int ans=0,cnt;
		for(ri i=1;i<=n;++i)
			if(a[i]){
				++ans;
				for(ri j=i;j<=n;++j){
					if(a[j])a[j]=0;
					else break;
				}
			}
		printf("%d\n",min(ans,2));
	}
	return 0;
}