#include<bits/stdc++.h>

using namespace std;

vector<int> encode(vector<string> agents) {
    vector<int> ids(agents.size());
    for (int i = 0; i < agents.size(); i++)
    {
        vector<int> num(6);
        int d = i/10;
        int u = i%10;
        for (int j = 0; j < 6; j+=2)
        {
            num[j] = d;
            num[j+1] = u;
        }
        int id = 0;
        for (int i = 0,j = 5; i <6; i++,j--)
        {
            int aux = 1;
            int cnt = j;
            while(cnt--){
                aux*=10;
            }
            id += aux*num[i];
        }
        ids[i] = id;
    }
    
    return ids;
}

string decode(vector<string> agents, int id) {
    map<int,int> md;
    map<int,int> mu;
    vector<int> num(6);
    int aux = id;
    for (int i = 5; i >=0 && aux; i--)
    {
        num[i] = aux%10;
        aux/=10;
    }
    
    for (int i = 0; i < 6; i+=2)
    {
        md[num[i]]++;
        mu[num[i+1]]++;
    }
    int res = 0;

    for (auto p : md) {
        int k = p.first;
        int v = p.second;

        if (v >= 2) {
            res += k * 10;
        }
    }

    for (auto p : mu) {
        int k = p.first;
        int v = p.second;

        if (v >= 2) {
            res += k;
        }
    }
    return agents[res];
}