
// QtQtQtView.cpp : CQtQtQtView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "QtQtQt.h"
#endif

#include "QtQtQtDoc.h"
#include "QtQtQtView.h"
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CQtQtQtView

IMPLEMENT_DYNCREATE(CQtQtQtView, CView)

BEGIN_MESSAGE_MAP(CQtQtQtView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_DRAW_TRI, &CQtQtQtView::OnDrawTri)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_DRAW_RECT, &CQtQtQtView::OnDrawRect)
	ON_COMMAND(ID_DRAW_CIRCLE, &CQtQtQtView::OnDrawCircle)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CQtQtQtView 생성/소멸
enum {DEFAULT, DRAW_TRIANGLE, DRAW_RECTANGLE, DRAW_CIRCLE, DRAW_POLYGON}f_stat;

CQtQtQtView::CQtQtQtView()
	: m_flag(0)
	, m_sPt(0)
	, m_ePt(0)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CQtQtQtView::~CQtQtQtView()
{
}

BOOL CQtQtQtView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CQtQtQtView 그리기

void CQtQtQtView::OnDraw(CDC* pDC)
{
	CQtQtQtDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	pDC->TextOutW(100, 200, _T("QtQt ZZange!"));
	CClientDC dc(this);

	m_Engine->redrawAllObjects(dc, selected_shape);
}


// CQtQtQtView 인쇄

BOOL CQtQtQtView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CQtQtQtView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CQtQtQtView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CQtQtQtView 진단

#ifdef _DEBUG
void CQtQtQtView::AssertValid() const
{
	CView::AssertValid();
}

void CQtQtQtView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CQtQtQtDoc* CQtQtQtView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CQtQtQtDoc)));
	return (CQtQtQtDoc*)m_pDocument;
}
#endif //_DEBUG

// CQtQtQtView 메시지 처리기

void CQtQtQtView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	SetCapture();
	switch (m_flag) {
	case DEFAULT:
		break;
	case DRAW_TRIANGLE:
		break;
	case DRAW_RECTANGLE:
		m_sPt = m_ePt = point;
		break;
	case DRAW_CIRCLE:
		m_sPt = m_ePt = point;
		break;
	}	
	CView::OnLButtonDown(nFlags, point);
}


void CQtQtQtView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	switch (m_flag) {
	case DEFAULT:
		break;
	case DRAW_TRIANGLE:
		break;
	case DRAW_RECTANGLE:
		m_Engine->createRectangle(m_sPt, m_ePt, RGB(255, 0, 0), RGB(0, 255, 255));
		break;
	case DRAW_CIRCLE:
		m_Engine->createCircle(m_sPt, m_ePt, RGB(255, 0, 0), RGB(0, 255, 255));
		break;
	}
	m_flag = DEFAULT;
	ReleaseCapture();
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}


void CQtQtQtView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	if (nFlags & MK_LBUTTON)
	{
		switch (m_flag) {
		case DEFAULT:
			break;
		case DRAW_TRIANGLE:
			break;
		case DRAW_RECTANGLE:
		{
			CRect rc(m_sPt, m_ePt);
			dc.SetROP2(R2_NOTXORPEN);
			dc.Rectangle(&rc);

			rc.SetRect(m_sPt, point);
			dc.Rectangle(&rc);
			m_ePt = point;
			break;
		}
		case DRAW_CIRCLE:
		{
			CRect rc(m_sPt, m_ePt);
			dc.SetROP2(R2_NOTXORPEN);
			dc.Ellipse(&rc);

			rc.SetRect(m_sPt, point);
			dc.Ellipse(&rc);
			m_ePt = point;
			break;
			break;
		}
		}
	}
	CView::OnMouseMove(nFlags, point);
}

void CQtQtQtView::OnDrawTri()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_flag = DRAW_TRIANGLE;
}

void CQtQtQtView::OnDrawRect()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_flag = DRAW_RECTANGLE;
}


void CQtQtQtView::OnDrawCircle()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_flag = DRAW_CIRCLE;
}


int CQtQtQtView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	m_Engine = new CEngine();
	return 0;
}
