#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fr(i,a,b) for(int i=a;i<b;i++)
#define frn(i,a,b) for(int i=a;i>=b;i--)
#define vi vector<int>
#define pii pair<int,int>
#define vpi vector<pair<int,int>>
#define vvi vector<vector<int>>
#define test int t;cin>>t; while(t--)
#define mp make_pair
#define pb push_back
#define pu push
#define fi first
#define se second
#define mod 1000000007
void fast() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int n;
unordered_map<string,int > m;
unordered_map<string,int > st;
int bit[100005];
void update(int i,int val){
	while(i<=100000){
		bit[i] += val;
		i += i&(-i);
	}
}
int query(int i){
	int s = 0;
	while(i>0){
		s+=bit[i];
		i -= i&(-i);
	}
	return s;
}
int32_t main() {
	fast();
	
	int to = 0;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		int l;
		cin>>l;
		m[s] = l;
		st[s] = 0;
	}
	int q;
	cin>>q;
	while(q--){
		char c;
		cin>>c;
		if(c=='+'){
			string s;
			cin>>s;
			update(m[s],1);
			to++;
			st[s]++;
		}
		else if(c=='-'){
			string s;
			cin>>s;
			if(st[s]){
				st[s]--;
				update(m[s],-1);
				to--;
			}
		}
		else{
			int l;
			cin>>l;
			cout<<to - query(l)<<endl;
		}
	}
	return 0;
}