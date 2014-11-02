#include "sr-utils.h"
#include <math.h>
#include <iostream>

float dot(sf::Vector2f a,sf::Vector2f b) {
	return a.x*b.x + a.y*b.y;
}

float norm_sqrd(sf::Vector2f v) {
	return v.x * v.x + v.y * v.y;
}

float norm(sf::Vector2f v) {
	return sqrt(norm_sqrd(v));
}

sf::Vector2f rotate(sf::Vector2f v, float angle) {
	return sf::Vector2f(v.x*cos(angle) - v.y*sin(angle), v.x*sin(angle) + v.y*cos(angle));
}

bool within(float val, float x1, float x2) {
	if (x1 <= val and val <= x2) return true;
	else return false;
}

bool withinBox(sf::Vector2f val, float x1, float x2, float y1, float y2) {
	if (within(val.x,x1,x2) && within(val.y,y1,y2)) return true;
	return false;
}