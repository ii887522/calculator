#ifndef II887522_CALCULATOR_MESSAGE_H
#define II887522_CALCULATOR_MESSAGE_H

#include <string>

using std::string;

namespace ii887522::Calculator
{
	struct Message final
	{
		enum class Head : unsigned int
		{
			EMPTY,
			INPUT_LEFT, INPUT_SQR, INPUT_SQRT, INPUT_RIGHT,
			INPUT_CE, INPUT_C, INPUT_BACKSPACE, INPUT_DIVIDE,
			INPUT_7, INPUT_8, INPUT_9, INPUT_MULTIPLY,
			INPUT_4, INPUT_5, INPUT_6, INPUT_MINUS,
			INPUT_1, INPUT_2, INPUT_3, INPUT_PLUS,
			INPUT_SIGN, INPUT_0, INPUT_DOT, INPUT_EQUAL
		};

		// remove move semantics
		Message(Message&&) = delete;
		Message& operator=(Message&&) = delete;

		Head head;
		string body;

		explicit Message(const Head head = Head::EMPTY, const string& body = "");
		Message(const Message&) = default;
		Message& operator=(const Message&) = default;
	};
}

#endif