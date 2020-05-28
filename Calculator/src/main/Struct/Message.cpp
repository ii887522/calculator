#include "Message.h"
#include <string>

using std::string;

namespace ii887522::Calculator
{
	Message::Message(const Head head, const string& body) : head{ head }, body{ body } { }
}