#include <cstdio>

using namespace std;

int main(){
    char s1[1001],s2[1001];
    int n=0,m=0,m2=0;
    char c;
    
    while(1){
        c=getchar();
        if(c=='\n') break;
        s1[n++]=c;
    }
    
    while(1){
        c=getchar();
        if(c=='\n') break;
        s2[m++]=c;
    }
    
    for(int i=0;i<m;i++) if(s2[i]!=' ') s2[m2++]=s2[i];
    m=m2;
    
    char M[5][5];
    bool used[26];
    int cont=0;
    
    for(int i=0;i<26;i++) used[i]=false;
    used['q'-'a']=true;
    
    for(int i=0;i<n;i++){
        if(s1[i]==' ' || used[s1[i]-'a']) continue;
        M[cont/5][cont%5]=s1[i]-'a'+'A';
        used[s1[i]-'a']=true;
        cont++;
    }
    
    for(c='A';c<='Z';c++){
        if(used[c-'A']) continue;
        M[cont/5][cont%5]=c;
        cont++;
    }
    
    int R[26],C[26];
    
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++){
            R[M[i][j]-'A']=i;
            C[M[i][j]-'A']=j;
        }
    
    int pos=0,r1,c1,r2,c2;
    int a,b;
    
    while(pos<m){
        if(pos==m-1 || s2[pos]==s2[pos+1]){
            a=s2[pos++]-'a';
            b='X'-'A';
        }else{
            a=s2[pos]-'a';
            b=s2[pos+1]-'a';
            pos+=2;
        }
        
        r1=R[a]; c1=C[a];
        r2=R[b]; c2=C[b];
        
        if(r1==r2) printf("%c%c",M[r1][(c1+1)%5],M[r1][(c2+1)%5]);
        else if(c1==c2) printf("%c%c",M[(r1+1)%5][c1],M[(r2+1)%5][c1]);
        else printf("%c%c",M[r1][c2],M[r2][c1]);
    }
    
    printf("\n");
    
    return 0;
}
