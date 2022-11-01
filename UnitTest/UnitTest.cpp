#include "CppUnitTest.h"
#include "..\Grysha4kr\Algoritm.cpp"
#include "..\Grysha4kr\Algoritm.h"
#include "..\Grysha4kr\Check.h"
#include "..\Grysha4kr\Check.cpp"
#include "..\Grysha4kr\File.h"
#include "..\Grysha4kr\File.cpp"
#include "..\Grysha4kr\PersonalInterface.h"
#include "..\Grysha4kr\PersonalInterface.cpp"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	private:
		int testNumb = 3;
		std::string testWord = "é";
		std::string testText[3] = { "é", "é","é" };
		int testSize = 5;
		std::vector<std::pair<std::string, int>> vec;
		std::map<std::string, int> statistic_mp;
	public:

		TEST_METHOD(TestMethod1)
		{
			WordsCheck(testSize, testText, vec, statistic_mp);
			Assert::IsTrue(vec[0].first == "é" && vec[0].second == 3);
		}

	};
}
