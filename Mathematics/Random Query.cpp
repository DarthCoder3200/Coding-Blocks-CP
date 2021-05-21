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

int prv[1000055] = {0};


int32_t main(){
	fast();
	int n;
	cin>>n;
	int a[n+1];
	fr(i,1,n+1) cin>>a[i];
	int ans = 0;
	fr(i,1,n+1){
		ans += (i-prv[a[i]])*(n+1-i)*2-1;
		prv[a[i]] = i;
	}
	//cout<<ans<<endl;
	cout<<fixed<<setprecision(6)<<float((1.0*ans/(n*(n))));
}