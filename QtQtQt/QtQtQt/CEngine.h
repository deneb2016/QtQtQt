#pragma once
#include "stdafx.h"
#include <list>
#include <vector>
#include "CShape.h"

using namespace std;
class CKey {
private:
	std::list<CShape*>::iterator iter;
	bool isValid;

public:
	CKey() {
		isValid = false;
	}
	bool isNull() {
		return !isValid;
	}
	void setIter(std::list<CShape*>::iterator it) {
		iter = it;
		isValid = true;
	}
	void setNull() {
		isValid = false;
	}
	std::list<CShape*>::iterator getIter() {
		return iter;
	}
};
class CEngine {
private:
	std::list<CShape*> objects;

public:
	void createCircle(CPoint lu, CPoint ld, COLORREF brush, COLORREF pen);
	void createRectangle(CPoint lu, CPoint rd, COLORREF brush, COLORREF pen);
	void createTriangle(CPoint u, CPoint v, CPoint w, COLORREF brush, COLORREF pen);

	void deleteObjects(vector<CKey>& dels);
	void redrawAllObjects(CClientDC& dc, vector<CKey>& selectedObjects); //: 모든 오브젝트에 대해 redraw호출
	CKey find(CPoint pos); //pos에 있는 오브젝트를 찾아서 키값 리턴
	void moveObjects(vector<CKey>& objects, CPoint moveVector);// : objects들 이동f


};