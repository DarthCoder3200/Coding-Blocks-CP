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

int32_t main(){
	fast();
	int n,m;cin>>n>>m;
	map<int,set<int>> g;
	fr(i,0,m){
		int a,b;
		cin>>a>>b;
		g[a].insert(b);
		g[b].insert(a);
	}
	set<int> y;
	set<int> x;
	set<int> z;
	fr(i,1,n+1){
		z.insert(i);
	}
	for(auto d:g){
		if(d.second.size() == n) y.insert(d.first),z.erase(d.first);
	}
	int ans = 1;
	for(auto k:g){
		if(y.find(k.first) == y.end()){
			for(auto d:k.second) if(y.find(d) == y.end()) x.insert(d),z.erase(d);
			x.insert(k.first),z.erase(k.first); 
			
			break;
		}
	}
	set<int> z_y;
	set<int> x_y;
	for(auto d:y) z_y.insert(d),x_y.insert(d);
	for(auto d:x) x_y.insert(d);
	for(auto d:z) z_y.insert(d);
		cout<<endl;

	for(auto k:g){
		if(z.find(k.first)!=z.end()) {
			k.second.insert(k.first);
			if(k.second != z_y){

				ans = 0;
				break;
			}
		}
		if(x.find(k.first)!=x.end()) {
			k.second.insert(k.first);
			if(k.second != x_y){

				ans = 0;
				break;
			}
		}
	}
	if(ans) cout<<"YES";
	else cout<<"NO";


}