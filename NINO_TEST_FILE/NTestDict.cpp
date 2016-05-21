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
			//����ƥ��
			string base = "-C";
			smatch result;

			bool isTrue = regex_match(base, result, WORD_REGEX);
			Assert::AreEqual(isTrue, true);
		}

		TEST_METHOD(Test_Regex_WORD_REGEX_hiragana)
		{
			//����ƥ��
			string base = "������";
			smatch result;

			bool isTrue = regex_match(base, result, WORD_REGEX);
			Assert::AreEqual(isTrue, true);
		}

		TEST_METHOD(Test_Regex_WORD_REGEX_kannji)
		{
			//����ƥ��
			string base = "�C����";
			smatch result;

			bool isTrue = regex_match(base, result, WORD_REGEX);
			Assert::AreEqual(isTrue, true);
		}


		TEST_METHOD(Test_Regex_PHONETIC_REGEX)
		{
			//����ƥ��
			string base = "-ijiri �\������";
			smatch result;

			bool isTrue = regex_match(base, result, PHONETIC_REGEX);
			Assert::AreEqual(isTrue, true);
		}

		TEST_METHOD(Test_Regex_MEANING_REGEX)
		{
			//����ƥ��
			string base = "��1�������Τ褦�Ǥ��롳����l��is��,��Чf��ngxi��o, ����d��iy��u����������de y��ngzi.";
			smatch result;

			bool isTrue = regex_match(base, result, MEANING_REGEX);
			Assert::AreEqual(isTrue, true);
		}

		TEST_METHOD(Test_Regex_EXAMPLE_REGEX)
		{
			//����ƥ��
			string base = "$�C�������꣯����Ķ���֯����j��g��u.$";
			smatch result;

			bool isTrue = regex_match(base, result, EXAMPLE_REGEX);
			Assert::AreEqual(isTrue, true);
		}

		TEST_METHOD(Test_Regex_SPACE_REGEX)
		{
			//����ƥ��
			string base = "";
			smatch result;

			bool isTrue = regex_match(base, result, SPACE_REGEX);
			Assert::AreEqual(isTrue, true);
		}

		TEST_METHOD(Test_NLexAnalysis_word)
		{
			//����ƥ��
			string base = "������";
			auto result = NLexAnalysis(base);

			auto isTrue = (result == N_WORD);
			Assert::AreEqual(isTrue, true);
		}


		TEST_METHOD(Test_NLexAnalysis_phonetic)
		{
			//����ƥ��
			string base = "adagokoro ����������";
			auto result = NLexAnalysis(base);

			auto isTrue = (result == N_PHONETIC);
			Assert::AreEqual(isTrue, true);
		}


		TEST_METHOD(Test_NLexAnalysis_space)
		{
			//����ƥ��
			string base = "";
			auto result = NLexAnalysis(base);

			auto isTrue = (result == N_SPACE);
			Assert::AreEqual(isTrue, true);
		}

		//���鵥�ʲ���
		TEST_METHOD(Test_NValueProcess_1)
		{
			//����ƥ��
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