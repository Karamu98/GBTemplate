#include <gb/gb.h>
#include <stdio.h>

#include "gba_types.h"
#include "../res/dungeon_map.h"
#include "../res/dungeon_tiles.h"

void init_gfx()
{
    // Load Background tiles and then map
    set_bkg_data(0, 79u, dungeon_tiles);
    set_bkg_tiles(0, 0, 32u, 32u, dungeon_mapPLN0);

	// Turn the background map on to make it visible
    SHOW_BKG;
}

void main()
{
	init_gfx();
	
	s8 num = 0;
	char disp[4];
	bool drawn = true;

	while (1)
	{
		if(num > 50)
		{
			sprintf(disp, "%d", num);
			printf("\n%s", disp);
			drawn = false;
		}
		else if(!drawn)
		{
			set_bkg_data(0, 79u, dungeon_tiles);
			set_bkg_tiles(0, 0, 32u, 32u, dungeon_mapPLN0);
			drawn = true;
		}

		++num;

		// Done processing, yield CPU and wait for start of next frame
        wait_vbl_done();
	}
	
}