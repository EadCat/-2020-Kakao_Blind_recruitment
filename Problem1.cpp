#include <string>
#include <vector>
#include <iostream>

using namespace std;

string string_copy(string target, int index, int length) {
    string copier = "";
    int count = 0;
    while (count < length) {
        if (target[count + index] == '\0')
            break;
        copier += target[count + index];
        count++;
    }
    return copier;
}

int solution(string s) {

    int answer = 1000;
    int half_size = s.size() / 2;
    vector<string> store;
    if (s.size() == 1) {
        answer = 1;
    }
    else {
        for (int step = 1; step <= half_size; step++) {
            int i = 0;
            store.clear();
            while (i <= s.size() - 1) {
                //cout << string_copy(s, i, step) << " ";
                store.push_back(string_copy(s, i, step));
                i += step;
            }

            string answer_col = "";

            int count = 1;
            int j;
            for (j = 0; j < store.size() - 1; j++) {
                if (store[j] == store[j + 1]) {
                    count++;
                }
                else {
                    if (count == 1) {
                        answer_col += store[j];
                    }
                    else {
                        answer_col += to_string(count) + store[j];
                        count = 1;
                    }
                }
            }
            if (j == store.size() - 1) {
                if (count == 1) {
                    answer_col += store[j];
                }
                else {
                    answer_col += to_string(count) + store[j];
                }
            }

            if (answer > answer_col.size())
                answer = answer_col.size();
            //cout << " -> " << answer_col << " ///// ";

        }
    }



    return answer;
}