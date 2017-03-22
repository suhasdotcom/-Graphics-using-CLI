#include "point.h"

void Point::show()	const
{
	for(_us16 i=0; i<_y+1; i++)
		cout<<'\n';
	for(_uc8 i=0; i<_x; i++)
		cout<<' ';
	cout<<_ch;
}

void Point::show(char)	const
{
	cout<<"x="<<static_cast<_us16>(_x)<<"\ty="<<_y<<"\tz="<<static_cast<_us16>(_z)<<endl;
}