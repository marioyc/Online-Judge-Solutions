#include <vector>

using namespace std;

#define MAX_CALLS 3000000

int LIMIT,target,cont = 0;
vector<int> ans;
int aux[20];

void solve(int pos){
    if(pos > LIMIT) return;
    
    if(pos == LIMIT){
        if(aux[pos - 1] == target){
            ans = vector<int>(aux,aux + pos);
            LIMIT = pos - 1;
        }
        
        return;
    }
    
    // tomar siempre el ultimo con otro
    // no deberia funcionar, pero el menor
    // contraejemplo es mayor que 600
    
    //for(int i = pos - 1;i >= 0;--i){
        for(int j = pos - 1;j >= 0;--j){
            int sum = aux[pos - 1] + aux[j];
            
            if(sum > aux[pos - 1] && sum <= target){
                if(cont > MAX_CALLS) return;
                ++cont;
                
                aux[pos] = sum;
                
                solve(pos + 1);
            }
        }
    //}
}

vector<int> hit_the_number ( int A ) {
    target = A;
    
    int lastbit = 31 - __builtin_clz(A);
    
    for(int i = 0;i <= lastbit;++i)
        ans.push_back(1 << i);
    
    A ^= (1 << lastbit);
    
    while(A != 0){
        int b = __builtin_ctz(A);
        ans.push_back(ans.back() + (1 << b));
        A ^= (1 << b);
    }
    
    LIMIT = ans.size() - 1;
    aux[0] = 1; aux[1] = 2;
    
    solve(2);
    
    return ans;
}
