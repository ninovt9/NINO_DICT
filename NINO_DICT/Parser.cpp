#include "stdafx.h"
#include "Parser.h"








namespace ninoDict
{
	Parser::Parser()
	{
	}

	//Word Parser::GetWord(Scanner &scanner)
	//{
	//	// word: name linebreak*2 phonetic meaning + example + linebreak +

	//	Token currectToken;
	//	
	//	std::wstring name;
	//	std::wstring phonetic;
	//	std::wstring meaning;
	//	std::vector<std::wstring> example;

	//	// name
	//	name = HandleMeaningState(scanner);

	//	// linebreak
	//	currectToken = HandleLineBreakState(scanner);

	//	// phonetic
	//	phonetic = HandleMeaningState(scanner, currectToken);

	//	// linebreak
	//	currectToken = HandleLineBreakState(scanner);

	//	// meaning
	//	meaning = HandleMeaningState(scanner, currectToken);

	//	// linebreak
	//	currectToken = HandleLineBreakState(scanner);

	//	return Word();

	//}

	std::wstring Parser::HandleMeaningState(Scanner &scanner, Token token = Token(TokenType::INVALID))
	{
		if (token.GetType() == TokenType::INVALID)
		{
			token = scanner.GetToken();
		}
		
		if (token.GetType() == TokenType::MEANING)
		{
			return token.GetContent();
		}
		else
		{
			// error
		}
	}

	Token Parser::HandleLineBreakState(Scanner &scanner)
	{
		Token token;

		// skip the linebreak;

		do {
			token = scanner.GetToken();
		} while (token.GetType() == TokenType::LINEBREAK);

		return token;
	}

	std::vector<std::wstring> Parser::HandleExampleState(Scanner &scanner)
	{
		std::vector<std::wstring> example;
		
		Token token = scanner.GetToken();
		while (token.GetType() == TokenType::EXAMPLE)
		{
			example.push_back(token.GetContent());
			token = scanner.GetToken();
		}


		// linebreak
		if (token.GetType() == TokenType::INVALID)
		{
			HandleLineBreakState(scanner);
		}
		
		return example;
	}


}



