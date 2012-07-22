#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int main(){
    int N,K;
    char name[1000][11];
    vector<int> rev[1000];
    bool used[1000];
    
    while(true){
        scanf("%d %d",&K,&N);
        
        if(N == 0) break;
        
        for(int i = 0;i < N;++i)
            rev[i].clear();
        
        for(int i = 0;i < N;++i){
            scanf("%s",name[i]);
            
            for(int j = 0,x;j < K;++j){
                scanf("%d",&x);
                rev[x - 1].push_back(i);
            }
        }
        
        int ans = 0;
        
        for(int i = 0;i < N;++i){
            bool ok = true;
            
            if(rev[i].size() != K) ok = false;
            else{
                memset(used,false,sizeof used);
                
                for(int j = rev[i].size() - 1,x;j >= 0;--j){
                    x = rev[i][j];
                    
                    if(x == i) ok = false;
                    else if(used[x]) ok = false;
                    else if(strcmp(name[x],name[i]) == 0) ok = false;
                    
                    used[x] = true;
                }
            }
            
            if(!ok) ++ans;
        }
        
        if(ans == 0) puts("NO PROBLEMS FOUND");
        else if(ans == 1) puts("1 PROBLEM FOUND");
        else printf("%d PROBLEMS FOUND\n",ans);
    }
    
    return 0;
}
