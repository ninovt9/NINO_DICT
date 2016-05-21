




#pragma once

#include <string>
#include <tuple>
#include <vector>


namespace ninoDict
{
	class Word
	{
	public:
		Word();
		Word(std::wstring name, std::wstring phonetic,
			std::wstring meaning);
		Word(std::wstring name, std::wstring phonetic,
			std::wstring meaning, std::vector<std::wstring> example);

	public:
		std::wstring GetName();
		std::wstring GetPhonetic();
		std::wstring GetMeaning();
		std::vector<std::wstring> GetExample();

	private:
		std::wstring name_;
		std::wstring phonetic_;
		std::wstring meaning_;
		std::vector<std::wstring> example_;
	};

	inline std::wstring Word::GetName()
	{
		return name_;
	}
	inline std::wstring Word::GetPhonetic()
	{
		return phonetic_;
	}
	inline std::wstring Word::GetMeaning()
	{
		return meaning_;
	}
	inline std::vector<std::wstring> Word::GetExample()
	{
		return example_;
	}

}


