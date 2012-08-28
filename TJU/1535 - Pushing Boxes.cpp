#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main(){
    int tc = 1,R,C,n,x;
    vector< pair<int, int> > b;
    vector<int> aux[20];
    char op[6];
    
    while(scanf("%d %d",&R,&C) == 2){
        if(R == 0) break;
        
        scanf("%d",&n);
        
        b.clear();
        
        for(int i = 0,r,c;i < n;++i){
            scanf("%d %d",&r,&c);
            b.push_back(make_pair(r,c));
        }
        
        while(true){
            scanf("%s",op);
            
            if(op[0] == 'd' && op[2] == 'n') break;
            
            scanf("%d",&x);
            
            for(int i = 0;i < max(R,C);++i) aux[i].clear();
            
            if(op[0] == 'd'){
                for(int i = 0;i < n;++i) aux[ b[i].second ].push_back(b[i].first);
                for(int i = 0;i < C;++i) sort(aux[i].begin(),aux[i].end());
                
                for(int i = 0;i < C;++i)
                    if(R - aux[i].size() < x)
                        x = R - aux[i].size();
                
                for(int j = 0;j < x;++j){
                    for(int i = 0;i < C;++i){
                        int sz = aux[i].size();
                        if(sz == 0) continue;
                        
                        if(aux[i][0] == j) ++aux[i][0];
                        
                        for(int k = 1;k < sz;++k){
                            if(aux[i][k] == aux[i][k - 1]) ++aux[i][k];
                            else break;
                        }
                    }
                }
                
                b.clear();
                
                for(int i = 0;i < C;++i){
                    int sz = aux[i].size();
                    
                    for(int k = 0;k < sz;++k)
                        b.push_back(make_pair(aux[i][k],i));
                }
            }
            
            if(op[0] == 'u'){
                for(int i = 0;i < n;++i) aux[ b[i].second ].push_back(b[i].first);
                for(int i = 0;i < C;++i) sort(aux[i].begin(),aux[i].end());
                
                for(int i = 0;i < C;++i)
                    if(R - aux[i].size() < x)
                        x = R - aux[i].size();
                
                for(int j = 0;j < x;++j){
                    for(int i = 0;i < C;++i){
                        int sz = aux[i].size();
                        if(sz == 0) continue;
                        
                        if(aux[i].back() == R - 1 - j) --aux[i].back();
                        
                        for(int k = sz - 2;k >= 0;--k){
                            if(aux[i][k] == aux[i][k + 1]) --aux[i][k];
                            else break;
                        }
                    }
                }
                
                b.clear();
                
                for(int i = 0;i < C;++i){
                    int sz = aux[i].size();
                    
                    for(int j = 0;j < sz;++j)
                        b.push_back(make_pair(aux[i][j],i));
                }
            }
            
            if(op[0] == 'l'){
                for(int i = 0;i < n;++i) aux[ b[i].first ].push_back(b[i].second);
                for(int i = 0;i < R;++i) sort(aux[i].begin(),aux[i].end());
                
                for(int i = 0;i < R;++i)
                    if(C - aux[i].size() < x)
                        x = C - aux[i].size();
                
                for(int j = 0;j < x;++j){
                    for(int i = 0;i < R;++i){
                        int sz = aux[i].size();
                        if(sz == 0) continue;
                        
                        if(aux[i].back() == C - 1 - j) --aux[i].back();
                        
                        for(int k = sz - 2;k >= 0;--k){
                            if(aux[i][k] == aux[i][k + 1]) --aux[i][k];
                            else break;
                        }
                    }
                }
                
                b.clear();
                
                for(int i = 0;i < R;++i){
                    int sz = aux[i].size();
                    
                    for(int j = 0;j < sz;++j)
                        b.push_back(make_pair(i,aux[i][j]));
                }
            }
            
            if(op[0] == 'r'){
                for(int i = 0;i < n;++i) aux[ b[i].first ].push_back(b[i].second);
                for(int i = 0;i < R;++i) sort(aux[i].begin(),aux[i].end());
                
                for(int i = 0;i < R;++i)
                    if(C - aux[i].size() < x)
                        x = C - aux[i].size();
                
                for(int j = 0;j < x;++j){
                    for(int i = 0;i < R;++i){
                        int sz = aux[i].size();
                        if(sz == 0) continue;
                        
                        if(aux[i][0] == j) ++aux[i][0];
                        
                        for(int k = 1;k < sz;++k){
                            if(aux[i][k] == aux[i][k - 1]) ++aux[i][k];
                            else break;
                        }
                    }
                }
                
                b.clear();
                
                for(int i = 0;i < R;++i){
                    int sz = aux[i].size();
                    
                    for(int j = 0;j < sz;++j)
                        b.push_back(make_pair(i,aux[i][j]));
                }
            }
        }
        
        sort(b.begin(),b.end());
        
        printf("Data set %d ends with boxes at locations",tc++);
        
        for(int i = 0;i < n;++i)
            printf(" (%d,%d)",b[i].first,b[i].second);
        
        puts(".");
    }
    
    return 0;
}
