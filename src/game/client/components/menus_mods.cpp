#include "menus.h"
#include <game/client/ui.h>

#include "modio/ModioSDK.h"

bool CMenus::InitializeModio()
{
	bool bComplete = false;
	/*bool bResult = false;
	auto InitOptions = Modio::InitializeOptions(Modio::GameID(0), Modio::ApiKey(""), Modio::Environment::Live, Modio::Portal::None, "UnknownUser");

	Modio::InitializeAsync(InitOptions, [&](Modio::ErrorCode ec)
		{
			if (!ec)
			{
				bResult = true;
			}
			bComplete = true;
		});

	while (!bComplete) {}*/

	return bComplete;
}

bool CMenus::IsUserAuthenticated()
{
	bool bComplete = false;
	/*bool bResult = false;

	Modio::VerifyUserAuthenticationAsync([&](Modio::ErrorCode ec)
		{
			if (!ec)
			{
				bResult = true;
			}
			bComplete = true;
		});

	while (!bComplete) {}*/

	return bComplete;
}

void CMenus::RenderModsMenu(CUIRect MainView)
{
	MainView.Margin(5.0f, &MainView);

	MainView.HSplitTop(20.0f, 0, &MainView);
	RenderBackButton(MainView);
}

void CMenus::RenderLoginBox(CUIRect View)
{

}