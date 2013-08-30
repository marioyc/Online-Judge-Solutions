#include <cstdio>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

map<string,int> cont;

int main(){
    int N,Q;
    char aux[20];
    string prop[4];
    
    scanf("%d",&N);
    
    for(int i = 0,sz;i < N;++i){
        scanf("%d",&sz);
        
        for(int j = 0;j < sz;++j){
            scanf("%s",aux);
            prop[j] = string(aux);
        }
        
        sort(prop,prop + sz);
        
        for(int mask = 0;mask < (1 << sz);++mask){
            string s;
            
            for(int j = 0;j < sz;++j)
                if(mask >> j & 1)
                    s += prop[j] + " ";
            
            ++cont[s];
        }
    }
    
    scanf("%d",&Q);
    
    for(int i = 0,sz;i < Q;++i){
        scanf("%d",&sz);
        
        for(int j = 0;j < sz;++j){
            scanf("%s",aux);
            prop[j] = string(aux);
        }
        
        sort(prop,prop + sz);
        
        string s;
        
        for(int j = 0;j < sz;++j)
            s += prop[j] + " ";
        
        printf("%d\n",cont[s]);
    }
    
    return 0;
}
