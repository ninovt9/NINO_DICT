
#pragma once


#include "Token.h"
#include "Error.h"

#include <fstream>
#include <vector>
#include <codecvt>



namespace ninoDict
{
	enum class State
	{
		START,
		MEANING,
		EXAMPLE,
		LINEBREAK,
		ERROR
	};

	class Scanner
	{
	public:
		Scanner();
		Scanner(std::wstring fileName);

	public:
		std::vector<Token>				GetTokenList();
		Token							GetToken();
		Token							GetToken(std::wifstream &stream);
		std::wstring					GetNextLine(std::wifstream &stream);

	public:
		const std::locale				GetUtf8() const;
		State							GetState() const;
		std::vector<std::wstring>		GetErrorReport() const;

	private:
		std::wifstream					stream_;
		State							state_;
		std::vector<std::wstring>		errorReport_;
		std::vector<Token>				tokenList_;
	};

	inline const std::locale Scanner::GetUtf8() const
	{
		// …Ë÷√±‡¬Î
		const std::locale empty_locale = std::locale::empty();
		typedef std::codecvt_utf8<wchar_t> converter_type;  //std::codecvt_utf16
		const converter_type* converter = new converter_type;
		const std::locale utf8 = std::locale(empty_locale, converter);

		return utf8;
	}

	inline State Scanner::GetState() const
	{
		return state_;
	}

	inline std::vector<std::wstring> Scanner::GetErrorReport() const
	{
		return errorReport_;
	}

}

