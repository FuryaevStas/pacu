#include	"header.h"

int main(int argc, char *argv[])
{
	int key(0);
	setlocale(LC_ALL, "");
	initGUI();
	signal(SIGWINCH, resizeSignalHandler);
	
	while ((key = getch()) != 'q')
	{
		switch (key)
		{
			
		}
	}

	finish(0);
}