#include "GUI.h"


using namespace::Grafix;

const point NEW()
{
	static _uc8 i;
	static _us16 j;
	i=i==__WIDTH_CONSTANT?0:i;
	cout<<'('<<_us16(i)<<','<<j<<")\n";
	return point(i++, j++, __LOWEST_PRIORITY_CONSTANT);
}

GUI::GUI(const vector<window> &__w)
	try
		: _w(__w)//:_gui(vector<point>(__HEIGHT_CONSTANT*__WIDTH_CONSTANT, NEW()))
{
	_us16 _p=0, _ptr=0;
	_uc8 i=0;
	_us16 j=0;
	for(j=0;j<__HEIGHT_CONSTANT; j++)
		for(i=0;i<__WIDTH_CONSTANT; i++)
		{
			_gui.push_back(point(i, j, __LOWEST_PRIORITY_CONSTANT));
		//	cout<<'('<<_gui.at(i*j).get_x()<<','<<_gui.at(i*j).get_y()<<")\n";
		}
//	cout<<"\nconstructing..."<<_gui.size()<<"\n";
	for(auto p=__w.begin(); p!=__w.end(); ++p, _ptr++)
	{
	//	cout<<endl<<"In";
		for(auto ptr=_gui.begin(); ptr!=_gui.end(); ++ptr, _p=(_p==__HEIGHT_CONSTANT*__WIDTH_CONSTANT?0:_p+1))
			if(p->get_priority()<=ptr->get_priority() && !ptr->isEnclosed())
				*ptr = p->get_win().at(_p);
		//		cout<<endl<<_p<<'\t'<<'('<<ptr->get_x()<<','<<ptr->get_y()<<"):\t"<<_uc8(*ptr);
	}
}
catch(...)
{
	cout<<"Caught some Exception\n";
}

GUI::GUI(const window __w[], _uc8cr _size)  //:_gui(vector<point>(__HEIGHT_CONSTANT*__WIDTH_CONSTANT, NEW()))
{
	_w = vector<window>(&__w[0], &__w[_size-1]);
	_us16 _p=0, _ptr=0;
	_uc8 i=0;
	_us16 j=0;
	for(j=0;j<__HEIGHT_CONSTANT; j++)
		for(i=0;i<__WIDTH_CONSTANT; i++)
		{
			_gui.push_back(point(i, j, __LOWEST_PRIORITY_CONSTANT));
		//	cout<<'('<<_gui.at(i*j).get_x()<<','<<_gui.at(i*j).get_y()<<")\n";
		}
//	cout<<"\nconstructing..."<<_gui.size()<<"\n";
	for(_ptr=0; _ptr<_size; _ptr++)
	{
	//	cout<<endl<<"In";
		for(auto ptr=_gui.begin(); ptr!=_gui.end(); ++ptr, _p=(_p==__HEIGHT_CONSTANT*__WIDTH_CONSTANT?0:_p+1))
			if(__w[_ptr].get_priority()<=ptr->get_priority() && !ptr->isEnclosed())
				*ptr = __w[_ptr].get_win().at(_p);
		//		cout<<endl<<_p<<'\t'<<'('<<ptr->get_x()<<','<<ptr->get_y()<<"):\t"<<_uc8(*ptr);
	}
}

const GUI* GUI::Draw() const
{
	cout<<toString();
	return this;
}

const string GUI::toString() const
{
	std::string str;
	for_each(_gui.begin(), _gui.end(), [&str](const point &p) {str.push_back(static_cast<char>(p));});
	return str;
}