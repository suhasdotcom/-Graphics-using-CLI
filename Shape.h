#ifndef SHAPE_H
#define SHAPE_H

#include "typedef.h"
#include <iostream>

namespace Grafix
{
	class Shape
	{
	public:
		virtual const Shape* Draw() const throw(std::bad_cast, std::bad_alloc, std::bad_exception) =0;
		virtual const bool is_closed() const =0;
		virtual const Shape* rotate(_s16cr =0) =0;										//rotate by a real angle
		virtual const Shape* resize(_s16cr ) =0;										//resize through a multiplier
		virtual const Shape* resize(_s16cr , _s16cr ) =0;								//resize by dimensions
		virtual const std::string toString() const =0;
//		virtual std::ostream operator<<(std::ostream &) const =0;
	};
}

#endif