#include "OGRGeometry.h"

PointSet OGRGeometry::GetAllPoints() const
{
	return container;
}

std::string OGRGeometry::GetGeometryType()
{
	return type;
}

bool OGRGeometry::Equals(OGRGeometry* geo) const
{
	if (geo->IsEmpty())
	{
		std::cout << geo->GetID() << ":点集为空\n";
		return false;
	}
	if (IsEmpty())
	{
		std::cout << id << "为空\n";
		return false;
	}

	//如果点总数不一样，不比较，直接判负
	if (geo->GetAllPoints().size() != GetAllPoints().size())
		return false;

	PointSet geo_set = geo->GetAllPoints();
	for (int i = 0; i < geo_set.size(); ++i)
	{
		for (int j = 0; j < GetAllPoints().size(); ++j)
		{
			if (GetAllPoints()[j].x != geo_set[i].x && GetAllPoints()[j].y != geo_set[i].y)
			{
				return false;
			}
		}
	}
	return true;
}

int OGRGeometry::GetID()
{
	return id;
}
