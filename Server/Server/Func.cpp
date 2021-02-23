#include "stdafx.h"
#include "Func.h"

const char* DeleteChr(char str[], char word)
{
	char *s = (char *)malloc(sizeof(str));

	int i, k = 0;

	for (i = 0; i < strlen(s); i++)
	{
		if (str[i] != word) s[k++] = str[i];
	}

	s[k] = '\0';
	return s;
}

vector<string> SplitString(string str, char word)
{
	// �Է¹��� ���ڿ����� Ư�� ���ڸ� �������� ������ vector�� �����Ͽ� ����
	vector<string> splitStr;

	str += ' ';

	string::iterator iter = str.begin();
	int index = 0;
	while (iter != str.end())
	{
		auto p = find(iter, str.end(), word);
		if (p != str.end())
		{
			string temp; 
			temp.assign(str, index, p - iter);
			splitStr.emplace_back(temp);
			index += p - iter + 1;
		}
		iter = p;
		if (p == str.end())
			break;
		iter++;
	}
	
	return splitStr;
}