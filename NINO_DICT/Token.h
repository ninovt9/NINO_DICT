#pragma once

#include <string>

namespace ninoDict
{
	enum class TokenType
	{
		MEANING,
		EXAMPLE,
		LINEBREAK,

		INVALID
	};

	class Token
	{
	public:
		Token();
		Token(TokenType type);
		Token(TokenType type, std::wstring content);

	public:
		TokenType GetType() const;
		std::wstring GetContent() const;

	public:
		Token(const Token& other);
		Token& operator=(const Token& other);
		bool operator==(const Token& other);
		bool operator==(const Token& other) const;

	private:
		TokenType type_;
		std::wstring content_;
	};

	inline TokenType Token::GetType() const
	{
		return type_;
	}

	inline std::wstring Token::GetContent() const
	{
		return content_;
	}
}



