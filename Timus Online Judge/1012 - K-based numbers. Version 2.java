import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.math.BigInteger;

public class timus1012 {
    public static void main(String args[]) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int N,K;

        N = Integer.parseInt(in.readLine());
        K = Integer.parseInt(in.readLine());

        BigInteger dp[][] = new BigInteger[N][2], auxK = new BigInteger(Integer.toString(K-1));

        dp[1][0] = auxK.add(BigInteger.ONE);
        dp[1][1] = auxK;

        for(int i = 2;i<N;++i){
            dp[i][0] = (dp[i-1][0].multiply(auxK)).add(dp[i-1][1]);
            dp[i][1] = dp[i-1][0].multiply(auxK);
        }

        BigInteger ans = dp[N-1][0].multiply(auxK);
        System.out.println(ans);
    }
}
