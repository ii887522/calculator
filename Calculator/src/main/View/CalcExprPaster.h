#ifndef TEST

#ifndef II887522_CALCULATOR_CALC_EXPR_PASTER_H
#define II887522_CALCULATOR_CALC_EXPR_PASTER_H

#include "../Any/View.h"
#include "../Any/App.h"
#include "../Any/Scene.h"
#include "../Any/Enums.h"
#include "../Struct/Pair.h"
#include "../Struct/Message.h"
#include <vector>
#include "../Struct/Token.h"
#include <string>

using std::vector;
using std::string;

namespace ii887522::Calculator
{
	// Not Thread Safe: it must only be used in main thread
	class CalcExprPaster final : public View
	{
		enum class State : unsigned int
		{
			RIGHT, SEEK_NUMBER, LEFT
		};

		// remove copy semantics
		CalcExprPaster(const CalcExprPaster&) = delete;
		CalcExprPaster& operator=(const CalcExprPaster&) = delete;

		// remove move semantics
		CalcExprPaster(CalcExprPaster&&) = delete;
		CalcExprPaster& operator=(CalcExprPaster&&) = delete;

		App& app;
		Scene& thisScene;
		State state;
		unsigned int savedI;
		unsigned int tokenI;

		void runNumberChar(const char);
		void runNumber(const string& value);
		void runBinaryOperator(const char operatorCh);
		void runUnaryOperator(const string& operatorStr);
		void runToken(const Token&);
		void runWhenRight(const Token&);
		void runWhenSeekNumber(const Token&);
		void runWhenLeft(const Token&);
		void run(const vector<Token>&);

	public:
		explicit CalcExprPaster(App&, Scene& thisScene);
		virtual Pair<Action, Message> reactMessage(const Message&) override;
	};
}

#endif
#endif