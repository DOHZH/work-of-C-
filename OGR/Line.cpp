#include "Line.h"

Line::Line(double x1, double y1, double x2, double y2)
{

	p1.x = x1;
	p1.y = y1;
	p2.x = x2;
	p2.y = y2;

	p1.status = true;
	p2.status = true;

	if (x1 == x2)
	{
		k = 0;
		b = 0;
		is_vertical = true;
	}
	else
	{
		k = (y1 - y2) / (x1 - x2);
		b = y1 - k * x1;
		is_vertical = false;
	}

}

Point Line::P1()
{
	return p1;
}

Point Line::P2()
{
	return p2;
}

double Line::K()
{
	return k;
}

double Line::B()
{
	return b;
}

bool Line::IsVertical()
{
	return is_vertical;
}

bool Line::Relation(Line* l)
{
	if (l->IsVertical())
	{
		if (IsVertical())
			return 0;
		else
		{
			if (l->P1().x < std::min(p1.x, p2.x) || l->P1().x > std::max(p1.x, p2.x))
				return 0;
			else
			{
				return 1;
			}

		}
	}
	else
	{
		if (IsVertical())
		{
			double y = l->K() * p1.x + l->B();
			if (y <= std::max(p1.y,p2.y) && y >= std::min(p1.y, p2.y))
				return 1;
			else
			{
				return 0;
			}
		}
		else
		{
			if (l->K() == k)
				return 0;
			else
			{
				double same_x = (l->B() - b) / (k - l->K());
				double same_y = k * same_x + b;
				if (same_y <= std::max(p1.y, p2.y) && same_y >= std::min(p1.y, p2.y))
					return 1;
				else
				{
					return 0;
				}
			}
			

		}
	}
}

