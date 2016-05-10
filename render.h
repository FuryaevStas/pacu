#ifndef _RENDER_H_
#define	_RENDER_H_

#include	"header.h"

#define DEFAULT_SIDEBAR_SIZE	30

struct COORD 
{
	unsigned int x: 16;
	unsigned int y: 16;
};

//void drawBorders(WINDOW *_window);

void drawTitle(WINDOW *_window, string _title);

void drawListContent();
void drawSummaryContent();

void drawListWindow();
void drawSummaryWindow();

void initGUI();
void resizeSignalHandler(int signum);

void finishGUI(int signum);

class	CDialogWindow
{
private:

public:
	CDialogWindow(WINDOW *_window);
	CDialogWindow(WINDOW *_window, string _title);
	~CDialogWindow();
	
	void	open();
	void	close();
	string	getLine();
};

#endif