#pragma once


#include <iostream>
#include <cstdlib>
#include <vector>
#include <stdexcept>


struct Hex {
    int q;
    int r;
    int s;
    
	Hex(int q, int r, int s);

	void add(const Hex& other);
	void subtract(const Hex& other);
	void multiply(int factor);

	Hex addHexes(Hex hex1, Hex hex2);

	int length() const;
	int distance(const Hex& other) const;

	const std::vector<Hex> directions = {
		Hex(1, 0, -1), Hex(1, -1, 0), Hex(0, -1, 1),
		Hex(-1, 0, 1), Hex(-1, 1, 0), Hex(0, 1, -1)
	};

	Hex directionHex(int direction) const;
	Hex neighbor(int direction);

	bool operator==(const Hex& other) const;

	bool operator!=(const Hex& other) const;

	Hex operator+(const Hex& other) const;

	Hex operator-(const Hex& other) const;

	Hex operator*(int factor) const;
};

