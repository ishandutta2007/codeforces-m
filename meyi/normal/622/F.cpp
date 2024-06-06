#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e6+10,mod=1e9+7;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
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
mi fac[maxn],ifac[maxn];
inline void init(int sz){
	fac[0]=1;
	for(ri i=1;i<=sz;++i)fac[i]=fac[i-1]*i;
	ifac[sz]=1/fac[sz];
	for(ri i=sz;i;--i)ifac[i-1]=ifac[i]*i;
}
int n;
mi pre[maxn],suf[maxn],y[maxn];
inline mi lgr(int k){
	pre[0]=1;
	for(ri i=1;i<=n;++i)pre[i]=pre[i-1]*(k-i);
	suf[n+1]=1;
	for(ri i=n;i;--i)suf[i]=suf[i+1]*(k-i);
	mi ret=0;
	for(ri i=1;i<=n;++i){
		if((n-i)&1)ret-=y[i]*pre[i-1]*suf[i+1]*ifac[i-1]*ifac[n-i];
		else ret+=y[i]*pre[i-1]*suf[i+1]*ifac[i-1]*ifac[n-i];
	}
	return ret;
}
int k,m;
int main(){
	scanf("%d%d",&m,&k);
	n=k+2;
	init(n);
	for(ri i=1;i<=n;++i)y[i]=y[i-1]+(mi(i)^k);
	printf("%d",m<=n?y[m]:lgr(m));
	return 0;
}