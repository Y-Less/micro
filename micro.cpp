/*  
 *  Version: MPL 1.1
 *  
 *  The contents of this file are subject to the Mozilla Public License Version 
 *  1.1 (the "License"); you may not use this file except in compliance with 
 *  the License. You may obtain a copy of the License at 
 *  http://www.mozilla.org/MPL/
 *  
 *  Software distributed under the License is distributed on an "AS IS" basis,
 *  WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 *  for the specific language governing rights and limitations under the
 *  License.
 *  
 *  The Original Code is the sscanf 2.0 SA:MP plugin.
 *  
 *  The Initial Developer of the Original Code is Alex "Y_Less" Cole.
 *  Portions created by the Initial Developer are Copyright (c) 2020
 *  the Initial Developer. All Rights Reserved.
 *  
 *  Contributor(s):
 *
 *  SA:MP team - plugin framework.
 *  
 *  Special Thanks to:
 *  
 *  SA:MP Team past, present and future
 */

#include "micro.h"

#include "SDK/plugin.h"

//----------------------------------------------------------

logprintf_t
	logprintf;

typedef cell (*sscanf_t)(AMX * amx, char * string, char * format, cell * params, int paramCount, char * file, int line);
sscanf_t sscanf;

static cell AMX_NATIVE_CALL
	n_SSCANF_Remote(AMX * amx, cell * params)
{
	return 42;
}

PLUGIN_EXPORT unsigned int PLUGIN_CALL
	Supports() 
{
	return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}

PLUGIN_EXPORT bool PLUGIN_CALL
	Load(void ** ppData)
{
	logprintf = (logprintf_t)ppData[PLUGIN_DATA_LOGPRINTF];
	logprintf("loading sscanf...");
	
	// Find if sscanf is already loaded:
	HANDLE server = GetCurrentProcess();
	HMODULE hMods[1024];
	DWORD cbNeeded;
	HMODULE dll = 0;
	if (EnumProcessModules(server, hMods, sizeof(hMods), &cbNeeded))
	{
		for (int i = 0; i < (cbNeeded / sizeof(HMODULE)); i++)
		{
			TCHAR szModName[MAX_PATH];
			if (GetModuleFileNameEx(server, hMods[i], szModName, sizeof(szModName) / sizeof(TCHAR)))
			{
				int len = strlen(szModName);
				if (len >= 11 && strcmp("\\sscanf.DLL", szModName + len - 11) == 0)
				{
					dll = hMods[i];
					break;
				}
			}
		}
	}

	if (dll)
	{
		sscanf = (sscanf_t)GetProcAddress(dll, "sscanf");
		if (sscanf)
		{
			logprintf(" succeeded.\n");
			return true;
		}
		else
		{
			logprintf(" failed, ensure the plugin version is at least 2.10.3.\n");
			return false;
		}
	}
	else
	{
		logprintf(" failed, ensure the sscanf plugin is loaded first.\n");
		return false;
	}
}

PLUGIN_EXPORT void PLUGIN_CALL
	Unload()
{
}

AMX_NATIVE_INFO
	microNatives[] =
		{
			{"SSCANF_Remote", n_SSCANF_Remote},
			{0,        0}
		};

PLUGIN_EXPORT int PLUGIN_CALL
	AmxLoad(AMX * amx) 
{
	return amx_Register(amx, microNatives, -1);
}

PLUGIN_EXPORT int PLUGIN_CALL
	AmxUnload(AMX * amx) 
{
	return AMX_ERR_NONE;
}

