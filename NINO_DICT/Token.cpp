#include "stdafx.h"
#include "Token.h"




namespace ninoDict
{

	Token::Token():type_(TokenType::INVALID), content_(L"")
	{

	}

	Token::Token(TokenType type) : type_(type), content_(L"")
	{

	}

	Token::Token(TokenType type, std::wstring content) : type_(type), content_(content)
	{

	}

	Token::Token(const Token& other)
	{
		type_ = other.type_;
		content_ = other.content_;
	}

	Token& Token::operator=(const Token& other)
	{
		type_ = other.type_;
		content_ = other.content_;
		return *this;
	}

	bool Token::operator==(const Token& other)
	{
		return (
			type_ == other.type_
			&& content_ == other.content_
			);
	}

	bool Token::operator==(const Token& other) const
	{
		return (
			type_ == other.type_
			&& content_ == other.content_
			);
	}

}





