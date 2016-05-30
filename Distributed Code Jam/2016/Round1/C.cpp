#include <message.h>
#include <cassert>
#include <cstdio>
#include <set>
#include "rps.h"

using namespace std;

#define MASTER_NODE 0

int N;
int nodes;
int my_id;

set<int> marked;

pair<int,char> calc_wins(pair<int,char> l, pair<int,char> r){
    if(l.second == r.second) return l;
    if(l.second == 'R' && r.second == 'S') return l;
    if(l.second == 'S' && r.second == 'P') return l;
    if(l.second == 'P' && r.second == 'R') return l;
    return r;
}

void assign(int id, int l, int r, int nodel, int noder){
    if(nodel == noder || l == r){
        PutInt(nodel,l);
        Send(nodel);
        PutInt(nodel,r);
        Send(nodel);
        marked.insert(id);
    }else{
        int mi = (l + r) >> 1;
        int nodemi = (nodel + noder) >> 1;
        assign(2 * id + 1,l,mi,nodel,nodemi);
        assign(2 * id + 2,mi + 1,r,nodemi + 1,noder);
    }
}

pair<int,char> solve(int id, int l, int r, int nodel, int noder){
    if(marked.find(id) != marked.end()){
        Receive(nodel);
        int aux = GetInt(nodel);
        pair<int,char> ret = make_pair(aux,GetFavoriteMove(aux));
        return ret;
    }

    int mi = (l + r) >> 1;
    int nodemi = (nodel + noder) >> 1;
    pair<int,char> ret1 = solve(2 * id + 1,l,mi,nodel,nodemi);
    pair<int,char> ret2 = solve(2 * id + 2,mi + 1,r,nodemi + 1,noder);
    return calc_wins(ret1,ret2);
}

pair<int,char> solve(int l, int r){
    if(l == r){
        return make_pair(l,GetFavoriteMove(l));
    }

    int mi = (l + r) >> 1;
    pair<int,char> ret1 = solve(l,mi);
    pair<int,char> ret2 = solve(mi + 1,r);
    return calc_wins(ret1,ret2);
}

int main(){
    N = GetN();
    nodes = NumberOfNodes();
    my_id = MyNodeId();

    if(my_id == MASTER_NODE){
        assign(0,0,(1 << N) - 1,0,nodes - 1);
        for(int i = 0;i < nodes;++i){
            PutInt(i,-1);
            Send(i);
        }
    }

    Receive(MASTER_NODE);
    int start = GetInt(MASTER_NODE);

    if(start != -1){
        Receive(MASTER_NODE);
        int end = GetInt(MASTER_NODE);
        pair<int,char> ret = solve(start,end);
        PutInt(MASTER_NODE,ret.first);
        Send(MASTER_NODE);

        Receive(MASTER_NODE);
        int check = GetInt(MASTER_NODE);
        assert(check == -1);
    }

    if(my_id == MASTER_NODE){
        pair<int,char> ret = solve(0,0,(1 << N) - 1,0,nodes - 1);
        printf("%d\n",ret.first);
    }

    return 0;
}
