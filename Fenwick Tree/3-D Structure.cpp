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
int a[200][200][200];
int bit[200][200][200];
int n;
int m;

void update(int x1,int y1,int z1,int up){
	x1++;y1++;z1++;
	for(int i=x1;i<102;i += ((i&-i))){
		for(int j=y1;j<102; j+= ((j&-j))){
			for(int k=z1;k<102;k+= ((k&-k))){
				bit[i][j][k] += up;
			}
		}
	}
}
int sum(int x,int y,int z){
	x++;y++;z++;
	int ans = 0;
	for(int i=x;i>0;i-= ((i&-i))){
		for(int j=y;j>0;j-= ((j&-j))){
			for(int k=z;k>0;k-= ((k&-k))){
				ans += bit[i][j][k];
			}
		}
	}
	return ans;
}

int32_t main(){
	fast();
	test{
		cin>>n>>m;
		fr(i,0,102) fr(j,0,102) fr(k,0,102) a[i][j][k] = bit[i][j][k] = 0;
		string s;
		fr(i,0,m){
			cin>>s;
			if(s=="UPDATE"){
				int x,y,z,up;
				cin>>x>>y>>z>>up;
				update(x,y,z,up-a[x][y][z]);
				a[x][y][z] = up;
			}
			else{
				int x1,x2,y1,y2,z1,z2;
				cin>>x1>>y1>>z1>>x2>>y2>>z2;
				int j4 = sum(x1-1, y1-1, z1-1);
       			int j1 = sum(x2, y1-1, z1-1) - j4;
     			int j2 = sum(x1-1, y2, z1-1) - j4;
       			int j3 = sum(x1-1, y1-1, z2) - j4;

     			cout<<sum(x2, y2, z2) - sum(x2, y1-1, z2) - sum(x1-1, y2, z2) - sum(x2, y2, z1-1) + 2*j4 + j1 + j2 + j3<<endl;
			}
		}
	}
}