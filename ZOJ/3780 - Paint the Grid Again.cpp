#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int T,N;
    char M[500][501];
    bool checkr[500],checkc[500];
    vector<int> L[1000];
    int in[1000];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        
        for(int i = 0;i < N;++i)
            scanf("%s",M[i]);
        
        memset(checkr,false,sizeof checkr);
        memset(checkc,false,sizeof checkc);
        memset(in,0,sizeof in);
        
        for(int i = 0;i < N;++i)
            for(int j = 0;j < N;++j)
                if(M[i][j] == 'X')
                    checkr[i] = true;
                else
                    checkc[j] = true;
        
        int N2 = 0;
        
        for(int i = 0;i < N;++i){
            if(checkr[i]) ++N2;
            if(checkc[i]) ++N2;
        }
        
        for(int i = 0;i < 2 * N;++i)
            L[i].clear();
        
        for(int i = 0;i < N;++i)
            if(checkr[i])
                for(int j = 0;j < N;++j)
                    if(checkc[j])
                        if(M[i][j] == 'X'){
                            L[j].push_back(N + i);
                            ++in[N + i];
                        }else{
                            L[N + i]. push_back(j);
                            ++in[j];
                        }
        
        priority_queue<int> Q;
        
        for(int i = 0;i < N;++i)
            if(checkc[i] && in[i] == 0)
                Q.push(-i);
        
        for(int i = 0;i < N;++i)
            if(checkr[i] && in[N + i] == 0)
                Q.push(-N-i);
        
        vector<int> ans;
        
        while(!Q.empty()){
            int aux = -Q.top();
            Q.pop();
            ans.push_back(aux);
            
            for(int i = L[aux].size() - 1,to;i >= 0;--i){
                to = L[aux][i];
                --in[to];
                
                if(in[to] == 0) Q.push(-to);
            }
        }
        
        if(ans.size() != N2) printf("No solution\n");
        else{
            for(int i = 0;i < N2;++i){
                printf("%c%d",ans[i] < N? 'C' : 'R',ans[i] < N? ans[i] + 1 : ans[i] - N + 1);
                if(i + 1 < N2) printf(" ");
                else printf("\n");
            }
        }
    }
    
    return 0;
}
