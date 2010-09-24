#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    char s[16];
    scanf("%s",s);
    int L=strlen(s);
    
    char ans[3][4*L+2];
    
    for(int i=0;i<3;i++)
        for(int j=0;j<4*L+2;j++)
            ans[i][j]='.';
    ans[0][4*L+1]=ans[1][4*L+1]=ans[2][4*L+1]=0;
    
    for(int i=0;i<L;i++) ans[2][4*i+2]=s[i];
    
    for(int i=0,c=2;i<L;i++,c+=4){
        if(i%3!=2){
            ans[0][c]='#';
            ans[1][c-1]='#';
            ans[1][c+1]='#';
            ans[2][c-2]='#';
            ans[2][c+2]='#';
        }
    }
    
    for(int i=0,c=2;i<L;i++,c+=4){
        if(i%3==2){
            ans[0][c]='*';
            ans[1][c-1]='*';
            ans[1][c+1]='*';
            ans[2][c-2]='*';
            ans[2][c+2]='*';
        }
    }
    
    printf("%s\n%s\n%s\n%s\n%s\n",ans[0],ans[1],ans[2],ans[1],ans[0]);
    
    return 0;
}
