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
 *  Special Thanks to:
 *  
 *  SA:MP Team past, present and future
 */

#pragma once

#include <stdint.h>

typedef
	void (* logprintf_t)(char *, ...);

#if defined __cplusplus
	#define PAWN_NATIVE_EXTERN extern "C"
#else
	#define PAWN_NATIVE_EXTERN extern
#endif

#if defined _WIN32 || defined __CYGWIN__
	#define PAWN_NATIVE_DLLEXPORT __declspec(dllexport)
	#define PAWN_NATIVE_DLLIMPORT __declspec(dllimport)
	#define PAWN_NATIVE_API __cdecl
#elif defined __linux__ || defined __APPLE__
	#define PAWN_NATIVE_DLLEXPORT __attribute__((visibility("default")))
	#define PAWN_NATIVE_DLLIMPORT 
	#define PAWN_NATIVE_API __attribute__((cdecl))
#endif

#define PAWN_NATIVE_EXPORT PAWN_NATIVE_EXTERN PAWN_NATIVE_DLLEXPORT
#define PAWN_NATIVE_IMPORT PAWN_NATIVE_EXTERN PAWN_NATIVE_DLLIMPORT

