#include<bits/stdc++.h>
using namespace std;
bool myc(string a,string b){
	int n = a.length();
	int m = b.length();
	if(n==m) return a<b;
	if(n>m){
		int k = 0;
		for(int i=0;i<m;i++){
			if(a[i] != b[i]){
				k = 1;
				break;
			}
		}
		if(k) return a<b;
		else return a>b;
	}
	else{
		int k = 0;
		for(int i=0;i<n;i++){
			if(a[i] != b[i]){
				k = 1;
				break;
			}
		}
		if(k) return a<b;
		else return b>a;
	}
}
int main() {

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
	int n;
	cin>>n;
	string s[n+1];
	for(int i=0;i<n;i++) cin>>s[i];
	sort(s,s+n,myc);
	for(int i=0;i<n;i++) cout<<s[i]<<endl;
	return 0;
}
