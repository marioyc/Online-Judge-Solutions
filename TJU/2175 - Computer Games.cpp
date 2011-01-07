#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>

using namespace std;

struct member{
    int id,p;
    
    member(){}
    
    member(int _id, int _p){
        id = _id; p = _p;
    }
    
    bool operator < (member X)const{
        return p<X.p;
    }
};

struct node{
    int id1,id2,diff,p1;
    
    node(){}
    
    node(int _id1, int _id2, int _diff, int _p1){
        id1 = _id1; id2 = _id2;
        diff = _diff; p1 = _p1;
    }
    
    bool operator < (node X)const{
        if(diff!=X.diff) return diff>X.diff;
        return p1<X.p1;
    }
}aux;

short type[100000];
int P[100000];
char name[100000][21];
bool in[100000];
priority_queue<node> Q;
set<member> S1,S2;
set<member> :: iterator it1,it2;
map<string, int> id;

int main(){
    int M,cont;
    char comm[6];
    
    while(true){
        scanf("%d",&M);
        if(M==0) break;
        
        id.clear();
        cont = 0;
        
        for(int i = 0;i<M;++i){
            scanf("%s",comm);
            
            if(comm[0]=='J'){
                type[i] = 0;
                scanf("%s %d",name[i],&P[i]);
                id[name[i]] = i;
            }else if(comm[0]=='L'){
                type[i] = 1;
                scanf("%s",name[i]);
            }else{
                type[i] = 2;
            }
        }
        
        memset(in,false,sizeof(in));
        
        Q = priority_queue<node>();
        S1.clear();
        S2.clear();
        
        for(int i = 0,ind,p;i<M;++i){
            if(type[i]==0){
                p = P[i];
                in[i] = true;
                it1 = S1.lower_bound(member(0,p));
                it2 = S2.lower_bound(member(0,-p));
                
                if(it1!=S1.end()) Q.push(node(it1->id,i,P[it1->id]-p,P[it1->id]));
                if(it2!=S2.end()) Q.push(node(i,it2->id,p-P[it2->id],p));
                
                S1.insert(member(i,p));
                S2.insert(member(i,-p));
            }else if(type[i]==1){
                ind = id[name[i]];
                p = P[ind];
                in[ind] = false;
                S1.erase(member(0,p));
                S2.erase(member(0,-p));
                it1 = S1.lower_bound(member(0,p));
                it2 = S2.lower_bound(member(0,-p));
                
                if(it1!=S1.end() && it2!=S2.end()) Q.push(node(it1->id,it2->id,P[it1->id]-P[it2->id],P[it1->id]));
            }else{
                while(!Q.empty()){
                    aux = Q.top();
                    
                    if(in[aux.id1] && in[aux.id2]) break;
                    else Q.pop();
                }
                
                if(Q.empty()) puts("Poor Mr.Yu");
                else{
                    aux = Q.top();
                    
                    printf("%s %s\n",name[aux.id1],name[aux.id2]);
                }
            }
        }
        
        puts("");
    }
    
    return 0;
}
