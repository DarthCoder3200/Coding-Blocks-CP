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
int a[10002];
int merge(int l,int m,int r){
	int temp[r-l+1];
	int i = l;
	int j = m+1;
	int k = 0;
	int ret = 0;
	while((i<=m)&&(j<=r)){
		if(a[i]<=a[j]){
			temp[k++] = a[i++];
		}
		else{
			temp[k++] = a[j++];
			ret += m-i+1;
		//	cout<<ret<<" bb"<<endl;
		}
	}
	while(i<=m){
		temp[k++] = a[i++];
	}
	while(j<=r){
		temp[k++] = a[j++];
	}
	fr(i,l,r+1) a[i] = temp[i-l];
	return ret;
}
int mergeSort(int l,int r){
	int m = (l+r)/2;
	if(l>=r) return 0;
	int s = mergeSort(l,m);
	//cout<<s<<" yt";
	int t = mergeSort(m+1,r);
	int j = merge(l,m,r);
	return s+t+j;
}


int32_t main(){
	fast();
	test{
		int n; cin>>n;
		//int a[n+1];
		fr(i,0,n) cin>>a[i];
		cout<<mergeSort(0,n-1)<<endl;
	}
}