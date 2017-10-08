#ifndef TLISTITEM_H
#define	TLISTITEM_H

#include "Square.h"
class TListItem {
public:
	TListItem(const Square& square);
	TListItem(const TListItem& orig);//copy constr
	friend std::ostream& operator<<(std::ostream& os, const TListItem& obj);
	friend bool operator==(TListItem& first, TListItem& last);

	TListItem* SetNext(TListItem* next);
	TListItem* GetNext();
	Square GetSquare() const;

	virtual ~TListItem();
private:
	Square square;
	TListItem *next;
};

#endif	/* TLISTITEM_H */