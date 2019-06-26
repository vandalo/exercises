#pragma once

#include <iostream>

template <class T>
struct SNode
{
	SNode* m_nextElement;
	SNode* m_previousElement;
	T m_element;

	SNode() :
		m_nextElement(nullptr)
		, m_previousElement(nullptr) 
	{};
	SNode(T& element, SNode* nextElement, SNode* previousElement) : 
		m_element(std::move(element))
		, m_nextElement(nextElement)
		, m_previousElement(previousElement)
	{};
};

template <class T>
class CMyList
{
public:
	CMyList();
	~CMyList();

	void push_back(T element);
	void push_front(T element);
	void pop_back();
	void pop_front();
	const T& front();
	const T& back();
	
	int size() const;
	bool empty() const;
	void print();

private:
	SNode<T>* m_end;
	SNode<T>* m_start;
	int m_numElements;
};

template <class T>
CMyList<T>::CMyList() :
	m_end(new SNode<T>)
	, m_start(m_end)
	, m_numElements(0)
{
	m_end->m_previousElement = m_start;
}

template <class T>
CMyList<T>::~CMyList()
{}

//Add an element in the last place of the list
template <class T>
void CMyList<T>::push_back(T element)
{
	++m_numElements;

	SNode<T>* newNode = new SNode<T>(element, m_end, m_end->m_previousElement);
	m_end->m_previousElement = newNode;
	newNode->m_previousElement->m_nextElement = newNode;
	if (m_start == m_end)
	{
		m_start = newNode;
	}
}

//Add an element in the first place of the list
template <class T>
void CMyList<T>::push_front(T element)
{
	++m_numElements;

	SNode<T>* newNode = new SNode<T>(element, m_start, nullptr);
	if (m_start == m_end)
	{
		m_end->m_previousElement = newNode;
	}
	m_start = newNode;
}

//Remove from the list the element in the back
template <class T>
void CMyList<T>::pop_back()
{
	--m_numElements;

	SNode<T>* aux = m_end->m_previousElement;
	aux->m_previousElement->m_nextElement = m_end;
	m_end->m_previousElement = aux->m_previousElement;
	delete(aux);
}

//Removes from the list the element in the front
template <class T>
void CMyList<T>::pop_front()
{
	--m_numElements;

	SNode<T>* aux = m_start;
	m_start = aux->m_nextElement;
	aux->m_nextElement->m_previousElement = aux->m_previousElement;
	delete(aux);
}

//Return first element of the list
template <class T>
const T& CMyList<T>::front()
{
	return m_start->m_element;
}

//Return last element of the list
template <class T>
const T& CMyList<T>::back()
{
	return m_end->m_previousElement->m_element;
}

//Returns the size of the list
template <class T>
int CMyList<T>::size() const
{
	return m_numElements;
}

//Returns true if the list is empty
template <class T>
bool CMyList<T>::empty() const
{
	return m_numElements == 0;
}

//Print the list
template <class T>
void CMyList<T>::print()
{
	if (m_start != m_end)
	{
		std::cout << "[";
		for (auto it = m_start; it != m_end; it = it->m_nextElement)
		{
			std::cout << it->m_element;
			if (it->m_nextElement != m_end)
			{
				std::cout << ", ";
			}
		}
		std::cout << "]" << std::endl;
	}
}