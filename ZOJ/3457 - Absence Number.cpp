#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

bool used[76344];
int found[100];

int solve(int den){
    int num = 1,last = 0,d,cont = 0;
    
    while(num<den) num *= 10;
    
    memset(used,false,sizeof(used));
    
    while(cont<100){
        d = num/den;
        num %= den;
        
        last = last*10+d;
        
        if(found[last]!=den){
            found[last] = den;
            ++cont;
        }
        
        last = d;
        
        if(!used[num]) used[num] = true;
        else{
            d = (num*10)/den;
            
            last = last*10+d;
            
            if(found[last]!=den){
                found[last] = den;
                ++cont;
            }
            
            break;
        }
        
        num *= 10;
    }
    
    if(cont!=99) return -1;
    
    int ret = 0;
    for(int i = 0;i<100;++i) if(found[i]!=den) ret = i;
    
    return ret;
}

int main(){
    int ans[100];
    
    memset(ans,-1,sizeof(ans));
    memset(found,-1,sizeof(found));
    
    for(int m = 327,cont = 0,n;m<=76344;++m){
        n = solve(m);
        
        if(n!=-1 && ans[n]==-1) ans[n] = m;
    }
    
    int N;
    
    while(scanf("%d",&N)==1)
        printf("%d\n",ans[N]);
    
    return 0;
}
