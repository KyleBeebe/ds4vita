
#include "remapper.h"

#include <array>
#include <utility>
#include <psp2kern/ctrl.h>

#define MASK_MAP_COUNT 24

// Pairs of button enums and the enum they are mapped to
std::array<std::pair<SceCtrlButtons, SceCtrlButtons>, MASK_MAP_COUNT> mask_map = {
	 {
	{SCE_CTRL_SELECT,SCE_CTRL_SELECT},
	{SCE_CTRL_L3,SCE_CTRL_L3},
	{SCE_CTRL_R3,SCE_CTRL_R3},
	{SCE_CTRL_START,SCE_CTRL_START},
	{SCE_CTRL_UP,SCE_CTRL_UP},
	{SCE_CTRL_RIGHT,SCE_CTRL_RIGHT},
	{SCE_CTRL_DOWN,SCE_CTRL_DOWN},
	{SCE_CTRL_LEFT,SCE_CTRL_LEFT},
	{SCE_CTRL_LTRIGGER,SCE_CTRL_L1},
	{SCE_CTRL_RTRIGGER,SCE_CTRL_R1},
	{SCE_CTRL_L1,SCE_CTRL_LTRIGGER},
	{SCE_CTRL_R1,SCE_CTRL_RTRIGGER},
	{SCE_CTRL_TRIANGLE,SCE_CTRL_TRIANGLE},
	{SCE_CTRL_CIRCLE,SCE_CTRL_CIRCLE},
	{SCE_CTRL_CROSS,SCE_CTRL_CROSS},
	{SCE_CTRL_SQUARE,SCE_CTRL_SQUARE},
	{SCE_CTRL_PSBUTTON,SCE_CTRL_PSBUTTON},
	{SCE_CTRL_HEADPHONE,SCE_CTRL_HEADPHONE},
	{SCE_CTRL_VOLUP,SCE_CTRL_VOLUP},
	{SCE_CTRL_VOLDOWN,SCE_CTRL_VOLDOWN},
	{SCE_CTRL_POWER,SCE_CTRL_POWER}
	 }
};

	// Using passed in button bit mask, checks each mappable button if pressed and sets 
	// new bit mask using mapped enum 
	unsigned int convert_buttons_mask(unsigned int buttons_in) {
		unsigned int ret_mask = 0;
		for (auto& it : mask_map) {
			if ((it.first & buttons_in) == it.first) {
				ret_mask |= it.second;
			}
		}

		return ret_mask;
	}

	void init_map() {

	}
