//#include<iostream>
//#include"Stack.h"
//
//using namespace std;
//
//void reverseString(string ip) {
//	double len = ip.length();
//	Stack<char>stack(len);
//	for (int i = 0; i < len; i++) {
//		stack.push(ip[i]);
//	}
//	while (!stack.isEmpty()) {
//		cout << stack.peak() << " ";
//		stack.pop();
//	}
//	cout << endl;
//}
//
//bool duplicates(string ip) {
//	double len = ip.length();
//	Stack<char>stack(len);
//	char top;
//	for (int i = 0; i < len; i++) {
//		stack.push(ip[i]);
//	}
//	while (!stack.isEmpty()) {
//		top = stack.peak();
//		stack.pop();
//		if (top == stack.peak()) {
//			return true;
//		}
//	}
//	return false;
//}
//
//bool isBalanced(string exp) {
//	int i=0;
//	Stack<char> obj(1000);
//	while (exp[i]!='\0'){
//		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
//			obj.push(exp[i]);
//		}
//		else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
//		{
//			if (obj.isEmpty()) {
//				cout << "Invalid expression." << endl;
//				return false;
//			}
//			else{
//				if (exp[i]==')' &&obj.peak()=='('){
//					obj.pop();
//				}
//				else if(exp[i] == '}' && obj.peak() == '{'){
//					obj.pop();
//				}
//				else if (exp[i] == ']' && obj.peak() == '['){
//					obj.pop();
//				}
//				else{
//					cout << "Invalid expression." << endl;
//					return false;
//				}
//			}
//		}
//		i++;
//	}
//	if (obj.isEmpty()){
//		return true;
//	}
//	else{
//		return false;
//	}
//}
//
//int main() {
//	cout << "J";
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//	system("pause");
//	return 0;
//}