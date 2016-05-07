#include	"header.h"

SSetting defaultKeys[] = {
	{"Quit", "q"},
	{"Open", "o"}
};

CConfigFile shortcuts(
	defaultKeys,
	MENU_ITEMS_NUM,
	"shortcuts.cfg"
);

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "");					//Set application locale to UTF-8
	initGUI();								//Initializing of GUI
	signal(SIGWINCH, resizeSignalHandler);	//Handling windows resizing
	
	int key(0);								//Pressed key	
	
	while ((key = getch()) != shortcuts.getPar(K_QUIT)[0])
	{
		mvaddch(5,5, shortcuts.getPar(K_QUIT)[0]);
		switch (key)						//Handling keyboard pressing
		{
			
		}
	}

	finishGUI(0);	//Do any exit functions and exit successfully
}