#include<cstdio>
#include<cstring>

using namespace std;

int main(){
    char s[101];
    int T,D,n;
    
    scanf("%d",&T);
    
    for(int i=0;i<T;i++){
        scanf("%s %d",s,&D);
        
        n=strlen(s);
        
        for(int j=0;j<n;j++) printf("%c",(char)((s[j]-'a'+D)%26+'a'));
        printf("\n");
    }
    
    return 0;
}
