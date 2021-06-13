//Wahe Guru ji ka Khalsa Wahe Guru ji ki Fateh
//HARJOT SINGH
//Software Developer and Data Scientist
//Contact me @ harjot3200@gmail.com
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define frn(i,a,b) for(int i=a;i>=b;i--)
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pair<int,int>>
#define test int t;cin>>t; while(t--)
#define mp make_pair
#define pb push_back
#define pu push
void fast(){ 
ios_base::sync_with_stdio(false); cin.tie(NULL); 
#ifndef ONLINE_JUDGE 
	freopen("input.txt","r",stdin); 
	freopen("output.txt","w",stdout); 
#endif
}

int n;int mj;
map<int,bool> vis;
map<int,list<int>> m;
int c;
void dfs(int i){
	vis[i] = 1;
	c++;
	for(auto x:m[i]) if(!vis[x]) dfs(x);
}
int32_t main(){
	fast();
	cin>>n>>mj;
	fr(i,0,n) vis[i] = false;
	fr(i,0,mj){
		int a,b;
		cin>>a>>b;
		m[a].pb(b);m[b].pb(a);
	}
	int ans = 0;
	fr(i,0,n){
		if(!vis[i]){
			c = 0;
			dfs(i);
			ans += c*(n-c);
		}
	}

	cout<<ans/2;
}