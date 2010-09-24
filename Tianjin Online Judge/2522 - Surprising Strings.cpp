#include<cstdio>
#include<cstring>

using namespace std;

int main(){    
    char string[80];
    int n;
    bool M[26][26];
    bool surprising;
    
    while(1){
        scanf("%s",string);
        if(string[0]=='*') break;
        
        n=strlen(string);
        surprising=true;
        
        for(int i=1;i<n && surprising;i++){
            memset(M,false,sizeof(M));
            
            for(int j=0;j+i<n && surprising;j++){
                if(M[string[j]-'A'][string[j+i]-'A']) surprising=false;
                else M[string[j]-'A'][string[j+i]-'A']=true;
            }
        }
        
        if(surprising) printf("%s is surprising.\n",string);
        else printf("%s is NOT surprising.\n",string);
    }
    
    return 0;
}
