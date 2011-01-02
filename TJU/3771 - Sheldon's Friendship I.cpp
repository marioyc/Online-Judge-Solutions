#include <cstdio>

using namespace std;

int main(){
    int T;
    scanf("%d",&T);
    
    char name[4][10];
    int value[10],ans;
    
    while(T--){
        for(int i = 0;i<4;++i)
            scanf("%s %d",name[i],&value[i]);
        
        ans = 0;
        
        for(int i = 1;i<4;++i)
            if(value[i]<value[ans])
                ans = i;
        
        printf("Poor %s\n",name[ans]);
    }
    
    return 0;
}
