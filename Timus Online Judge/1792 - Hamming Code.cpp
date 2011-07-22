#include <cstdio>
#include <vector>

using namespace std;

bool test(vector<int> v){
    int s = v[0] ^ v[1] ^ v[2] ^ v[3];
    
    if(v[4] != (s ^ v[0])) return false;
    if(v[5] != (s ^ v[1])) return false;
    if(v[6] != (s ^ v[2])) return false;
    
    return true;
}

void print(vector<int> v){
    for(int i = 0;i < 7;++i)
        printf("%d ",v[i]);
}

int main(){
    vector<int> a(7),b(7);
    
    for(int i = 0;i < 7;++i)
        scanf("%d",&a[i]);
    
    if(test(a)) print(a);
    else{
        for(int i = 0;i < 7;++i){
            b = a;
            b[i] ^= 1;
            
            if(test(b)){
                print(b);
                break;
            }
        }
    }
    
    return 0;
}
