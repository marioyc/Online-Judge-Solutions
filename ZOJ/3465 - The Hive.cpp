#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int main(){
    int n,r,t,ans;
    int sz[] = {7,8,9,10,11,10,9,8,7},type[9][11];
    int first[] = {17,18,19,20,21,20,19,18,17};
    bool empty[9][11];
    char s[3];
    string hive[24];
    
    hive[0]  = "         _";
    hive[1]  = "       _/ \\_";
    hive[2]  = "     _/ \\_/ \\_";
    hive[3]  = "   _/ \\_/ \\_/ \\_";
    hive[4]  = " _/ \\_/ \\_/ \\_/ \\_";
    hive[5]  = "/ \\_/ \\_/ \\_/ \\_/ \\";
    hive[6]  = "\\_/ \\_/ \\_/ \\_/ \\_/";
    hive[7]  = "/ \\_/ \\_/ \\_/ \\_/ \\";
    hive[8]  = "\\_/ \\_/ \\_/ \\_/ \\_/";
    hive[9]  = "/ \\_/ \\_/ \\_/ \\_/ \\";
    hive[10] = "\\_/ \\_/ \\_/ \\_/ \\_/";
    hive[11] = "/ \\_/ \\_/ \\_/ \\_/ \\";
    hive[12] = "\\_/ \\_/ \\_/ \\_/ \\_/";
    hive[13] = "/ \\_/ \\_/ \\_/ \\_/ \\";
    hive[14] = "\\_/ \\_/ \\_/ \\_/ \\_/";
    hive[15] = "/ \\_/ \\_/ \\_/ \\_/ \\";
    hive[16] = "\\_/ \\_/ \\_/ \\_/ \\_/";
    hive[17] = "/ \\_/ \\_/ \\_/ \\_/ \\";
    hive[18] = "\\_/ \\_/ \\_/ \\_/ \\_/";
    hive[19] = "  \\_/ \\_/ \\_/ \\_/";
    hive[20] = "    \\_/ \\_/ \\_/";
    hive[21] = "      \\_/ \\_/";
    hive[22] = "        \\_/";
    
    while(scanf("%d",&n)==1){
        memset(type,0,sizeof(type));
        memset(empty,true,sizeof(empty));
        ans = 0;
        
        for(int i = 0;i<n;++i){
            scanf("%s",s);
            
            r = s[0]-'A';
            t = s[1];
            
            for(int j = 0;j<sz[r];++j){
                if(empty[r][j]){
                    if(j==0 || empty[r][j-1] || type[r][j-1]!=t){
                        type[r][j] = t;
                        empty[r][j] = false;
                    }else if(!empty[r][j-1] && type[r][j-1]==t){
                        empty[r][j-1] = true;
                        ++ans;
                    }
                    
                    break;
                }
            }
        }
        
        printf("The number of candy is %d.\n",ans);
        
        for(int i = 0;i<9;++i){
            for(int j = 0;j<sz[i];++j){
                hive[first[i]-2*j][2*i+1] = ' ';
                if(!empty[i][j]) hive[first[i]-2*j][2*i+1] = type[i][j];
            }
        }
        
        for(int i = 0;i<23;++i) printf("%s\n",hive[i].c_str());
    }    
    
    return 0;
}
