#ifndef TEST

#ifndef II887522_CALCULATOR_RADIAL_GRADIENT_H
#define II887522_CALCULATOR_RADIAL_GRADIENT_H

#include "../View/ResourceView.h"
#include "../Any/RadialGradientModel.h"
#include <SDL.h>
#include "../Any/Enums.h"
#include "../Struct/Size.h"

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

		RadialGradientModel viewModel;

	public:
		// Param renderer: it must not be assigned to integer
		explicit RadialGradient(SDL_Renderer*const renderer, const Size& parentSize);

		virtual Action reactMouseMotion(const SDL_MouseMotionEvent&) override;
		virtual void render() override;
	};
}

#endif
#endif