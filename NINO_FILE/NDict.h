#pragma once

#include <regex>
#include <string>
#include <iostream>
#include <fstream>


//待解决问题：查找单词部分如何设计？

enum N_STATE
{
	//N_WORD, N_PHONETIX, N_MEANING, N_EXAMPLE, N_SPACE, N_NONE
	N_WORD, N_PHONETIC, N_SPACE, N_NONE
};

//正则表达式
//暂时只使用这两个
const std::regex WORD_REGEX("\\S+");
const std::regex PHONETIC_REGEX("\\S[a-z]+\\s\\S+");


const std::regex MEANING_REGEX("\\S+");
const std::regex EXAMPLE_REGEX("\\$\\S+");
const std::regex SPACE_REGEX("");

//分析、判断类别
N_STATE NLexAnalysis(std::string line);

//处理value部分
void NValueProcess(std::ifstream &fileStream, std::vector<std::string> &valueVector);

//
//void NLexAnalysis(std::string line)
//{
//	std::string result;
//	//空行->word
//	if(std::regex_match(line, ))
//	
//}


//
////根据状态更改动作
//void print(std::string line, N_STATE state)
//{
//	if (state == word)
//	{
//		std::cout << "我是单词：" << line << std::endl;
//	}
//	else if (state == meaning)
//	{
//		std::cout << "我是释义：" << line << std::endl;
//	}
//	else if (state == example)
//	{
//		std::cout << "我是例句：" << line << std::endl;
//	}
//	else
//	{
//		std::cout << "我是松鼠：" << line << std::endl;
//	}
//}




//void analysis(fstream &file, N_STATE state)
//{
//	string line;
//	getline(file, line);
//
//	//判断
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
//	//		std::cout << "叫我换行符" << line << std::endl;
//	//	}
//	//	
//	//}
//
//
//
//	system("pause");
//	return 0;
//}

