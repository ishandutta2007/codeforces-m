#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10,mod=1e9+7;
struct modint{
	int val;
	inline modint(int val_=0):val(val_){}
	inline modint &operator=(int val_){return val=val_,*this;}
	inline modint &operator+=(const modint &k){return val=val+k.val>=mod?val+k.val-mod:val+k.val,*this;}
	inline modint &operator-=(const modint &k){return val=val-k.val<0?val-k.val+mod:val-k.val,*this;}
    inline modint &operator*=(const modint &k){return val=1ll*val*k.val%mod,*this;}
    inline modint &operator^=(int k){
        modint ret=1,tmp=*this;
        for(;k;k>>=1,tmp*=tmp)if(k&1)ret*=tmp;
        return val=ret.val,*this;
    }
    inline modint &operator/=(modint k){return *this*=(k^=mod-2);}
    inline modint &operator+=(int k){return val=val+k>=mod?val+k-mod:val+k,*this;}
    inline modint &operator-=(int k){return val=val<k?val-k+mod:val-k,*this;}
    inline modint &operator*=(int k){return val=1ll*val*k%mod,*this;}
    inline modint &operator/=(int k){return *this*=((modint(k))^=mod-2);}
    template<class T>friend modint operator+(modint a,T b){return a+=b;}
    template<class T>friend modint operator-(modint a,T b){return a-=b;}
    template<class T>friend modint operator*(modint a,T b){return a*=b;}
    template<class T>friend modint operator/(modint a,T b){return a/=b;}
    friend modint operator^(modint a,int b){return a^=b;}
    friend bool operator==(modint a,int b){return a.val==b;}
    friend bool operator!=(modint a,int b){return a.val!=b;}
    inline bool operator!(){return !val;}
    inline modint operator-(){return val?mod-val:0;}
    inline modint &operator++(int){return *this+=1;}
};
using mi=modint;
mi fac[maxn],ifac[maxn],pw2[maxn],pw2n[maxn];
inline void init(int sz){
	fac[0]=1;
	for(ri i=1;i<=sz;++i)fac[i]=fac[i-1]*i;
	ifac[sz]=1/fac[sz];
	for(ri i=sz;i;--i)ifac[i-1]=ifac[i]*i;
	pw2[0]=1;
	for(ri i=1;i<=sz;++i)pw2[i]=pw2[i-1]*2;
}
inline mi C(int x,int y){
	if(x<y)return 0;
	return fac[x]*ifac[y]*ifac[x-y];
}
int a[maxn],k,m,n,t_case;
int main(){
	init(200000);
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&k);
		if(n&1){
			mi tmp=1;
			for(ri i=0;i<n;i+=2)tmp+=C(n,i);
			printf("%d\n",tmp^k);
		}
		else{
			pw2n[0]=1;
			for(ri i=1;i<=k;++i)pw2n[i]=pw2n[i-1]*pw2[n];
			mi ans=0,tmp=0;
			for(ri i=0;i<n;i+=2)tmp+=C(n,i);
			for(ri i=0;i<=k;++i){
				ans+=(tmp^(k-i))*(i?pw2n[i-1]:1);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}