#include "stdafx.h"
#include "CEngine.h"

void CEngine::createCircle(CPoint lu, CPoint ld, COLORREF brush, COLORREF pen)
{
	objects.push_front(new CCircle(lu, ld, brush, pen));
}

void CEngine::createRectangle(CPoint lu, CPoint ld, COLORREF brush, COLORREF pen)
{
	objects.push_front(new CRectangle(lu, ld, brush, pen));
}

void CEngine::createTriangle(CPoint u, CPoint v, CPoint w, COLORREF brush, COLORREF pen)
{
	objects.push_front(new CTriangle(u, v, w, brush, pen));
}

void CEngine::deleteObjects(vector<CKey>& dels) 
{
	for (CKey k : dels)
	{
		delete *k.getIter();
		objects.erase(k.getIter());
	}
	dels.clear();
}

void CEngine::redrawAllObjects(CClientDC& dc, vector<CKey>& selectedObjects)
{
	for (CShape* obj : objects) {
		obj->redraw(dc, false);
	}
}

CKey CEngine::find(CPoint pos) 
{
	CKey ret;
	for (auto iter = objects.begin(); iter != objects.end(); ++iter) {
		CShape* obj = *iter;
		if (obj->select(pos)) {
			ret.setIter(iter);
			break;
		}
	}
	return ret;
}


void CEngine::moveObjects(vector<CKey>& objects, CPoint moveVector) 
{
	for (CKey k : objects) {
		auto iter = k.getIter();
		CShape* obj = *iter;
		obj->move(moveVector);
	}
}