#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int main(){
    int T,cont[10],L;
    char num[21];
    string x;
    
    scanf("%d",&T);
    memset(cont,0,sizeof(cont));
    
    while(T--){
        scanf("%s",num);
        L = strlen(num);
        
        for(int i = 0;i<L;++i) ++cont[num[i]-'0'];
        for(int i = 1;i<=4;++i) --cont[i];
        
        int rem = 0;
        
        for(int i = 1;i<=9;++i){
            while(cont[i]){
                putchar('0'+i);
                rem = (rem*10+i)%7;
                --cont[i];
            }
        }
        
        rem = (rem*10000)%7;
        rem = (7-rem)%7;
        
        if(rem==0) x = "3241";
        else if(rem==1) x = "1324";
        else if(rem==2) x = "1234";
        else if(rem==3) x = "2341";
        else if(rem==4) x = "1243";
        else if(rem==5) x = "1342";
        else x = "2134";
        
        printf("%s",x.c_str());
        
        while(cont[0]){
            putchar('0');
            --cont[0];
        }
        
        putchar('\n');
    }
    
    return 0;
}
