/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
namespace fastio{
    char in[100000];
    int itr=0,llen=0;
    char get(){
        if(itr==llen)llen=fread(in,1,100000,stdin),itr=0;
        if(llen==0)return EOF;
        return in[itr++];
    }
    char out[100000];
    int itr2=0;
    void put(char c){
        out[itr2++]=c;
        if(itr2==100000){
            fwrite(out,1,100000,stdout);
            itr2=0;
        }
    }
    int clear(){
        fwrite(out,1,itr2,stdout);
        itr2=0;
        return 0;
    }
    int getint(){
        int ret=0;char ch=get();
        if(ch=='-')return -getint();
        while (ch<'0'||ch>'9'){
            ch=get();if(ch=='-')return -getint();
        }
        while ('0'<=ch&&ch<='9'){
            ret=ret*10-48+ch;
            ch=get();
        }
        return ret;
    }
    string getstr(){
        string ret="";
        char ch=get();
        while(ch==' '||ch=='\n')ch=get();
        while(ch!=' '&&ch!='\n')ret.push_back(ch),ch=get();
        return ret;
    }
    void putstr(string s){
        for(int i=0;i<s.size();i++)put(s[i]);
    }
    void putint(int x){
        if(x<0){
            put('-');
            putint(-x);
            return;
        }
        if(x==0){
            put('0');put(' ');
            return;
        }
        char c[40];int pos=0;
        while(x){
            c[pos++]='0'+x%10;
            x/=10;
        }
        for(int i=pos-1;i>=0;i--)put(c[i]);
        put(' ');
    }
    void putln(int x){
        if(x<0){
            put('-');
            putln(-x);
            return;
        }
        if(x==0){
            put('0');put('\n');
            return;
        }
        char c[40];int pos=0;
        while(x){
            c[pos++]='0'+x%10;
            x/=10;
        }
        for(int i=pos-1;i>=0;i--)put(c[i]);
        put('\n');
    }
}
using namespace fastio;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
inline int Rand(){return rand()*32768+rand();}
map<int,int>mp[1000005];
int n,ans[1000005],res[1000005],cnt[1000005];
vector<int>g[1000005];
void dfs(int x,int par,int dep){
	int pos=-1;
	for(auto to:g[x]){
		if(to!=par){
			dfs(to,x,dep+1);
			if(pos==-1||mp[pos].size()<mp[to].size())pos=to;
		}
	}
	mp[x].swap(mp[pos]);
	ans[x]=ans[pos];
	cnt[x]=cnt[pos];
	for(auto to:g[x]){
		if(to!=par&&to!=pos){
			for(auto p:mp[to]){
				int &v=mp[x][p.first];
				v+=p.second;
				if(make_pair(v,-p.first)>make_pair(cnt[x],-ans[x])){
					cnt[x]=v;
					ans[x]=p.first;
				}
			}
		}
	}
	mp[x][dep]++;
	if(make_pair(mp[x][dep],-dep)>make_pair(cnt[x],-ans[x])){
		cnt[x]=mp[x][dep];
		ans[x]=dep;
	}
	res[x]=ans[x]-dep;
	for(auto to:g[x]){
		if(to!=par){
			mp[to].clear();
		}
	} 
}
int main(){
	n=getint();
	for(int i=1;i<n;i++){
		int x=getint(),y=getint();
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,-1,0);
	for(int i=1;i<=n;i++)putln(res[i]);
	clear();
	return 0;
}