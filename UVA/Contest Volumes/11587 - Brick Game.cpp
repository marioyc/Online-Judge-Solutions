#include <cstdio>
#include <cstring>

using namespace std;

bool valid[21],used[21];
char s[101];
int L,best,ans[20],aux[20],cont;

void search(int pos){
    if(cont > best) return;
    
    if(pos == 0){
        if(s[0] == 'W' && !valid[1]) return;
        for(int i = 1,j = 0;i <= 20;++i)
            if(used[i]) aux[j++] = i;
        
        bool take = false;
        
        if(cont < best) take = true;
        else{
            for(int i = 0;i < cont;++i){
                if(ans[i] < aux[i]) break;
                if(aux[i] < ans[i]) take = true;
            }
        }
        
        if(take){
            best = cont;
            for(int i = 0;i < cont;++i) ans[i] = aux[i];
        }
        
        return;
    }
    
    bool done = false;
    
    if(s[pos] == 'L') done = true;
    else{
        if(pos < 20 && used[pos + 1]) done = true;
        
        for(int j = pos-1;j >= 0 && pos-j <= 20;--j)
            if(used[pos-j] && s[j] == 'L') done = true;
    }
    
    if(done) search(pos - 1);
    else{
        if(pos < 20 && valid[pos + 1]){
            used[pos + 1] = true;
            ++cont;
            
            search(pos - 1);
            
            used[pos + 1] = false;
            --cont;
        }
        
        for(int i = 1;i <= 20 && pos >= i;++i){
            if(!used[i] && valid[i] && s[pos-i] == 'L'){
                used[i] = true;
                ++cont;
                
                search(pos - 1);
                
                used[i] = false;
                --cont;
            }
        }
    }
}

int main(){
    int T;
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%s",s);
        L = strlen(s);
        
        memset(valid,true,sizeof(valid));
        
        for(int i = 0;i < L && i < 20;++i)
            if(s[i] == 'L')
                valid[i + 1] = false;
        
        for(int i = 0;i < L;++i)
            if(s[i] == 'L')
                for(int j = i-1;j >= 0 && i-j <= 20;--j)
                    if(s[j] == 'L') valid[i - j] = false;
        
        memset(used,false,sizeof(used));
        cont = 0;
        
        if(s[0] == 'W' && valid[1]){
            used[1] = true;
            ++cont;
        }
        
        best = 21;
        search(L-1);
        
        printf("Case %d:",tc);
        
        if(best == 0) printf(" %d",L + 1);
        else if(best < 21)
            for(int i = 0;i < best;++i) printf(" %d",ans[i]);
        
        printf("\n");
    }
    
    return 0;
}
