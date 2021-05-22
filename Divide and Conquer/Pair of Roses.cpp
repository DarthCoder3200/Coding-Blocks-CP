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
int m;

bool getS(int t,int s){
	int r = n-1;
	while(s<=r){
		int m1 = (s+r)/2;
		if(a[m1] == t) return true;
		if(a[m1] > t) r = m1-1;
		else s = m1+1;
	}
	return false;
}

int32_t main(){
	fast();
	test{
		cin>>n;
		fr(i,0,n) cin>>a[i];
		cin>>m;
		sort(a,a+n);
		int fi=-1,se=-1;
		int d = 1000000000;
		fr(i,0,n-1){
			if(getS(m-a[i],i+1)){
				if(max(m-a[i],a[i]) - min(m-a[i],a[i]) < d){
					d = max(m-a[i],a[i]) - min(m-a[i],a[i]);
					fi = a[i];
					se = m-a[i];
					if(se<fi) swap(se,fi);
				}
			}
		}
		cout<<"Deepak should buy roses whose prices are "<<fi<<" and "<<se<<'.'<<endl;
	}
}