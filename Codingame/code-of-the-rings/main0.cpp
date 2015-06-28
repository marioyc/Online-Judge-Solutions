#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
 
int val(char c){
    if(c == ' ') return 0;
    return c - 'A' + 1;
}

int moves(int s, int e){
    int pos,neg;
    if(s <= e){
        pos = e - s;
        neg = 27 - pos;
    }else{
        neg = s - e;
        pos = 27 - neg;
    }
    
    if(neg < pos) return -neg;
    else return pos;
}

int main()
{
    string magicPhrase;
    getline(cin, magicPhrase);
    
    string sol;
    int pos = 0;
    
    for(int i = 0;i < magicPhrase.size();++i){
        int want = val(magicPhrase[i]);
        int m = moves(pos,want);
        
        if(m > 0){
            for(int i = 0;i < m;++i){
                sol += '+';
            }
        }else{
            for(int i = 0;i < -m;++i){
                sol += '-';
            }
        }
        
        pos = want;
        sol += '.';
    }
    
    cout << sol << endl;
}