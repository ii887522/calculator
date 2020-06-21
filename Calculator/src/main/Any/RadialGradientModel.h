#ifndef II887522_CALCULATOR_RADIAL_GRADIENT_MODEL_H
#define II887522_CALCULATOR_RADIAL_GRADIENT_MODEL_H

#include "../Struct/Point.h"
#include "../Struct/Size.h"
#include "../Functions/math_ext.h"
#include "../Struct/Rect.h"
#include "../Struct/Flow.h"
#include "../Struct/Range.h"

namespace ii887522::Calculator
{
	// Not Thread Safe
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

		explicit constexpr RadialGradientModel(const Size& parentSize, const Size& size) : parentSize{ parentSize }, size{ size },
			a{ 255u }, position{ 1024, 1024 } /* 1024, 1024 to hide it */ { }

		constexpr void reactMouseMotion(const Point& mousePosition)
		{
			follow(mousePosition);
			constexpr auto fadingBorderWidth{ 16 };
			if (isOverlap(mousePosition, Rect{ Point{ 0, 0 }, Size{ fadingBorderWidth, fadingBorderWidth } }))
			{
				if (mousePosition.x < mousePosition.y)
					a = static_cast<unsigned int>(map(static_cast<float>(mousePosition.x), Flow<const Range<const float>>{
						Range<const float>{ 0.f, fadingBorderWidth }, Range<const float>{ 0.f, 255.f } }));
				else
					a = static_cast<unsigned int>(map(static_cast<float>(mousePosition.y), Flow<const Range<const float>>{
						Range<const float>{ 0.f, fadingBorderWidth }, Range<const float>{ 0.f, 255.f } }));
			}
			else if (isOverlap(mousePosition, Rect{ Point{ fadingBorderWidth, 0 }, Size{ parentSize.w - (fadingBorderWidth << 1u),
				fadingBorderWidth } }))
			{
				a = static_cast<unsigned int>(map(static_cast<float>(mousePosition.y), Flow<const Range<const float>>{
					Range<const float>{ 0.f, fadingBorderWidth }, Range<const float>{ 0.f, 255.f } }));
			}
			else if (isOverlap(mousePosition, Rect{ Point{ parentSize.w - fadingBorderWidth, 0 }, Size{ fadingBorderWidth,
				fadingBorderWidth } }))
			{
				if (parentSize.w - mousePosition.x < mousePosition.y)
					a = static_cast<unsigned int>(map(static_cast<float>(mousePosition.x), Flow<const Range<const float>>{
						Range<const float>{ static_cast<float>(parentSize.w - fadingBorderWidth), static_cast<float>(parentSize.w) },
						Range<const float>{ 255.f, 0.f } }));
				else
					a = static_cast<unsigned int>(map(static_cast<float>(mousePosition.y), Flow<const Range<const float>>{
						Range<const float>{ 0.f, fadingBorderWidth }, Range<const float>{ 0.f, 255.f } }));
			}
			else if (isOverlap(mousePosition, Rect{ Point{ parentSize.w - fadingBorderWidth, fadingBorderWidth },
				Size{ fadingBorderWidth, parentSize.h - (fadingBorderWidth << 1u) } }))
			{
				a = static_cast<unsigned int>(map(static_cast<float>(mousePosition.x), Flow<const Range<const float>>{
					Range<const float>{ static_cast<float>(parentSize.w - fadingBorderWidth), static_cast<float>(parentSize.w) },
					Range<const float>{ 255.f, 0.f } }));
			}
			else if (isOverlap(mousePosition, Rect{ Point{ parentSize.w - fadingBorderWidth, parentSize.h - fadingBorderWidth },
				Size{ fadingBorderWidth, fadingBorderWidth } }))
			{
				if (parentSize.w - mousePosition.x < parentSize.h - mousePosition.y)
					a = static_cast<unsigned int>(map(static_cast<float>(mousePosition.x), Flow<const Range<const float>>{
						Range<const float>{ static_cast<float>(parentSize.w - fadingBorderWidth), static_cast<float>(parentSize.w) },
						Range<const float>{ 255.f, 0.f } }));
				else
					a = static_cast<unsigned int>(map(static_cast<float>(mousePosition.y), Flow<const Range<const float>>{
						Range<const float>{ static_cast<float>(parentSize.h - fadingBorderWidth), static_cast<float>(parentSize.h) },
						Range<const float>{ 255.f, 0.f } }));
			}
			else if (isOverlap(mousePosition, Rect{ Point{ fadingBorderWidth, parentSize.h - fadingBorderWidth },
				Size{ parentSize.w - (fadingBorderWidth << 1u), fadingBorderWidth } }))
			{
				a = static_cast<unsigned int>(map(static_cast<float>(mousePosition.y), Flow<const Range<const float>>{
					Range<const float>{ static_cast<float>(parentSize.h - fadingBorderWidth), static_cast<float>(parentSize.h) },
					Range<const float>{ 255.f, 0.f } }));
			}
			else if (isOverlap(mousePosition, Rect{ Point{ 0, parentSize.h - fadingBorderWidth }, Size{ fadingBorderWidth,
				fadingBorderWidth } }))
			{
				if (mousePosition.x < parentSize.h - mousePosition.y)
					a = static_cast<unsigned int>(map(static_cast<float>(mousePosition.x), Flow<const Range<const float>>{
						Range<const float>{ 0.f, fadingBorderWidth }, Range<const float>{ 0.f, 255.f } }));
				else
					a = static_cast<unsigned int>(map(static_cast<float>(mousePosition.y), Flow<const Range<const float>>{
						Range<const float>{ static_cast<float>(parentSize.h - fadingBorderWidth), static_cast<float>(parentSize.h) },
						Range<const float>{ 255.f, 0.f } }));
			}
			else if (isOverlap(mousePosition, Rect{ Point{ 0, fadingBorderWidth }, Size{ fadingBorderWidth, parentSize.h -
				(fadingBorderWidth << 1u) } }))
			{
				a = static_cast<unsigned int>(map(static_cast<float>(mousePosition.x), Flow<const Range<const float>>{
					Range<const float>{ 0.f, fadingBorderWidth }, Range<const float>{ 0.f, 255.f } }));
			}
			else a = 255u;
		}

		constexpr void reactMouseLeaveWindow()
		{
			a = 0u;
		}
	};
}

#endif