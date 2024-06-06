#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
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
    template<class T>friend modint operator^(modint a,T b){return a/=b;}
    template<class T>friend modint operator/(modint a,T b){return a/=b;}
    friend modint operator^(modint a,int b){return a^=b;}
    friend bool operator==(modint a,int b){return a.val==b;}
    friend bool operator!=(modint a,int b){return a.val!=b;}
    inline bool operator!(){return !val;}
    inline modint operator-(){return val?mod-val:0;}
    inline modint &operator++(){return *this+=1;}
};
using mi=modint;
int cnt[31][maxn],m,n,t_case;
signed main(){
    scanf("%d",&t_case);
    while(t_case--){
        scanf("%d%d",&n,&m);
        for(ri i=0;i<30;++i)clear(cnt[i],n);
        while(m--){
			ri l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			for(ri i=0;i<30;++i)
				if(!(x&(1<<i)))
					++cnt[i][l],--cnt[i][r+1];
		}
		mi ans=0;
		for(ri i=0;i<30;++i){
			ri tot=0;
			for(ri j=1;j<=n;++j){
				cnt[i][j]+=cnt[i][j-1];
				if(!cnt[i][j])++tot;
			}
			if(tot)ans+=mi(2)^(n-1+i);
		}
		printf("%d\n",ans);
    }
    return 0;
}