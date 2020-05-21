#ifndef TEST

#ifndef II887522_CALCULATOR_SUBSYSTEMS_H
#define II887522_CALCULATOR_SUBSYSTEMS_H

namespace ii887522::Calculator
{
	// Not Thread Safe: it must only be used in main thread
	struct Subsystems final
	{
		// remove copy semantics
		Subsystems(const Subsystems&) = delete;
		Subsystems& operator=(const Subsystems&) = delete;

		// remove move semantics
		Subsystems(Subsystems&&) = delete;
		Subsystems& operator=(Subsystems&&) = delete;

		explicit Subsystems();
		~Subsystems();
	};
}

#endif
#endif