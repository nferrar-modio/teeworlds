#ifndef ENGINE_SHARED_MODIO_H
#define ENGINE_SHARED_MODIO_H

#include <thread>

#include "engine/modio.h"
#include "modio/ModioSDK.h"

class CModioThreadRunner
{

private:
	std::thread Thread;
	bool Running = true;

public:

	void StartThread()
	{
		dbg_msg("modio", "Init RunPendingHandlers");
		Thread = std::thread([&]()
			{
				while (Running)
				{
					Modio::RunPendingHandlers();
					std::this_thread::sleep_for(std::chrono::milliseconds(1));
				}
			});
	};
	void StopThread() { Running = false; };
};

class CModioManager : public IModioManager
{

private:
	CModioThreadRunner m_Modio;

public:
	CModioManager();

	virtual CModioThreadRunner* Runner() { return &m_Modio; }
	virtual CModioManager* Get() { return this; }

	virtual void Init();
	virtual void Shutdown();

	static void LogCallback(Modio::LogLevel LogLevel, std::string Msg);
};

#endif