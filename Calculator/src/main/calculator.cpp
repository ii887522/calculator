#ifndef TEST

#include <SDL.h>
#include "App.h"

namespace ii887522::Calculator
{
	static int main(int, char**)
	{
		const App app;
		return 0;
	}
}

int main(int argc, char** argv)
{
	return ii887522::Calculator::main(argc, argv);
}

#endif