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
	int s;
	cin>>s;
	int a[n+1];
	int sum = 0;
	fr(i,0,n) {
		cin>>a[i];
		sum += a[i];
	}
	int ans = sum;
	int st = 0;
	int e = ans;
	//if(s>=n){
	//	cout<<a[n-1];
	//	return 0;
	//}
	while(st<=e){
		int m = (st+e)/2;
		int k = 0;
		int c = 0;
		fr(i,0,n){
			if(c+a[i]<=m){
				c+=a[i];
			}
			else{
				k++;
				c = a[i];
				if(c>m) {
					k = n+1;
					break;
				}
			}
		}
		if(k+1>s) st = m+1;
		else{
			e = m-1;
			//cout<<m<<endl;
			ans = min(ans,m);
		}

	}
	cout<<ans;

}