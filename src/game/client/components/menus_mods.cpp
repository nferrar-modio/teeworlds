#include "menus.h"
#include <game/client/ui.h>

#include "modio/ModioSDK.h"
#include "ModioDefines.h"

bool CMenus::InitializeModio()
{
	bool bResult = false;

	bool bComplete = false;
	auto InitOptions = Modio::InitializeOptions(Modio::GameID(MODIO_GAME_ID), Modio::ApiKey(MODIO_GAME_API_KEY), Modio::Environment::Live, Modio::Portal::None, "UnknownUser");

	Modio::InitializeAsync(InitOptions, [&](Modio::ErrorCode ec)
		{
			if (!ec)
			{
				bResult = true;
			}
			bComplete = true;
		});

	while (!bComplete) {}

	return bResult;
}

bool CMenus::IsUserAuthenticated()
{
	bool bResult = false;

	bool bComplete = false;

	Modio::VerifyUserAuthenticationAsync([&](Modio::ErrorCode ec)
		{
			if (!ec)
			{
				bResult = true;
			}
			bComplete = true;
		});

	while (!bComplete) {}

	return bResult;
}

void CMenus::RenderModsMenu(CUIRect MainView)
{
	MainView.Margin(5.0f, &MainView);

	MainView.HSplitTop(20.0f, 0, &MainView);

	if (IsUserAuthenticated())
	{
		// draw the mod list
	}
	else
	{
		RenderLoginBox(MainView);
	}

	RenderBackButton(MainView);
}

void CMenus::RenderLoginBox(CUIRect View)
{
	if (Client()->State() != IClient::STATE_OFFLINE)
		return;

	// same size like tabs in top but variables not really needed
	float Spacing = 3.0f;
	float ButtonWidth = (View.w / 1.5f) - (Spacing * 5.0) / 6.0f;

	// render background
	View.HSplitBottom(60.0f, 0, &View);
	RenderBackgroundShadow(&View, true, 10.f);
}