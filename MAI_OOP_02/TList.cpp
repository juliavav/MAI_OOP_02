#include "TList.h"

TList::TList() : first(nullptr) {
}

TList::TList(const TList& orig) {
	first = orig.first;
}

std::ostream& operator<<(std::ostream& os, const TList& list) {

	TListItem *item = list.first;

	while (item != nullptr)
	{
		os << *item;
		item = item->GetNext();
	}

	return os;
}

void TList::addFirst(Square &&square) {
	TListItem *other = new TListItem(square);
	other->SetNext(first);
	first = other;
}

void TList::addLast(Square &&square) {
	TListItem *other = new TListItem(square);
	TListItem *iter = this->first;
	if (first != nullptr) {
		while (iter->GetNext() != nullptr) {
			iter = iter->SetNext(iter->GetNext());
		}
		iter->SetNext(other);// little bit strange
		other->SetNext(nullptr);
	}
	else {
		first=other;
	}
}

void TList::insert(Square &&squareNext, Square &&square) {
	TListItem *other = new TListItem(square);
	TListItem *iter = this->first;
	while (!(iter->GetSquare() == squareNext)&& (iter->GetNext() != nullptr)) {
		iter=iter->GetNext();
	}

	if (iter->GetNext() == nullptr) {
		std::cout << "5.There is not such element in this list." << std::endl;
	}
	else {
		other->SetNext(iter->GetNext());
		iter->SetNext(other);
	}
}
bool TList::empty() {
	return first == nullptr;
}
Square TList::getElement(int n){
	TListItem* iter = this->first;
	for (int i = 1; i < n; i++) {
		iter = iter->GetNext();
		
	}
	return iter->GetSquare();
}
void TList::delElement(Square && square)//пофиксить!!!!!!!!!!!!!!!!!!!!!
{
	TListItem* iter = this->first;
	if (iter != nullptr&&iter->GetNext() != nullptr) {
		while (!(iter->GetNext()->GetSquare() == square) && !(iter->GetNext() == nullptr)) {
			iter = iter->GetNext();
		}
		if (!(iter->GetNext() == nullptr)) {
			iter->SetNext(iter->GetNext()->GetNext());
		}
		else {
			std::cout << "3. No such element!" << std::endl;
		}
	}
	else {

		std::cout << "3. No such element!" << std::endl;
	}

}
void TList::eraseList() {
	first = nullptr;
}

TList::~TList() {
	std::cout << "List deleted!" << std::endl;
	delete first;
}