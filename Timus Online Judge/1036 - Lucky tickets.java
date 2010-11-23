import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class timus1036 {
    public static void main(String args[]) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int N,S;

        N = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(st.nextToken());

        if((S&1)==1) System.out.println("0\n");
        else{
            BigInteger dp[][] = new BigInteger[51][501];
            S >>= 1;

            dp[0][0] = BigInteger.ONE;
            for(int i = 1;i<=S;++i) dp[0][i] = BigInteger.ZERO;

            for(int i = 1;i<=N;++i){
                for(int j = 0;j<=S;++j){
                    dp[i][j] = BigInteger.ZERO;
                    for(int d = 0;d<=9;++d)
                        if(j>=d) dp[i][j] = dp[i][j].add(dp[i-1][j-d]);
                }
            }

            BigInteger ans = dp[N][S].multiply(dp[N][S]);
            System.out.println(ans);
        }
    }
}
