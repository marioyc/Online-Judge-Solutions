#include <iostream>
#include <sstream>
#include <cstring>
#include <string>

using namespace std;

int S,M,N,C[120],pow3[8];
bool teaches[120][8];
int memo[6562][100];

int solve(int cont[],int mask, int pos){
    if(pos == N){
        for(int i = 0;i < S;++i)
            if(cont[i] < 2) return 5000000;
        
        return 0;
    }
    
    int &ret = memo[mask][pos];
    
    if(ret == -1){
        ret = min(5000000,solve(cont,mask,pos + 1));
        
        for(int i = 0;i < S;++i){
            if(teaches[M + pos][i]){
                if(cont[i] < 2) mask += pow3[i];
                ++cont[i];
            }
        }
        
        ret = min(ret,C[M + pos] + solve(cont,mask,pos + 1));
        
        for(int i = 0;i < S;++i){
            if(teaches[M + pos][i]){
                --cont[i];
                if(cont[i] < 2) mask -= pow3[i];
            }
        }
    }
    
    return ret;
}

int main(){
    pow3[0] = 1;
    
    for(int i = 1;i < 8;++i)
        pow3[i] = pow3[i-1] * 3;
    
    string line;
    int x,aux[8],mask;
    
    while(true){
        cin >> S >> M >> N;
        if(S == 0) break;
        
        memset(teaches,false,sizeof(teaches));
        getline(cin,line);
        
        for(int i = 0;i < M + N;++i){
            getline(cin,line);
            istringstream is(line);
            
            is >> C[i];
            while(is >> x) teaches[i][x-1] = true;
        }
        
        int ans = 0;
        
        for(int i = 0;i < S;++i) aux[i] = 0;
        mask = 0;
        
        for(int i = 0;i < M;++i){
            ans += C[i];
            
            for(int j = 0;j < S;++j){
                if(teaches[i][j]){
                    if(aux[j] < 2) mask += pow3[j];
                    ++aux[j];
                }
            }
        }
        
        memset(memo,-1,sizeof(memo));
        ans += solve(aux,mask,0);
        
        cout << ans << endl;
    }
    
    return 0;
}
