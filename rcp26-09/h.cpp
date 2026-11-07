#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()
const double ep = 0.00000001; 
const double delta = 0.0000001;
bool igual(double a, double b){
    double x = abs(a-b);
    return x<ep;
}

double formula(double r,double h, double x){
    double R = (x*h)+r;
    double vol = (3.14159265359 * h * ( R*R +r*r + r*R))/3.0;
    return vol;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        double r,R,h;cin>>r>>R>>h;
        double x = (R-r)/h;
        double l  = 0, der = h,mid = 0;
        double vol = (3.14159265359 * h * ( R*R +r*r + r*R))/3.0;
        double ob = vol/2;
        while(l<=der){
            mid= (l+der)/2;
            double nue= formula(r,mid,x);
            if(igual(nue,ob))break;
            if(nue>ob){
               der = mid- delta;
            }else{
               l = mid+ delta;
            }
        }
        
        cout << fixed << setprecision(6)<< mid << endl;
        
        // double hp = (3.0 *(vol/2.0))/(3.14159265359 *( R*R +r*r + r*R));
        // cout << fixed << setprecision(6)<< hp << endl;
        // double vol2 = (3.14159265359 * hp * ( R*R +r*r + r*R))/3.0;
        // cout << fixed << setprecision(6)<< vol << endl;
    }

    

    return 0;
}