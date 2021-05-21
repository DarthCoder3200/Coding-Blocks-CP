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
	//test{
		int n;
		cin>>n;
		int a[n+1];
		fr(i,0,n) cin>>a[i];
		if(n>=70) {
			cout<<"YES"<<endl;
			return 0;
		}
		int x = 0;
		fr(i,0,n) fr(j,i+1,n) fr(k,j+1,n) fr(l,k+1,n) if(a[i]^a[j]^a[k]^a[l] == 0){cout<<"YES"; return 0;}
		cout<<"NO";
		return 0;
	//}
}