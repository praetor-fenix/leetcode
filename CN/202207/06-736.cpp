#include <cctype>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
private:
    void parse_space(const string &expr, int &t) {
        while(t < expr.length() && isspace(expr[t])) {
            ++t;
        }
    }

    int parse_expr(const string &expr, unordered_map<string, stack<int>> &var, int &t, string &id) {
        int res = 0;

        if(expr[t] == '(') {
            ++t;
            res = parse_calc(expr, var, t);
        } else if(expr[t] == '-' || isdigit(expr[t])) {
            res = parse_num(expr, t);
        } else {
            id = parse_var(expr, t);
            res = var.count(id) > 0 ? var[id].top() : 0;
        }

        parse_space(expr, t);

        return res;
    }

    int parse_num(const string &expr, int &t) {
        int res = 0;

        bool minus = false;
        if(expr[t] == '-') {
            minus = true;
            ++t;
        }

        while(t < expr.length() && isdigit(expr[t])) {
            res = res * 10 + (expr[t] - '0');
            ++t;
        }

        parse_space(expr, t);

        return minus ? -res : res;
    }

    string parse_var(const string &expr, int &t) {
        string res;

        while(t < expr.length() && (islower(expr[t]) || isdigit(expr[t]))) {
            res.push_back(expr[t]);
            ++t;
        }

        parse_space(expr, t);
        
        return res;
    }

    int parse_calc(const string &expr, unordered_map<string, stack<int>> &var, int &t) {
        int res = 0;

        string id, _;
        string op = parse_op(expr, t);
        if(op == "let") {
            unordered_set<string> names;
            while(expr[t] != ')') {
                res = parse_expr(expr, var, t, id);
                if(expr[t] != ')') {
                    res = parse_expr(expr, var, t, _);

                    if(var.count(id) <= 0) {
                        stack<int> n;
                        var[id] = n;
                    }

                    stack<int> &s = var[id];
                    if(names.count(id) > 0) {
                        s.pop();
                    }
                    
                    s.push(res);
                    names.insert(id);
                }
            }

            for(auto it = names.begin(); it != names.end(); ++it) {
                stack<int> &s = var[*it];
                s.pop();
            }
        } else if(op == "add") {
            int res1 = parse_expr(expr, var, t, _);
            int res2 = parse_expr(expr, var, t, _);
            res = res1 + res2;
        } else if(op == "mult") {
            int res1 = parse_expr(expr, var, t, _);
            int res2 = parse_expr(expr, var, t, _);
            res = res1 * res2;
        }

        ++t;
        parse_space(expr, t);

        return res;
    }

    string parse_op(const string &expr, int &t) {
        string res;

        while(t < expr.length() && isalpha(expr[t])) {
            res.push_back(expr[t]);
            ++t;
        }

        parse_space(expr, t);

        return res;
    }

public:
    int evaluate(string expression) {
        int mark = 0;
        unordered_map<string, stack<int>> variable;
        string _;
        return parse_expr(expression, variable, mark, _);
    }
};