#pragma once

class Dice {
public:
	Dice();
	int getFace() const;
	void roll();
private:
	int face_;		//number on dice
};