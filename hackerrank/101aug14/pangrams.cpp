#include <iostream>

using namespace std;

int get_mask(string x){
    int ret = 0;
    
    for(int i = x.size() - 1;i >= 0;--i){
        if(x[i] >= 'A' && x[i] <= 'Z') ret |= (1 << (x[i] - 'A'));
        if(x[i] >= 'a' && x[i] <= 'z') ret |= (1 << (x[i] - 'a'));
    }
    
    return ret;
}

int main(){
    string s;
    int have = 0;
    
    while(cin >> s){
        have |= get_mask(s);
    }
    
    cout << (have == (1 << 26) - 1? "pangram" : "not pangram") << '\n';
    
    return 0;
}
