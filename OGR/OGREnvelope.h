#pragma once
class OGREnvelope
{
public:
	OGREnvelope();
	OGREnvelope(double maxx, double minx, double maxy, double miny);
	double min_x;
	double min_y;
	double max_x;
	double max_y;
};

