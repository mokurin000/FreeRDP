/**
 * FreeRDP: A Remote Desktop Protocol Implementation
 * Keyboard Layouts
 *
 * Copyright 2009-2012 Marc-Andre Moreau <marcandre.moreau@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <freerdp/locale/vkcodes.h>

#include <freerdp/utils/memory.h>

struct _VIRTUAL_KEY_CODE
{
	UINT32 code; /* Windows Virtual Key Code */
	const char* name; /* Virtual Key Code Name */
};
typedef struct _VIRTUAL_KEY_CODE VIRTUAL_KEY_CODE;

static const VIRTUAL_KEY_CODE VIRTUAL_KEY_CODE_TABLE[256] =
{
	{ 0, "" },
	{ VK_LBUTTON, "VK_LBUTTON" },
	{ VK_RBUTTON, "VK_RBUTTON" },
	{ VK_CANCEL, "VK_CANCEL" },
	{ VK_MBUTTON, "VK_MBUTTON" },
	{ VK_XBUTTON1, "VK_XBUTTON1" },
	{ VK_XBUTTON2, "VK_XBUTTON2" },
	{ 0, "" },
	{ VK_BACK, "VK_BACK" },
	{ VK_TAB, "VK_TAB" },
	{ 0, "" },
	{ 0, "" },
	{ VK_CLEAR, "VK_CLEAR" },
	{ VK_RETURN, "VK_RETURN" },
	{ 0, "" },
	{ 0, "" },
	{ VK_SHIFT, "VK_SHIFT" },
	{ VK_CONTROL, "VK_CONTROL" },
	{ VK_MENU, "VK_MENU" },
	{ VK_PAUSE, "VK_PAUSE" },
	{ VK_CAPITAL, "VK_CAPITAL" },
	{ VK_KANA, "VK_KANA" }, /* also VK_HANGUL */
	{ 0, "" },
	{ VK_JUNJA, "VK_JUNJA" },
	{ VK_FINAL, "VK_FINAL" },
	{ VK_KANJI, "VK_KANJI" }, /* also VK_HANJA */
	{ 0, "" },
	{ VK_ESCAPE, "VK_ESCAPE" },
	{ VK_CONVERT, "VK_CONVERT" },
	{ VK_NONCONVERT, "VK_NONCONVERT" },
	{ VK_ACCEPT, "VK_ACCEPT" },
	{ VK_MODECHANGE, "VK_MODECHANGE" },
	{ VK_SPACE, "VK_SPACE" },
	{ VK_PRIOR, "VK_PRIOR" },
	{ VK_NEXT, "VK_NEXT" },
	{ VK_END, "VK_END" },
	{ VK_HOME, "VK_HOME" },
	{ VK_LEFT, "VK_LEFT" },
	{ VK_UP, "VK_UP" },
	{ VK_RIGHT, "VK_RIGHT" },
	{ VK_DOWN, "VK_DOWN" },
	{ VK_SELECT, "VK_SELECT" },
	{ VK_PRINT, "VK_PRINT" },
	{ VK_EXECUTE, "VK_EXECUTE" },
	{ VK_SNAPSHOT, "VK_SNAPSHOT" },
	{ VK_INSERT, "VK_INSERT" },
	{ VK_DELETE, "VK_DELETE" },
	{ VK_HELP, "VK_HELP" },
	{ VK_KEY_0, "VK_KEY_0" },
	{ VK_KEY_1, "VK_KEY_1" },
	{ VK_KEY_2, "VK_KEY_2" },
	{ VK_KEY_3, "VK_KEY_3" },
	{ VK_KEY_4, "VK_KEY_4" },
	{ VK_KEY_5, "VK_KEY_5" },
	{ VK_KEY_6, "VK_KEY_6" },
	{ VK_KEY_7, "VK_KEY_7" },
	{ VK_KEY_8, "VK_KEY_8" },
	{ VK_KEY_9, "VK_KEY_9" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ VK_KEY_A, "VK_KEY_A" },
	{ VK_KEY_B, "VK_KEY_B" },
	{ VK_KEY_C, "VK_KEY_C" },
	{ VK_KEY_D, "VK_KEY_D" },
	{ VK_KEY_E, "VK_KEY_E" },
	{ VK_KEY_F, "VK_KEY_F" },
	{ VK_KEY_G, "VK_KEY_G" },
	{ VK_KEY_H, "VK_KEY_H" },
	{ VK_KEY_I, "VK_KEY_I" },
	{ VK_KEY_J, "VK_KEY_J" },
	{ VK_KEY_K, "VK_KEY_K" },
	{ VK_KEY_L, "VK_KEY_L" },
	{ VK_KEY_M, "VK_KEY_M" },
	{ VK_KEY_N, "VK_KEY_N" },
	{ VK_KEY_O, "VK_KEY_O" },
	{ VK_KEY_P, "VK_KEY_P" },
	{ VK_KEY_Q, "VK_KEY_Q" },
	{ VK_KEY_R, "VK_KEY_R" },
	{ VK_KEY_S, "VK_KEY_S" },
	{ VK_KEY_T, "VK_KEY_T" },
	{ VK_KEY_U, "VK_KEY_U" },
	{ VK_KEY_V, "VK_KEY_V" },
	{ VK_KEY_W, "VK_KEY_W" },
	{ VK_KEY_X, "VK_KEY_X" },
	{ VK_KEY_Y, "VK_KEY_Y" },
	{ VK_KEY_Z, "VK_KEY_Z" },
	{ VK_LWIN, "VK_LWIN" },
	{ VK_RWIN, "VK_RWIN" },
	{ VK_APPS, "VK_APPS" },
	{ 0, "" },
	{ VK_SLEEP, "VK_SLEEP" },
	{ VK_NUMPAD0, "VK_NUMPAD0" },
	{ VK_NUMPAD1, "VK_NUMPAD1" },
	{ VK_NUMPAD2, "VK_NUMPAD2" },
	{ VK_NUMPAD3, "VK_NUMPAD3" },
	{ VK_NUMPAD4, "VK_NUMPAD4" },
	{ VK_NUMPAD5, "VK_NUMPAD5" },
	{ VK_NUMPAD6, "VK_NUMPAD6" },
	{ VK_NUMPAD7, "VK_NUMPAD7" },
	{ VK_NUMPAD8, "VK_NUMPAD8" },
	{ VK_NUMPAD9, "VK_NUMPAD9" },
	{ VK_MULTIPLY, "VK_MULTIPLY" },
	{ VK_ADD, "VK_ADD" },
	{ VK_SEPARATOR, "VK_SEPARATOR" },
	{ VK_SUBTRACT, "VK_SUBTRACT" },
	{ VK_DECIMAL, "VK_DECIMAL" },
	{ VK_DIVIDE, "VK_DIVIDE" },
	{ VK_F1, "VK_F1" },
	{ VK_F2, "VK_F2" },
	{ VK_F3, "VK_F3" },
	{ VK_F4, "VK_F4" },
	{ VK_F5, "VK_F5" },
	{ VK_F6, "VK_F6" },
	{ VK_F7, "VK_F7" },
	{ VK_F8, "VK_F8" },
	{ VK_F9, "VK_F9" },
	{ VK_F10, "VK_F10" },
	{ VK_F11, "VK_F11" },
	{ VK_F12, "VK_F12" },
	{ VK_F13, "VK_F13" },
	{ VK_F14, "VK_F14" },
	{ VK_F15, "VK_F15" },
	{ VK_F16, "VK_F16" },
	{ VK_F17, "VK_F17" },
	{ VK_F18, "VK_F18" },
	{ VK_F19, "VK_F19" },
	{ VK_F20, "VK_F20" },
	{ VK_F21, "VK_F21" },
	{ VK_F22, "VK_F22" },
	{ VK_F23, "VK_F23" },
	{ VK_F24, "VK_F24" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ VK_NUMLOCK, "VK_NUMLOCK" },
	{ VK_SCROLL, "VK_SCROLL" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ VK_LSHIFT, "VK_LSHIFT" },
	{ VK_RSHIFT, "VK_RSHIFT" },
	{ VK_LCONTROL, "VK_LCONTROL" },
	{ VK_RCONTROL, "VK_RCONTROL" },
	{ VK_LMENU, "VK_LMENU" },
	{ VK_RMENU, "VK_RMENU" },
	{ VK_BROWSER_BACK, "VK_BROWSER_BACK" },
	{ VK_BROWSER_FORWARD, "VK_BROWSER_FORWARD" },
	{ VK_BROWSER_REFRESH, "VK_BROWSER_REFRESH" },
	{ VK_BROWSER_STOP, "VK_BROWSER_STOP" },
	{ VK_BROWSER_SEARCH, "VK_BROWSER_SEARCH" },
	{ VK_BROWSER_FAVORITES, "VK_BROWSER_FAVORITES" },
	{ VK_BROWSER_HOME, "VK_BROWSER_HOME" },
	{ VK_VOLUME_MUTE, "VK_VOLUME_MUTE" },
	{ VK_VOLUME_DOWN, "VK_VOLUME_DOWN" },
	{ VK_VOLUME_UP, "VK_VOLUME_UP" },
	{ VK_MEDIA_NEXT_TRACK, "VK_MEDIA_NEXT_TRACK" },
	{ VK_MEDIA_PREV_TRACK, "VK_MEDIA_PREV_TRACK" },
	{ VK_MEDIA_STOP, "VK_MEDIA_STOP" },
	{ VK_MEDIA_PLAY_PAUSE, "VK_MEDIA_PLAY_PAUSE" },
	{ VK_LAUNCH_MAIL, "VK_LAUNCH_MAIL" },
	{ VK_MEDIA_SELECT, "VK_MEDIA_SELECT" },
	{ VK_LAUNCH_APP1, "VK_LAUNCH_APP1" },
	{ VK_LAUNCH_APP2, "VK_LAUNCH_APP2" },
	{ 0, "" },
	{ 0, "" },
	{ VK_OEM_1, "VK_OEM_1" },
	{ VK_OEM_PLUS, "VK_OEM_PLUS" },
	{ VK_OEM_COMMA, "VK_OEM_COMMA" },
	{ VK_OEM_MINUS, "VK_OEM_MINUS" },
	{ VK_OEM_PERIOD, "VK_OEM_PERIOD" },
	{ VK_OEM_2, "VK_OEM_2" },
	{ VK_OEM_3, "VK_OEM_3" },
	{ VK_ABNT_C1, "VK_ABNT_C1" },
	{ VK_ABNT_C2, "VK_ABNT_C2" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ VK_OEM_4, "VK_OEM_4" },
	{ VK_OEM_5, "VK_OEM_5" },
	{ VK_OEM_6, "VK_OEM_6" },
	{ VK_OEM_7, "VK_OEM_7" },
	{ VK_OEM_8, "VK_OEM_8" },
	{ 0, "" },
	{ 0, "" },
	{ VK_OEM_102, "VK_OEM_102" },
	{ 0, "" },
	{ 0, "" },
	{ VK_PROCESSKEY, "VK_PROCESSKEY" },
	{ 0, "" },
	{ VK_PACKET, "VK_PACKET" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ 0, "" },
	{ VK_ATTN, "VK_ATTN" },
	{ VK_CRSEL, "VK_CRSEL" },
	{ VK_EXSEL, "VK_EXSEL" },
	{ VK_EREOF, "VK_EREOF" },
	{ VK_PLAY, "VK_PLAY" },
	{ VK_ZOOM, "VK_ZOOM" },
	{ VK_NONAME, "VK_NONAME" },
	{ VK_PA1, "VK_PA1" },
	{ VK_OEM_CLEAR, "VK_OEM_CLEAR" },
	{ 0, "" }
};

const char* freerdp_keyboard_get_virtual_key_code_name(UINT32 vkcode)
{
	return VIRTUAL_KEY_CODE_TABLE[vkcode].name;
}

UINT32 freerdp_keyboard_get_virtual_key_code_from_name(const char* vkcode_name)
{
	int i = 0;
	for (i = 0; i < ARRAY_SIZE(VIRTUAL_KEY_CODE_TABLE); i++)
	{
		if (VIRTUAL_KEY_CODE_TABLE[i].name)
		{
			if (strcmp(vkcode_name, VIRTUAL_KEY_CODE_TABLE[i].name) == 0)
			{
				return VIRTUAL_KEY_CODE_TABLE[i].code;
			}
		}
	}
	return 0;
}
