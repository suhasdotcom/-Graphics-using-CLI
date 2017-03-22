#ifndef WINDOW_H
#define WINDOW_H

#pragma once

#include <vector>
#include <algorithm>
#include <string>
#include "point.h"
#include "Shape.h"
#include "Manifest.h"

using std::vector;
using std::for_each;
using std::string;

namespace Grafix
{
	typedef class Window : public Shape
	{
	private:
		_uc8 _x, _z;
		_us16 _y;
		const string __name;
		static auto _id()->_uc8r											//static _uc8r _id()
		{
			static _uc8 i;
			return i;
		}
		_uc8c __id;
		string _Title;
		_uc8 _style;
		vector<point> win;
		_uc8 __priority;
		virtual const point fill_blanks(_uc8cr ,_us16cr);
	public:
		Window(_uc8cr x_start=0, 
			_us16cr y_start=0, 
			_uc8cr height=10, 
			_us16cr width=10, 
			const string Title=string("Title"), 
			_uc8cr style=__BOLD, 
			_uc8cr priority=__HIGHEST_PRIORITY_CONSTANT,
			const string name ="Window"+_uc8c(_id()));
		virtual const Shape* Draw() const throw(std::bad_cast, std::bad_exception);
		virtual const bool is_closed() const {return true;}
		virtual const Shape* rotate(_s16cr ) {return dynamic_cast<const Shape*>(this);}
		virtual const Shape* resize(_s16cr) {return dynamic_cast<const Shape*>(this);}
		virtual const Shape* resize(_s16cr, _s16cr) {return dynamic_cast<const Shape*>(this);}
		virtual const string toString() const;
		virtual const _uc8cr get_priority() const {return __priority;}
		virtual const bool set_priority(_uc8cr __p) { return (__priority=__p)?true:false;}
		virtual const _uc8cr get_style() const {return _style;}
		virtual const bool set_style(_uc8cr __s) { return (_style=__s)?true:false;}
		virtual const string& get_title() const {return _Title;}
		virtual const bool set_title(const string& __t) 
		{ 
			_Title=__t;
			if(_Title==__t)
				return true;
			return false;
		}
		const vector<point>& get_win() const	{return win;}
		_us16c get_id() const	{return static_cast<_us16c>(__id);}
		const string& get_name() const {return __name;}
		const Window& operator=(const Window &w)
		{
			this->_x = w._x;
			this->_z = w._z;
			this->_y = w._y;
			this->_Title = w._Title;
			this->_style = w._style;
			this->win = w.win;
			this->__priority = w.__priority;
			return *this;
		}
//		ostream& operator<<(ostream &) const;
	}window;
}
using namespace::Grafix;

#endif