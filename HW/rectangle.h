#pragma once

class Rectangle {
public:
	Rectangle();
	Rectangle(int width, int height);
	int area();
	int perimeter();
		
private:
	int w, h;
};