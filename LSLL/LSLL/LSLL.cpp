#include"LSLL.h"
#include<iostream>
using namespace std;

template<typename T>
LSLL<T>::LSLL()
{
	head = nullptr;
}

template<typename T>
LSLL<T>::LSLL(const LSLL<T>& ref): LSLL()
{
	if (!ref.head)
		return;
	Node<T>* ptr = ref.head;
	Node<T>* value = new Node<T>(ptr->info);
	head = value;
	Node<T>* p = head;
	ptr = ptr->next;
	while (ptr != nullptr)
	{
		value = new Node<T>(ptr->info);
		p->next = value;
		p = p->next;
		ptr = ptr->next;
	}
}


template<typename T>
void LSLL<T>:: insertAtHead(T val)
{
	Node<T>* p = new Node<T>(val);
	p->next = head;
	head = p;
}

template<typename T>
void LSLL<T>:: insertAtTail(T val)
{
	Node<T>* ptr = new Node<T>(val);
	if (!head)
	{
		head = ptr;
		return;
	}
	Node<T>* p = head;
	while (p->next != nullptr)
		p = p->next;
	p->next = ptr;
}

template<typename T>
void LSLL<T>::print()
{
	Node<T>* p = head;
	while (p != nullptr)
	{
		cout << p->info << " ";
		p = p->next;
	}
	cout << endl;
}

template<typename T>
void LSLL<T>::insertAfter(T key, T val)
{
	if (!head)
		return;
	Node<T>* p = head;
	while (p != nullptr)
	{
		if (p->info == key)
		{
			Node<T>* ptr = new Node<T>(val);
			ptr->next = p->next;
			p->next = ptr;
			return;
		}
		p = p->next;
	}
}

template<typename T>
void LSLL<T>::insertBefore(T key, T val)
{
	if (!head)
		return;
	if (head->info == key)
	{
		insertAtHead(val);
		return;
	}
	Node<T>* prev = head;
	Node<T>* p = head->next;
	while (p != nullptr)
	{
		if (p->info == key)
		{
			Node<T>* ptr = new Node<T>(val);
			prev->next = ptr;
			ptr->next = p;
			return;
		}
		prev = p;
		p = p->next;
	}

}

template<typename T>
void LSLL<T>::remove(T key)
{
	if (!head)
		return;
	if (head->info == key)
	{
		delete head;
		head = nullptr;
		return;
	}
	Node<T>* p = head->next;
	Node<T>* prev = head;
	while (p != nullptr)
	{
		if (p->info == key)
		{
			prev->next = p->next;
			delete p;
			return;
		}
		prev = p;
		p = p->next;
	}
}

template<typename T>
void LSLL<T>::removeAtHead()
{
	if (!head)
		return;
	Node<T>* p = head;
	head = p->next;
	delete p;

}

template<typename T>
void LSLL<T>::removeAttail()
{
	if (!head)
		return;
	if (head->next == nullptr)
	{
		delete head;
		head = nullptr;
		return;
	}
	Node<T>* p = head;
	while (p->next->next != nullptr)
	{
		p = p->next;
	}
	delete p->next;
	p->next = nullptr;

}

template<typename T>
void LSLL<T>::removeAfter(T key)
{
	if (!head)
		return;
	Node<T>* p = head;
	while (p != nullptr)
	{
		if (p->info == key)
		{
			if (p->next == nullptr)
				return;
			Node<T>* ptr = p->next;
			p->next = p->next->next;
			delete ptr;
			return;
		}
		p = p->next;
	}
}

template<typename T>
void LSLL<T>::removeBefore(T key)
{
	if (!head || !(head->next))
		return;
	Node<T>* p;
	if (head->next->info == key) 
	{
		p = head;
		head = head->next;
		delete p;
		return;
	}
	Node<T>* prev = head;
	p = head->next->next;
	while (p != nullptr)
	{
		if (p->info == key)
		{
			delete prev->next;
			prev->next = p;
			return;
		}
		p = p->next;
		prev = prev->next;
	}

}

template<typename T>
int LSLL<T>::findLength()
{
	int count = 0;
	Node<T>* p = head;
	while (p != nullptr)
	{
		count++;
		p = p->next;
	}
	return count;
}

template<typename T>
T LSLL<T>::middleNode()
{
	if (!head)
		exit(0);
	int length = findLength();
	Node<T>* p = head;
	int j = (length % 2 == 0) ? (length / 2) : (length / 2 + 1);
	int  i = 1;
	while (i < j)
	{
		p = p->next;
		i++;
	}
	return p->info;
}

template<typename T>
Node<T>* LSLL<T>:: getHead()
{
	return head;
}

template <typename T>
void LSLL<T>::setHead(Node<T>* p)
{
	if (p)
		head = p;
}

template<typename T>
LSLL<T>::~LSLL()
{
	Node<T>* p = head;
	Node<T>* prev = p;
	while (p != nullptr)
	{
		prev = p->next;
		delete p;
		p = prev;
	}
	head = nullptr;
}

template <typename T>
void LSLL<T>::sort()
{ 
	if (!head || !head->next)
		return;
	Node<T>* p = head; // before minimum
	Node<T>* cur = head; 
	Node<T>* minNode = head; // address of  min node
	Node<T>* prev = head;
	T min = cur->info;
	cur = head->next;
	while (cur != nullptr)
	{
		if (min > cur->info)
		{
			min = cur->info;
			p = prev;
			minNode = cur;
		}
		prev = cur;
		cur = cur->next;
	}
	if (min != head->info)
	{
		p->next = minNode->next;
		minNode->next = head;
		head = minNode;
	}
	Node<T>* chngPrev = head;
	Node<T>* chng = head->next;
	min = chng->info;
	prev = head->next;
	cur = chng->next;
	while (chng->next != nullptr)
	{
		while (cur != nullptr)
		{
			if (min > cur->info) 
			{
				min = cur->info;
				p = prev;
				minNode = cur;
			}
			prev = cur;
			cur = cur->next;
		}
		if (min != chng->info)
		{
			p->next = minNode->next;
			minNode->next = chng;
			chngPrev->next = minNode;
		}
		else
		{
			minNode = chng;
		}
		this->print();
		chngPrev = minNode;
		chng = minNode->next;
		min = chng->info;
		prev = chng;
		cur = chng->next;
	}
}

template<typename T>
LSLL<T> LSLL<T>:: doUnion(LSLL<T> l2)
{
	Node<T>* p = head;
	LSLL<T> l3;
	while (p != nullptr)
	{
		l3.insertAtTail(p->info);
		p = p->next;
	}
	p = l2.head;
	bool flag = true;
	Node<T>* ptr = head;
	while (p != nullptr)
	{
		flag = true;
		ptr = head;
		while (ptr != nullptr)
		{
			if (p->info == ptr->info)
			{
				flag = false;
				break;
			}
			ptr = ptr->next;
		}
		if (flag)
		{
			l3.insertAtTail(p->info);
		}
		p = p->next;
	}
	return l3;
}

template<typename T>
bool LSLL<T>::isEqual(LSLL<T> l2)
{
	Node<T>* p = head;
	bool flag = false;
	Node<T>* pl2 = l2.head;
	while (p != nullptr)
	{
		flag = false;
		pl2 = l2.head;
		while (pl2 != nullptr)
		{
			if (p->info == pl2->info)
			{
				flag = true;
				break;
			}
			pl2 = pl2->next;
		}
		if (!flag)
			break;
		p = p->next;
	}
	return flag;
}

template<typename T>
LSLL<T> LSLL<T>::createClone()
{
	if (!head)
		return *this;
	LSLL<T> cloneList;
	Node<T>* ptr = head;
	Node<T>* value = new Node<T>(ptr->info);
	cloneList.head = value;
	Node<T>* p = cloneList.head;
	ptr = ptr->next;
	while (ptr != nullptr)
	{
		value = new Node<T>(ptr->info);
		p->next = value;
		p = p->next;
		ptr = ptr->next;
	}
	return cloneList;
}

template<typename T>
void LSLL<T>::delAlternate()
{
	Node<T>* p = head;
	Node<T>* ptr = head->next;
	while (ptr != nullptr)
	{
		p->next = ptr->next;
		delete ptr;
		if (!p->next || !p->next->next)
		{
			break;
		}
		p = p->next;
		ptr = p->next;
	}

}

template<typename T>
void LSLL<T>::splitList(LSLL<T>& list1, LSLL<T>& list2)
{
	if (!head)
		return;
	int len = findLength();
	int secLen = 0;
	if (len % 2 == 0)
	{
		len = len / 2;
		secLen = len;
	}
	else
	{
		len = len / 2 + 1;
		secLen = len - 1;
	}
	Node<T> *ptr = nullptr;
	Node<T> *p = head;
	int i = 1;
	while (i <= len)
	{
		ptr = p;
		list1.insertAtTail(p->info);
		p = p->next;
		delete ptr;
		i++;
	}
	
	i = 1;
	while (i <= secLen)
	{
		ptr = p;
		list2.insertAtTail(p->info);
		p = p->next;
		delete ptr;
		i++;
	}
	head = nullptr;
}

template<typename T>
void LSLL<T>::removeDuplicates()
{
	if (!head || !head->next)
		return;
	Node<int>* p = head;
	Node<int>* q = p;
	while (p != nullptr)
	{
		Node<T>* ptr = p->next;
		while (ptr != nullptr) {
			if (p->info == ptr->info)
			{
				q->next = ptr->next;
				delete ptr;
				ptr = q->next;
			}
			else 
			{
				q = ptr;
				ptr = ptr->next;
			}
		}
		p = p->next;
		q = p;
	}
}

template<typename T>
LSLL<T> LSLL<T>:: mergeSortedLists(LSLL<T>& list2)
{
	LSLL<int> l3;
	Node<int>* p = head;
	Node<int>* ptr = list2.head;
	while (p != nullptr || ptr != nullptr)
	{
		if (p == nullptr)
		{
			while (ptr != nullptr)
			{
				l3.insertAtTail(ptr->info);
				ptr = ptr->next;
			}
			break;
		}
		if (ptr == nullptr)
		{
			while (p != nullptr)
			{
				l3.insertAtTail(p->info);
				p = p->next;
			}
			break;
		}
		if (p->info <= ptr->info)
		{
			l3.insertAtTail(p->info);
			p = p->next;
		}
		else
		{
			l3.insertAtTail(ptr->info);
			ptr = ptr->next;
		}
	}
	return l3;
}

template<typename T>
void LSLL<T>:: reversePrint()
{
	
}

template<typename T>
void LSLL<T>::reverseList()
{
	if (!head || !head->next)
		return;
	Node<T>* p = head->next;
	Node<T>* prev = head;
	Node<T>* ptr = p->next;
	head->next = nullptr;
	while (ptr != nullptr) {
		p->next = prev;
		prev = p;
		p = ptr;
		ptr = ptr->next;
	}
	p->next = prev;
	head = p;
}

template<typename T>
void LSLL<T>:: swapMNth(int m, int n)
{
	if (!head || n == m)
		return;
	if (m > n)
	{
		int temp = m;
		m = n;
		n = temp;
	}
	Node<T>* prevM = nullptr;
	Node<T>* M = nullptr;
	Node<T>* nextM = nullptr;
	Node<T>* prevN = nullptr;
	Node<T>* N = nullptr;
	Node<T>* nextN = nullptr;
	Node<T>* p = head;
	Node<T>* prev = head;
	int i = 1;
	while (p != nullptr)
	{
		if (i == m)
		{
			prevM = prev;
			M = p;
			nextM = p->next;
		}
		if (i == n)
		{
			prevN = prev;
			N = p;
			nextN = p->next;
		}
		prev = p;
		p = p->next;
		i++;
	}
	if (!M || !N)
		return;
	prevM->next = N;
	prevN->next = M;
	M->next = nextN;
	if (N != nextM)
		N->next = nextM;
	else
		N->next = M;
	if (m == 1)
	{
		head = N;
	}
}

template<typename T>
void LSLL<T>::sortAddrSwap() 
{
	if (!head || !head->next)
		return;
	Node<T>* p = head->next;
	Node<T>* ptr = p;
	Node<T>* minNode = head;
	int m = 1, n = 1,k = 1;
	while (ptr != nullptr)
	{
		while (p != nullptr)
		{
			k++;
			if (p->info < minNode->info)
			{
				n = k;
				minNode = p;
			}	
			p = p->next;
		}
		swapMNth(m, n);
		m++;
		k = m;
		n = m;
		minNode = ptr;
		ptr = ptr->next;
		p = ptr;
	}
}