#include <bits/stdc++.h>
using namespace std;

vector<string> m;
set<pair<int,int>> v;

int contar(int r, int c) {
    if(r<0||r>=m.size()||c<0||c>=m[0].size()||v.count({r,c})) return 0;
    v.insert({r,c});
    
    if(m[r][c]=='^') 
        return 1 + contar(r+1,c-1) + contar(r+1,c+1);
    else
        return contar(r+1,c);
}

int main() {
    string s;
    while(getline(cin,s)) 
        if(!s.empty()) m.push_back(s);
    
    // Buscar 'S'
    for(int i=0;i<m.size();i++)
        for(int j=0;j<m[0].size();j++)
            if(m[i][j]=='S')
                cout<<contar(i+1,j)<<endl;
    
    return 0;
}
