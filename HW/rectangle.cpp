#include "rectangle.h"

Rectangle::Rectangle() {
	w = 0;
	h = 0;
}

Rectangle::Rectangle(int width, int height) {
	if (width <= 0) {
		width = 0;
	}
	if (height <= 0) {
		height = 0;
	}
	w = width;
	h = height;
}

int Rectangle::area() {
	return w * h;
}

int Rectangle::perimeter() {
	return (w + h) * 2;
}