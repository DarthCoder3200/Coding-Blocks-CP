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
	test{
		map<int,int> board;
		fr(i,1,101) board[i] = i;
		int n;
		cin>>n;
		fr(i,0,n){
			int a,b;
			cin>>a>>b;
			board[a] = b;
		}
		int mt;cin>>mt;
		fr(i,0,mt){
			int a,b;
			cin>>a>>b;
			board[a] = b;
		}
		map<int,list<int>> m;
		fr(i,1,101)
			fr(j,1,7)
				if(i+j<=100) if(i == board[i]) m[i].pb(board[i+j]);
		
		map<int,int> path;
		map<int,bool> vis;
		fr(i,1,101){
			path[i] = 0;
			vis[i] = false;
		}
		queue<int> q;
		q.push(1);
		path[1] = 0;
		while(!q.empty()){
			int a = q.front();
			q.pop();
			vis[a] = true;
			for(auto x:m[a]){
				if(!vis[x]){
					path[x] = path[a]+1;
					vis[x] = true;
					q.push(x);
				}
			}
		}
		if(path[100]) cout<<path[100]<<endl;
		else cout<<"-1"<<endl;
	}
}