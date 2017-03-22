#ifndef TYPEDEF_H
#define TYPEDEF_H

#ifdef _WIN32

#ifdef __cplusplus
namespace Grafix
{
#endif									//C++
	//Datatypes
	typedef			bool	_b8;
	typedef unsigned long	_ul32;
	typedef	unsigned short	_us16;
	typedef			short	_s16;
	typedef				int	_i32;
	typedef unsigned int	_ui32;
	typedef			double	_d64;
	typedef			char	_c8;
	typedef	unsigned char	_uc8;
	typedef		long long	_ll64;
	typedef		long double	_ld64;
	typedef			float	_f32;
	typedef		long float	_lf64;
	//constants
	typedef	const			bool	_b8c;
	typedef const unsigned long		_ul32c;
	typedef	const unsigned short	_us16c;
	typedef	const			short	_s16c;
	typedef	const				int	_i32c;
	typedef const	unsigned int	_ui32c;
	typedef	const			double	_d64c;
	typedef	const			char	_c8c;
	typedef const	unsigned char	_uc8c;
	typedef	const		long long	_ll64c;
	typedef	const		long double	_ld64c;
	typedef	const			float	_f32c;
	typedef	const		long float	_lf64c;
	//references
	typedef	bool&					_b8r;
	typedef char&					_c8r;
	typedef unsigned long&			_ul32r;
	typedef	unsigned short&			_us16r;
	typedef			short&			_s16r;
	typedef				int&		_i32r;
	typedef unsigned int&			_ui32r;
	typedef			double&			_d64r;
	typedef	unsigned char&			_uc8r;
	typedef		long long&			_ll64r;
	typedef		long double&		_ld64r;
	typedef			float&			_f32r;
	typedef		long float&			_lf64r;
	//constant references
	typedef	const bool&				_b8cr;
	typedef const unsigned long&	_ul32cr;
	typedef	const unsigned short&	_us16cr;
	typedef	const			short&	_s16cr;
	typedef	const			int&	_i32cr;
	typedef const	unsigned int&	_ui32cr;
	typedef	const			double&	_d64cr;
	typedef	const			char&	_c8cr;
	typedef const	unsigned char&	_uc8cr;
	typedef	const		long long&	_ll64cr;
	typedef	const	long double&	_ld64cr;
	typedef	const			float&	_f32cr;
	typedef	const		long float&	_lf64cr;
#ifdef __cplusplus
}
using namespace Grafix;
#endif								//C++

#endif								//32-bit-windows Environment

#endif