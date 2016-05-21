#include "stdafx.h"
#include "CppUnitTest.h"
#include "Scanner.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ninoDict;

using std::wifstream;

const std::wstring TEST_PATH = L"D:\\code\\Project\\Jp\\NINO_DICT\\NINO_TEST_DICT\\";

namespace NINO_TEST_DICT
{
	TEST_CLASS(TestScanner)
	{
	public:



		TEST_METHOD(Test_Class_Init)
		{
			// open file
			Scanner scanner(TEST_PATH + L"I'm error.txt");
			Assert::AreEqual(scanner.GetErrorReport().size(), static_cast<size_t>(1), L"file error");
		
		}

		TEST_METHOD(Test_Class_GetTokenList)
		{
			Scanner scanner(TEST_PATH + L"Test_Scanner_GetTokenList.txt");
			auto tokenList = scanner.GetTokenList();
			auto iter = tokenList.begin();

			Assert::AreEqual((*(iter)	== Token(TokenType::MEANING, L"����ֱ��")),				true, L"meaning(����ֱ��)");
			Assert::AreEqual((*(++iter) == Token(TokenType::LINEBREAK)),						true, L"linebreak_1");
			Assert::AreEqual((*(++iter) == Token(TokenType::LINEBREAK)),						true, L"linebreak_2");
			Assert::AreEqual((*(++iter) == Token(TokenType::MEANING, L"yakinaosi �䤭�ʤ���")), true, L"meaning(yakinaosi �䤭�ʤ���)");
			Assert::AreEqual((*(++iter) == Token(TokenType::LINEBREAK)),						true, L"linebreak_3");
			Assert::AreEqual((*(++iter) == Token(TokenType::MEANING, L"��1�����⤦һ�ȟ������ȡ�����ch��ng sh��o,��z��i��,�ؿ�k��o.")),	true, L"meaning(��1�����⤦һ�ȟ������ȡ�����ch��ng sh��o,��z��i��,�ؿ�k��o.)");
			Assert::AreEqual((*(++iter) == Token(TokenType::LINEBREAK)),						true, L"linebreak_4");
			Assert::AreEqual((*(++iter) == Token(TokenType::MEANING, L"��2������Ʒ�����¤Ρ�����f��nb��n,��дg��ixi��,�ı�g��ibi��n.")),	true, L"meaning(��2������Ʒ�����¤Ρ�����f��nb��n,��дg��ixi��,�ı�g��ibi��n.)");
			Assert::AreEqual((*(++iter) == Token(TokenType::LINEBREAK)),						true, L"linebreak_5");
			Assert::AreEqual((*(++iter) == Token(TokenType::EXAMPLE, L"$����ϥ��`�Ƥ�Ԋ�Ο���ֱ���������Ǹ�µ�ʫ�ķ���.")),		true, L"example($����ϥ��`�Ƥ�Ԋ�Ο���ֱ���������Ǹ�µ�ʫ�ķ���.)");
			Assert::AreEqual((*(++iter) == Token(TokenType::LINEBREAK)),						true, L"linebreak_6");



		}

		TEST_METHOD(Test_GetNextChar)
		{
			Scanner scanner;
			std::wifstream stream(TEST_PATH + L"Test_GetNextChar.txt");  //input

			wchar_t a;

			if (stream.fail())
			{
				Assert::Fail(L"Failed to open file");
			}
			else
			{
				stream.imbue(scanner.GetUtf8());
				stream.get();	// ����utf-8��ʶ�ֽ�
			}

			Assert::AreEqual((scanner.GetNextLine(stream) == ( L"����������")),		true, L"Line:����������");
			Assert::AreEqual((scanner.GetNextLine(stream)+L"1" == (L"1")),			true, L"Line:\n");			
			Assert::AreEqual((scanner.GetNextLine(stream) == (L"������")),		true, L"Line:������");
		}


		TEST_METHOD(Test_GetToken)
		{
			Scanner scanner;
			std::wifstream stream(TEST_PATH + L"Test_Scanner_GetToken.txt");
			stream.imbue(scanner.GetUtf8());
			stream.get();

			Assert::AreEqual((scanner.GetToken(stream) == Token(TokenType::MEANING, L"����")),	true,	L"line_1 : meaning(����)");
			Assert::AreEqual((scanner.GetToken(stream) == Token(TokenType::LINEBREAK)),			true,	L"line_2 : linebreak");
			Assert::AreEqual((scanner.GetToken(stream) == Token(TokenType::LINEBREAK)),			true,	L"line_3 : linebreak");
			Assert::AreEqual((scanner.GetToken(stream) == Token(TokenType::MEANING, L"gaiji ������")),	true,	L"line_4 : meaning(gaiji ������)");
			Assert::AreEqual((scanner.GetToken(stream) == Token(TokenType::LINEBREAK)),			true,	L"line_5: linebreak");
			Assert::AreEqual((scanner.GetToken(stream) == Token(TokenType::MEANING, L"����w��ish��.")),	true,	L"line_6 : meaning(����w��ish��.)");
			Assert::AreEqual((scanner.GetToken(stream) == Token(TokenType::LINEBREAK)),			true,	L"line_7: linebreak");
			Assert::AreEqual((scanner.GetToken(stream) == Token(TokenType::EXAMPLE, L"$�����n����������ģ����¿�.")),	true,	L"line_8 : example($�����n����������ģ����¿�.)");

			// Example
			stream = std::wifstream(TEST_PATH + L"Test_Example.txt");
			stream.imbue(scanner.GetUtf8());
			stream.get();

			Assert::AreEqual((scanner.GetToken(stream) == Token(TokenType::EXAMPLE, L"$�U�g�Ϥ����棯�����ϵ�����l��y��.")), true, L"line_1 : example($�U�g�Ϥ����棯�����ϵ�����l��y��.)");
			Assert::AreEqual((scanner.GetToken(stream) == Token(TokenType::EXAMPLE, L"$����ϽU�g���S����ʤ�������¾����ϰ첻��.")), true, L"line_1 : example($����ϽU�g���S����ʤ�������¾����ϰ첻��.)");

		}


		
		




	};
}