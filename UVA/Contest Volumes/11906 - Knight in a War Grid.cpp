#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main(){
    int tc = 1,T,R,C,M,N,W;
    bool poss[100][100],conn[100][100];
    int Qr[10000],Qc[10000],head,tail;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d %d %d %d",&R,&C,&M,&N,&W);
        
        memset(poss,true,sizeof(poss));
        
        for(int i = 0,x,y;i<W;++i){
            scanf("%d %d",&x,&y);
            poss[x][y] = false;
        }
        
        int even = 0,odd = 0;
        
        set< pair<int, int> > S;
        
        S.insert(make_pair(M,N));
        S.insert(make_pair(M,-N));
        S.insert(make_pair(-M,N));
        S.insert(make_pair(-M,-N));
        S.insert(make_pair(N,M));
        S.insert(make_pair(N,-M));
        S.insert(make_pair(-N,M));
        S.insert(make_pair(-N,-M));
        
        set< pair<int, int> > :: iterator it;
        vector<int> dr,dc;
        
        for(it = S.begin();it!=S.end();++it){
            dr.push_back((*it).first);
            dc.push_back((*it).second);
        }
        
        int sz = S.size();
        
        memset(conn,false,sizeof(conn));
        head = tail = 0;
        
        conn[0][0] = true;
        Qr[tail] = 0; Qc[tail] = 0;
        ++tail;
        
        while(head<tail){
            int r = Qr[head],c = Qc[head];
            ++head;
            
            for(int i = 0,r2,c2;i<sz;++i){
                r2 = r+dr[i]; c2 = c+dc[i];
                
                if(r2>=0 && r2<R && c2>=0 && c2<C && !conn[r2][c2] && poss[r2][c2]){
                    conn[r2][c2] = true;
                    Qr[tail] = r2; Qc[tail] = c2;
                    ++tail;
                }
            }
        }
        
        for(int i = 0;i<R;++i) for(int j = 0;j<C;++j){
            if(conn[i][j]){
                int cont = 0;
                
                for(int k = 0;k<sz;++k){
                    int r2 = i+dr[k],c2 = j+dc[k];
                    if(r2>=0 && r2<R && c2>=0 && c2<C && poss[r2][c2]) ++cont;
                }
                
                if(cont & 1) ++odd;
                else ++even;
            }
        }
        
        printf("Case %d: %d %d\n",tc++,even,odd);
    }
    
    return 0;
}
