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
	int n;
	cin>>n;
	int a[n+1];
	int b[n+1];
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>b[i];
	}
	sort(a,a+n);
	sort(b,b+n);
	priority_queue<int> q1;
	priority_queue<int> q2;
	for(int i=1;i<n;i++){
		q1.push(a[i]-a[i-1]-1);
		q2.push(b[i]-b[i-1]-1);
	}
	cout<<q1.top()*q2.top()
}