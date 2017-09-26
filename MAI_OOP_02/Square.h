#ifndef SQUARE_H
#define	SQUARE_H
#include <cstdlib>
#include <iostream>

class Square {
public:
	Square();
	Square(const Square& orig);
	Square(long int i);

	Square& operator++();
	double SquareF();
	friend Square operator+(const Square& left, const Square& right);

	friend std::ostream& operator<<(std::ostream& os, const Square& obj);
	friend std::istream& operator>>(std::istream& is, Square& obj);

	Square& operator=(const Square & right);

	virtual ~Square();
private:
	long int side_a;
};

#endif	/* SQUARE_H */