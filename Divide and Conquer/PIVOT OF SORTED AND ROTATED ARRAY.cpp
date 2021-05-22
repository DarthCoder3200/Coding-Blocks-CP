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
int n;
int a[100005];

int GetA(){
	int e= n-1;
	int s = 0;
	int ans;
	while(s<=e){
		int m = (s+e)/2;
		if(a[m]>=a[s]){
			if(a[m]>a[m+1]){
				ans = m;
				break;
			}
			s = m+1;
		}
		else{
			e = m-1;
		}
	}
	return ans;
}


int32_t main(){
	fast();
	cin>>n;
	fr(i,0,n) cin>>a[i];
	cout<<GetA();
}