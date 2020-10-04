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

static cell AMX_NATIVE_CALL
	n_SSCANF_Remote(AMX * amx, cell * params)
{
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
	logprintf("micro loaded");
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

