#include "stdafx.h"
#include "CEngine.h"
<<<<<<< HEAD

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

void CEngine::deleteObjects(vector<CKey>& dels) 
{
	for (CKey k : dels)
	{
		objects.erase(k.getIter());
	}
	dels.clear();
}

void redrawAllObjects(CClientDC& dc, vector<list<CShape>::iterator>& selectedObjects)
{
	for(CSha)
}



=======
>>>>>>> 75a4fdef8ddddf63262c2ef9631d668489d4d796
