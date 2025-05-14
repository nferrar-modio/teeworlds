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

	CUIRect Top, Title;

	MainView.HSplitTop(256.0f, &Top, &MainView);
	Top.HSplitTop(20.f, &Title, &Top);
	UI()->DoLabel(&Title, "Mod.io", 14.f, TEXTALIGN_MC, Title.w * 0.9f, false);
	if (IsUserAuthenticated())
	{
		// draw the mod list
	}
	else
	{
		RenderLoginBox(Top);
	}

	RenderBackButton(MainView);
}

void CMenus::RenderLoginBox(CUIRect View)
{
	// render background
	//View.HSplitBottom(120.0f, &View, 0);
	RenderBackgroundShadow(&View, true, 10.f);
}