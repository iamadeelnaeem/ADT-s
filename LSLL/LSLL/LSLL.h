#pragma once
#include <iostream>
using namespace std;
template <typename T>
struct Node
{
	T info;
	Node<T>* next;
	Node()
	{
		next = nullptr;
	}
	Node(T val)
	{
		info = val;
		next = nullptr;
	}
};

template<typename T>
class LSLL
{
	Node<T>* head;
public:
	LSLL();
	LSLL(const LSLL<T>& ref);
	void insertAtHead(T val);
	void insertAtTail(T val);
	void print();
	void insertAfter(T key, T val);
	void insertBefore(T key, T val);
	void remove(T key);
	void removeAtHead();
	void removeAttail();
	void removeAfter(T key);
	void removeBefore(T key);
	int findLength();
	T middleNode();
	Node<T>* getHead();
	void setHead(Node<T>*);
	void sort();
	LSLL<T> doUnion(LSLL<T> l2); // 1
	bool isEqual(LSLL<T> l2); // 2
	LSLL<T> createClone(); // 3
	void delAlternate(); // 4
	void splitList(LSLL<T> & list1, LSLL<T>& list2); // 5
	void removeDuplicates(); // 6
	LSLL<T> mergeSortedLists(LSLL<T>& list2); // 7
	void reversePrint(); // 8
	void reverseList(); // 9
	void swapMNth(int m, int n); // 11
	void sortAddrSwap();
	void sortDataSwap();
	// 13 BInary search and getting logn // No Because first if go to the middle we will have to go 
	// through each node and thats make the count half
	~LSLL();
};

