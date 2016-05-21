#include "stdafx.h"
#include "NDict.h"

using std::ifstream;
using std::string;
using std::vector;
using std::smatch;
using std::regex_match;


//�����������
N_STATE NLexAnalysis(string line)
{
	smatch result;
	if (regex_match(line, result, WORD_REGEX))
	{
		return N_WORD;
	}
	else if (regex_match(line, result, PHONETIC_REGEX))
	{
		return N_PHONETIC;
	}
	else if (regex_match(line, result, SPACE_REGEX))
	{
		return N_SPACE;
	}
	else
	{
		return N_NONE;
	}
}

//����value����
void NValueProcess(ifstream &fileStream, vector<string> &valueVector)
{
	string line;
	std::getline(fileStream, line);
	//�����˳�
	if (NLexAnalysis(line) == N_SPACE)
	{
		return;
	}
	//�ǿ����
	else
	{
		valueVector.push_back(line);
		NValueProcess(fileStream, valueVector);
	}
}


