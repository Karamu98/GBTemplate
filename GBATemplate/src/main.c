#include <gb/gb.h>
#include <stdio.h>

#include "gba_types.h"

void main()
{
	SHOW_BKG; DISPLAY_ON;
	
	s8 num = 0;
	char disp[4];
	while (1)
	{
		sprintf(disp, "%d", num);
		printf("\n%s", disp);

		++num;
	}
	
}