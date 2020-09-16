#include "CalcScreenModel.h"
#include "../Struct/Rect.h"

namespace ii887522::Calculator
{
	CalcScreenModel::CalcScreenModel(const Rect& calcResultRect) : calcResultRect{ calcResultRect }, state{ State::INITIAL } { }
}