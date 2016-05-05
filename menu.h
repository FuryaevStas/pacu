#ifndef	_MENU_H_
#define	_MENU_H_

#define MENU_ITEMS_NUM 2

enum keys {
	K_QUIT,
	K_OPEN
};

struct SKey {
	char	key;
	string	name;	
};

#endif