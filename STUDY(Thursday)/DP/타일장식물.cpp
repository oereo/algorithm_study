#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
    long long answer = 0;
    long long test = 0;
    long dp[80] = {0};
    long bp[80] = {0};
    int n = 0;
    dp[0] = 1;
    dp[1] = 1;
    bp[1] = 4;
    bp[2] = 6;
    bp[3] = 10;
    for(int i = 2; i<N; i++){
        dp[i] = dp[i-1]+dp[i-2];
       
    }
   
   if(N<4){
       test = bp[N];
   }
   else{
       test = 1*dp[N-4]+2*dp[N-3]+2*dp[N-2]+3*dp[N-1];
   }
      
    
    answer = test;
    
    return answer;
}