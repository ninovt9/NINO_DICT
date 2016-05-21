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

			Assert::AreEqual((*(iter)	== Token(TokenType::MEANING, L"焼き直し")),				true, L"meaning(焼き直し)");
			Assert::AreEqual((*(++iter) == Token(TokenType::LINEBREAK)),						true, L"linebreak_1");
			Assert::AreEqual((*(++iter) == Token(TokenType::LINEBREAK)),						true, L"linebreak_2");
			Assert::AreEqual((*(++iter) == Token(TokenType::MEANING, L"yakinaosi やきなおし")), true, L"meaning(yakinaosi やきなおし)");
			Assert::AreEqual((*(++iter) == Token(TokenType::LINEBREAK)),						true, L"linebreak_3");
			Assert::AreEqual((*(++iter) == Token(TokenType::MEANING, L"（1）〔もう一度焼くこと〕重烧chóng shāo,再zài烧,重烤kǎo.")),	true, L"meaning(（1）〔もう一度焼くこと〕重烧chóng shāo,再zài烧,重烤kǎo.)");
			Assert::AreEqual((*(++iter) == Token(TokenType::LINEBREAK)),						true, L"linebreak_4");
			Assert::AreEqual((*(++iter) == Token(TokenType::MEANING, L"（2）〔作品や文章の〕翻版fānbǎn,改写gǎixiě,改编gǎibiān.")),	true, L"meaning(（2）〔作品や文章の〕翻版fānbǎn,改写gǎixiě,改编gǎibiān.)");
			Assert::AreEqual((*(++iter) == Token(TokenType::LINEBREAK)),						true, L"linebreak_5");
			Assert::AreEqual((*(++iter) == Token(TokenType::EXAMPLE, L"$これはゲーテの詩の焼き直しだ／这是歌德的诗的翻版.")),		true, L"example($これはゲーテの詩の焼き直しだ／这是歌德的诗的翻版.)");
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
				stream.get();	// 跳过utf-8标识字节
			}

			Assert::AreEqual((scanner.GetNextLine(stream) == ( L"あいうえお")),		true, L"Line:あいうえお");
			Assert::AreEqual((scanner.GetNextLine(stream)+L"1" == (L"1")),			true, L"Line:\n");			
			Assert::AreEqual((scanner.GetNextLine(stream) == (L"らりるれろ")),		true, L"Line:らりるれろ");
		}


		TEST_METHOD(Test_GetToken)
		{
			Scanner scanner;
			std::wifstream stream(TEST_PATH + L"Test_Scanner_GetToken.txt");
			stream.imbue(scanner.GetUtf8());
			stream.get();

			Assert::AreEqual((scanner.GetToken(stream) == Token(TokenType::MEANING, L"外事")),	true,	L"line_1 : meaning(外事)");
			Assert::AreEqual((scanner.GetToken(stream) == Token(TokenType::LINEBREAK)),			true,	L"line_2 : linebreak");
			Assert::AreEqual((scanner.GetToken(stream) == Token(TokenType::LINEBREAK)),			true,	L"line_3 : linebreak");
			Assert::AreEqual((scanner.GetToken(stream) == Token(TokenType::MEANING, L"gaiji がいじ")),	true,	L"line_4 : meaning(gaiji がいじ)");
			Assert::AreEqual((scanner.GetToken(stream) == Token(TokenType::LINEBREAK)),			true,	L"line_5: linebreak");
			Assert::AreEqual((scanner.GetToken(stream) == Token(TokenType::MEANING, L"外事wàishì.")),	true,	L"line_6 : meaning(外事wàishì.)");
			Assert::AreEqual((scanner.GetToken(stream) == Token(TokenType::LINEBREAK)),			true,	L"line_7: linebreak");
			Assert::AreEqual((scanner.GetToken(stream) == Token(TokenType::EXAMPLE, L"$外事課／（警察署的）外事科.")),	true,	L"line_8 : example($外事課／（警察署的）外事科.)");

			// Example
			stream = std::wifstream(TEST_PATH + L"Test_Example.txt");
			stream.imbue(scanner.GetUtf8());
			stream.get();

			Assert::AreEqual((scanner.GetToken(stream) == Token(TokenType::EXAMPLE, L"$経済上の利益／经济上的利益lìyì.")), true, L"line_1 : example($経済上の利益／经济上的利益lìyì.)");
			Assert::AreEqual((scanner.GetToken(stream) == Token(TokenType::EXAMPLE, L"$それは経済上許されない／这件事经济上办不到.")), true, L"line_1 : example($それは経済上許されない／这件事经济上办不到.)");

		}


		
		




	};
}