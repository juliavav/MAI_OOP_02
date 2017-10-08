#ifndef TLIST_H
#define	TLIST_H

#include "Square.h"
#include "TListItem.h"

class TList {
public:
	TList();
	TList(const TList& orig);

	void addFirst(Square &&square);
	void addLast(Square &&square);
	void insert(Square &&square, Square &&squareNext);
	bool empty();
	Square getElement(int n);
	void delElement(Square &&square);
	void eraseList();
	friend std::ostream& operator<<(std::ostream& os, const TList& stack);
	virtual ~TList();
private:	

	TListItem *first;
};

#endif	/* TLIST_H */