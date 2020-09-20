#ifdef TEST

#include "string_ext.test.h"
#include <cassert>
#include "../../main/Functions/string_ext.h"

namespace ii887522::Calculator
{
	static void testNegate()
	{
		assert(-string{ "0" } == "0");
		assert(-string{ "1" } == "-1");
		assert(-string{ "2" } == "-2");
		assert(-string{ "-2" } == "2");
		assert(-string{ "-20" } == "20");
		assert(-string{ "-21" } == "21");
		assert(-string{ "-31" } == "31");
		assert(-string{ "-310" } == "310");
		assert(-string{ "310" } == "-310");
	}

	static void testSizeIgnoreDash()
	{
		assert(sizeIgnoreDash("1") == 1u);
		assert(sizeIgnoreDash("10") == 2u);
		assert(sizeIgnoreDash("100") == 3u);
		assert(sizeIgnoreDash("-100") == 3u);
	}

	static void testNoTrailingDot()
	{
		{
			string numberStr{ "0" };
			noTrailingDot(numberStr);
			assert(numberStr == "0");
		}
		{
			string numberStr{ "1" };
			noTrailingDot(numberStr);
			assert(numberStr == "1");
		}
		{
			string numberStr{ "1." };
			noTrailingDot(numberStr);
			assert(numberStr == "1");
		}
		{
			string numberStr{ "1.0" };
			noTrailingDot(numberStr);
			assert(numberStr == "1.0");
		}
	}

	static void testGetNumberFromBinaryExpr()
	{
		assert(getNumberFromBinaryExpr("0 +") == 0.);
		assert(getNumberFromBinaryExpr("1 -") == 1.);
		assert(getNumberFromBinaryExpr("2.0 x") == 2.);
		assert(getNumberFromBinaryExpr("2.1 /") == 2.1);
		assert(getNumberFromBinaryExpr("2.2 =") == 2.2);
		assert(getNumberFromBinaryExpr("3.2 +") == 3.2);
		assert(getNumberFromBinaryExpr("3.21 -") == 3.21);
	}

	static void testNoTrailingZeros()
	{
		{
			string numberStr{ "0" };
			noTrailingZeros(numberStr);
			assert(numberStr == "0");
		}
		{
			string numberStr{ "1" };
			noTrailingZeros(numberStr);
			assert(numberStr == "1");
		}
		{
			string numberStr{ "1." };
			noTrailingZeros(numberStr);
			assert(numberStr == "1.");
		}
		{
			string numberStr{ "1.0" };
			noTrailingZeros(numberStr);
			assert(numberStr == "1.");
		}
		{
			string numberStr{ "1.1" };
			noTrailingZeros(numberStr);
			assert(numberStr == "1.1");
		}
		{
			string numberStr{ "1.10" };
			noTrailingZeros(numberStr);
			assert(numberStr == "1.1");
		}
		{
			string numberStr{ "1.01" };
			noTrailingZeros(numberStr);
			assert(numberStr == "1.01");
		}
		{
			string numberStr{ "1.00" };
			noTrailingZeros(numberStr);
			assert(numberStr == "1.");
		}
		{
			string numberStr{ "1.010" };
			noTrailingZeros(numberStr);
			assert(numberStr == "1.01");
		}
		{
			string numberStr{ "0.00" };
			noTrailingZeros(numberStr);
			assert(numberStr == "0.");
		}
	}

	static void testGetNumberFromUnaryExpr()
	{
		assert(getNumberFromUnaryExpr("sqr(0)") == 0.);
		assert(getNumberFromUnaryExpr("sqrt(1)") == 1.);
		assert(getNumberFromUnaryExpr("sqr(2.0)") == 2.);
		assert(getNumberFromUnaryExpr("sqr(2.1)") == 2.1);
		assert(getNumberFromUnaryExpr("sqr(2.2)") == 2.2);
		assert(getNumberFromUnaryExpr("sqr(3.2)") == 3.2);
		assert(getNumberFromUnaryExpr("sqr(3.21)") == 3.21);
	}

	static void testGetUnaryOperator()
	{
		assert(getUnaryOperator("a(0)") == "a");
		assert(getUnaryOperator("b(1)") == "b");
		assert(getUnaryOperator("c(2)") == "c");
		assert(getUnaryOperator("ca(20)") == "ca");
		assert(getUnaryOperator("cb(21)") == "cb");
		assert(getUnaryOperator("db(31)") == "db");
		assert(getUnaryOperator("dba(310)") == "dba");
	}

	static void testToString()
	{
		assert(toString(0., 7u) == "0");
		assert(toString(1., 7u) == "1");
		assert(toString(10., 7u) == "10");
		assert(toString(11., 7u) == "11");
		assert(toString(21., 7u) == "21");
		assert(toString(210., 7u) == "210");
		assert(toString(210.0, 7u) == "210");
		assert(toString(210.1, 7u) == "210.1");
		assert(toString(210.01, 7u) == "210.01");
		assert(toString(210.10, 7u) == "210.1");
		assert(toString(210.100, 7u) == "210.1");
		assert(toString(210.101, 7u) == "210.101");
		assert(toString(-210.101, 7u) == "-210.101");
		assert(toString(-210.101, 6u) == "-210.1");
		assert(toString(-210.101, 5u) == "-210.1");
		assert(toString(-210.101, 4u) == "-210");
		assert(toString(-210.101, 3u) == "-210");
		assert(toString(-210.101, 2u) == "MATH ERROR");
		assert(toString(-210.101, 1u) == "MATH ERROR");
		assert(toString(210.01, 6u) == "210.01");
		assert(toString(210.01, 5u) == "210");
		assert(toString(210.01, 3u) == "210");
		assert(toString(210.01, 2u) == "MATH ERROR");
		assert(toString(210.01, 1u) == "MATH ERROR");
	}

	void testStringExt()
	{
		testNegate();
		testSizeIgnoreDash();
		testNoTrailingDot();
		testGetNumberFromBinaryExpr();
		testNoTrailingZeros();
		testGetNumberFromUnaryExpr();
		testGetUnaryOperator();
		testToString();
	}
}

#endif