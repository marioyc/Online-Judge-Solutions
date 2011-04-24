import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.math.BigInteger;

public class timus1513 {
    public static void main(String args[]) throws Exception{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        if(K == 0) System.out.println(1);
        else{
            BigInteger dp[][] = new BigInteger[N][2];
            BigInteger sum[] = new BigInteger[N+2];

            dp[0][0] = dp[0][1] = BigInteger.ONE;
            sum[0] = BigInteger.ONE;
            sum[1] = sum[0].add(BigInteger.ONE);

            for(int i = 1,s;i < N;++i){
                dp[i][0] = dp[i-1][0].add(dp[i-1][1]);
                sum[i+1] = sum[i].add(dp[i][0]);
                
                s = i-K;

                if(s >= 0) dp[i][1] = sum[i].subtract(sum[s]);
                else dp[i][1] = sum[i];
            }

            System.out.println(dp[N-1][0].add(dp[N-1][1]));
        }
    }
}
