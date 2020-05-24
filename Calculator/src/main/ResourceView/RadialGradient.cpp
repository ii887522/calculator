#ifndef TEST

#include "RadialGradient.h"
#include "../View/ResourceView.h"
#include <SDL.h>
#include <SDL_image.h>
#include "../Struct/Point.h"

namespace ii887522::Calculator
{
	RadialGradient::RadialGradient(SDL_Renderer*const renderer) :
		ResourceView{ renderer, IMG_Load("res/main/radial_gradient.png"), Point{ 1024, 1024 } } /* 1024, 1024 to hide it */ { }


}

#endif