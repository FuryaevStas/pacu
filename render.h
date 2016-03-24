#ifndef _RENDER_H_
#define	_RENDER_H_

#define DEFAULT_SIDEBAR_SIZE	30

struct COORD 
{
	unsigned int x: 16;
	unsigned int y: 16;
};

void drawBorders(WINDOW *_window);

void initGUI();
void resizeSignalHandler(int signum);

void finish(int signum);

#endif