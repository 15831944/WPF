#pragma once
#include <queue>
using namespace std;

template<class T>
class ThreadQueue
{

public:
	ThreadQueue();
	~ThreadQueue();

	bool isEmpty();
	void Push(const T&obj);
	void Pop();
	int Size();

	T& Front();
	T& Back();
	void Clear();

private:
	std::queue<T>_Map;
	int  size;
	HANDLE mutexHandle;
};

template <class T> ThreadQueue<T>::ThreadQueue()
{
	mutexHandle = CreateMutex(NULL, FALSE, NULL);
	size = 0;
}

template <class T> ThreadQueue<T>::~ThreadQueue()
{
	CloseHandle(mutexHandle);
}
template <class T> bool ThreadQueue<T>::isEmpty()
{
	if (0 == size)
	{
		return true;
	}
	return false;
}

template<class T> void ThreadQueue<T>::Push(const T&obj)
{
	WaitForSingleObject(mutexHandle, INFINITE);
	_Map.push(obj);
	size = _Map.size();
	ReleaseMutex(mutexHandle);
}
template<class T> void ThreadQueue<T>::Pop()
{
	WaitForSingleObject(mutexHandle, INFINITE);
	_Map.pop();
	size = _Map.size();
	ReleaseMutex(mutexHandle);
}
template<class T> int ThreadQueue<T>::Size()
{
	return size;
}
template <class T> T& ThreadQueue<T>::Front()
{
	WaitForSingleObject(mutexHandle, INFINITE);
	T& obj = Queue.front();
	ReleaseMutex(mutexHandle);
	return obj;
}

template <class T> T& ThreadQueue<T>::Back()
{
	WaitForSingleObject(mutexHandle, INFINITE);
	T& obj = Queue.back();
	ReleaseMutex(mutexHandle);
	return obj;
}

template <class T> void ThreadQueue<T>::Clear()
{
	WaitForSingleObject(mutexHandle, INFINITE);
	while (!Queue.empty())
	{
		Queue.pop();
	}
	size = 0;
	ReleaseMutex(mutexHandle);
}
