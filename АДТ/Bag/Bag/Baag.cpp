#include "pch.h"
#include "Baag.h"


Baag::Baag()
{
}


Baag::~Baag()
{
}

Baag::Baag(int book1, int pen1, string color1)
{
	if (book1 > 0 && pen1 > 0)
		book = book1;
	     pen = pen1;
	   color = color1;
}

void Baag::set_book(int book1)
{
	if (book1 > 0)
		book = book1;
}

int Baag::get_book() const
{
	return book;
}

void Baag::set_pen(int pen1)
{
	if (pen1 > 0)
		pen = pen1;
}

int Baag::get_pen() const
{
	return pen;
}

void Baag::set_color(string color1)
{
	color = color1;
}

string Baag::get_color() 
{
	return color;
}

