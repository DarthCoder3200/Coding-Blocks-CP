#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fr(a,b) for(int i=a;i<b;i++)
#define frn(a,b) for(int i=a;i>=b;i--)
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
	int n,k;
	cin>>n>>k;
	int l;
	int g = 0;
	priority_queue<int> pq;
	for(int i=0;i<n;i++){
		cin>>l;
		if(l==2){
			cout<<pq.top();
			cout<<endl;
		}
		else {
			int a,b;
			cin>>a>>b;
			int d = a*a + b*b;
			if(g<k) {pq.push(d); g++;}
			else if(d<pq.top()){
				pq.pop();
				pq.push(d);
			}
		}
	}
	return 0;
}