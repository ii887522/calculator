#ifndef TEST

#ifndef II887522_CALCULATOR_NAV_BAR_H
#define II887522_CALCULATOR_NAV_BAR_H

#include "../Any/View.h"
#include <SDL.h>
#include "../Struct/Size.h"

namespace ii887522::Calculator
{
	// Not Thread Safe: it must only be used in main thread
	class NavBar final : public View
	{
		// remove copy semantics
		NavBar(const NavBar&) = delete;
		NavBar& operator=(const NavBar&) = delete;

		// remove move semantics
		NavBar(NavBar&&) = delete;
		NavBar& operator=(NavBar&&) = delete;

		const Size size;

	public:
		// Param renderer: it must not be assigned to integer
		explicit NavBar(SDL_Renderer*const renderer, const Size&);

		virtual void render() override;
	};
}

#endif
#endif