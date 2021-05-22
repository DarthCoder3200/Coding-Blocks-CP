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
int n,c;
int a[100005];

int32_t main(){
	fast();
	cin>>n>>c;
	fr(i,0,n) cin>>a[i];
	sort(a,a+n);
	int s = 1;
	int e = 1000000005;
	int ans = 0;
	while(s<=e){
		int m = (s+e)/2;
		int k = c;
		int prev = a[0];
		k--;
		fr(i,1,n){
			if(k==0) break;
			if((k!=0)&&a[i]-prev >= m){
				prev = a[i];
				k--;
				//if(k==0) cout<<m<<endl;
			}
		}
		if(k) e = m-1;
		else{
			s = m+1;
			ans = max(ans,m);
		}
	}
	cout<<ans;
}