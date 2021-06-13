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
unordered_map<string,int> kg;
unordered_map<int,string> kg2;
map<int,list<int>> m;
int n,mj;
int32_t main(){
	fast();
	int er = 0;
	while(!cin.eof()){
		er++;
		//int n,mj;
		cin>>n;

		string s;
		fr(i,0,n){
			cin>>s;
			kg[s] = i;
			kg2[i] = s;
		}
		cin>>mj;
		int indegree[n+1];
		memset(indegree,0,sizeof indegree);
		fr(i,0,mj){
			string a,b;
			cin>>a>>b;
			m[kg[a]].pb(kg[b]);
			indegree[kg[b]]++;
		}
		queue<int> order;
		queue<int> sr;
		fr(i,0,n) if(!indegree[i]) order.push(i),sr.push(i);
		while(!sr.empty()){
			int a = sr.front();
			sr.pop();
			for(auto x:m[a]){
				indegree[x]--;
				if(!indegree[x]) order.push(x),sr.push(x); 
			}
		}
		cout<<"Case #"<<er<<": Vivek should drink beverages in this order:";
		while(!order.empty()){
			cout<<" "<<kg2[order.front()];
			order.pop();
		}
		cout<<'.';
		cout<<endl;
	}
}