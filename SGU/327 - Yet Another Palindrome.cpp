#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int N;
string s[14][2];
bool ok[14];
int best[14][2][14][2];
int memo[(1 << 14)][14][2],choose1[(1 << 14)][14][2],choose2[(1 << 14)][14][2];

int solve(int mask, int last, int dir){
    if(mask == (1 << N) - 1) return 0;
    
    int &ret = memo[mask][last][dir];
    
    if(ret == -1){
        for(int i = 0;i < N;++i){
            for(int di = 0;di < 2;++di){
                if((mask & (1 << i)) == 0){
                    int aux = solve((mask | (1 << i)),i,di) + s[i][di].size() - best[last][dir][i][di];
                    
                    if(ret == -1 || aux < ret){
                        choose1[mask][last][dir] = i;
                        choose2[mask][last][dir] = di;
                        ret = aux;
                    }
                }
            }
        }
    }
    
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    
    cin >> N;
    
    for(int i = 0;i < N;++i)
        cin >> s[i][0];
    
    for(int i = 0;i < N;++i){
        s[i][1] = s[i][0];
        reverse(s[i][1].begin(),s[i][1].end());
    }
    
    memset(ok,true,sizeof ok);
    
    for(int i = 0;i < N;++i){
        if(ok[i])
            for(int j = i + 1;j < N;++j)
                if(s[j][0] == s[i][0] || s[j][1] == s[i][0])
                    ok[j] = false;
    }
    
    for(int i = 0;i < N;++i)
        if(ok[i])
            for(int j = 0;j < N && ok[i];++j)
                if(ok[j] && j != i && (s[j][0].find(s[i][0]) != string::npos || s[j][1].find(s[i][0]) != string::npos))
                    ok[i] = false;
    
    for(int i = 0;i < N;++i){
        if(ok[i]){
            for(int di = 0;di < 2;++di){
                for(int j = 0;j < N;++j){
                    if(ok[j] && j != i){
                        for(int dj = 0;dj < 2;++dj){
                            int li = s[i][di].size(),lj = s[j][dj].size();
                            int mx = min(li,lj);
                            best[i][di][j][dj] = 0;
                            
                            for(int k = mx - 1;k > 0;--k)
                                if(s[i][di].substr(li - k,k) == s[j][dj].substr(0,k)){
                                    best[i][di][j][dj] = k;
                                    break;
                                }
                        }
                    }
                }
            }
        }
    }
    
    int done = 0;
    
    for(int i = 0;i < N;++i)
        if(!ok[i]) done |= (1 << i);
    
    memset(memo,-1,sizeof memo);
    
    string ans;
    bool found = false;
    
    for(int i = 0;i < N;++i){
        if(!ok[i]) continue;
        int len = s[i][0].size();
        
        string ret[2];
        
        for(int di = 0;di < 2;++di){
            solve((done | (1 << i)),i,di);
            int mask = (done | (1 << i)),last = i,dir = di;
            
            while(mask != (1 << N) - 1){
                int c1 = choose1[mask][last][dir],c2 = choose2[mask][last][dir];
                ret[di] += s[c1][c2].substr(best[last][dir][c1][c2],s[c1][c2].size() - best[last][dir][c1][c2]);
                mask |= (1 << c1);
                last = c1;
                dir = c2;
            }
        }
        
        for(int j = len,k = 0;j >= 0;--j,++k){
            // par
            int common = min(j,k);
            bool check = true;
            
            for(int x = 0;x < common;++x)
                if(s[i][0][j - 1 - x] != s[i][0][j + x])
                    check = false;
            
            if(check){
                string aux;
                
                for(int x = 0;x < max(j,k);++x){
                    int cur;
                    if(j + x < len) cur = j + x;
                    else cur = 2 * j - 1 - (j + x);
                    aux += s[i][0][cur];
                }
                
                if(j >= k) aux += ret[1];
                else aux += ret[0];
                
                string aux2 = aux;
                reverse(aux2.begin(),aux2.end());
                aux = aux2 + aux;
                if(!found || aux.size() < ans.size()) ans = aux,found = true;
            }
            
            // impar
            if(j > 0){
                common = min(j - 1,k);
                check = true;
                
                for(int x = 0;x < common;++x)
                    if(s[i][0][j - 2 - x] != s[i][0][j + x])
                        check = false;
                
                if(check){
                    string aux;
                    
                    for(int x = 0;x < max(j - 1,k) + 1;++x){
                        int cur;
                        if(j - 1 + x < len) cur = j - 1 + x;
                        else cur = 2 * j - 2 - (j - 1 + x);
                        aux += s[i][0][cur];
                    }
                    
                    if(j - 1 >= k) aux += ret[1];
                    else aux += ret[0];
                    
                    string aux2 = aux.substr(1,aux.size() - 1);
                    reverse(aux2.begin(),aux2.end());
                    aux = aux2 + aux;
                    if(!found || aux.size() < ans.size()) ans = aux,found = true;
                }
            }
        }
    }
    
    cout << ans << '\n';
    
    return 0;
}
