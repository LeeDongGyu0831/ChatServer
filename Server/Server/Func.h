#pragma once
template<typename T1, typename T2>
void Safe_Delete_Unordered_Map(unordered_map<T1, T2*>& _map)
{
	for (auto& pair : _map)
	{
		SAFE_DELETE(pair.second);
	}

	_map.clear();
}

template<typename T1, typename T2>
T2* Find_Unordered_Map(unordered_map<T1, T2*>& _map, const T1& _key)
{
	unordered_map<T1, T2*>::iterator iter = _map.find(_key);
	if (iter == _map.end())
	{
		// 해당 원소가 없음
		return NULL;
	}

	return iter->second;
}

template<typename T1, typename T2>
void Safe_Delete_Map(map<T1, T2*>& _map)
{
	for (auto& pair : _map)
	{
		SAFE_DELETE(pair.second);
	}

	_map.clear();
}

template<typename T, int iSize>
void Safe_Delete_Array(T*(&_arr)[iSize])
{
	for (UINT i = 0; i < iSize; ++i)
	{
		SAFE_DELETE(_arr[i]);
	}
}

template<typename T>
void Safe_Delete_Vector(vector<T*> _vec)
{
	for (UINT i = 0; i < _vec.size(); ++i)
	{
		SAFE_DELETE(_vec[i]);
	}
}

template<typename T>
void Safe_Delete_List(list<T*> _list)
{
	for (auto& data : _list)
	{
		SAFE_DELETE(data);
	}
}

const char* DeleteChr(char str[], char word);
vector<string> SplitString(string str, char word);