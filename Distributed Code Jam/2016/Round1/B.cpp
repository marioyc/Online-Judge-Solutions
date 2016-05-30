#include <message.h>
#include <cstdio>
#include "oops.h"

using namespace std;

#define MASTER_NODE 7

int main(){
    long long N = GetN();
    long long nodes = NumberOfNodes();
    long long my_id = MyNodeId();
    long long local_min = 1000000000000000000LL;
    long long local_max = -1000000000000000000LL;

    for(int i = my_id;i < N;i += nodes){
        long long aux = GetNumber(i);
        if(aux > local_max) local_max = aux;
        if(aux < local_min) local_min = aux;
    }

    if(my_id < N){
        PutLL(MASTER_NODE, local_max);
        Send(MASTER_NODE);
        PutLL(MASTER_NODE, local_min);
        Send(MASTER_NODE);
    }

    if(my_id == MASTER_NODE){
        long long global_max = local_max;
        long long global_min = local_min;
        for(int node = 0;node < nodes && node < N;++node){
            Receive(node);
            long long aux_max = GetLL(node);
            Receive(node);
            long long aux_min = GetLL(node);
            if(aux_max > global_max) global_max = aux_max;
            if(aux_min < global_min) global_min = aux_min;
        }
        printf("%lld\n",global_max - global_min);
    }

    return 0;
}
