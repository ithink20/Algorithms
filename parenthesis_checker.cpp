#include <iostream>
#include <algorithm>
#include <climits>
#include <stack>

using namespace std;

class Solution {
public:
	bool isMatching(char c1, char c2) {
		if (c1 == '(' && c2 == ')') {
			return true;
		} else if (c1 == '{' && c2 == '}') {
			return true;
		} else if (c1 == '[' && c2 == ']') {
			return true;
		}
		else {
			return false;
		}
	}
	bool isValid(string s) {
		stack <char> st;
    	for (int i = 0; i < s.size(); ++i) {
    		if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
    			st.push(s[i]);
    		}
    		if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
    			if (st.empty()) {
    				return false;
    			}
    			else if (!isMatching(st.top(), s[i])) {
    				return false;
    			}
    			st.pop();
    		}
    	}
    	if (st.empty()) {
    		return true;
    	} else {
    		return false; 
    	}
    }
};

int main() {
	string str;
	cin >> str;
	Solution s;
	s.isValid(str) ? cout << "true\n" : cout << "false\n";
	return 0;
}