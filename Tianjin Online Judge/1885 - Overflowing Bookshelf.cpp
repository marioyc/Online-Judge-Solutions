#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>

#define all(v) (v).begin(), (v).end()

using namespace std;

int W[101];
int T[101];

bool orden(pair <int, int> a, pair <int, int> b){
    return a.second > b.second;
}

int main(){
    int w, caso=0, ind, width, total, t, aux, minT;
    char c;
    while(1){
        scanf("%d\n",&w);
        caso++;
        if(w==-1) break;
        
        total=0,t=0;
        
        memset(T, 0, sizeof(T));
        
        while(1){
            scanf("%c",&c);
            if(c=='E') break;
            else if(c=='A'){
                t++;
                
                scanf("%d %d\n",&ind,&width);
                
                W[ind]=width;
                T[ind]=t;
                
                total+=width;
                
                while(total>w){
                    minT=(1<<30);
                    for(int i=1; i<=100; i++){
                        if(T[i]!=0 && T[i]<minT){
                            minT=T[i];
                            aux=i;
                        }
                    }
                    total-=W[aux];
                    T[aux]=0;
                }
            }else if(c=='R'){
                scanf("%d\n",&ind);
                
                if(T[ind]){
                    T[ind]=0;
                    total-=W[ind];
                }
            }
        }
        printf("PROBLEM %d:",caso);
        
        vector< pair<int, int> > v;
        
        for(int i=1; i<=100; i++)
            if(T[i]) v.push_back(make_pair(i, T[i]));
        
        sort(all(v), orden);
        
        for(int i=0; i<v.size(); i++) printf(" %d",v[i].first);
        
        printf("\n");
    }
    
    return 0;
}
