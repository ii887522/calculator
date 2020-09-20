#ifndef TEST

#include "CalcExprPaster.h"
#include "../Any/App.h"
#include "../Any/Scene.h"
#include "../Any/View.h"
#include "../Any/Enums.h"
#include "../Struct/Pair.h"
#include "../Struct/Message.h"
#include "../Any/CalcExprLexer.h"
#include "../Any/CalcExprValidator.h"
#include <stdexcept>
#include <vector>
#include "../Struct/Token.h"
#include <string>

using std::invalid_argument;
using std::vector;
using std::string;

namespace ii887522::Calculator
{
	CalcExprPaster::CalcExprPaster(App& app, Scene& thisScene) : View{ nullptr }, app{ app }, thisScene{ thisScene }, state{ State::RIGHT },
		savedI{ 0u }, tokenI{ 0u } { }

	void CalcExprPaster::runNumberChar(const char ch)
	{
		switch (ch)
		{
		case '0': thisScene.reactMessage(Message{ Message::Head::INPUT_0 });
			break;
		case '1': thisScene.reactMessage(Message{ Message::Head::INPUT_1 });
			break;
		case '2': thisScene.reactMessage(Message{ Message::Head::INPUT_2 });
			break;
		case '3': thisScene.reactMessage(Message{ Message::Head::INPUT_3 });
			break;
		case '4': thisScene.reactMessage(Message{ Message::Head::INPUT_4 });
			break;
		case '5': thisScene.reactMessage(Message{ Message::Head::INPUT_5 });
			break;
		case '6': thisScene.reactMessage(Message{ Message::Head::INPUT_6 });
			break;
		case '7': thisScene.reactMessage(Message{ Message::Head::INPUT_7 });
			break;
		case '8': thisScene.reactMessage(Message{ Message::Head::INPUT_8 });
			break;
		case '9': thisScene.reactMessage(Message{ Message::Head::INPUT_9 });
			break;
		case '.': thisScene.reactMessage(Message{ Message::Head::INPUT_DOT });
		}
	}

	void CalcExprPaster::runNumber(const string& value)
	{
		for (auto i{ value[0] == '-' ? 1u : 0u }; i != value.size(); ++i) runNumberChar(value[i]);
		if (value[0] == '-') thisScene.reactMessage(Message{ Message::Head::INPUT_SIGN });
	}

	void CalcExprPaster::runBinaryOperator(const char operatorCh)
	{
		switch (operatorCh)
		{
		case '+': thisScene.reactMessage(Message{ Message::Head::INPUT_PLUS });
			break;
		case '-': thisScene.reactMessage(Message{ Message::Head::INPUT_MINUS });
			break;
		case 'x': thisScene.reactMessage(Message{ Message::Head::INPUT_MULTIPLY });
			break;
		case '/': thisScene.reactMessage(Message{ Message::Head::INPUT_DIVIDE });
		}
	}

	void CalcExprPaster::runUnaryOperator(const string& operatorStr)
	{
		if (operatorStr == "sqr") thisScene.reactMessage(Message{ Message::Head::INPUT_SQR });
		else if (operatorStr == "sqrt") thisScene.reactMessage(Message{ Message::Head::INPUT_SQRT });
	}

	void CalcExprPaster::runToken(const Token& token)
	{
		switch (token.type)
		{
		case Token::Type::NUMBER: runNumber(token.value);
			break;
		case Token::Type::BINARY_OPERATOR: runBinaryOperator(token.value[0u]);
			break;
		case Token::Type::UNARY_OPERATOR: runUnaryOperator(token.value);
			break;
		case Token::Type::EQUAL: thisScene.reactMessage(Message{ Message::Head::INPUT_EQUAL });
		}
	}

	void CalcExprPaster::runWhenRight(const Token& token)
	{
		if (token.type == Token::Type::UNARY_OPERATOR) state = State::SEEK_NUMBER;
		else runToken(token);
		++tokenI;
	}

	void CalcExprPaster::runWhenSeekNumber(const Token& token)
	{
		if (token.type != Token::Type::NUMBER) ++tokenI;
		else
		{
			state = State::LEFT;
			savedI = tokenI + 1u;
		}
	}

	void CalcExprPaster::runWhenLeft(const Token& token)
	{
		switch (token.type)
		{
		case Token::Type::UNARY_OPERATOR:
		case Token::Type::LEFT_BRACKET:
		case Token::Type::NUMBER:
			runToken(token);
			--tokenI;
			break;
		default:
			state = State::RIGHT;
			tokenI = savedI;
		}
	}

	void CalcExprPaster::run(const vector<Token>& tokens)
	{
		tokenI = 0u;
		app.reactMessage(Message{ Message::Head::INPUT_C });
		while (tokenI != tokens.size())
		{
			switch (state)
			{
			case State::RIGHT: runWhenRight(tokens[tokenI]);
				break;
			case State::SEEK_NUMBER: runWhenSeekNumber(tokens[tokenI]);
				break;
			case State::LEFT: runWhenLeft(tokenI == UINT_MAX ? Token{ } : tokens[tokenI]);
			}
		}
	}

	Pair<Action, Message> CalcExprPaster::reactMessage(const Message& message)
	{
		if (message.head != Message::Head::PASTE_TO_CALC_RESULT) return Pair{ Action::NONE, Message{ } };
		const auto clipboardText{ SDL_GetClipboardText() };
		try
		{
			const auto tokens{ CalcExprLexer{ }.run(string{ clipboardText }) };
			if (!CalcExprValidator{ }.run(tokens)) throw invalid_argument{ "Invalid calculator expression! Please try again." };
			run(tokens);
		}
		catch (const invalid_argument&)
		{
			SDL_free(clipboardText);
			return Pair{ Action::NONE, Message{ Message::Head::ERROR } };
		}
		SDL_free(clipboardText);
		return Pair{ Action::NONE, Message{ } };
	}
}

#endif