#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

struct node{
    int pos,rem,dist;
    
    node(){}
    node(int _pos, int _rem, int _dist) : pos(_pos), rem(_rem), dist(_dist) {}
};

int main(){
    char s[21];
    int dist[21][200],chose[21][200],prev[21][200];
    int K;
    
    while(scanf("%s %d",s,&K) == 2){
        int L = strlen(s);
        
        int ans = -1;
        memset(dist,-1,sizeof dist);
        queue<node> Q;
        
        Q.push(node(0,0,0));
        dist[0][0] = 0;
        
        while(!Q.empty()){
            node cur = Q.front();
            Q.pop();
            
            if(cur.dist != dist[cur.pos][cur.rem]) continue;
            if(cur.rem == 0 && cur.pos == L) break;
            
            int rem = (2 * cur.rem) % K;
            
            if(dist[cur.pos][rem] == -1 || 1 + cur.dist < dist[cur.pos][rem]){
                Q.push(node(cur.pos,rem,1 + cur.dist));
                dist[cur.pos][rem] = 1 + cur.dist;
                chose[cur.pos][rem] = 0;
                prev[cur.pos][rem] = cur.rem;
            }
            
            rem = (cur.rem * 2 + s[cur.pos] - '0') % K;
            
            if(cur.pos < L && (dist[cur.pos + 1][rem] == -1 || 1 + cur.dist < dist[cur.pos + 1][rem])){
                Q.push(node(cur.pos + 1,rem,1 + cur.dist));
                dist[cur.pos + 1][rem] = 1 + cur.dist;
                chose[cur.pos + 1][rem] = 2;
                prev[cur.pos + 1][rem] = cur.rem;
            }
            
            rem = (2 * cur.rem + 1) % K;
            
            if(dist[cur.pos][rem] == -1 || 1 + cur.dist < dist[cur.pos][rem]){
                Q.push(node(cur.pos,rem,1 + cur.dist));
                dist[cur.pos][rem] = 1 + cur.dist;
                chose[cur.pos][rem] = 1;
                prev[cur.pos][rem] = cur.rem;
            }
        }
        
        if(dist[L][0] == -1) puts("impossible");
        else{
            string ans;
            
            int pos = L,rem = 0;
            
            while(pos != 0 || rem != 0){
                if(chose[pos][rem] == 0){
                    ans += '0';
                    rem = prev[pos][rem];
                }else if(chose[pos][rem] == 1){
                    ans += '1';
                    rem = prev[pos][rem];
                }else if(chose[pos][rem] == 2){
                    ans += s[pos - 1];
                    rem = prev[pos][rem];
                    --pos;
                }
            }
            
            reverse(ans.begin(),ans.end());
            
            puts(ans.c_str());
        }
    }
    
    return 0;
}
