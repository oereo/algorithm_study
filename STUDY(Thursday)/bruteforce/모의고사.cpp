#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> answer_1;
    vector<int> first = {1,2,3,4,5};
    vector<int> second = {2,1,2,3,2,4,2,5};
    vector<int> third = {3,3,1,1,2,2,4,4,5,5};
    int fir = 0;
    int sec = 0;
    int thi = 0;
     
    int length = answers.size();
    
    int cnt_1 = length/5;
    int cnt_2 = length/8;
    int cnt_3 = length/10;
    
    for(int i = 0; i<cnt_1; i++){
        first.insert(first.end(), first.begin(), first.end());
    }
    for(int i = 0; i<cnt_2; i++){
        second.insert(second.end(), second.begin(), second.end());
    }
    for(int i = 0; i<cnt_3; i++){
        third.insert(third.end(), third.begin(), third.end());
    }
    for(int i = 0; i<length; i++){
        if(first[i] == answers[i]){
            fir++;
        }
        if(second[i] == answers[i]){
            sec++;
        }
        if(third[i] == answers[i]){
            thi++;
        }
    }
  
    answer_1.push_back(fir);
    answer_1.push_back(sec);
    answer_1.push_back(thi);

    
    int max = *max_element(answer_1.begin(), answer_1.end());
    if(max == fir){
        answer.push_back(1);
    }
    if(max == sec){
        answer.push_back(2);
    }
    if(max == thi){
        answer.push_back(3);
    }
    
    return answer;
}