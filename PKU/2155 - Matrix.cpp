#include <iostream>
#include <cstring>

using namespace std;

int N;
char bit[1002][1002];

void update(int x, int y){
    ++x; ++y;
    
    for(int qx = x;qx <= N + 1;qx += qx & -qx)
        for(int qy = y;qy <= N + 1;qy += qy & -qy)
            bit[qx][qy] ^= 1;
}

int query(int x, int y){
    ++x; ++y;
    
    int ret = 0;
    
    for(int qx = x;qx > 0;qx -= qx & -qx)
        for(int qy = y;qy > 0;qy -= qy & -qy)
            ret ^= bit[qx][qy];
    
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    
    int T,Q;
    int x1,y1,x2,y2,x,y;
    char op;
    bool first = true;
    
    cin >> T;
    
    while(T--){
        cin >> N >> Q;
        
        memset(bit,0,sizeof bit);
        
        if(!first) cout << '\n';
        first = false;
        
        while(Q--){
            cin >> op;
            
            if(op == 'C'){
                cin >> x1 >> y1 >> x2 >> y2;
                
                update(x2,y2);
                update(x2,y1 - 1);
                update(x1 - 1,y2);
                update(x1 - 1,y1 - 1);
            }else{
                cin >> x >> y;
                
                cout << (query(N,N) ^ query(x - 1,N) ^ query(N,y - 1) ^ query(x - 1,y - 1)) << '\n';
            }
        }
    }
    
    return 0;
}
