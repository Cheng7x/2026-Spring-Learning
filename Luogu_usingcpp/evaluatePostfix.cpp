#include <iostream>
#include <stack>
#include <sstream>
#include <string>
using namespace std;

int evaluatePostfix(const string& expr) {
	stack<int> st;
	stringstream ss(expr);
	string token;
	
	while (ss >> token) {
		if (isdigit(token[0])) {
			st.push(stoi(token));
		} else {
			int right = st.top(); st.pop();
			int left = st.top(); st.pop();
			
			if (token == "+") st.push(left + right);
			else if (token == "-") st.push(left - right);
			else if (token == "*") st.push(left * right);
			else if (token == "/") st.push(left / right);
		}
	}
	
	return st.top();
}

int main() {
	string expr = "23 34 45 * 5 6 + 7 + / +";
	cout << evaluatePostfix(expr) << endl;  
	return 0;
}

