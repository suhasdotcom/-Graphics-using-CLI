#include "Window.h"
#include <algorithm>

using namespace::Grafix;
using std::for_each;

const point Window::fill_blanks(_uc8cr _left_c, _us16cr _left_r)
{
	_uc8 i=_left_c;
	for(;i<__WIDTH_CONSTANT; i++)
		win.push_back(point(i, _left_r, __priority, ' ', false));
	return point(i, _left_r, __priority, ' ', false);
}

Window::Window(_uc8cr __x, _us16cr __y, _uc8cr __h, _us16cr __w, const string Title, _uc8cr __s, _uc8cr __p, const string name)
	try
	: _x(__x),
	_y(__y),
	_z(__p),
	__priority(__p),
	_style(__s),
	__name(name),
	_Title(Title),
	__id(_id()++)
{
	_uc8 i=0, cursor_i=0;
	_us16 j=0, cursor_j=0;
	for(; j<__y/2;j++, cursor_j++) fill_blanks(cursor_i, cursor_j);
	//	win.push_back(point(cursor_i, cursor_j*2, __p, '\n'));
	for(; i<__x; i++, cursor_i++)
		win.push_back(point(cursor_i, cursor_j*2, __priority, 0));
	win.push_back(point(cursor_i, cursor_j*2, __priority, _style==__BOLD?475:434, true));
	for(i=0; i<__w; i++, cursor_i++)
		win.push_back(point(cursor_i, cursor_j*2, __priority, _style==__BOLD?i==__w-2?'X':i==__w-3?477:i==__w-4?478:475:i==__w-2?'x':434, true));
//	win.push_back(point(cursor_i++, cursor_j++*2, __priority, '\n'));
	fill_blanks(++cursor_i, cursor_j++);
	for(j=0; j<__h/2; j++, cursor_j++)
	{
		for(i=0; i<=__x+__w; i++)
		{
			if(!j && i==__x || !j && i==__x+__w)
				win.push_back(point(cursor_i, cursor_j*2, __priority, _style==__BOLD?434:(i==__x?474:447), true));
			else if(j<__h/3 && (i==__x || i==__x+__w))
				win.push_back(point(cursor_i, cursor_j*2, __priority, _style==__BOLD?433:435, true));
			else if(i==__x || i==__x+__w)
				win.push_back(point(cursor_i, cursor_j*2, __priority, _style==__BOLD?432:(j==__h/2-1?i==__x?448:473:435), true));	//473
			else if(j==__h/2-1 && i>=__x)
				win.push_back(point(cursor_i, cursor_j*2, __priority, _style==__BOLD?476:452, true));
			else
				win.push_back(point(cursor_i, cursor_j*2, __priority, ' ', true));
		}
		cursor_i=i;
		fill_blanks(cursor_i, cursor_j);
	//	win.push_back(point(cursor_i, cursor_j*2, __p, '\n'));
	}
	for(;j<__HEIGHT_CONSTANT2; j++, cursor_j++) fill_blanks(cursor_i=cursor_i==__WIDTH_CONSTANT?0:cursor_i, cursor_j);
//	for_each(win.begin(), win.end(), [&](const point &p){cout<<static_cast<char>(p);});
}
catch(std::exception &e)
{
	cout<<endl<<e.what()<<endl;
}

//ostream& Window::operator<<(ostream &out) const
//{
////	return out;
//}

const Shape* Window::Draw() const throw(std::bad_cast, std::bad_exception)
{
	std::string str;
	for_each(win.begin(), win.end(), [&str](const point &p) {str.push_back(static_cast<char>(p));});
	cout<<str;//toString();
	return dynamic_cast<const Shape*>(this);									//throws bad_cast
}

inline const string Window::toString() const
{
	std::string str;
	for_each(win.begin(), win.end(), [&str](const point &p) {str.push_back(static_cast<char>(p));});
	return str;
}