#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

struct node{
    int M[3][3];
    
    int toInt(){
        int ret = 0;
        
        for(int i = 0;i < 3;++i)
            for(int j = 0;j < 3;++j)
                ret = ret * 10 + M[i][j];
        
        return ret;
    }
}cur,nxt,Q[362880];

map<int, string> next;

void bfs(){
    for(int i = 0;i < 3;++i)
        for(int j = 0;j < 3;++j)
            cur.M[i][j] = 3 * i + j + 1;
    
    int val = cur.toInt(),val2,head = 0,tail = 0;
    
    next[val] = string();
    Q[tail++] = cur;
    
    while(head < tail){
        cur = Q[head++];
        val = cur.toInt();
        
        // movimientos horizontales
        for(int i = 0;i < 3;++i){
            nxt = cur;
            
            swap(nxt.M[i][2],nxt.M[i][1]);
            swap(nxt.M[i][2],nxt.M[i][0]);
            val2 = nxt.toInt();
            
            if(next.find(val2) == next.end()){
                string s = "H";
                s += '1' + i;
                next[val2] = s + next[val];
                Q[tail++] = nxt;
            }
        }
        
        // movimientos verticales
        for(int i = 0;i < 3;++i){
            nxt = cur;
            
            swap(nxt.M[2][i],nxt.M[1][i]);
            swap(nxt.M[1][i],nxt.M[0][i]);
            val2 = nxt.toInt();
            
            if(next.find(val2) == next.end()){
                string s = "V";
                s += '1' + i;
                next[val2] = s + next[val];
                Q[tail++] = nxt;
            }
        }
    }
}

void solve(){
    int cont = 0,val = cur.toInt();
    string ans;
    
    if(next.find(val) == next.end()) puts("Not solvable");
    else{
        ans = next[val];
        printf("%d %s\n",ans.size() / 2,ans.c_str());
    }
}

int main(){
    bfs();
    
    while(scanf("%d %d %d %d %d %d %d %d %d",&cur.M[0][0],&cur.M[0][1],&cur.M[0][2]
                                            ,&cur.M[1][0],&cur.M[1][1],&cur.M[1][2]
                                            ,&cur.M[2][0],&cur.M[2][1],&cur.M[2][2]) == 9){
        solve();
    }
    
    return 0;
}
