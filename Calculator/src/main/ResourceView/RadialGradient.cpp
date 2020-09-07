#ifndef TEST

#include "RadialGradient.h"
#include "../View/ResourceView.h"
#include "../Any/RadialGradientModel.h"
#include <SDL.h>
#include <SDL_image.h>
#include "../Struct/Point.h"
#include "../Any/Enums.h"
#include "../Struct/Size.h"

namespace ii887522::Calculator
{
	RadialGradient::RadialGradient(SDL_Renderer*const renderer, const Size& parentSize) :
		ResourceView{ renderer, IMG_Load("res/main/radial_gradient.png"), Point{ 1024, 1024 } } /* 1024, 1024 to hide it */,
		viewModel{ parentSize, Size{ getSurface()->w, getSurface()->h } } { }

	Action RadialGradient::reactMouseMotion(const SDL_MouseMotionEvent& motionEvent)
	{
		viewModel.reactMouseMotion(Point{ motionEvent.x, motionEvent.y });
		return Action::NONE;
	}

	Action RadialGradient::reactMouseLeaveWindow(const SDL_WindowEvent&)
	{
		viewModel.reactMouseLeaveWindow();
		return Action::NONE;
	}

	void RadialGradient::render()
	{
		SDL_SetTextureAlphaMod(getTexture(), static_cast<Uint8>(viewModel.getA()));
		const SDL_Rect rect{ viewModel.getPosition().x, viewModel.getPosition().y, getSurface()->w, getSurface()->h };
		SDL_RenderCopy(getRenderer(), getTexture(), nullptr, &rect);
	}
}

#endif