#include<cstdio>
#include<cstring>

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int T,score,prev;
    char str[80];
    
    scanf("%d",&T);
    
    for(int caso=1;caso<=T;caso++){
        scanf("%s",str);
        
        score=0;
        prev=0;
        
        for(int i=0;i<strlen(str);i++){
            if(str[i]=='O') prev++;
            else prev=0;
            
            score+=prev;
        }
        
        printf("%d\n",score);
    }
    
    return 0;
}
