#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int L,memo[100][100];
char S[101];

int solve(int s, int e){
    if(s>e) return 0;
    
    int &ret = memo[s][e];
    
    if(ret==-1){
        ret = 1+solve(s+1,e);
        
        if(S[s]=='(' || S[s]=='['){
            for(int i = s+1;i<=e;++i)
                if((S[s]=='(' && S[i]==')') || (S[s]=='[' && S[i]==']'))
                    ret = min(ret,solve(s+1,i-1)+solve(i+1,e));
        }
    }
    
    return ret;
}

void print(int s, int e){
    if(s>e) return;
    
    int best = solve(s,e);
    
    if(1+solve(s+1,e)==best){
        if(S[s]=='(' || S[s]==')'){
            putchar('(');
            putchar(')');
        }else{
            putchar('[');
            putchar(']');
        }
        
        print(s+1,e);
        return;
    }
    
    for(int i = s+1;i<=e;++i){
        if(((S[s]=='(' && S[i]==')') || (S[s]=='[' && S[i]==']')) && best==solve(s+1,i-1)+solve(i+1,e)){
            if(S[s]=='('){
                putchar('(');
                print(s+1,i-1);
                putchar(')');
                print(i+1,e);
            }else{
                putchar('[');
                print(s+1,i-1);
                putchar(']');
                print(i+1,e);
            }
            
            return;
        }
    }
}

int main(){
    scanf("%s",S);
    L = strlen(S);
    
    memset(memo,-1,sizeof(memo));
    print(0,L-1);
    putchar('\n');
    
    return 0;
}
