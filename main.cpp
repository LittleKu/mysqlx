#include "MyDriver.h"

PLATFORM_EXTERN_C mysqlx::IDBDriver *GetDBDriver()
{
	return &g_MyDriver;
}