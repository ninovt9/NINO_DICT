#include "stdafx.h"
#include "CppUnitTest.h"
#include "Parser.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ninoDict;

#include <algorithm>

using std::wifstream;

const std::wstring TEST_PATH = L"D:\\code\\Project\\Jp\\NINO_DICT\\NINO_TEST_DICT\\";

namespace NINO_TEST_DICT
{
	TEST_CLASS(TestParser)
	{
	public:

		TEST_METHOD(Test_HandleLineBreakState)
		{
			Scanner scanner(TEST_PATH + L"Test_Parser_LineBreak.txt");
			Parser parser;

			if (scanner.GetErrorReport().size() >= static_cast<size_t>(1))
			{
				Assert::Fail(L"Failed to open file");
			}

			// 此处返回linebreak后一行的token，实现方法着实傻逼，不忍直视。。。
			// 等我给Scanner写完peek以后就能改这个了。。。
			Assert::AreEqual((parser.HandleLineBreakState(scanner) == Token(TokenType::INVALID)), true, L"line break");
		}


		TEST_METHOD(Test_HandleExample)
		{
			Scanner scanner(TEST_PATH + L"Test_Example.txt");
			Parser parser;

			if (scanner.GetErrorReport().size() >= static_cast<size_t>(1))
			{
				Assert::Fail(L"Failed to open file");
			}

			std::vector<std::wstring> correct = { L"$経済上の利益／经济上的利益lìyì.", L"$それは経済上許されない／这件事经济上办不到." };
			std::vector<std::wstring> result = parser.HandleExampleState(scanner);
			Assert::AreEqual(std::equal(result.begin(), result.end(), correct.begin(), correct.end()), true);
		}

	};
}