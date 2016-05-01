#ifndef _LINKED
#define _LINKED

#include <iostream>
using namespace std;


template <class T>
class Node
{
public:
	Node()
	{
		ptrNext = NULL;
		ptrPrev = NULL;
	}

	T data;
	Node* ptrNext;
	Node* ptrPrev;
};

template <class T>
class LinkedList
{
public:
	LinkedList()
	{
		ptrFront = NULL;
		ptrEnd = NULL;
		m_size = 0;
	}

	~LinkedList()
	{
		Clear();
	}

	void Clear()
	{
		while (ptrFront != NULL)
		{
			PopBack();
		}
	}

	void PushBack(T data)
	{
		Node<T>* newNode = new Node<T>;
		newNode->data = data;

		if (ptrFront == NULL && ptrEnd == NULL)
		{
			ptrFront = newNode;
			ptrEnd = newNode;
		}
		else
		{
			newNode->ptrPrev = ptrEnd;
			ptrEnd->ptrNext = newNode;
			ptrEnd = newNode;
		}
		m_size++;
	}

	void PushFront(T data)
	{
		Node<T>* newNode = new Node<T>;
		newNode->data = data;

		if (ptrFront == NULL && ptrEnd == NULL)
		{
			ptrFront = newNode;
			ptrEnd = newNode;
		}
		else
		{
			newNode->ptrNext = ptrFront;
			ptrFront->ptrPrev = newNode;
			ptrFront = newNode;
		}
		m_size++;
	}


	void PopBack()
	{
		if (m_size == 0)
		{
			return;
		}
		else if (ptrFront == ptrEnd)
		{
			delete ptrFront;
			ptrFront = NULL;
			ptrEnd = NULL;
			m_size = 0;
		}
		else
		{
			Node<T>* temp = ptrEnd->ptrPrev;
			delete ptrEnd;
			ptrEnd = temp;
			ptrEnd->ptrNext = NULL;
			m_size--;
		}
	}

	void PopFront()
	{
		if (m_size == 0)
		{
			return;
		}
		else if (ptrFront == ptrEnd)
		{
			delete ptrFront;
			ptrFront = NULL;
			ptrEnd = NULL;
			m_size = 0;
		}
		else
		{
			Node<T>* temp = ptrFront->ptrNext;
			delete ptrFront;
			ptrFront = temp;
			ptrFront->ptrPrev = NULL;
			m_size--;
		}
	}

	T GetFirst()
	{
		return ptrFront->data;
	}

	T GetLast()
	{
		return ptrEnd->data;
	}

	T At(int index)
	{
		Node<T>*ptrCurrent = ptrFront;
		int counter = 0;
		while (counter < index)
		{

			ptrCurrent = ptrCurrent->ptrNext;
			counter++;
		}
		ptrCurrent->data;
	}

	int Size()
	{
		return m_size;
	}

	bool IsEmpty()
	{
		return (m_size == 0);
	}

	void Display()
	{
		Node<T>*ptrCurrent = ptrFront;
		int counter = 0;
		while (ptrCurrent != NULL)
		{
			cout << counter << ptrCurrent->data << endl;
			ptrCurrent = ptrCurrent->ptrNext;
			counter++;
		}
	}

private:
	Node<T>* ptrFront;
	Node<T>* ptrEnd;
	int m_size;

};


#endif
