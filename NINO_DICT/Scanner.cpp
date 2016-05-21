
#include "stdafx.h"
#include "Scanner.h"






namespace ninoDict
{
	Scanner::Scanner() :stream_(), state_(State::START), errorReport_(), tokenList_()
	{

	}
	

	Scanner::Scanner(std::wstring fileName) : stream_(fileName), state_(State::START), errorReport_(), tokenList_()
	{
		if (!stream_.fail())
		{
			stream_.imbue(GetUtf8());
			stream_.get();	// 跳过utf-8标识字节
		}
		else
		{
			ErrorFile(L"Failed to open file", errorReport_);
		}
	}


	std::wstring Scanner::GetNextLine(std::wifstream &stream)
	{
		stream.imbue(GetUtf8());

		std::wstring result;
		std::getline(stream, result);

		return result;
	}

	Token Scanner::GetToken(std::wifstream &stream)
	{
		// first line
		std::wstring currectLine = GetNextLine(stream);

		// state judge
		do {
			switch (state_)
			{
			case State::START:
				break;

			case State::MEANING:
				state_ = State::START;
				return Token(TokenType::MEANING, currectLine);
				break;

			case State::EXAMPLE:
				state_ = State::START;
				return Token(TokenType::EXAMPLE, currectLine);
				break;

			case State::LINEBREAK:
				state_ = State::START;
				return Token(TokenType::LINEBREAK);
				break;

			case State::ERROR:
				return Token(TokenType::INVALID);
				break;
			}

			// state 迁移
			if (currectLine[0] == L'$')
			{
				state_ = State::EXAMPLE;
			}
			else if (currectLine + L"1" == (L"1"))
			{
				state_ = State::LINEBREAK;
			}
			else if (currectLine.size() != static_cast<size_t>(0))
			{
				state_ = State::MEANING;
			}
			else
			{
				state_ = State::ERROR;
			}
		} while (state_ != State::ERROR || !stream.eof());
	
		return Token(TokenType::INVALID);
	}

	Token Scanner::GetToken()
	{
		return GetToken(stream_);
	}


	std::vector<Token> Scanner::GetTokenList()
	{
		while (!stream_.eof())
		{
			tokenList_.push_back(GetToken(stream_));
		}
		return tokenList_;
	}


}


