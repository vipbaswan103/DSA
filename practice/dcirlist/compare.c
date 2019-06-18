#include "dcirlist.h"
#include "compare.h"

comp compare(int x, int y)
{
	if(x>y)
		return GREATER;
	if(x<y)
		return LESSER;
	return EQUAL;
}
