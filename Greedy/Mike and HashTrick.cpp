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

bool myc(pair<int,int> p,pair<int,int> q){
	return p.second<q.second;
}

int32_t main(){
	fast();
	int n;
	cin>>n;
	int a[n+1];
	map<int,int> m;
	int c = 0;
	for(int i=0;i<n;i++){
		int l;
		cin>>l;
		a[i] = l;
		if(m.find(l) == m.end()){
			m[l] = -1;
			c++;
		}
	}
	for(int i=n-1;i>=0;i--){
		if(m[a[i]] == -1) {
			m[a[i]] = c;
			c--;
		}
	}
	vector<pair<int,int>> p;
	for(auto x:m) p.push_back(x);
	sort(p.begin(),p.end(),myc);
	for(auto x:p) cout<<x.first<<endl;
}