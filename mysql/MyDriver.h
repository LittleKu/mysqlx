/**
 * vim: set ts=4 sw=4 tw=99 noet :
 * =============================================================================
 * SourceMod MySQL Extension
 * Copyright (C) 2004-2008 AlliedModders LLC.  All rights reserved.
 * =============================================================================
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License, version 3.0, as published by the
 * Free Software Foundation.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * As a special exception, AlliedModders LLC gives you permission to link the
 * code of this program (as well as its derivative works) to "Half-Life 2," the
 * "Source Engine," the "SourcePawn JIT," and any Game MODs that run on software
 * by the Valve Corporation.  You must obey the GNU General Public License in
 * all respects for all other code used.  Additionally, AlliedModders LLC grants
 * this exception to all derivative works.  AlliedModders LLC defines further
 * exceptions, found in LICENSE.txt (as of this writing, version JULY-31-2007),
 * or <http://www.sourcemod.net/license.php>.
 *
 * Version: $Id$
 */

#ifndef _INCLUDE_MYSQL_DRIVER_H_
#define _INCLUDE_MYSQL_DRIVER_H_

#define SOURCEMOD_SQL_DRIVER_CODE
#include <IDBDriver.h>
#include <platform.h>
#if defined PLATFORM_WINDOWS
#include <winsock.h>
#endif

#include <mysql.h>
#if !defined(PLATFORM_WINDOWS)
# include <my_global.h>
# include <my_sys.h>
#endif

#include <sh_list.h>
#include <am-thread-utils.h>
#include <am-string.h>

#define M_CLIENT_MULTI_RESULTS    ((1) << 17)  /* Enable/disable multi-results */
using namespace SourceHook;

namespace mysqlx
{
	class MyDatabase;

	class MyDriver : public IDBDriver
	{
	public:
		MyDriver();
		virtual ~MyDriver();
	public: //IDBDriver
		IDatabase *Connect(const DatabaseInfo *info, bool persistent, char *error, size_t maxlength);
		const char *GetIdentifier();
		const char *GetProductName();
		bool IsThreadSafe();
		bool InitializeThreadSafety();
		void ShutdownThreadSafety();
	public:
		void Shutdown();
		void RemoveFromList(MyDatabase *pdb, bool persistent);
	private:
		ke::Mutex m_Lock;
		List<MyDatabase *> m_TempDbs;
		List<MyDatabase *> m_PermDbs;
	};

	unsigned int strncopy(char *dest, const char *src, size_t count);
}

extern mysqlx::MyDriver g_MyDriver;

#endif //_INCLUDE_SM_MYSQL_DRIVER_H_
