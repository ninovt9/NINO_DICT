#include "stdafx.h"
#include "Dictionary.h"

namespace ninoDict
{
	Dictionary::Dictionary():state_(State::START)
	{
		//// …Ë÷√±‡¬Î
		//const std::locale empty_locale = std::locale::empty();
		//typedef std::codecvt_utf8<wchar_t> converter_type;  //std::codecvt_utf16
		//const converter_type* converter = new converter_type;
		//utf8_locale_ = std::locale(empty_locale, converter);
	}

	Dictionary::Dictionary(const std::wstring& fileName) :state_(State::START)
	{
		// …Ë÷√±‡¬Î
		//const std::locale empty_locale = std::locale::empty();
		//typedef std::codecvt_utf8<wchar_t> converter_type;  //std::codecvt_utf16
		//const converter_type* converter = new converter_type;
		//utf8_locale_ = std::locale(empty_locale, converter);

		stream_ = std::wifstream(fileName);
		if (stream_.fail())
		{
			// error
		}
	}

	wchar_t Dictionary::GetNextChar(std::wifstream &stream)
	{
		stream.imbue(utf8_locale_);

		wchar_t result;
		// strip space
		do {
			stream >> result;
		} while (result == ' ' || result == '°°');

		return result;
	}

	Word Dictionary::GetNextWord(std::wifstream &stream)
	{
		// first char
		wchar_t currectChar = GetNextChar(stream);

		// state judge
		while (!stream.eof())
		{
			switch (state_)
			{
			case State::START:
				break;
			case State::WORD:
				// handle word
				break;
			case State::LINEBREAK:
				break;
			}

			// state «®“∆
			if (currectChar != L'\n')
			{
				state_ = State::WORD;
			}
			else
			{
				state_ = State::LINEBREAK;
			}
		}

		// return invaild
		return Word();
	}

	Word Dictionary::HandleWordState(std::wifstream &stream, wchar_t currectChar)
	{
		// WORD: NAME LINEBREAK PHONETIC MEANING + EXAMPLE*;
		
		// HandleNameState

		// HandleLineBreakState

		// HandlePhoneticState

		// HandleMeaningState

		// HandleExampleState

		return Word();
	}



}


