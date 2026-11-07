#include <bits/stdc++.h>
using namespace std;

int parent_[100005+2], rnk[100005+2];

int find(int x){
    while(parent_[x]!=x){ parent_[x]=parent_[parent_[x]]; x=parent_[x]; }
    return x;
}
void unite(int a,int b){
    a=find(a); b=find(b);
    if(a==b) return;
    if(rnk[a]<rnk[b]) swap(a,b);
    parent_[b]=a;
    if(rnk[a]==rnk[b]) rnk[a]++;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);

    vector<int> v(n+1);
    v[0]=0;
    for(int i=1;i<=n;i++) scanf("%d",&v[i]);

    for(int i=0;i<=n+1;i++){ parent_[i]=i; rnk[i]=0; }

    for(int i=0;i<m;i++){
        int L,R; scanf("%d %d",&L,&R);
        unite(L, R+1);   // arista entre L y R+1
    }

    vector<int> s(n+2,0); // s[i] = target[i] para i=1..n
    for(int i=1;i<=n;i++) s[i] = v[i]^v[i-1];
    for(auto x:s)cout<<x<<" ";cout<<"\n";
    vector<int> xorSum(n+2,0);
    for(int i=1;i<=n;i++){
        int r = find(i);
        xorSum[r] ^= s[i];
    }

    int freeRoot = find(n+1); // nodo libre N+1

    vector<char> visited(n+2,0);
    bool ok=true;
    for(int i=1;i<=n+1;i++){
        int r = find(i);
        if(visited[r]) continue;
        visited[r]=1;
        bool hasFree = (r==freeRoot);
        if(!hasFree && xorSum[r]!=0){ ok=false; break; }
    }

    printf(ok? "YES\n" : "NO\n");
    return 0;
}