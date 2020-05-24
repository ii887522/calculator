#ifndef II887522_CALCULATOR_RADIAL_GRADIENT_MODEL_H
#define II887522_CALCULATOR_RADIAL_GRADIENT_MODEL_H

#include "../Struct/Point.h"
#include "../Struct/Size.h"
#include "../Functions/math_ext.h"
#include "../Struct/Rect.h"

namespace ii887522::Calculator
{
	// 
	class RadialGradientModel final
	{
		// remove copy semantics
		RadialGradientModel(const RadialGradientModel&) = delete;
		RadialGradientModel& operator=(const RadialGradientModel&) = delete;

		// remove move semantics
		RadialGradientModel(RadialGradientModel&&) = delete;
		RadialGradientModel& operator=(RadialGradientModel&&) = delete;

		const Size parentSize;
		const Size size;

		constexpr void follow(const Point& mousePosition)
		{
			position.x = mousePosition.x - (size.w >> 1u);
			position.y = mousePosition.y - (size.h >> 1u);
		}

	public:
		unsigned int a;
		Point position;

		// 
		explicit constexpr RadialGradientModel(const Size& parentSize, const Size& size) : parentSize{ parentSize }, size{ size },
			a{ 255u }, position{ 1024, 1024 } /* 1024, 1024 to hide it */ { }

		constexpr void reactMouseMotion(const Point& mousePosition)
		{
			follow(mousePosition);
			constexpr auto fadingBorderWidth{ 16 };
			if (isOverlap(mousePosition, Rect{ Point{ 0, 0 }, Size{ fadingBorderWidth, fadingBorderWidth } }))
			{
				if (mousePosition.x < mousePosition.y)
				{

				}
				else
				{

				}
			}
			else if (isOverlap(mousePosition, Rect{ Point{ fadingBorderWidth, 0 }, Size{ parentSize.w - (fadingBorderWidth << 1u),
				fadingBorderWidth } }))
			{

			}
			else if (isOverlap(mousePosition, Rect{ Point{ parentSize.w - fadingBorderWidth, 0 }, Size{ fadingBorderWidth,
				fadingBorderWidth } }))
			{
				if (parentSize.w - mousePosition.x < mousePosition.y)
				{

				}
				else
				{

				}
			}
			else if (isOverlap(mousePosition, Rect{ Point{ parentSize.w - fadingBorderWidth, fadingBorderWidth },
				Size{ fadingBorderWidth, parentSize.h - (fadingBorderWidth << 1u) } }))
			{

			}
			else if (isOverlap(mousePosition, Rect{ Point{ parentSize.w - fadingBorderWidth, parentSize.h - fadingBorderWidth },
				Size{ fadingBorderWidth, fadingBorderWidth } }))
			{
				if (parentSize.w - mousePosition.x < parentSize.h - mousePosition.y)
				{

				}
			}
			else if (isOverlap(mousePosition, Rect{ Point{ fadingBorderWidth, parentSize.h - fadingBorderWidth },
				Size{ parentSize.w - (fadingBorderWidth << 1u), fadingBorderWidth } }))
			{

			}
			else if (isOverlap(mousePosition, Rect{ Point{ 0, parentSize.h - fadingBorderWidth }, Size{ fadingBorderWidth,
				fadingBorderWidth } }))
			{
				if (mousePosition.x < parentSize.h - mousePosition.y)
				{

				}
				else
				{

				}
			}
			else if (isOverlap(mousePosition, Rect{ Point{ 0, fadingBorderWidth }, Size{ fadingBorderWidth, parentSize.h -
				(fadingBorderWidth << 1u) } }))
			{

			}
			else a = 255u;
		}
	};
}

#endif