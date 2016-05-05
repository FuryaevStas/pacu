#include	"header.h"

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "");					//Set application locale to UTF-8
	initGUI();								//Initializing of GUI
	signal(SIGWINCH, resizeSignalHandler);	//Handling windows resizing
	
	int key(0);								//Pressed key
	
	while ((key = getch()) != 'q')
	{
		switch (key)						//Handling keyboard pressing
		{
			
		}
	}

	finish(0);	//Do any exit functions and exit successfully
}