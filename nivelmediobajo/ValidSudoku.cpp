#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll MOD = 1e9+7;

ll gaus(ll n){
    return (n*(n+1))/2;
}

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<int>> column(9);
        vector<set<int>> row(9);
        bool f = 1;
        for (int i = 0; i < 9 && f; i+=3)
        {
            for (int j = 0; j < 9 && f; j+=3)
            {for (int y = i; y < 3+i && f; y++)
            {
                set<int> area;

                for (int x = j; x < 3+j && f; x++)
                {
                    if(column[x].find(board[y][x]) != column[x].end()
                        || row[y].find(board[y][x]) != row[y].end()
                        || area.find(board[y][x]) != area.end()    
                    ){
                        f = 0;
                        break;
                    }else{
                        column[x].insert(board[y][x]);
                        row[y].insert(board[y][x]);
                        area.insert(board[y][x]);    
                    }
                }
                
            }}
            
        }
        return f;

    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
}