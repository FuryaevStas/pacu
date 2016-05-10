#include	"header.h"

SSetting	defaultSettings[] = {
	{ "listPath", "none" }
};

extern	CConfigFile	shortcuts;

CConfigFile config(
				defaultSettings,
				SETTINGS_NUM,
				"pacu.cfg");

COORD	*parentCoords	= new COORD();
COORD	*resizedCoords	= new COORD();

WINDOW*	mainwin			(NULL);
WINDOW*	list			(NULL);
WINDOW*	summary			(NULL);
WINDOW*	menu			(NULL);

int		sidebarSize		(DEFAULT_SIDEBAR_SIZE);
int		menuHeight		(1);

void drawTitle(WINDOW *_window, const char *_title)
{
	wattron(_window, A_REVERSE);
	mvwaddstr(_window, 0, 3, _title);
	wattroff(_window, A_REVERSE);
}

void drawListContent()
{
	if (!strcmp(config.getPar(LIST_PATH).value.c_str(), "none"))
	{
		mvwaddstr(list, 5, 5, "NO FILE");
		wrefresh(list);
	}
}

void drawSummaryContent()
{
	
}

void drawListWindow()
{
	if (list != NULL)
		delwin(list);
	list	= subwin(mainwin,
					parentCoords->y - menuHeight,
					parentCoords->x - sidebarSize,
					0, 0);
	box(list, 0, 0);
	drawTitle(list, "List");
	drawListContent();
	wrefresh(list);
}

void drawSummaryWindow()
{
	if (summary != NULL)
		delwin(summary);
	summary	= subwin(mainwin,
					parentCoords->y - menuHeight,
					sidebarSize,
					0, parentCoords->x - sidebarSize);
	box(summary, 0, 0);
	drawTitle(summary, "Summary");
	wrefresh(summary);
}

//TODO: Values through a cycle 'for'

void drawMenu()
{
	if (menu != NULL)
		delwin(menu);
	menu = subwin(mainwin,
				menuHeight,
				parentCoords->x,
				parentCoords->y - 1, 0);
	init_pair(1, COLOR_BLACK, COLOR_CYAN);
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	wattron(menu, COLOR_PAIR(1));
	mvwhline(menu, 0, 0, ' ', parentCoords->x);
	wattroff(menu, COLOR_PAIR(1));
	for (int i(0); i < MENU_ITEMS_NUM; i++)
	{
		wattron(menu, COLOR_PAIR(2));
		waddch(menu, shortcuts.getPar(i).value[0]);
		wattroff(menu, COLOR_PAIR(2));
		wattron(menu, COLOR_PAIR(1));
		wprintw(menu, "%s", shortcuts.getPar(i).name.c_str());
		wattroff(menu, COLOR_PAIR(1));
	}
	
	refresh();
}

void initGUI()
{
	if ((mainwin = initscr()) == NULL)
	{
		fprintf(stderr, "Error initialising ncurses.\n");
		exit(EXIT_FAILURE);	//Exit if couldn't initialize curses
	}
	
	start_color();			//Allow colors
	use_default_colors();	//Allow window transperency
	
	noecho();				//Disable output when any key is pressed
	keypad(stdscr, true);	//Allow using functional keys
	curs_set(false);		//Disable cursor
	
	//Write window's size to the 'parentCoords'
	getmaxyx(stdscr, parentCoords->y, parentCoords->x);
	
	//Draw main elements
	drawListWindow();
	drawSummaryWindow();
	drawMenu();
	
	refresh();				//Update the screen (Main window and subwindows)
}


//Resizing function for the window
//'signum' is using for the 'signal()' function
void resizeSignalHandler(int signum)
{
	
	endwin();	//Reinitializing window to refresh 'getmaxyx()' values
	initscr();	//^^
	refresh();	//^^
	
	//Get new window's size to the 'resizedCoords' struct
	getmaxyx(mainwin, resizedCoords->y, resizedCoords->x);
	
	if (resizedCoords->y != parentCoords->y ||
		resizedCoords->x != parentCoords->x)
	{
		//Refresh old values
		parentCoords->y = resizedCoords->y;
		parentCoords->x = resizedCoords->x;
		
		//Clean the screen to redraw
		clear();
		
//TODO: Optimize to reduce the CPU loading
		drawListWindow();
		drawSummaryWindow();		
		drawMenu();
		
		refresh();
	}
}

//Closing of all windows and shutting down the program
void finishGUI(int signum)
{
	delwin(list);
	delwin(summary);
	delwin(mainwin);
	endwin();
	
	exit(signum);
}