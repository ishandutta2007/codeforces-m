/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include<bits/stdc++.h>
#define int long long
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
        while(isspace(ch))ch=get();
        while(!isspace(ch))ret.push_back(ch),ch=get();
        return ret;
    }
    void putstr(string s){
        for(int i=0;i<s.size();i++)put(s[i]);
    }
    template<class T>void putint(T x){
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
    template<class T>void putln(T x){
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
	struct Flusher_ {
		~Flusher_(){clear();}
	}io_flusher_;
}
using namespace fastio;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1e9+7;
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
struct Max_Flow{
	#define MAXN 666
	struct edge{
		int to,flow,rev,ori;
		edge(int _to,int _flow,int _rev){to=_to;flow=_flow;ori=_flow;rev=_rev;}
	};
	vector<edge>g[MAXN];
	void clear(){
		for(int i=0;i<MAXN;i++)g[i].clear();
	}
	void reset(){
		for(int i=0;i<MAXN;i++){
			for(int j=0;j<g[i].size();j++){
				g[i][j].flow=g[i][j].ori;
			}
		}
	}
	void add_edge(int x,int y,int z){
		cerr<<x<<" "<<y<<" "<<z<<endl;
		g[x].push_back(edge(y,z,g[y].size()));
		g[y].push_back(edge(x,0,(int)g[x].size()-1));
	}
	int q[MAXN],dist[MAXN],itr[MAXN],b,e;
	bool bfs(int s,int t){
		memset(dist,inf,sizeof dist);
		b=e=0;q[e++]=s;
		dist[s]=0;
		while(b<e){
			int x=q[b++];
			for(int i=0;i<g[x].size();i++){
				int to=g[x][i].to;
				if(dist[to]>dist[x]+1&&g[x][i].flow>0){
					dist[to]=dist[x]+1;
					q[e++]=to;
				}
			}
		}
		return dist[t]<inf;
	}
	int dfs(int x,int t,int f){
		if(x==t)return f;
		int ret=0;
		for(int &i=itr[x];i<g[x].size();i++){
			int to=g[x][i].to;
			if(dist[to]!=dist[x]+1)continue;
			if(!g[x][i].flow)continue;
			int v=dfs(to,t,min(f-ret,g[x][i].flow));
			ret+=v;
			g[x][i].flow-=v;
			g[to][g[x][i].rev].flow+=v;
			if(ret==f)break;
		}
		return ret;
	}
	int max_flow(int s,int t){
		int ret=0;
		while(bfs(s,t)){
			memset(itr,0,sizeof itr);
			ret+=dfs(s,t,INT_MAX);
		}
		return ret;
	}
}G;
int n,S=664,T=665;
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		while(x--){
			int y;cin>>y;
			G.add_edge(i,y+n,(ll)1e14);
		}
	}
	ll got=0;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		G.add_edge(i+n,T,1e9);
		G.add_edge(S,i,1e9-x);
		got+=x;
	}
	got+=G.max_flow(S,T);
	for(int i=1;i<=n;i++)got-=1e9;
	cout<<got<<endl;
	return 0;
}