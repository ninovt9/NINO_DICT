#include "stdafx.h"
#include "CppUnitTest.h"
#include "Token.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ninoDict;

namespace NINO_TEST_CALCULATOR
{
	TEST_CLASS(TestToken)
	{
	public:
		TEST_METHOD(Test_Class_Init)
		{
			Token token;
			Assert::AreEqual((token.GetType() == TokenType::INVALID), true, L"default init -> type");
			Assert::AreEqual((token.GetContent() == L""), true, L"default init -> content");

			token = Token(TokenType::MEANING, L"かわいい");
			Assert::AreEqual((token.GetType() == TokenType::MEANING), true, L"value init -> type");
			Assert::AreEqual((token.GetContent() == L"かわいい"), true, L"value init -> content");

		}


		TEST_METHOD(Test_Class_OperatorEqual)
		{
			Token t_1(TokenType::MEANING, L"かわいい");
			Token t_2(TokenType::MEANING, L"かわいい");
			Token t_3(TokenType::MEANING, L"可爱");
			Assert::AreEqual((t_1 == t_2), true);
			Assert::AreEqual((t_1 == t_3), false);

			const Token ct_1(TokenType::MEANING, L"可爱");
			const Token ct_2(TokenType::EXAMPLE, L"不可爱");
			Assert::AreEqual((ct_1 == ct_2), false);
		}
	};
}