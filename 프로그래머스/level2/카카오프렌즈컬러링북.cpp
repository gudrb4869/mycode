#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int dr[] = {-1,0,1,0};
    int dc[] = {0,1,0,-1};
    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j] == false && picture[i][j] != 0) {
                int size = 0;
                visited[i][j] = true;
                q.push({i, j});
                number_of_area++;
                while (!q.empty()) {
                    pair<int, int> p = q.front();
                    q.pop();
                    size++;
                    for (int k = 0; k < 4; k++) {
                        int new_r = p.first + dr[k];
                        int new_c = p.second + dc[k];
                        if (new_r >= 0 && new_r < m && new_c >= 0 && new_c < n) {
                            if (visited[new_r][new_c] == false && picture[p.first][p.second] == picture[new_r][new_c]) {
                                q.push({new_r, new_c});
                                visited[new_r][new_c] = true;
                            }
                        } 
                    }
                }
                max_size_of_one_area = max(max_size_of_one_area, size);
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}