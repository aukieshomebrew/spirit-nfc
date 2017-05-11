#include <3ds/gfx.h>
#include <3ds/console.h>
#include <3ds/services/hid.h>
#include <3ds/services/apt.h>
#include "base/menu.h"
#include "base/nfc_card.h"

enum State
{
	STATE_MENU,
	STATE_MENU_SCAN,
	STATE_EXIT
};

int main(int argc, char **argv)
{
	gfxInitDefault();
	consoleInit(GFX_TOP, NULL);

	State state = STATE_MENU;
	Menu *menu = new Menu(5);
	NFCCard *card = new NFCCard();

	card->ScanInit();

	menu->addItem("-> Scan info card.");
	menu->addItem("-> Exit.");

	while (aptMainLoop())
	{

		if (state == STATE_MENU)
		{
			menu->printMenu();
			hidScanInput();
			u32 kDown = hidKeysDown();

			if (kDown & KEY_START)
				break;
			if (kDown & KEY_DUP)
			{
				menu->menuUp();
			}
			if (kDown & KEY_DDOWN)
			{
				menu->menuDown();
			}

			if (kDown & KEY_A)
			{
				switch (menu->getItemSelected())
				{
				case 0:
					state = STATE_MENU_SCAN;
				case 1:
					state = STATE_EXIT;	
				};
				
			}
		}

		else if(state == STATE_MENU_SCAN)
		{
			card->ScanCard(16);
			hidScanInput();
			u32 kDown = hidKeysDown();

			if(kDown & KEY_START)
			{
				break;
			}

		}

		else if(state == STATE_EXIT)
		{
			break;
		}

		else
		{
			break;
		}

		gfxFlushBuffers();
		gfxSwapBuffers();
		gspWaitForVBlank();
	}

	gfxExit();
	return 0;
}