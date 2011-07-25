#include <cstdio>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

int main(){
    int N,L;
    char s1[205],s2[205];
    vector<string> v[4];
    string names[] = {"Slytherin:", "Hufflepuff:", "Gryffindor:", "Ravenclaw:"};
    
    scanf("%d\n",&N);
    
    for(int i = 0;i < N;++i){
        fgets(s1,205,stdin);
        fgets(s2,15,stdin);
        
        L = strlen(s1);
        s1[L - 1] = 0;
        
        if(s2[0] == 'S') v[0].push_back(s1);
        if(s2[0] == 'H') v[1].push_back(s1);
        if(s2[0] == 'G') v[2].push_back(s1);
        if(s2[0] == 'R') v[3].push_back(s1);
    }
    
    for(int i = 0;i < 4;++i){
        puts(names[i].c_str());
        
        int sz = v[i].size();
        
        for(int j = 0;j < sz;++j) puts(v[i][j].c_str());
        putchar('\n');
    }
    
    return 0;
}
