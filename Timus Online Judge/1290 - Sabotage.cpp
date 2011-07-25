#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> calc(vector<int> v){
    vector<int> ret;
    int sz = v.size(),pos = 0;
    
    sort(v.begin(),v.end());
    
    if(sz > 0){
        ret.push_back(sz);
        
        for(int i = 1;i < v[sz - 1];++i){
            while(pos < sz && v[pos] == i) ++pos;
            ret.push_back(sz - pos);
        }
    }
    
    return ret;
}

int main(){
    int N;
    vector<int> v;
    
    scanf("%d",&N);
    
    for(int i = 0,aux;i < N;++i){
        scanf("%d",&aux);
        v.push_back(aux);
    }
    
    v = calc(calc(v));
    int sz = v.size();
    
    for(int i = 0;i < sz;++i)
        printf("%d\n",v[i]);
    
    return 0;
}
