#ifndef ENGINE_MODIO_H
#define ENGINE_MODIO_H

#include "kernel.h"

class IModioManager : public IInterface
{
	MACRO_INTERFACE("modio", 0)
public:

	virtual void Init() = 0;
	virtual void Shutdown() = 0;
	virtual class CModioThreadRunner* Runner() = 0;
	virtual class CModioManager* Get() = 0;
};

extern IModioManager* CreateModioManager();

#endif