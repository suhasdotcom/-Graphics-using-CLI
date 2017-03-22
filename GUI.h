#ifndef GUI_H
#define GUI_H

#ifdef _WIN32
#include "Window.h"
#else
#error: File Created for 32-bit Windows Only
#endif

#pragma once

#ifdef __cplusplus
#include <string>
#include <vector>
using std::string;
using std::vector;

namespace Grafix
{
	class GUI
	{
		vector<window> _w;
		vector<point> _gui;
	public:
		GUI(const vector<window> &);
		GUI(const window[], _uc8cr __size =1);
		virtual const GUI* Draw() const;
		virtual const bool is_closed() const {return true;}
		virtual const string toString() const;
		operator _c8()
		{
			static _uc8 i;
			return _gui.at(i++);
		}
		operator _uc8()
		{
			static _uc8 i;
			return _gui.at(i++);
		}
	};
}
using namespace Grafix;
#endif

#endif