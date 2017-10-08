#include "Square.h"
#include <iostream>
#include <cmath>

Square::Square() : Square(0) {
}

Square::Square(long int i) : side_a(i) {
	//std::cout << "Square created: " << side_a << std::endl;
}

Square::Square(const Square& orig) {
	//std::cout << "Square copy created" << std::endl;
	side_a = orig.side_a;
}

Square& Square::operator=(const Square& right) {

	if (this == &right) return *this;

	//std::cout << "Square copied" << std::endl;
	side_a = right.side_a;

	return *this;
}

Square& Square::operator++() {

	side_a++;

	return *this;
}

Square operator+(const Square& left, const Square& right) {

	return Square(left.side_a + right.side_a);
}
bool operator==(const Square & left, const Square & right){
	return left.side_a == right.side_a;
}
double Square::SquareF() {

	return side_a*side_a;
}

Square::~Square() {
	//std::cout << "Square deleted" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Square& obj) {

	os << "a=" << obj.side_a;
	return os;
}

std::istream& operator>>(std::istream& is, Square& obj) {

	is >> obj.side_a;

	return is;
}