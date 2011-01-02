#include <iostream>
#include <cstring>

using namespace std;

string move(int dir){
    if(dir==0) return "LD";
    if(dir==1) return "L";
    if(dir==2) return "LU";
    if(dir==3) return "D";
    if(dir==4) return "U";
    if(dir==5) return "RD";
    if(dir==6) return "R";
    return "RU";
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    
    int sx = s1[0]-'a',sy = s1[1]-'1';
    int ex = s2[0]-'a',ey = s2[1]-'1';
    
    int dx[] = {-1,-1,-1,0,0,1,1,1},dy[] = {-1,0,1,-1,1,-1,0,1};
    int prev[8][8],Qx[64],Qy[64],head = 0,tail = 0;
    memset(prev,-1,sizeof(prev));
    
    prev[sx][sy] = -2;
    Qx[tail] = sx; Qy[tail] = sy; ++tail;
    
    while(head<tail){
        int x = Qx[head],y = Qy[head]; ++head;
        
        if(x==ex && y==ey) break;
        
        for(int i = 0;i<8;++i){
            int x2 = x+dx[i],y2 = y+dy[i];
            
            if(x2>=0 && x2<8 && y2>=0 && y2<8 && prev[x2][y2]==-1){
                prev[x2][y2] = i;
                Qx[tail] = x2; Qy[tail] = y2; ++tail;
            }
        }
    }
    
    int ans[14],sz = 0;
    
    while(ex!=sx || ey!=sy){
        ans[sz] = prev[ex][ey];
        ex -= dx[ans[sz]]; ey -= dy[ans[sz]];
        ++sz;
    }
    
    cout<<sz<<'\n';
    
    for(int i = 0;i<sz;++i)
        cout<<move(ans[sz-1-i])<<'\n';
    
    return 0;
}
