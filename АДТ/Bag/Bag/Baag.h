#pragma once
#include <string>

using namespace std;

class Baag
{

private:
	int book, pen;
	string color;

public:
	Baag();
	~Baag();
	Baag(int book1, int pen1, string color1);
	void set_book(int book1);
	int get_book() const;
	void set_pen(int pen1);
	int get_pen() const;
	void set_color(string color1);
	string get_color();
};

