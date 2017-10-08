#include "TListItem.h"
#include <iostream>

TListItem::TListItem(const Square& square) {
	this->square = square;
	this->next = nullptr;
	std::cout << "List item: created" << std::endl;
}

TListItem::TListItem(const TListItem& orig) {
	this->square = orig.square;
	this->next = orig.next;
	std::cout << "List item: copied" << std::endl;
}

TListItem* TListItem::SetNext(TListItem* next) {
	TListItem* old = this->next;
	this->next = next;
	return old;
}

Square TListItem::GetSquare() const {
	return this->square;
}

TListItem* TListItem::GetNext() {
	return this->next;
}

TListItem::~TListItem() {
	std::cout << "List item: deleted"<< std::endl;
	delete next;

}

std::ostream& operator<<(std::ostream& os, const TListItem& obj) {
	os << "[" << obj.square << "]";//<< std::endl;
	return os;
}

bool operator==(TListItem & first, TListItem &last){
	return first.square == last.square;
}
