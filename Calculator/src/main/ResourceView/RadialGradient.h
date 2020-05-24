#ifndef TEST

#ifndef II887522_CALCULATOR_RADIAL_GRADIENT_H
#define II887522_CALCULATOR_RADIAL_GRADIENT_H

#include "../View/ResourceView.h"
#include <SDL.h>

namespace ii887522::Calculator
{
	// Not Thread Safe: it must only be used in main thread
	class RadialGradient final : public ResourceView
	{
		// remove copy semantics
		RadialGradient(const RadialGradient&) = delete;
		RadialGradient& operator=(const RadialGradient&) = delete;

		// remove move semantics
		RadialGradient(RadialGradient&&) = delete;
		RadialGradient& operator=(RadialGradient&&) = delete;



	public:
		// Param renderer: it must not be assigned to intger
		explicit RadialGradient(SDL_Renderer*const renderer);
	};
}

#endif
#endif