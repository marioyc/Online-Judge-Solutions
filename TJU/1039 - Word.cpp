#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int getMask(char *s){
    int mask = 0;
    
    for(int i = 0;s[i];++i)
        if(s[i]=='b')
            mask |= (1<<i);
    
    return mask;
}

int main(){
    int L,s;
    
    while(scanf("%d",&L)==1){
        char start[L+1],rule[5];
        scanf("%s",start);
        
        int next[2][2][2];
        
        for(int i = 0;i<8;++i){
            scanf("%s",rule);
            next[rule[0]-'a'][rule[1]-'a'][rule[2]-'a'] = rule[3]-'a';
        }
        
        scanf("%d",&s);
        
        int used[(1<<L)],inv[(1<<L)],cycle_start,cycle_length;
        memset(used,-1,sizeof(used));
        
        char cur[L+1],nxt[L+1];
        memset(cur,0,sizeof(cur));
        memset(nxt,0,sizeof(nxt));
        
        for(int i = 0;i<L;++i) cur[i] = start[i];
        
        int mask = getMask(cur);
        used[mask] = 0;
        inv[0] = mask;
        
        for(int it = 1;;++it){
            for(int i = 0;i<L;++i)
                nxt[i] = 'a'+next[cur[(i+L-2)%L]-'a'][cur[i]-'a'][cur[(i+1)%L]-'a'];
            
            for(int i = 0;i<L;++i)
                cur[i] = nxt[i];
            
            mask = getMask(cur);
            
            if(used[mask]==-1){
                used[mask] = it;
                inv[it] = mask;
            }else{
                cycle_start = used[mask];
                cycle_length = it-used[mask];
                break;
            }
        }
        
        if(s<=cycle_start) mask = inv[s];
        else mask = inv[cycle_start+(s-cycle_start)%cycle_length];
        
        string aux[L];
        
        for(int i = 0;i<L;++i)
            for(int j = 0;j<L;++j)
                aux[i] += ((mask & (1<<((i+j)%L)))? 'b' : 'a');
        
        sort(aux,aux+L);
        printf("%s\n",aux[0].c_str());
    }
    
    return 0;
}
