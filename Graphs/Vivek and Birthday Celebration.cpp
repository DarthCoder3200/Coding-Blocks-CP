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
int n,mj;
map<int,list<int>> m;
map<int,bool> vis; 

int dfs(int i){
	vis[i] = true;
	int k = 1;
	for(auto x: m[i]){
		if(!vis[x]) k+= dfs(x);  
	}
	return k;
}
int32_t main(){
	fast();
	cin>>n>>mj;
	fr(i,0,mj){
		int a,b;cin>>a>>b;
		m[a].pb(b);
	}
	int ans = n;
	fr(i,1,n+1) vis[i] = false;
	fr(i,1,n+1){
			fr(i,1,n+1) vis[i] = false;
			ans = min(ans,dfs(i));
	}
	cout<<ans;
}