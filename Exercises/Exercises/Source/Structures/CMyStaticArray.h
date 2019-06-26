#pragma once


template <class T, int SIZE>
class CMyStaticArray
{
public:
	T* begin();
	T* end();

	T& operator[](int pos);

	static constexpr int GetSize() {
		return SIZE;
	}

	T get(int pos);
private:
	T myArray[SIZE + 1];
};

template <class T, int SIZE>
T& CMyStaticArray<T, SIZE>::operator[](int pos)
{
	if (pos < SIZE - 1)
	{
		return myArray[pos];
	}
	return myArray[pos];
}

template <class T, int SIZE>
T* CMyStaticArray<T, SIZE>::begin()
{
	return &myArray[0];
}

template <class T, int SIZE>
T* CMyStaticArray<T, SIZE>::end()
{
	return &myArray[SIZE];
}

template <class T, int SIZE>
T CMyStaticArray<T, SIZE>::get(int pos)
{
	if (pos < SIZE - 1)
	{
		return myArray[pos];
	}
	return T();
}

