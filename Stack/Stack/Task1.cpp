#include<iostream>
#include"Stack.h"
#include"Stack.cpp"
using namespace std;

int precedence(char exp) {
	if (exp == '+' or exp == '-') {
		return 1;
	}
	if (exp == '*' or exp == '/'){
		return 2;
	}
	if (exp == '^')
		return 3;
	else
		return 0;
}

char* infixToPostfix(const char * exp) {
	int i = 0;
	char* postFix = new char[40];
	Stack<char> obj(100);
	int j = 0;

	while (exp[i] != '\0') {
		if (exp[i] >= 'a' && exp[i] <= 'z' || exp[i] >= 'A' && exp[i] <= 'Z' || exp[i] >= '0' && exp[i] <= '9') {
			postFix[j] = exp[i];
			i++;
			j++;
		}
		else if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[' ) {
			obj.push(exp[i]);
			i++;
		}
		else if (exp[i] == ')') {
			while (obj.peak() != '(') {
					postFix[j] = obj.peak();
					obj.pop();
					j++;
				}
				obj.pop();
				i++;
			}
		else{
			while (!obj.isEmpty() && precedence(exp[i]) <= precedence(obj.peak())) {
				postFix[j] = obj.peak();
				obj.pop();
				i++;
				j++;
			}
			obj.push(exp[i]);
			i++;
		}
	}
	while (!obj.isEmpty()) {
		postFix[j] = obj.peak();
		obj.pop();
		i++;
		j++;
	}
	j++;
	postFix[j] = '\0';
	return postFix;
}

double evaluatePostfix(const char* postExp) {
	int i = 0;
	double answer;
	Stack<double>s(100);
	double first_term, sec_term;
	while (postExp[i] != '\0') {
		if (postExp[i] >= '0' && postExp[i] <= '9') {
			s.push(postExp[i]);
			i++;
		}
		else if (!s.isEmpty() && postExp[i] == '+' || postExp[i] == '-' || postExp[i] == '*' || postExp[i] == '/') {
			if (postExp[i] == '+') {
				sec_term = s.peak();
				s.pop();
				first_term = s.peak();
				s.pop();
				answer = first_term + sec_term;
				s.push(answer);
				i++;
			}
			if (postExp[i] == '-') {
				sec_term = s.peak();
				s.pop();
				first_term = s.peak();
				s.pop();
				answer = first_term - sec_term;
				s.push(answer);
				i++;
			}
			if (postExp[i] == '*') {
				sec_term = s.peak();
				s.pop();
				first_term = s.peak();
				s.pop();
				answer = first_term * sec_term;
				s.push(answer);
				i++;
			}
			if (postExp[i] == '/') {
				sec_term = s.peak();
				s.pop();
				first_term = s.peak();
				s.pop();
				answer = first_term / sec_term;
				s.push(answer);
				i++;
			}
		}
	}
	answer = s.peak();
	s.pop();
	return answer;
}

int main() {
	cout << "Enter an infix string: " << endl;
	char* s1 = new char[1000];
	cin >> s1;
	cout << s1 << endl;
	char* postfix = infixToPostfix(s1);
	cout << "Post fix expression is:" << endl;
	cout << postfix << endl;

	cout << "Enter an expression to be evaluated: " << endl;
	char* s2 = NULL;
	cin >> s2;
	double ans = evaluatePostfix(s2);
	cout << "Answer is:" << endl;
	cout << ans;
}