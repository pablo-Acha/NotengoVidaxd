#include<bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
    int mn = 1e6;
    for (int i = 0; i < strs.size(); i++)
    {
        mn = min(int(strs[i].size()),mn);
    }
    int res = 0;
    for (int i = 0; i < mn; i++)
    {
        char p = strs[0][i];
        bool f = 1;
        for(auto x:strs){
            if(p!=x[i]){
                f= 0;
                break;
            }
        }
        if(f){
            res++;
        }else{
            break;
        }
    }
    return strs[0].substr(0,res);
    
}

int maxArea(vector<int>& height) {
    map<int,int> mpiz;        
    map<int,int> mpder;
    priority_queue<pair<int,int>> iz;        
    priority_queue<pair<int,int>> der;
    int n = height.size(); 
    for (int i = 0; i < n; i++)
    {
        if(mpiz.find(height[i])==mpiz.end())mpiz[height[i]] = i; 
    }
    for(auto [a,b]:mpiz){
        iz.push({a,b});
    }
    int acr = n+1;
    while(!iz.empty()){
        auto [a,b] = iz.top();
        iz.pop();
        acr = min(acr,b);
        mpiz[a] = acr;
    }

    for (int i = n-1; i >=0; i--)
    {
        if(mpder.find(height[i])==mpder.end())mpder[height[i]] = i; 
    }
    for(auto [a,b]:mpder){
        der.push({a,b});
    }
    acr = -1;
    while(!der.empty()){
        auto [a,b] = der.top();
        der.pop();
        acr = max(acr,b);
        mpder[a] = acr;
    }
    int area = 0;
    for (int i = 0; i < n; i++)
    {
        int h = height[i];
        if(mpiz[h]<i){
            area = max(h*(i-mpiz[h]),area);
        }
        if(mpder[h]>i){
            area = max(h*(mpder[h]-i),area);
        }
    }
    return area;
}

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            arr[i].push_back(matrix[j][i]);   
        }
    }
    matrix = arr;
}


bool isHappy(int n) {
    set<int> s;
    int act = n;
    while(s.find(act) == s.end()){
        s.insert(act);
        int p = 0;
        while(act){
            p+= (act%10 )*(act%10);
            act/=10;
        }
        act = p;
    }
    if(s.find(1)!=s.end()){
        cout<<"NO"<<"\n";
    }else{
        cout<<"YES"<<"\n";
    }
}



bool isValidSudoku(vector<vector<char>>& board) {
    bool f = 1;
    for (int i = 0; i < 9 && f; i++)
    {
        set<int> s;
        for (int j = 0; j < 9 && f; j++)
        {
            if(s.find(board[i][j])!=s.end() || board[i][j]<0 || board[i][j]>9){f = 0;break;}
            s.insert(board[i][j]);
        }
    }
    for (int i = 0; i < 9 && f; i++)
    {
        set<int> s;
        for (int j = 0; j < 9; j++)
        {
            if(s.find(board[j][i])!=s.end() || board[i][j]<0 || board[i][j]>9){f = 0;break;}
            s.insert(board[j][i]);
        }
    }
    
    for (int i = 0; i < 3 && f; i++)
    {
        for (int j = 0; j < 3 && f; j++)
        {
            set<int> s;
            for (int y = i*3; y < i*3 + 3 && f; y++)
            {
                for (int x = j*3; x <j*3 + 3 && f; x++)
                {
                    if(s.find(board[y][x])!=s.end() || board[i][j]<0 || board[i][j]>9){f = 0;cout<<"e"<<"\n";break;}
                    s.insert(board[y][x]);
                }    
            }
        }
    }
    return f;
    
}

void gameOfLife(vector<vector<int>>& board) {
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> arr(board.size(),vector<int>(board[0].size()));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
                int res = 0;
            for (int h = i-1; h < i+2; h++)
            {
                for (int k = j-1; k < j+2; k++)
                {
                    if(h <0 || h >=n || k <0 || k >=m || (i == h && j == k)){
                        continue;       
                    }   
                    res+= board[h][k];
                }
                
            }
            if(board[i][j] == 1 && res <2){
                    arr[i][j] = 0;
                }else if(board[i][j] == 1 && res<4){
                    arr[i][j] = 1;
                }else if(board[i][j] == 1){
                    arr[i][j] = 0;
                }else if(board[i][j] == 0 && res == 3){
                    arr[i][j] = 1;
                }
        }
    }
    board = arr;
}
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int acc = (digits[n-1]+1)/10;
        digits[n-1] = (digits[n-1]+1)%10;
        int i = n-2;
        while(acc && i>=0){
            digits[i] = digits[i]+acc;
            acc = digits[i]/10;
            digits[i] = digits[i]%10;
            i--;
        }
        for(auto a:digits)cout<<a<<" ";
        if(acc){
            int j = 0;
            int aux = 0;
            while(j<n){
                aux = digits[j];
                digits[j] = acc;
                j++;
            }
            digits.push_back(aux);
        }
        return digits;
    }
};

class Solution {
public:
    string convertToTitle(int columnNumber) {
        deque<char> res;
        while (columnNumber)
        {
            columnNumber--;
            char d = char('A'+ columnNumber);
            res.push_front(d);
            columnNumber/=26;
        }
        string fin = "";
        for(auto a:res){
            fin.push_back(a);
        }
        return fin;
    }

};

class Solution {
public:
    string addBinary(string a, string b) {
        int an = a.size();
        int bn = b.size();
        int mx = max(an,bn);
        char acc  = '0';
        string res = "";
        int sum = 0;
        for (int i = 0; i < mx; i++)
        {
            char p = '0',s = '0';
            if(an-1-i>=0 &&   a[an-1-i] == '1')p = '1';
            if(bn-1-i>=0 &&   b[bn-1-i] == '1')s = '1';
            sum = (acc-'0') +  (p-'0') + (s-'0');
            char dig = char((sum%2) + '0');
            acc = char((sum/2) + '0'); 
            res  = dig+res;
        }  
        if(acc == '1'){
            return acc +res;
        }
        return res;
    }
};
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> pre;
        for (int i = 1; i < 1001; i++)
        {
            set<int> s;
            int aux = i;
            while(i){
                s.insert(i%10);
                i/10;
            }
            if(s.find(0) !=s.end())continue;
            bool f = 1;
            for(auto a:s){
                if(i%a !=0){
                    f = 0;
                    break;
                }
            }
            if(f)continue;
            pre.push_back(i);
        }
        
        int l = lower_bound(pre.begin(),pre.end(),left)-pre.begin();
        int r = upper_bound(pre.begin(),pre.end(),right)-pre.begin();
        vector<int> res;
        for (int i = l; i < r; i++)
        {
            res.push_back(pre[i]);
        }
        return res;
    }
};


void setZeroes(vector<vector<int>>& matrix) {
    set<int> cerosI;
    set<int> cerosJ;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
        if(cerosJ.find(j)!=cerosJ.end())continue;
            if(matrix[i][j] == 0){
                cerosI.insert(i);
                cerosI.insert(j);
                break;
            }   
        }
    }    
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(cerosI.find(i) != cerosI.end() || 
            cerosJ.find(j) != cerosJ.end()){
                matrix[i][j] = 0;
            }
        }
        
    }
    
}



vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n = matrix[0].size();
    int m = matrix.size();
    vector<vector<int>> vis(m,vector<int>(n));
    int h = 0;
    vector<int> res;
    bool f =1; 
    while(f){
        int j = h;
        int i = h;
        bool sigue = 0;
        for (; j < n-h; j++)
        {
            sigue = 1;
            if(vis[i][j]){
                f = 0;
                break;
            }else{
                vis[i][j] = 1;
            }
            res.push_back(matrix[i][j]);
        }
        j--;
        if(!f || !sigue)break;
        i++;
        for (; i < m-h; i++)
        {
            if(vis[i][j]){
                f = 0;
                break;
            }else{
                vis[i][j] = 1;
            }
            res.push_back(matrix[i][j]);
        }
        i--;
        if(!f || !sigue)break;
        
        j--;
        for (; j >= h; j--)
        {
            if(vis[i][j]){
                f = 0;
                break;
            }else{
                vis[i][j] = 1;
            }
            res.push_back(matrix[i][j]);
        }
        j++;
        if(!f || !sigue)break;
        
        i--;
        for (; i >= h+1; i--)
        {
            if(vis[i][j]){
                f = 0;
                break;
            }else{
                vis[i][j] = 1;
            }
            res.push_back(matrix[i][j]);
        }
        if(!f || !sigue)break;
        h++;
    }
    return res;
    
}


int main(){
    vector<vector<int>> brr= {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> arr= {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> res = spiralOrder(brr);
    for(auto a:res)cout<<a<<" ";
    return 0;
}

