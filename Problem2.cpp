#include <string>
#include <vector>

using namespace std;

bool right_check(string p) {
    int front = 0, back = 0;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(')
            front++;
        else if (p[i] == ')')
            back++;
        if (front < back)
            return false;
    }
    return true;
}

string codefix(string p) {
    if (p.empty())
        return "";
    else {
        string u, v;
        int front = 0, back = 0;
        int i;
        for (i = 0; i < p.size(); i++) {
            if (p[i] == '(') {
                front++;
            }
            else if (p[i] == ')') {
                back++;
            }
            if (front != 0 && front == back)
                break;
        }
        i++;
        u = p.substr(0, i);
        if (i != p.size()) {
            while (p[i] != '\0') {
                v += p[i];
                i++;
            }
        }
        else {
            v = "";
        }
        if (right_check(u)) {
            return u += codefix(v);
        }
        else {
            string res = "";
            res += '(';
            res += codefix(v);
            res += ')';
            u = u.substr(1, u.size() - 2);
            for (int j = 0; j < u.size(); j++) {
                if (u[j] == '(')
                    res += ')';
                else
                    res += '(';
            }
            return res;
        }

    }
}

string solution(string p) {
    string answer = "";

    answer = codefix(p);


    return answer;
}