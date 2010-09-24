/*
ID: zion_ba1
LANG: C++
TASK: namenum
*/

#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    char f[26],x='2';
    for(char i='A';i<='Z';i++){
        f[i-'A']=x;
        if(i=='C' || i=='F' || i=='I' || i=='L' || i=='O' || i=='S' || i=='V' || i=='Y') x++;
    }
    
    freopen("namenum.in","r",stdin);
    freopen("namenum.out","w",stdout);
    
    char N[13];
    scanf("%s",N);
    
    int L=strlen(N);
    
    freopen("dict.txt","r",stdin);
    
    char M[13];
    bool ok,found=false;
    
    while(scanf("%s",M)==1){
        if(strlen(M)!=L) continue;
        
        ok=true;
        
        for(int i=0;i<L;i++)
            if(f[M[i]-'A']!=N[i]) ok=false;
        
        if(ok){
            printf("%s\n",M);
            found=true;
        }
    }
    
    if(!found) printf("NONE\n");
    
    return 0;
}
