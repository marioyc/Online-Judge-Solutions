#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    char s[81];
    int L=0;
    
    while(scanf("%s",s)==1){
        if(s[0]=='<'){
            if(s[1]=='b'){
                L=0;
                printf("\n");
            }else{
                if(L>0) printf("\n");
                for(int i=0;i<80;i++) printf("-");
                printf("\n");
                L=0;
            }
        }else{
            if(L==0){
                L=strlen(s);
                printf("%s");
            }else{
                if(L+1+strlen(s)>80){
                    printf("\n");
                    printf("%s",s);
                    L=strlen(s);
                }else{
                    L+=1+strlen(s);
                    printf(" %s",s);
                }
            }
        }
    }
    
    if(L>0) printf("\n");
    
    return 0;
}
