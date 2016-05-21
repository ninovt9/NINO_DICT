#include "stdafx.h"
#include "CppUnitTest.h"
#include "NDict.h"

using std::regex;
using std::smatch;
using std::regex_match;
using std::string;
using std::vector;
using std::fstream;
using std::ifstream;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NINO_TEST_FILE
{		
	TEST_CLASS(NTestDict)
	{
	public:
		
		TEST_METHOD(Test_Regex_WORD_REGEX_letter)
		{
			//单词匹配
			string base = "-C";
			smatch result;

			bool isTrue = regex_match(base, result, WORD_REGEX);
			Assert::AreEqual(isTrue, true);
		}

		TEST_METHOD(Test_Regex_WORD_REGEX_hiragana)
		{
			//单词匹配
			string base = "いじり";
			smatch result;

			bool isTrue = regex_match(base, result, WORD_REGEX);
			Assert::AreEqual(isTrue, true);
		}

		TEST_METHOD(Test_Regex_WORD_REGEX_kannji)
		{
			//单词匹配
			string base = "機構い";
			smatch result;

			bool isTrue = regex_match(base, result, WORD_REGEX);
			Assert::AreEqual(isTrue, true);
		}


		TEST_METHOD(Test_Regex_PHONETIC_REGEX)
		{
			//单词匹配
			string base = "-ijiri ‐いじり";
			smatch result;

			bool isTrue = regex_match(base, result, PHONETIC_REGEX);
			Assert::AreEqual(isTrue, true);
		}

		TEST_METHOD(Test_Regex_MEANING_REGEX)
		{
			//单词匹配
			string base = "（1）〔…のようである〕类似lèisì,仿效fǎngxiào, 带有dàiyǒu……的样子de yàngzi.";
			smatch result;

			bool isTrue = regex_match(base, result, MEANING_REGEX);
			Assert::AreEqual(isTrue, true);
		}

		TEST_METHOD(Test_Regex_EXAMPLE_REGEX)
		{
			//单词匹配
			string base = "$機構いじり／随意改动组织机构jīgòu.$";
			smatch result;

			bool isTrue = regex_match(base, result, EXAMPLE_REGEX);
			Assert::AreEqual(isTrue, true);
		}

		TEST_METHOD(Test_Regex_SPACE_REGEX)
		{
			//单词匹配
			string base = "";
			smatch result;

			bool isTrue = regex_match(base, result, SPACE_REGEX);
			Assert::AreEqual(isTrue, true);
		}

		TEST_METHOD(Test_NLexAnalysis_word)
		{
			//单词匹配
			string base = "いじり";
			auto result = NLexAnalysis(base);

			auto isTrue = (result == N_WORD);
			Assert::AreEqual(isTrue, true);
		}


		TEST_METHOD(Test_NLexAnalysis_phonetic)
		{
			//单词匹配
			string base = "adagokoro あだごころ";
			auto result = NLexAnalysis(base);

			auto isTrue = (result == N_PHONETIC);
			Assert::AreEqual(isTrue, true);
		}


		TEST_METHOD(Test_NLexAnalysis_space)
		{
			//单词匹配
			string base = "";
			auto result = NLexAnalysis(base);

			auto isTrue = (result == N_SPACE);
			Assert::AreEqual(isTrue, true);
		}

		//单组单词测试
		TEST_METHOD(Test_NValueProcess_1)
		{
			//单词匹配
			ifstream file("F:\\code\\Project\\Jp\\NINO_DICT\\NINO_TEST_FILE\\Test_NValueProcess_1.txt");
			
			
			if (file)
			{
				vector<string> result;
				NValueProcess(file, result);
			}
			else
			{
				int i = 0;
			}
			

		
			int i = 0;
		}

		
	};
}