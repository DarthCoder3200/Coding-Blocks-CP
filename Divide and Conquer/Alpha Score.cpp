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
#define mod 1000000007
int n;
int a[100005];


int merge(int left,int right,int m){
	if(left>=right) return 0;
	vi b;
	int i = left;
	int j = m+1;
	int ret = 0;
	while((i<=m) && (j<=right)){
		if (a[i]<a[j]){
			b.pb(a[j]);
			j++;
		}
		else{
			ret += ((((j-1-m)%mod+mod)%mod)*a[i]);
			ret = ret%mod;
			b.pb(a[i]);
			i++;
		}
	}
	while(i<=m){
		ret += a[i]*(((right-m)%mod+mod)%mod);
		ret = ret%mod;
		b.pb(a[i]);
		i++;
	}
	while(j<=right){
		b.pb(a[j]);
		j++;
	}
	int k = left;
	for(auto x:b)	a[k++] = x;
	return ret;
}


int mergeSort(int left, int right){
	if(left>=right) return 0;
	int ans = 0;
	int m = (left + right)/2;
	ans += mergeSort(left,m);
	ans += mergeSort(m+1,right);
	ans += merge(left, right, m);
	ans = ans%mod;
	return ans;
}

int32_t main(){
	fast();
	cin>>n;
	fr(i,0,n) cin>>a[i];
	cout<<mergeSort(0,n-1);
}