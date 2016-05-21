




#pragma once

#include "Word.h"

#include <map>
#include <fstream>

#include <locale>
#include <codecvt>

namespace ninoDict
{

	enum class State
	{
		START,
		WORD,
		LINEBREAK
	};

	enum class WordState
	{
		NAME,
		LINEBREAK,
		PHONETIC,
		MEANING,
		EXAMPLE
	};

	class Dictionary
	{
	public:
		Dictionary();
		Dictionary(const std::wstring& fileName);

	public:
		wchar_t GetNextChar(std::wifstream &stream);
		Word	GetNextWord(std::wifstream &stream);

	public:
		Word	HandleWordState(std::wifstream &stream, wchar_t currectChar);
		// void	HandleLineBreakState(std::wifstream &stream, wchar_t currectChar);


		//void CreateDict();
		//
		
		//void HandleNameState();
		//void HandleLineBreakState();
		//void HandlePhoneticState();		// 注音应该有两个状态
		//void HandleMeaningState();
		//void HandleExampleState();
		// '$'\S + '\n';

	private:
		State state_;
		std::wifstream stream_;
		std::map<std::wstring, Word> wordDict_;
		std::locale utf8_locale_;
	};
}


