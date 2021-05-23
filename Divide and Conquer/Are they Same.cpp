
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
bool equal(string a,string b){
	if(a==b) return true;
	if(a.length()%2!=0) return false;
	string c;
	int i = 0;
	while(i<a.length()/2){
		c.push_back(a[i]);
		i++;
	}
	string d;
	while(i<a.length()){
		d.push_back(a[i]);
		i++;
	}
	i = 0;
	string e;
	while(i<b.length()/2){
		e.push_back(b[i]);
		i++;
	}
	string f;
	while(i<b.length()){
		f.push_back(b[i]);
		i++;
	}
	if((equal(c,e)&&equal(d,f))||(equal(c,f)&&equal(d,e))) return true;
	return false;
}

int32_t main() {
	test{
		while(t--){
			string a,b;
			cin>>a>>b;
			if(equal(a,b)) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
	return 0;
}