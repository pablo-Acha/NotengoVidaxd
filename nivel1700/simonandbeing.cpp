#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int t,n,a[N],del[N],stk[N],top,ans;
void init(){
	for(int i=1;i<=n;i++){
		del[i]=0;
	}
	ans=n;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		init();
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		top=0;
		for(int i=1;i<=n;i++){
			while(top&&a[stk[top]]<a[i]){
				top--;
			}
			stk[++top]=i;
			del[i]+=i-top;
		}
        for (int i = 1; i <= n; i++)
        {
            cout<<del[i]<<" ";
        }cout<<"\n";
        
        for (int i = 1; i <= n; i++)
        {
            cout<<stk[i]<<" ";
        }cout<<"\n";


		top=0;
		for(int i=n;i>=1;i--){
			while(top&&a[stk[top]]<a[i]){
				top--;
			}
			stk[++top]=i;
            cout<<i<<" "<<top<<"\n";
			del[i]+=n-i+1-top;
		}

        for (int i = 1; i <= n; i++)
        {
            cout<<del[i]<<" ";
        }cout<<"\n";
        
        for (int i = 1; i <= n; i++)
        {
            cout<<stk[i]<<" ";
        }cout<<"\n";

		for(int i=1;i<=n;i++){
			ans=min(ans,del[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}