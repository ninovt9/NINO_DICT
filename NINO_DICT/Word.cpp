#include "stdafx.h"
#include "Word.h"







namespace ninoDict
{
	Word::Word() :name_(L""), phonetic_(), meaning_(L""), example_()
	{

	}

	Word::Word(std::wstring name, std::wstring phonetic,
		std::wstring meaning)
		: name_(name), phonetic_(phonetic), meaning_(meaning), example_()
	{

	}

	Word::Word(std::wstring name, std::wstring phonetic,
		std::wstring meaning, std::vector<std::wstring> example)
		: name_(name), phonetic_(phonetic), meaning_(meaning), example_(example)
	{

	}
}


