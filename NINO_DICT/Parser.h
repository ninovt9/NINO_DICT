#pragma once



#include "Scanner.h"
#include "Word.h"



namespace ninoDict
{
	class Parser
	{
	public:
		Parser();

	public:
		// Word GetWord(Scanner &scanner);

	public:
		std::wstring					HandleMeaningState(Scanner &scanner, Token token);
		Token							HandleLineBreakState(Scanner &scanner);
		std::vector<std::wstring>		HandleExampleState(Scanner &scanner);
		


	private:
		Scanner scanner;

	};

}




