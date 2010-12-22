#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <set>

using namespace std;

struct state{
    string M[6];
    int dist;
    
    state(){}
    
    string toString(){
        string ret;
        
        for(int i = 0;i<6;++i)
            ret += M[i];
        
        return ret;
    }
    
    bool done(){
        for(int i = 0;i<6;++i){
            bool ok = true;
            
            for(int j = 5;j>=0;--j){
                if(M[i][j]!='x' && M[i][j]!='.') ok = false;
                if(M[i][j]=='x') return ok;
            }
        }
        
        return false;
    }
};

char M[6][7];
set<string> S;

int bfs(){
    queue<state> Q;
    
    state aux;
    for(int i = 0;i<6;++i) aux.M[i] = string(M[i]);
    aux.dist = 0;
    
    S.insert(aux.toString());
    Q.push(aux);
    
    bool found[26];
    
    while(!Q.empty()){
        aux = Q.front();
        Q.pop();
        
        if(aux.done()) return aux.dist;
        ++aux.dist;
        
        memset(found,false,sizeof(found));
        
        for(int r = 0;r<6;++r) for(int c = 0;c<6;++c){
            if(aux.M[r][c]!='.' && !found[aux.M[r][c]-'a']){
                found[aux.M[r][c]-'a'] = true;
                char cur = aux.M[r][c];
                
                if(r<5 && aux.M[r+1][c]==cur){
                    int l = 1;
                    while(r+l<6 && aux.M[r+l][c]==cur) ++l;
                    
                    int s = r,e = r+l-1;
                    
                    while(s>0 && aux.M[s-1][c]=='.') --s;
                    while(e<5 && aux.M[e+1][c]=='.') ++e;
                    
                    for(int i = r;i<r+l;++i) aux.M[i][c] = '.';
                    
                    for(int i = s;i+l-1<=e;++i){
                        for(int j = 0;j<l;++j) aux.M[i+j][c] = cur;
                        
                        string str = aux.toString();
                        
                        if(S.find(str)==S.end()){
                            S.insert(str);
                            Q.push(aux);
                        }
                        
                        for(int j = 0;j<l;++j) aux.M[i+j][c] = '.';
                    }
                    
                    for(int i = r;i<r+l;++i) aux.M[i][c] = cur;
                }else{
                    int l = 1;
                    while(c+l<6 && aux.M[r][c+l]==cur) ++l;
                    
                    int s = c,e = c+l-1;
                    
                    while(s>0 && aux.M[r][s-1]=='.') --s;
                    while(e<5 && aux.M[r][e+1]=='.') ++e;
                    
                    for(int i = c;i<c+l;++i) aux.M[r][i] = '.';
                    
                    for(int i = s;i+l-1<=e;++i){
                        for(int j = 0;j<l;++j) aux.M[r][i+j] = cur;
                        
                        string str = aux.toString();
                        
                        if(S.find(str)==S.end()){
                            S.insert(str);
                            Q.push(aux);
                        }
                        
                        for(int j = 0;j<l;++j) aux.M[r][i+j] = '.';
                    }
                    
                    
                    for(int i = c;i<c+l;++i) aux.M[r][i] = cur;
                }
            }
        }
    }
    
    return -1;
}

int main(){
    int T = 0,n;
    
    while(true){
        scanf("%d",&n);
        if(n==0) break;
        
        for(int i = 0;i<6;++i)
            scanf("%s",M[i]);
        
        int ans = bfs();
        ++T;
        
        if(ans==-1) printf("You are trapped in scenario #%d.\n",T);
        else printf("Scenario #%d requires %d moves.\n",T,1+ans);
    }
    
    return 0;
}
