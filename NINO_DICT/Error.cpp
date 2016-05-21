#include "stdafx.h"
#include "Error.h"


namespace ninoDict
{
	void ErrorFile(const std::wstring& msg, std::vector<std::wstring>& errorReport)
	{
		errorReport.push_back(L"FileError: " + msg);
	}

}