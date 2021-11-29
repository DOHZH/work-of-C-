#include "OGRLineString.h"

OGRLineString::OGRLineString()
{
	length = 0.0f;
	type = "OGRLineString";
	type_index = 3;
	id = CalId(type_index);
}

bool OGRLineString::IsEmpty() const
{
	return container.empty();
}

void OGRLineString::GetMBR(OGREnvelope* e) const
{
	if (IsEmpty())
	{
		std::cout << "集合" << id << "为空集\n";
		return;
	}

	double minx = DBL_MAX, maxx = DBL_MIN, miny = DBL_MAX, maxy = DBL_MIN;

	for (int i = 0; i < container.size(); ++i)
	{
		double x = container[i].x;
		double y = container[i].y;
		if (x < minx)
			minx = x;

		if (x > maxx)
			maxx = x;

		if (y < miny)
			miny = y;

		if (y > maxy)
			maxy = y;
	}

	e->max_x = maxx;
	e->min_x = minx;
	e->max_y = maxy;
	e->min_y = miny;
}

OGREnvelope OGRLineString::GetMBR() const
{
	if (IsEmpty())
	{
		throw "集合" + std::to_string(id) + "为空集\n";
	}

	double minx = DBL_MAX, maxx = DBL_MIN, miny = DBL_MAX, maxy = DBL_MIN;

	for (int i = 0; i < container.size(); ++i)
	{
		double x = container[i].x;
		double y = container[i].y;
		if (x < minx)
			minx = x;

		if (x > maxx)
			maxx = x;

		if (y < miny)
			miny = y;

		if (y > maxy)
			maxy = y;
	}

	OGREnvelope e;

	e.max_x = maxx;
	e.min_x = minx;
	e.max_y = maxy;
	e.min_y = miny;

	return e;
}

void OGRLineString::Clone(OGRLineString* geo)
{
	container = geo->container;
	length = geo->length;
	
}

OGRLineString* OGRLineString::Clone()
{
	OGRLineString p;
	p.container = container;
	p.length = length;
	OGRLineString* result = &p;
	return result;
}

OGRErr OGRLineString::ImportFromWkt(std::string)
{
	throw "LineString无法读取文件\n";
	CalLineLength();
	return OGRErr::ReadErr;
}

OGRErr OGRLineString::ExportToWkt(std::string) const
{
	throw "LineString无法输出文件\n";
	return OGRErr::OutErr;
}

double OGRLineString::GetLength()
{
	CalLineLength();
	return length;
}

bool OGRLineString::Intersects(OGRLineString* l) const
{
	
	for (int i = 0; i < l->container.size() - 1; ++i)
	{
		for (int j = 0; j < container.size()-1; ++j)
		{
			Line self_imp(container[j].x, container[j].y, container[j+1].x, container[j+1].y);
			Line l_imp(l->container[i].x, l->container[i].y, l->container[i + 1].x, l->container[i + 1].y);
			if (!self_imp.Relation(&l_imp))
				return 0;
		}
	}	
	return 1;
}

double OGRLineString::Intersects(OGRPolygon* geo) const
{
	bool inner = 0;
	bool outer = 0;
	for (int i = 0; i < container.size(); ++i)
	{
		OGRPoint p(container[i]);
		if (geo->Contains(&p))
			inner = 1;
		else
		{
			outer = 1;
		}

		if (inner && outer)
			return 1;
	}
	
	return 0;
}

void OGRLineString::CalLineLength()
{
	double l = 0;
	for (int i = 0; i < container.size()-1; ++i)
	{
		l += CalLength(container[i],container[i+1]);
	}

	length = l;
}
