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
	int p;
	cin>>p;
	int n;
	cin>>n;
	int a[n+1];
	int s = 0;
	fr(i,0,n) {
		cin>>a[i];
		s += a[i];
	}
	int st = 0;
	int ans = s;
	int e = s;
	while(st<=e){
		int m = (st+e)/2;
		int k = 0;
		int c = 0;
		fr(i,0,n){
			if((c+a[i])<=m){
				c += a[i];
			}
			else if(a[i]>m){
				k=-1;
				break;
			}
			else{
				k++;
				c = a[i];
			}
		}
		if(k!=-1){
			if(k+1<=p){
				ans = min(ans,m);
				e = m-1; 
			}
			else st = m+1;
		}
		else st = m+1;
	}
	cout<<ans;

}