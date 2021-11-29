#include "OGREnvelope.h"

OGREnvelope::OGREnvelope()
{
	min_x = 0.0f;
	min_y = 0.0f;
	max_x = 0.0f;
	max_y = 0.0f;
}

OGREnvelope::OGREnvelope(double maxx, double minx, double maxy, double miny)
{
	min_x = minx;
	min_y = miny;
	max_x = maxx;
	max_y = maxy;
}
