#include <cstdio>
#include <cstring>

using namespace std;

char s[100001];
int next_pos[100000];

int getInd(char c){
    if(c >= 'A' && c <= 'Z') return c-'A';
    if(c == '_') return 26;
    return c-'a'+27;
}

int main(){
    int x,L;
    
    scanf("%d %s",&x,s);
    L = strlen(s);
    --x;
    
    int cont[54];
    memset(cont,0,sizeof(cont));
    for(int i = 0;i < L;++i) ++cont[getInd(s[i]) + 1];
    for(int i = 1;i < 53;++i) cont[i] += cont[i-1];
    
    for(int i = 0;i < L;++i) next_pos[cont[getInd(s[i])]++] = i;
    for(int i = 0;i < L;++i) putchar(s[x = next_pos[x]]);
    putchar('\n');
    
    return 0;
}
