#ifndef II887522_CALCULATOR_BUTTON_MODEL_H
#define II887522_CALCULATOR_BUTTON_MODEL_H

namespace ii887522::Calculator
{
	// 
	class ButtonModel final
	{
		// remove copy semantics
		ButtonModel(const ButtonModel&) = delete;
		ButtonModel& operator=(const ButtonModel&) = delete;

		// remove move semantics
		ButtonModel(ButtonModel&&) = delete;
		ButtonModel& operator=(ButtonModel&&) = delete;



	public:
		// 
		explicit constexpr ButtonModel() { }


	};
}

#endif