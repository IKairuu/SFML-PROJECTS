#include "sprite.h"

int main()
{
	sprite kai ;
	while(kai.windowOpen())
	{
		kai.updateProgram() ;
		kai.renderProgram() ;
	}
	return 0 ;
}
