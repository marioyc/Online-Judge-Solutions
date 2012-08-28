#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

map< vector<int>, int > id;
#define MAXN 100000

int parent[MAXN];

int Find(int x){
    if(parent[x] != x) parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(int x, int y){
    x = Find(x); y = Find(y);
    parent[x] = y;
}

int main(){
    ios::sync_with_stdio(0);
    
    int tc = 1,n,x,cont;
    string line;
    
    while(true){
        cin >> n;
        if(n == 0) break;
        
        getline(cin,line);
        
        getline(cin,line);
        istringstream is(line);
        
        vector<int> S,T;
        
        for(int i = 0;i < n;++i){
            is >> x;
            S.push_back(x);
        }
        
        for(int i = 0;i < n;++i){
            is >> x;
            T.push_back(x);
        }
        
        for(int i = 0;i < MAXN;++i) parent[i] = i;
        id.clear(); cont = 0;
        
        id[S] = cont++;
        if(id.find(T) == id.end()) id[T] = cont++;
        
        while(true){
            getline(cin,line);
            if(line == "-1") break;
            
            istringstream is2(line);
            
            vector<int> a,b;
            
            for(int i = 0;i < n && is2 >> x;++i) a.push_back(x);
            for(int i = 0;i < n && is2 >> x;++i) b.push_back(x);
            
            if(a.size() + b.size() < 2 * n) break;
            
            if(id.find(a) == id.end()) id[a] = cont++;
            if(id.find(b) == id.end()) id[b] = cont++;
            
            Union(id[a],id[b]);
        }
        
        cout << "Maze #" << tc++;
        if(Find(id[S]) == Find(id[T])) cout << " can be travelled\n";
        else cout << " cannot be travelled\n";
    }
    
    return 0;
}
