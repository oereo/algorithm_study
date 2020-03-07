// 문제 설명
// 주어진 항공권을 모두 이용하여 여행경로를 짜려고 합니다. 항상 ICN 공항에서 출발합니다.

// 항공권 정보가 담긴 2차원 배열 tickets가 매개변수로 주어질 때, 방문하는 공항 경로를 배열에 담아 return 하도록 solution 함수를 작성해주세요.

// 제한사항
// 모든 공항은 알파벳 대문자 3글자로 이루어집니다.
// 주어진 공항 수는 3개 이상 10,000개 이하입니다.
// tickets의 각 행 [a, b]는 a 공항에서 b 공항으로 가는 항공권이 있다는 의미입니다.
// 주어진 항공권은 모두 사용해야 합니다.
// 만일 가능한 경로가 2개 이상일 경우 알파벳 순서가 앞서는 경로를 return 합니다.
// 모든 도시를 방문할 수 없는 경우는 주어지지 않습니다.
// 입출력 예
// tickets	return
// [[ICN, JFK], [HND, IAD], [JFK, HND]]	[ICN, JFK, HND, IAD]
// [[ICN, SFO], [ICN, ATL], [SFO, ATL], [ATL, ICN], [ATL,SFO]]	[ICN, ATL, ICN, SFO, ATL, SFO]
// 입출력 예 설명
// 예제 #1

// [ICN, JFK, HND, IAD] 순으로 방문할 수 있습니다.

// 예제 #2

// [ICN, SFO, ATL, ICN, ATL, SFO] 순으로 방문할 수도 있지만 [ICN, ATL, ICN, SFO, ATL, SFO] 가 알파벳 순으로 앞섭니다.


#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
vector<string> result;
vector<string> start;
vector<string> answer = {"ICN"};
vector<vector<int>> check;
string temp = "";
vector<int> visit;
int index = 0;
void DFS(string first, int index, vector<vector<string>> &tickets){
    visit[index] = 1;
    for(int i = 1; i<tickets.size(); i++){
        if( visit[i] == 0 &&(first == tickets[i][0])){
           if(temp>tickets[i][1]){
                temp = tickets[i][1];
                index = i;
            }
        }
    }
    answer.push_back(result[0]);
    DFS(result[0], tickets);
    //cout<< tickets.size();
    //for(int i = 0; i<result.size(); i++){
    //     cout << result[i];
    //}
}


vector<string> solution(vector<vector<string>> tickets) {
    int n = tickets.size();
    check.assign(n, vector<int>(n, 0));
    visit.assing(n, 0);
    temp = "ZZZ";
    //cout << n;
    for(int i = 0; i<tickets.size(); i++){
        if(tickets[i][0] == "ICN"){
            if(temp>tickets[i][1]){
                temp = tickets[i][1];
                index = i;
            }
            
            //start.push_back(tickets[i][1]);
            //sort(start.begin(), start.end());
        }
    }
    cout << temp << " " << index;
    answer.push_back(temp);
    DFS(start[0],index, tickets);
    return answer;
}