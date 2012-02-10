#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int get_gender(string &s){
    int ret = -1;
    int L = s.size();
    
    if(L >= 4 && s[L - 3] == 'g' && s[L - 2] == 'v' && s[L - 1] == 'w') ret = 0;
    if(L >= 3 && s[L - 2] == 'j' && s[L - 1] == 'k') ret = 1;
    
    return ret;
}

map<string, int> gender;
map< string, pair<string, string> > parents;
map<string, int> id;
map<string, string> couple;
vector<int> L[3000],L2[3000];
bool visited[3000],done[3000];

bool dfs(int cur){
    if(visited[cur]) return false;
    visited[cur] = true;
    done[cur] = false;
    
    for(int i = L2[cur].size() - 1;i >= 0;--i){
        int to = L2[cur][i];
        
        if(visited[to] && !done[to]) return true;
        if(dfs(to)) return true;
    }
    
    done[cur] = true;
    
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    
    int T,N;
    string a[1000],b[1000],c[1000];
    
    cin >> T;
    
    while(T--){
        cin >> N;
        
        bool ok = true;
        
        for(int i = 0; i < N; ++i)
            cin >> a[i] >> b[i] >> c[i];
        
        couple.clear();
        gender.clear();
        parents.clear();
        
        for(int i = 0; i < N && ok; ++i){
            int x1 = get_gender(b[i]);
            int x2 = get_gender(c[i]);
            
            if(x1 == -1 || x2 == -1 || x1 != x2) ok = false;
            
            gender[ a[i] ] = x1;
        }
        
        if(!ok) puts("NO");
        else{
            for(int i = 0;i < N; ++i){
                if(gender[ a[i] ] == 0){
                    b[i] = b[i].substr(0,b[i].size() - 3);
                    c[i] = c[i].substr(0,c[i].size() - 3);
                }else{
                    b[i] = b[i].substr(0,b[i].size() - 2);
                    c[i] = c[i].substr(0,c[i].size() - 2);
                }
                
                pair<string, string> P = make_pair(b[i],c[i]);
                if(P.first > P.second) swap(P.first,P.second);
                parents[ a[i] ] = P;
            
                if(couple.find(c[i]) != couple.end()){
                    if(couple[ c[i] ] != b[i]) ok = false;
                }else couple[ c[i] ] = b[i];
                
                if(couple.find(b[i]) != couple.end()){
                    if(couple[ b[i] ] != c[i]) ok = false;
                }else couple[ b[i] ] = c[i];
            }
            
            for(int i = 0;i < N && ok;++i){
                if(gender.find(b[i]) != gender.end() && gender.find(c[i]) != gender.end()){
                    int x = gender[ b[i] ];
                    int y = gender[ c[i] ];
                    
                    if(x == 1 && y == 1) ok = false;
                }
                
                if(parents.find(b[i]) != parents.end() && parents.find(c[i]) != parents.end() && parents[ b[i] ] == parents[ c[i] ])
                    ok = false;
                
                if(a[i] == b[i] || a[i] == c[i] || b[i] == c[i])
                    ok = false;
            }
            
            if(!ok) puts("NO");
            else{
                
                id.clear();
                for(int i = 0;i < 3000;++i){
                    L[i].clear();
                    L2[i].clear();
                }
                
                int cont = 0;
                
                for(int i = 0;i < N;++i){
                    if(id.find(a[i]) == id.end()) id[ a[i] ] = cont++;
                    if(id.find(b[i]) == id.end()) id[ b[i] ] = cont++;
                    if(id.find(c[i]) == id.end()) id[ c[i] ] = cont++;
                    
                    int A = id[ a[i] ],B = id[ b[i] ],C = id[ c[i] ];
                    
                    L[B].push_back(A);
                    L[A].push_back(B);
                    L[C].push_back(A);
                    L[A].push_back(C);
                    
                    L2[B].push_back(A);
                    L2[C].push_back(A);
                }
                
                
                memset(visited,false,sizeof visited);
                queue<int> Q;
                
                visited[0] = true;
                Q.push(0);
                
                while(!Q.empty()){
                    int cur = Q.front();
                    Q.pop();
                    --cont;
                    
                    for(int i = L[cur].size() - 1;i >= 0;--i){
                        int to = L[cur][i];
                        
                        if(!visited[to]){
                            visited[to] = true;
                            Q.push(to);
                        }
                    }
                }
                
                if(cont == 0){
                    memset(visited,false,sizeof visited);
                    memset(done,false,sizeof done);
                    ok = true;
                    
                    for(int i = 0;i < N;++i){
                        if(!visited[i]){
                            if(dfs(i)) ok = false;
                        }
                    }
                    
                    if(!ok) puts("NO");
                    else puts("YES");
                }else puts("NO");
            }
        }
    }
    
    return 0;
}
