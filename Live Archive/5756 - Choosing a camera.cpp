#include <cstdio>
#include <cmath>
#include <queue>
#include <set>

using namespace std;

#define eps 1e-7

struct node{
    int p;
    double z;
    
    node(){}
    
    node(int _p, double _z):
        p(_p), z(_z){}
    
    bool operator < (node X)const{
        return p < X.p;
    }
};

struct node2{
    int p,c,id;
    double z;
    
    node2(){}
    
    node2(int _p, double _z, int _c, int _id):
        p(_p), z(_z), c(_c), id(_id){}
    
    bool operator < (node2 X)const{
        if(c == X.c) return id > X.id;
        return c > X.c;
    }
};

int main(){
    int T,Q;
    
    char op[2];
    int p,c;
    double z;
    
    set<node>::iterator it,it2;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&Q);
        
        set<node> S;
        priority_queue<node2> best;
        
        int cont = 0;
        bool first = true;
        
        while(Q--){
            scanf("%s",op);
            ++cont;
            
            if(op[0] == 'P'){
                scanf("%d %lf %d",&p,&z,&c);
                node aux(p,z);
                
                if(S.empty()) S.insert(aux);
                else{
                    it = S.find(aux);
                    
                    if(it == S.end()){
                        S.insert(aux);
                        
                        it = S.find(aux);
                        
                        if(it != S.end()){
                            ++it;
                            if(it->z >= aux.z) S.erase(aux);
                        }
                    }else if(it->z < aux.z){
                        S.erase(it);
                        S.insert(aux);
                    }
                }
                
                it = S.find(aux);
                
                if(it != S.end()){
                    while(true){
                        it2 = it;
                        
                        if(it2 == S.begin()) break;
                        
                        --it2;
                        
                        if(it2->z <= aux.z) S.erase(it2);
                        else break;
                    }
                }
                
                best.push(node2(p,z,c,cont));
            }else{
                int ans = -1;
                
                while(!best.empty()){
                    node2 aux = best.top();
                    
                    it = S.find( node(aux.p,aux.z) );
                    
                    if(it == S.end() || abs(it->z - aux.z) > eps) best.pop();
                    else{
                        ans = aux.id;
                        break;
                    }
                }
                
                if(!first) putchar(' ');
                first = false;
                printf("%d",ans);
            }
        }
        
        putchar('\n');
    }
    
    return 0;
}
