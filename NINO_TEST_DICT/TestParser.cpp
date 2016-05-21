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

			// �˴�����linebreak��һ�е�token��ʵ�ַ�����ʵɵ�ƣ�����ֱ�ӡ�����
			// ���Ҹ�Scannerд��peek�Ժ���ܸ�����ˡ�����
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

			std::vector<std::wstring> correct = { L"$�U�g�Ϥ����棯�����ϵ�����l��y��.", L"$����ϽU�g���S����ʤ�������¾����ϰ첻��." };
			std::vector<std::wstring> result = parser.HandleExampleState(scanner);
			Assert::AreEqual(std::equal(result.begin(), result.end(), correct.begin(), correct.end()), true);
		}

	};
}