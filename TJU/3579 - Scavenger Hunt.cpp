#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> factors(int n){
    vector<int> ret;
    
    for(int i = 1;i <= n / i;++i){
        if(n % i == 0){
            ret.push_back(i);
            if(n / i != i) ret.push_back(n / i);
        }
    }
    
    sort(ret.begin(),ret.end());
    return ret;
}

int main(){
    int P,Q;
    
    scanf("%d %d",&P,&Q);
    
    vector<int> vp = factors(P);
    vector<int> vq = factors(Q);
    int np = vp.size(),nq = vq.size();
    
    for(int i = 0;i < np;++i)
        for(int j = 0;j < nq;++j)
            printf("%d %d\n",vp[i],vq[j]);
    
    return 0;
}
