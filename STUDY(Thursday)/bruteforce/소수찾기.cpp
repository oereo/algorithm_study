#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


vector<char> temp;
vector<int> prime{0,0};
vector<int> prime_n;
int solution(string numbers) {
    int answer = 0;
    int length = numbers.size();
    string str = "";
    
    for(int i = 0; i<length; i++){
        temp.push_back(numbers[i]);
    }
    sort(temp.begin(), temp.end());
    
    for(int i = length-1; i>=0; i--){
        str += temp[i];
    }
    //cout << str;
    int str_size = stoi(str); // 최대값
    for(int i = 2; i<str_size; i++){
        prime.push_back(i);
    }
    for(int i =2; i<=str_size; i++){
        if(prime[i] == 0) continue;
        for(int j = i+i; j<=str_size; j+=i){
            prime[j] = 0;
        }
    }
    for (int i = 2; i <= str_size; i++) {
        if (prime[i] != 0){
            prime_n.push_back(prime[i]);
            cout << prime[i] << " ";
        }
           
    }
    
    for(int i = 0; i<prime_n.size();i++){
        string tt = to_string(prime_n[i]);
        for(int j = 0; j<tt.size(); j++){
            for(int z = 0; z<length; z++){
                if(tt[j]== numbers[z]-48){
                    answer++;
                    //prime_n.erase(prime_n.begin()+i);
                }    
            }
            
        }
    }
    //answer = prime_n.size();
    cout << prime_n[5]<<endl;
   // cout << tt[1];
    
    //answer = prime[6][1];
    return answer;
}