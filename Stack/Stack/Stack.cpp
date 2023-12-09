#include "Stack.h"
#include<iostream>
using namespace std;

template<typename T>
Stack<T>::Stack(int s) {
	size = s;
	top = -1;
	stack = new T[s];
}
template<typename T>
Stack<T>::Stack(Stack& obj) {
	int size = obj.size;
	T* st = new T[size];
	while(!obj.isEmpty()) {
		st.push(obj.peak());
		obj.pop();
	}
}
template<typename T>
Stack<T>::~Stack() {
	if (stack) {
		delete[]stack;
	}
	stack = nullptr;
}
template<typename T>
bool Stack<T>::isFull() {
	if (top == size - 1) {
		return true;
	}
	return false;
}
template<typename T>
bool Stack<T>::isEmpty() {
	if (top == -1) {
		return true;
	}
	return false;
}
template<typename T>
T Stack<T>::peak() {
	if (!isEmpty()) {
		return stack[top];
	}
}
template<typename T>
void Stack<T>::push(T val) {
	if (isFull()) {
		resize();
	}
	stack[++top] = val;
}
template<typename T>
void Stack<T>::pop()
{
	if (!isEmpty())
		top--;
}
template<typename T>
void Stack<T>::resize() {
	T* temp = new T[size * 2];
	for (int i = 0; i < size; i++) {
		temp[i] = stack[i];
	}
	delete[]stack;
	stack = temp;
	size = size * 2;
}
template<typename T>
void Stack<T>::shrink() {
	T* temp = new T[size / 2];
	for (int i = 0; i < size; i++) {
		temp[i] = stack[i];
	}
	delete[]stack;
	stack = temp;
	size = size / 2;
}
template<typename T>
void Stack<T>::display() {
	cout << stack[top];
}