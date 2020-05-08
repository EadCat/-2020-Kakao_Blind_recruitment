#include <string>
#include <vector>

using namespace std;

vector<vector<int>> rotate_clockwise(vector<vector<int>> key) {
    int M = key.size() - 1;
    vector<vector<int>> copy(key.size(), vector<int>(key.size()));
    for (int i = 0; i < key.size(); i++) {
        for (int j = 0; j < key.size(); j++) {
            copy[j][M-i] = key[i][j];
        }
    }
    return copy;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    int M = key.size();
    int N = lock.size();
    int field_size = 2 * M + N - 2;
    int tries = N + M - 1;

    vector<vector<int>> field(field_size, vector<int>(field_size, 2)); // 1 init
    int a;
    int b;
    int detection = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            field[M - 1 + i][M - 1 + j] = lock[i][j];
            if (lock[i][j] == 0)
                detection++;
        }
    }
    a = 0;
    b = 0;
    int count = 0;
    for (int i = 0; i < 4; i++) {
        // 필드 검사
        for (int j = 0; j < tries; j++) {
            for (int k = 0; k < tries; k++) {
                for (a = 0; a < M; a++) {
                    for (b = 0; b < M; b++) {
                        if (field[a + j][b + k] == 0 && key[a][b] == 1) {
                            count++;
                        }
                        if (field[a + j][b + k] == 1 && key[a][b] == 1) {
                            break; break;
                        }
                    }
                }
                if (count == detection)
                    return true;
                count = 0;
            }
        }

        // 회전
        key = rotate_clockwise(key);
    }


    return false;
}