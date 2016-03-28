#include "stdafx.h"
#include "CppUnitTest.h"
#include "../ServerChat/AccountRepository.h"
#include"../ServerChat/Parse.h"
//#include<string>
//using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestSever
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		

		TEST_METHOD(TesBus)
		{
			AccountRepository ar;
			Assert::IsTrue(ar.Check("email", "1"));

		}

		//TEST_METHOD(TesSum)
		//{
		//	
		//	Assert::AreEqual(5, 2+3);

		//}
		//TEST_METHOD(TestInsetUsesr)
		//{
		//

		//}
		//TEST_METHOD(TesParseJson)
		//{
		//	Parse j;
		//	string exptected = "JohnDoe";
		//	string s = "{\"type\":1,\"username\":\"John\",\"password\":\"Doe\"}";
		//	string actual = j.ParseJson(s);
		//	bool t = exptected.compare(actual);
		//	Assert::IsTrue(t);

		//}
		//TEST_METHOD(TesParseJson1)
		//{
	
		//	Parse j;
		//	string s  = "{\"type\":1,\"result\":true}";
		//	Assert::IsTrue( j.ParseBool(s));
		//	
		//}


	};
}