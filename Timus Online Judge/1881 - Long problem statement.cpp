#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int h,w,n;
    char s[10001];
    
    scanf("%d %d %d",&h,&w,&n);
    
    int lines = 1,cont = 0,len;
    
    for(int i = 0;i < n;++i){
        scanf("%s",s);
        
        len = strlen(s) + 1;
        
        if(cont + len <= w + 1) cont += len;
        else{
            cont = len;
            ++lines;
        }
    }
    
    printf("%d\n",(lines + h - 1) / h);
    
    return 0;
}
