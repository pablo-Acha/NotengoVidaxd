#include<iostream>
using namespace std;
int T;
int n;
char a[505][505];
int b[505][505];
int fa[505];
int Find(int x){
	if(fa[x]==x)return x;
	return fa[x]=Find(fa[x]);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)cin>>a[i][j];
		}
		int f=1;
		for(int i=1;i<=n;i++){
			if(a[i][i]=='0')f=0;
			for(int j=1;j<=n;j++){
				b[i][j]=a[i][j]-'0';
				if(i==j)b[i][j]=0;
				for(int k=1;k<=n;k++){
					if(k==i||k==j)continue;
					if(a[i][k]=='1'&&a[k][j]=='1'){
						if(a[i][j]=='0')f=0;
						b[i][j]=0;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(b[i][j]&&Find(i)==Find(j))f=0;
				if(b[i][j])fa[Find(j)]=Find(i);
			}
		}
		for(int i=2;i<=n;i++){
			if(Find(i)!=Find(i-1))f=0;
		}
		if(!f){
			cout<<"No\n";
			continue;
		}
		cout<<"Yes\n";
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(b[i][j])cout<<i<<' '<<j<<'\n';
			}
		}
	}
	return 0;
}
