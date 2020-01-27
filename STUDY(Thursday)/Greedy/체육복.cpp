#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int cnt = 0;
    vector<int> student;
    student.assign(n+1, 1);
    
    for(int i = 0; i<lost.size(); i++){
        student[lost[i]] = 0;
        
    }
    
    for(int i = 0; i<reserve.size(); i++){
        
        if(student[reserve[i]] == 0){
            student[reserve[i]] = 1;
        }
        else if(student[reserve[i]-1] ==0){
            student[reserve[i]-1] = 1;
        }
        else if(student[reserve[i]+1] == 0){
            student[reserve[i]+1] = 1;
        }
    }
    
    for(int i = 1; i<student.size();i++){
        if(student[i] == 1){
            cnt++;
        }
    }
    answer = cnt;
    return answer;
}