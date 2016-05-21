#pragma once

#include <regex>
#include <string>
#include <iostream>
#include <fstream>


//��������⣺���ҵ��ʲ��������ƣ�

enum N_STATE
{
	//N_WORD, N_PHONETIX, N_MEANING, N_EXAMPLE, N_SPACE, N_NONE
	N_WORD, N_PHONETIC, N_SPACE, N_NONE
};

//������ʽ
//��ʱֻʹ��������
const std::regex WORD_REGEX("\\S+");
const std::regex PHONETIC_REGEX("\\S[a-z]+\\s\\S+");


const std::regex MEANING_REGEX("\\S+");
const std::regex EXAMPLE_REGEX("\\$\\S+");
const std::regex SPACE_REGEX("");

//�������ж����
N_STATE NLexAnalysis(std::string line);

//����value����
void NValueProcess(std::ifstream &fileStream, std::vector<std::string> &valueVector);

//
//void NLexAnalysis(std::string line)
//{
//	std::string result;
//	//����->word
//	if(std::regex_match(line, ))
//	
//}


//
////����״̬���Ķ���
//void print(std::string line, N_STATE state)
//{
//	if (state == word)
//	{
//		std::cout << "���ǵ��ʣ�" << line << std::endl;
//	}
//	else if (state == meaning)
//	{
//		std::cout << "�������壺" << line << std::endl;
//	}
//	else if (state == example)
//	{
//		std::cout << "�������䣺" << line << std::endl;
//	}
//	else
//	{
//		std::cout << "��������" << line << std::endl;
//	}
//}




//void analysis(fstream &file, N_STATE state)
//{
//	string line;
//	getline(file, line);
//
//	//�ж�
//
//}
//
//
//
//
//int main()
//{
//
//	//fstream file("JpDict.txt");
//	//string line;
//
//	//string pattren("");
//	//regex r(pattren);
//	//smatch result;
//
//	//while (!file.eof())
//	//{
//	//	getline(file, line);
//	//	if (regex_match(line, result, r))
//	//	{
//	//		std::cout << "���һ��з�" << line << std::endl;
//	//	}
//	//	
//	//}
//
//
//
//	system("pause");
//	return 0;
//}

