
// QtQtQtView.cpp : CQtQtQtView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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
	// ǥ�� �μ� ����Դϴ�.
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

// CQtQtQtView ����/�Ҹ�
enum {DEFAULT, DRAW_TRIANGLE, DRAW_RECTANGLE, DRAW_CIRCLE, DRAW_POLYGON}f_stat;

CQtQtQtView::CQtQtQtView()
	: m_flag(0)
	, m_sPt(0)
	, m_ePt(0)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CQtQtQtView::~CQtQtQtView()
{
}

BOOL CQtQtQtView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CQtQtQtView �׸���

void CQtQtQtView::OnDraw(CDC* pDC)
{
	CQtQtQtDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	pDC->TextOutW(100, 200, _T("QtQt ZZange!"));
	CClientDC dc(this);

	m_Engine->redrawAllObjects(dc, selected_shape);
}


// CQtQtQtView �μ�

BOOL CQtQtQtView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CQtQtQtView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CQtQtQtView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CQtQtQtView ����

#ifdef _DEBUG
void CQtQtQtView::AssertValid() const
{
	CView::AssertValid();
}

void CQtQtQtView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CQtQtQtDoc* CQtQtQtView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CQtQtQtDoc)));
	return (CQtQtQtDoc*)m_pDocument;
}
#endif //_DEBUG

// CQtQtQtView �޽��� ó����

void CQtQtQtView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_flag = DRAW_TRIANGLE;
}

void CQtQtQtView::OnDrawRect()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_flag = DRAW_RECTANGLE;
}


void CQtQtQtView::OnDrawCircle()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	m_flag = DRAW_CIRCLE;
}


int CQtQtQtView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	m_Engine = new CEngine();
	return 0;
}
