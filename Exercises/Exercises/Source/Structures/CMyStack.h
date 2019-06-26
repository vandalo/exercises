#pragma once

#include "CMyList.h"

template <class T>
class CMyStack
{
	CMyList m_list;

	void push_front(T element);
	void pop_front();
};

template <class T>
void CMyStack<T>::pop_front()
{
	m_list.pop_front();
}

template <class T>
void CMyStack<T>::push_front(T element)
{
	m_list.push_front(element);
}