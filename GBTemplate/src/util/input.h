#ifndef _INPUT_H__
#define _INPUT_H__

#include "gba_types.h"

void UpdateInput();
void BindActionToInput(u8 actionID, void(*func)(void*), void* extraData);

#endif