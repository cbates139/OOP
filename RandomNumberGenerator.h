#pragma once

class RandomNumberGenerator {
public:
	RandomNumberGenerator();
	int getRandomValue(int) const;
private:
	void seed() const;
};