#include <cstdio>
#include <cstring>

using namespace std;

const int MOD = 1000000007;
int L1,L2,best[2001][2001],cont[2001][2001];
char s1[2001],s2[2001];
int Q1[4004001],Q2[4004001],head,tail,aux,l;

void add(int p1, int p2, char c){
    l = best[p1][p2] + 1;
    aux = cont[p1][p2];
    
    if(p1 < L1 && s1[p1] == c) ++p1;
    if(p2 < L2 && s2[p2] == c) ++p2;
    
    if(best[p1][p2] == -1 || best[p1][p2] == l){
        if(best[p1][p2] == -1){
            best[p1][p2] = l;
            Q1[tail] = p1; Q2[tail] = p2;
            ++tail;
        }
        
        cont[p1][p2] += aux;
        if(cont[p1][p2] >= MOD) cont[p1][p2] -= MOD;
    }
}

void solve(){
    head = tail = 0;
    memset(cont,0,sizeof(cont));
    memset(best,-1,sizeof(best));
    
    best[0][0] = 0; cont[0][0] = 1;
    Q1[tail] = 0; Q2[tail] = 0;
    ++tail;
    
    int p1,p2;
    
    while(head < tail){
        p1 = Q1[head]; p2 = Q2[head];
        ++head;
        
        if(p1 < L1 && p2 < L2 && s1[p1] == s2[p2]) add(p1,p2,s1[p1]);
        else{
            if(p1 < L1) add(p1,p2,s1[p1]);
            if(p2 < L2) add(p1,p2,s2[p2]);
        }
    }
}

int main(){
    scanf("%s %s",s1,s2);
    L1 = strlen(s1);
    L2 = strlen(s2);
    
    solve();
    
    printf("%d\n",cont[L1][L2]);
    
    return 0;
}
