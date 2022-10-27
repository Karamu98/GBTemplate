#include "input.h"
#include <gb/gb.h>

static const int MultiplyDeBruijnBitPosition2[32] = 
{
  0, 1, 28, 2, 29, 14, 24, 3, 30, 22, 20, 15, 25, 17, 4, 8, 
  31, 27, 13, 23, 21, 19, 16, 7, 26, 12, 18, 6, 11, 5, 10, 9
};

void (*S_KeyPressed[8])(void*);
void* S_KeyPressedData[8];

void BindActionToInput(u8 actionID, void(*func)(void*), void* extraData)
{
	if(actionID < J_RIGHT || actionID > J_START)
	{
		return;
	}
	
	int idx = MultiplyDeBruijnBitPosition2[(uint32_t)(actionID * 0x077CB531U) >> 27];
	S_KeyPressed[idx] = func;
	S_KeyPressedData[idx] = extraData;
}

void UpdateInput()
{
	uint8_t input = joypad();
	for(int i = 0; i < 8; ++i)
	{
		if(input & (1 << i))
		{
			void (*curPressed)(void*) = S_KeyPressed[i];
			if(curPressed != NULL)
			{
				curPressed(S_KeyPressedData[i]);
			}
		}
	}
}