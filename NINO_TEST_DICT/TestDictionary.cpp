#include "stdafx.h"
#include "CppUnitTest.h"
#include "Dictionary.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ninoDict;

using std::wifstream;

const std::string TEST_PATH = "D:\\code\\Project\\Jp\\NINO_DICT\\NINO_TEST_DICT\\";

namespace NINO_TEST_DICT
{		
	TEST_CLASS(TestDictionary)
	{
	public:
		
		TEST_METHOD(Test_GetNextChar)
		{
			Dictionary dictionary;
			std::wifstream stream(TEST_PATH + "Test_GetNextChar.txt");  //input

			if (stream.fail())
			{
				Assert::Fail(L"Failed to open file");
			}

			Assert::AreEqual(dictionary.GetNextChar(stream), L'あ', L"あいうえお  ->  あ");
			Assert::AreEqual(dictionary.GetNextChar(stream), L'い', L"あいうえお  ->  い");
			Assert::AreEqual(dictionary.GetNextChar(stream), L'う', L"あいうえお  ->  う");
			Assert::AreEqual(dictionary.GetNextChar(stream), L'え', L"あいうえお  ->  え");
			Assert::AreEqual(dictionary.GetNextChar(stream), L'お', L"あいうえお  ->  お");


			// contain space
			stream = std::wifstream(TEST_PATH + "Test_GetNextChar_space.txt");

			if (stream.fail())
			{
				Assert::Fail(L"Failed to open file");
			}

			Assert::AreEqual(dictionary.GetNextChar(stream), L'あ', L"あ お  ->  あ");
			Assert::AreEqual(dictionary.GetNextChar(stream), L'お', L"あ お  ->  お");

		}

	};
}