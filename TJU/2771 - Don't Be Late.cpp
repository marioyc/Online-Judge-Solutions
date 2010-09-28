#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int T,x;
    char c;
    int cont[52];
    
    scanf("%d\n",&T);
    
    for(int caso=1;caso<=T;caso++){
        fill(cont,cont+52,0);
        
        while(1){
            c=getchar();
            if(c=='\n') break;
            
            if(c>='A' && c<='Z') cont[c-'A']++;
            else cont[26+c-'a']++;
        }
        
        x=0;
        
        for(int i=0;i<26;i++)
            if(cont[i]>x){
                x=cont[i];
                c='A'+i;
            }
        
        for(int i=26;i<52;i++)
            if(cont[i]>x){
                x=cont[i];
                c='a'+i-26;
            }
        
        printf("%c\n",c);
    }
    
    return 0;
}
