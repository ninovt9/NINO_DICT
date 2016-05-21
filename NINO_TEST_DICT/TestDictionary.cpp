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

			Assert::AreEqual(dictionary.GetNextChar(stream), L'��', L"����������  ->  ��");
			Assert::AreEqual(dictionary.GetNextChar(stream), L'��', L"����������  ->  ��");
			Assert::AreEqual(dictionary.GetNextChar(stream), L'��', L"����������  ->  ��");
			Assert::AreEqual(dictionary.GetNextChar(stream), L'��', L"����������  ->  ��");
			Assert::AreEqual(dictionary.GetNextChar(stream), L'��', L"����������  ->  ��");


			// contain space
			stream = std::wifstream(TEST_PATH + "Test_GetNextChar_space.txt");

			if (stream.fail())
			{
				Assert::Fail(L"Failed to open file");
			}

			Assert::AreEqual(dictionary.GetNextChar(stream), L'��', L"�� ��  ->  ��");
			Assert::AreEqual(dictionary.GetNextChar(stream), L'��', L"�� ��  ->  ��");

		}

	};
}