#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define MAXN 250000

vector< pair<int, int> > LX[2*MAXN +1],LY[2*MAXN + 1];
int X[MAXN + 1],Y[MAXN + 1];

int main(){
    ios::sync_with_stdio(false);
    
    int T,N;
    string dir;
    bool first = true;
    
    cin >> T;
    
    while(T--){
        cin >> N >> dir;
        
        for(int i = 2*N;i >= 0;--i){
            LX[i].clear();
            LY[i].clear();
        }
        
        X[0] = Y[0] = N;
        
        LX[X[0]].push_back(make_pair(Y[0],0));
        LY[Y[0]].push_back(make_pair(X[0],0));
        
        for(int i = 1;i <= N;++i){
            if(dir[i - 1] == 'N'){
                X[i] = X[i - 1];
                Y[i] = Y[i - 1] + 1;
            }else if(dir[i - 1] == 'S'){
                X[i] = X[i - 1];
                Y[i] = Y[i - 1] - 1;
            }else if(dir[i - 1] == 'E'){
                X[i] = X[i - 1] + 1;
                Y[i] = Y[i - 1];
            }else{
                X[i] = X[i - 1] - 1;
                Y[i] = Y[i - 1];
            }
            
            LX[X[i]].push_back(make_pair(Y[i],i));
            LY[Y[i]].push_back(make_pair(X[i],i));
        }
        
        for(int i = 2*N;i >= 0;--i){
            sort(LX[i].begin(),LX[i].end());
            sort(LY[i].begin(),LY[i].end());
        }
        
        int l = -1,s,e;
        char dir;
        
        for(int i = 0;i <= N;++i){
            int szX = LX[ X[i] ].size();
            int lo = 0,hi = szX - 1,mi;
            
            while(lo < hi){
                mi = (lo + hi) >> 1;
                
                if(LX[ X[i] ][mi].first < Y[i]) lo = mi + 1;
                else hi = mi;
            }
            
            if(lo > 0){
                int ind = LX[ X[i] ][lo - 1].second;
                
                if(ind != i - 1 && ind != i + 1){
                    int l2 = abs(X[i] - X[ind]) + abs(Y[i] - Y[ind]);
                    
                    if((l == -1 || l2 < l) || (l2 == l && i < s) || (l2 == l && i == s && ind > e)){
                        l = l2;
                        s = i;
                        e = ind;
                        dir = 'S';
                    }
                }
            }
            
            if(lo + 1 < szX){
                int ind = LX[ X[i] ][lo + 1].second;
                
                if(ind != i - 1 && ind != i + 1){
                    int l2 = abs(X[i] - X[ind]) + abs(Y[i] - Y[ind]);
                    
                    if((l == -1 || l2 < l) || (l2 == l && i < s) || (l2 == l && i == s && ind > e)){
                        l = l2;
                        s = i;
                        e = ind;
                        dir = 'N';
                    }
                }
            }
            
            int szY = LY[ Y[i] ].size();
            lo = 0; hi = szY - 1;
            
            while(lo < hi){
                mi = (lo + hi) >> 1;
                
                if(LY[ Y[i] ][mi].first < X[i]) lo = mi + 1;
                else hi = mi;
            }
            
            if(lo > 0){
                int ind = LY[ Y[i] ][lo - 1].second;
                
                if(ind != i - 1 && ind != i + 1){
                    int l2 = abs(X[i] - X[ind]) + abs(Y[i] - Y[ind]);
                    
                    if((l == -1 || l2 < l) || (l2 == l && i < s) || (l2 == l && i == s && ind > e)){
                        l = l2;
                        s = i;
                        e = ind;
                        dir = 'W';
                    }
                }
            }
            
            if(lo + 1 < szY){
                int ind = LY[ Y[i] ][lo + 1].second;
                
                if(ind != i - 1 && ind != i + 1){
                    int l2 = abs(X[i] - X[ind]) + abs(Y[i] - Y[ind]);
                    
                    if((l == -1 || l2 < l) || (l2 == l && i < s) || (l2 == l && i == s && ind > e)){
                        l = l2;
                        s = i;
                        e = ind;
                        dir = 'E';
                    }
                }
            }
        }
        
        if(!first) cout << '\n';
        first = false;
        
        cout << l << ' ' << s << ' ' << e << ' ' << dir << '\n';
    }
    
    return 0;
}
