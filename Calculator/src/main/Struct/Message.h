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
			EMPTY
		};

		// remove copy semantics
		Message(const Message&) = delete;
		Message& operator=(const Message&) = delete;

		// remove move semantics
		Message(Message&&) = delete;
		Message& operator=(Message&&) = delete;

		const Head head;
		const string body;

		explicit Message(const Head head = Head::EMPTY, const string& body = "");
	};
}

#endif