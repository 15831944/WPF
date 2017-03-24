template<class keyType, class valueType>
class ThreadMap
{

public:
	ThreadMap();
	~ThreadMap();

	bool isEmpty();
	void Push(const keyType& obj1, const valueType& obj2);
	bool Pop(keyType& obj1, pair<keyType, valueType>& pairValue);
	bool Query(keyType& obj1, pair<keyType, valueType>& pairValue);
	bool Exist(keyType& obj1);
	void Clear();
	int Size();
private:
	std::map<keyType, valueType> _Map;
	int  size;
	HANDLE mutexHandle;
};

template <class keyType, class valueType> ThreadMap<keyType, valueType>::ThreadMap()
{
	mutexHandle = CreateMutex(NULL, FALSE, NULL);
	size = 0;
}

template <class keyType, class valueType> ThreadMap<keyType, valueType>::~ThreadMap()
{
	CloseHandle(mutexHandle);
}

template <class keyType, class valueType> bool ThreadMap<keyType, valueType>::isEmpty()
{
	if (0 == size)
	{
		return true;
	}
	return false;
}

template<class keyType, class valueType> void ThreadMap<keyType, valueType>::Push(const keyType& obj1, const valueType& obj2)
{
	WaitForSingleObject(mutexHandle, INFINITE);
	_Map[obj1] = obj2;
	size = _Map.size();
	ReleaseMutex(mutexHandle);
}

template<class keyType, class valueType>
bool ThreadMap<keyType, valueType>::Pop(keyType& obj1, pair<keyType, valueType>& pairValue)
{
	WaitForSingleObject(mutexHandle, INFINITE);
	map<keyType, valueType>::iterator it = _Map.find(obj1);
	bool bret = it != _Map.end();
	if (bret)
	{
		pairValue.first		= it->first;
		pairValue.second	= it->second;
		_Map.erase(it);
	}
	size = _Map.size();
	ReleaseMutex(mutexHandle);

	return bret;
}

template<class keyType, class valueType>
bool ThreadMap<keyType, valueType>::Query(keyType& obj1, pair<keyType, valueType>& pairValue)
{
	WaitForSingleObject(mutexHandle, INFINITE);
	map<keyType, valueType>::iterator it = _Map.find(obj1);
	bool bret = it != _Map.end();
	if (bret)
	{
		pairValue.first		= it->first;
		pairValue.second	= it->second;
	}
	size = _Map.size();
	ReleaseMutex(mutexHandle);

	return bret;
}

template<class keyType, class valueType>
bool ThreadMap<keyType, valueType>::Exist(keyType& obj1)
{
	WaitForSingleObject(mutexHandle, INFINITE);
	map<keyType, valueType>::iterator it = _Map.find(obj1);
	bool bret = it != _Map.end();
	ReleaseMutex(mutexHandle);

	return bret;
}

template<class keyType, class valueType> int ThreadMap<keyType, valueType>::Size()
{
	return size;
}

template <class keyType, class valueType> void ThreadMap<keyType, valueType>::Clear()
{
	WaitForSingleObject(mutexHandle, INFINITE);
	while (!_Map.empty())
		_Map.clear();
	size = 0;
	ReleaseMutex(mutexHandle);
}
