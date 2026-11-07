#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool f(vector<int> &arr, int k, int h ){
        int j = 1;
        for (int i = 0; i < arr.size() && h; i++,j++)
        {
            int aux  =  arr[i]/k + (arr[i]%k>0);
            if(aux>h)break;
            h-=aux;
        }
        if(j == arr.size()){
            return true;
        }
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r =1e9,mid;
        while(l<=r){
            mid = (l+r) /2;
            if(f(piles,mid,h)){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return l; 
    }
};