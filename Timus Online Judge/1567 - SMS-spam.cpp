#include <cstdio>
#include <string>
#include <map>

using namespace std;

map<char, int> cost;

void add(string s){
    int L = s.size();
    
    for(int i = L-1;i >= 0;--i)
        cost[s[i]] = i + 1;
}

int main(){
    add("abc"); add("def"); add("ghi");
    add("jkl"); add("mno"); add("pqr");
    add("stu"); add("vwx"); add("yz");
    add(".,!"); add(" ");
    
    int ans = 0;
    char c;
    
    while((c = getchar()) != EOF)
        ans += cost[c];
	
    printf("%d\n",ans);
    
    return 0;
}
