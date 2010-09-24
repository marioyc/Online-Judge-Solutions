#include<cstdio>
#include<cstring>

using namespace std;

int main(){    
    int R,C;
    char s[201];
    
    while(1){
        scanf("%d",&C);
        if(C==0) break;
        
        scanf("%s",s);
        
        R=strlen(s)/C;
        
        for(int j=0;j<C;j++)
            for(int i=0;i<R;i++)
                if(i%2==0) printf("%c",s[C*i+j]);
                else printf("%c",s[C*i+C-1-j]);
        
        printf("\n");
    }
    
    return 0;
}
