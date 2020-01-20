#include <string>
#include <vector>
#include <iostream>

using namespace std;
int result = 0;
int cnt = 0;
int b = 1;
int ans = 0;

void DFS(int cnt,int length, int value, int target, vector<int> &numbers){
    
    if(length == cnt){
        if(value == target){
    
            ans++;
         }
     return;   
    }
    
    
     DFS(cnt+1,length, value+numbers[cnt], target, numbers);
     DFS(cnt+1,length, value-numbers[cnt], target, numbers);
    
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int length = numbers.size();
    //int plus_cnt = numbers.size()-1;
    //int minus_cnt = 1;
        
    DFS(1,length, numbers[0], target, numbers);
    DFS(1,length, 0 - numbers[0], target, numbers);
    
    answer = ans;
    
    return answer;
}