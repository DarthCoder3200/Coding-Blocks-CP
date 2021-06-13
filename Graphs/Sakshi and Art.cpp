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
map<pair<int,int>,list<pair<int,int>>> m;
map<pair<int,int>,bool> vis;
int dfs(pair<int,int> src){
	vis[src] = true;
	int ans = m[src].size()%2;
	for(auto i:m[src]){
		if(!vis[i]) ans+=dfs(i);
	}
	return ans;
}
int32_t main() {
	fast();
	int n;
	cin>>n;
	int a,b,c,d;
	while(n--){
		cin>>a>>b>>c>>d;
		m[make_pair(a,b)].push_back(make_pair(c,d));
		m[make_pair(c,d)].push_back(make_pair(a,b));
	}
	
	for(auto i:m) vis[i.first]= false;
	c = 0;
	int ans  = 0;
	for(auto i:m){
		if(!vis[i.first]){
			c++;
			ans += max(dfs(i.first),(int)2);
		}
	}
	cout<<ans/2-1;
	return 0;
}