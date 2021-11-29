#include "OGRLinearRing.h"

OGRLinearRing::OGRLinearRing()
{
	length = 0.0f;
	type = "OGRLinearRing";
	type_index = 4;
	id = CalId(type_index);
}

double OGRLinearRing::GetLength()
{
	CalLineLength();
	return length;
}

bool OGRLinearRing::Intersects(OGRLineString* l) const
{
	for (int i = 0; i < l->container.size() - 1; ++i)
	{
		for (int j = 0; j < container.size(); ++j)
		{
			Line l_imp(l->container[i].x, l->container[i].y, l->container[i + 1].x, l->container[i + 1].y);
			if (j == container.size() - 1)
			{
				Line self_imp(container[j].x, container[j].y, container[0].x, container[0].y);
				if (!self_imp.Relation(&l_imp))
					return 0;
			}
			else
			{
				Line self_imp(container[j].x, container[j].y, container[j + 1].x, container[j + 1].y);
				if (!self_imp.Relation(&l_imp))
					return 0;
			}

		}
	}
	return 1;
}

void OGRLinearRing::CalLineLength()
{
	double l = 0;
	for (int i = 0; i < container.size(); ++i)
	{
		if (i == container.size()-1)
			l += CalLength(container[i], container[0]);
		else
		{
			l += CalLength(container[i], container[i + 1]);
		}
	}

	length = l;
}
