#ifndef POINT_H
#define POINT_H

#ifdef _WIN32
#include "typedef.h"
#include "Manifest.h"
#else
#error: File Created for 32-bit Windows Only
#endif

#ifdef __cplusplus
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;
namespace Grafix
{
#endif	

	typedef class Point point;

	static class _Cursor
	{
	private:
		static volatile _uc8 _x;
		static volatile _uc8 _z;
		static volatile _us16 _y;
		friend class Point;
	public:
		_Cursor& current()
		{	return *this;}
		const _Cursor& current() const
		{	return *this;}
	}cursor;

	typedef class Point
	{
	private:
		_uc8 _ch;
		_uc8 _x, _z;
		_us16 _y;
		_b8 _enclosed;
		static _us16c _x_max=__WIDTH_CONSTANT;
		static _us16c _y_max=__HEIGHT_CONSTANT*2;
		static _uc8c _z_max= __LOWEST_PRIORITY_CONSTANT;
	public:
		Point(_uc8cr _x=0, _us16cr _y=0, _uc8cr _z=0, _uc8cr _ch=0, _b8cr _is_Enclosed=false) : _x(_x<=_x_max?_x:0), _y(_y<=_y_max?_y/2:0), _z(_z<=_z_max?_z:0), _ch(_ch), _enclosed(_is_Enclosed){}
		void show(char)	const;
		void show()	const;
		operator char() const {return _ch;}
		_uc8c isEnclosed() const {return _enclosed;}
		_uc8c get_priority() const {return _z;}
		_us16c get_x() const {return _x;}
		_us16c get_y() const {return _y;}
		friend ostream& operator<<(ostream &out, const Point &p)
		{
			out<<"x="<<static_cast<_us16>(p._x)<<"\ty="<<p._y<<"\tz="<<static_cast<_us16>(p._z);
			return out;
		}
		const point& operator=(const point &p)
		{
			this->_x = p._x;
			this->_y = p._y;
			this->_z = p._z;
			this->_enclosed = p._enclosed;
			this->_ch = p._ch;
			return *this;
		}
	}point;
#ifdef __cplusplus
}
using namespace::Grafix;
#endif

#endif