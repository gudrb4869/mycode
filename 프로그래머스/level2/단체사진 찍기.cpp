#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool check(string s, char a, char b, char op, int val) {
    int idx_a, idx_b;
    for (int i = 0; i < s.length(); i++) {
        if (s.at(i) == a) idx_a = i;
        if (s.at(i) == b) idx_b = i;
    }
    int dist = abs(idx_a - idx_b) - 1;
    if (op == '>')
        return dist > val;
    else if (op == '=')
        return dist == val;
    else
        return dist < val;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    vector<char> friends = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    do {
        string s = "";
        for (char c : friends) {
            s += c;
        }
        bool flag = true;
        for (string d : data) {
            if (!check(s, d[0], d[2], d[3], int(d[4] - '0'))) {
                flag = false;
                break;
            }
        }
        if (flag) answer++;
    } while(next_permutation(friends.begin(), friends.end()));
    return answer;
}