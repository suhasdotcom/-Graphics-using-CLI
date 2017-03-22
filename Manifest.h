#ifndef MANIFEST_H
#define MANIFEST_H

#pragma once

#include "typedef.h"

/**-------------------System Definition File------------------------
*	@Description:	This file takes the current specification of the system from the user such as 
*					screen height, width, tab, spaces etc to work adaptably for many systems.
*					This file needs manual intervention at the time of this program's birth
*					but generates a whole GUI after all the specifications have been 
*					supplied to this file
*/

#ifdef __cplusplus
namespace Grafix
{
#endif
	//height
	_us16c __HEIGHT_CONSTANT = 298;
	//width
	_us16c __WIDTH_CONSTANT = 80;
	//depth
	_uc8c __LAYERS_CONSTANT = 2;

	/**	@permission:	The subsequent instructions are system specific and must not
	*					be altered by the user in any circumatances
	*	@Description:	These codes decide the priority of each window created
	*/
	_uc8c __HIGHEST_PRIORITY_CONSTANT = 0;
	_uc8c __LOWEST_PRIORITY_CONSTANT = __LAYERS_CONSTANT-1;
	_us16c __HEIGHT_CONSTANT2 = __HEIGHT_CONSTANT*2;
	_us16c __HEIGHT_CONSTANT1_58 = __HEIGHT_CONSTANT*1.58;

//	typedef enum Style
//	{
	_uc8c	__BOLD = 0;
	_uc8c	__REGULAR =1;
//	}style;
#ifdef __cplusplus
}
using namespace Grafix;
#endif

#endif