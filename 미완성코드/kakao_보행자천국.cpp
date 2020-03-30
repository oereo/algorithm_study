#include <vector>
#include <iostream>

//struct direct {
//    row = {-1, 0, 1, 0};
//    col = {0, 1, 0, -1};
//}

using namespace std;

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    vector<vector<int>> map;
    map.assign(m+1, vector<int>(n+1, 0));
    map[0][1] = 1;
    for(int i = 1; i<m+1; i++){
        for(int j = 1; j<n+1; j++){
            map[i][j] = map[i-1][j]+map[i][j-1];

            if(city_map[i-1][j-1] == 1){
                map[i][j] = 0;
            }
            else if(city_map[i-1][j-1] == 2){
                map[i][j] =1;
                if(i == 1){
                    map[i+1][j] = 0;
                    map[i][j+1] = 1;
                    //map[i][j] = map[i-1][j];
                    //map[i+1][j] = map[i+1][j-1];
                    //map[i][j+1] = map[i][j-1];
                    //map[i+1][j] = map[i][j];  
                }
                if(j == 1){
                    map[i][j] = 0;
                }
            }



            //cout<< " "<<map[i][j] << " ";
        }
        cout<<endl;
    }

    int answer = 0;
    answer = map[m][n]%MOD;
    return answer;
}