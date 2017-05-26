#include "stdafx.h"
#include "CEngine.h"

void CEngine::createCircle(CPoint lu, CPoint ld, COLORREF brush, COLORREF pen)
{
	objects.push_back(CCircle(lu, ld, brush, pen));
}

void CEngine::createRectangle(CPoint lu, CPoint ld, COLORREF brush, COLORREF pen)
{
	objects.push_back(CRectangle(lu, ld, brush, pen));
}

void CEngine::createTriangle(CPoint u, CPoint v, CPoint w, COLORREF brush, COLORREF pen)
{
	objects.push_back(CTriangle(u, v, w, brush, pen));
}


