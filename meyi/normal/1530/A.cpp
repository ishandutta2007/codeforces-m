#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline void ckmax(int &x,const int &y){if(x<y)x=y;}
template<class T>inline void ckmin(int &x,const int &y){if(x>y)x=y;}
int a[maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		ri k=0;
		while(n)k=max(k,n%10),n/=10;
		printf("%d\n",k);
	}
}