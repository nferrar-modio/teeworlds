#include <engine/shared/modio.h>

CModioManager::CModioManager()
{
	//m_Modio = CModioThreadRunner();
}

void CModioManager::Init()
{
	Runner()->StartThread();
	Modio::SetLogCallback(&CModioManager::LogCallback);
}

void CModioManager::Shutdown()
{
	Runner()->StopThread();
}

void CModioManager::LogCallback(Modio::LogLevel LogLevel, std::string Msg)
{
	dbg_msg("modioSDK", Msg.c_str());
}

IModioManager* CreateModioManager() { return new CModioManager; }
