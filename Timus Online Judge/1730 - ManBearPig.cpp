#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int gcd(int a, int b){
    while(a % b != 0){
        a %= b;
        swap(a,b);
    }
    
    return b;
}

bool check(int x){
    for(int i = 0;i <= 10;++i)
        if(x == (1 << i)) return true;
    
    return false;
}

int get_level(int x){
    for(int i = 0;i <= 10;++i)
        if(x < (1 << (i+1)) - 1)
            return i;
    
    return -1;
}

bool visited[2048];
int creature[2048],ind[2048];
queue<int> Q;

int main(){
    int n = 0;
    char x[201];
    string s,name[10];
    
    scanf("%s",x);
    s = string(x) + "-";
    
    int L = s.size();
    
    for(int i = 0;i < L;++i){
        name[n] = string();
        
        while(s[i] != '-'){
            name[n] += s[i];
            ++i;
        }
        
        ++n;
    }
    
    int a[10],b[10];
    bool possible = true;
    char c;
    
    for(int i = 0;i < n;++i){
        scanf("%d/%d",&a[i],&b[i]);
        
        int g = gcd(a[i],b[i]);
        a[i] /= g; b[i] /= g;
        a[i] *= 1024 / b[i];
        
        if(!check(b[i])) possible = false;
    }
    
    if(!possible) puts("No solution");
    else{
        int total = 1024,cont = 0;
        Q.push(0);
        
        memset(visited,false,sizeof(visited));
        memset(creature,-1,sizeof(creature));
        
        while(total != 0){
            int cur = Q.front();
            Q.pop();
            
            int lvl = get_level(cur);
            int pow2 = (1 << (10 - lvl));
            bool used = false;
            visited[cur] = true;
            ++cont;
            
            for(int i = 0;i < n;++i){
                if(a[i] >= pow2){
                    a[i] -= pow2;
                    total -= pow2;
                    creature[cur] = i;
                    used = true;
                    break;
                }
            }
            
            if(!used){
                Q.push(2 * cur + 1);
                Q.push(2 * cur + 2);
            }
        }
        
        printf("%d\n",cont);
        
        for(int i = 2047,j = 1;i >= 0;--i){
            if(visited[i]){
                ind[i] = j++;
                
                if(creature[i] != -1) printf("%s\n",name[creature[i]].c_str());
                else printf("%d %d\n",ind[2 * i + 1],ind[2 * i + 2]);
            }
        }
    }
    
    return 0;
}
