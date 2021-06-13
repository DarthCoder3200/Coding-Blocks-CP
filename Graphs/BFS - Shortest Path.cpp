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
int n,mq;
map<int,list<int>> m;
int32_t main(){
	fast();
	test{
		cin>>n>>mq;
		fr(i,0,mq){
			int a,b;
			cin>>a>>b;
			m[a].pb(b);
			m[b].pb(a);
		}
		map<int,int> path;
		map<int,bool> vis;
		fr(i,1,n+1){
			path[i] = -1;
			//cout<<i;
			vis[i] = false;
		}
		queue<int> q;
		int s;cin>>s;
		q.push(s);
		path[s] = 0;
		while(!q.empty()){
			int a = q.front();
			q.pop();
			vis[a] = true;
			for(auto x:m[a]){
				if(!vis[x]){
					path[x] = path[a]+6;
					vis[x] = true;
					q.push(x);
				}
			}
		}
		for(auto x:path){
			if(x.second !=0) cout<<x.second<<" ";
		}
		cout<<endl;
		m.clear();
	}
}