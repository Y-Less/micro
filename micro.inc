/*
 *  sscanf 2.10.0
 *  Created by Y_Less, updated by Emmet_.
 *
 *  Version: MPL 1.1
 *
 *  The contents of this file are subject to the Mozilla Public License Version
 *  1.1 (the "License"); you may not use this file except in compliance with
 *  the License. You may obtain a copy of the License at
 *  [url]http://www.mozilla.org/MPL/[/url]
 *
 *  Software distributed under the License is distributed on an "AS IS" basis,
 *  WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 *  for the specific language governing rights and limitations under the
 *  License.
 *
 *  The Original Code is the sscanf 2.0 SA:MP plugin.
 *
 *  The Initial Developer of the Original Code is Alex "Y_Less" Cole.
 *  Portions created by the Initial Developer are Copyright (C) 2020
 *  the Initial Developer. All Rights Reserved.
 *
 *  Contributor(s):
 *
 *  Special Thanks to:
 *
 *      SA:MP Team past, present and future
 */

#if !defined _INC_SSCANF
	#error Please include <sscanf> first.
#endif

native SSCANF_Test__(const file[], const line, {Float,_}:...);

#if !defined __PawnBuild && !defined SSCANF_NO_NICE_FEATURES
	#error sscanf likes the community compiler.  Use `#define SSCANF_NO_NICE_FEATURES` to ignore this.
#endif

#if defined __PawnBuild
	#define SSCANF_Test( SSCANF_Test__(__file,__line,
#else
	#define SSCANF_Test( SSCANF_Test__(SSCANF_MIC_,-1,
#endif

stock const
	SSCANF_MIC_[] = "micro"; // Append "unknown file" in the plugin when line number < 0.

