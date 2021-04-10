
// Homework4View.cpp: CHomework4View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Homework4.h"
#endif

#include "Homework4Doc.h"
#include "Homework4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHomework4View

IMPLEMENT_DYNCREATE(CHomework4View, CView)

BEGIN_MESSAGE_MAP(CHomework4View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CHomework4View 생성/소멸

CHomework4View::CHomework4View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
}

CHomework4View::~CHomework4View()
{
}

BOOL CHomework4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CHomework4View 그리기

void CHomework4View::OnDraw(CDC* pDC) // 창을 조작하거나 할 때 다시 그려줌 (refresh)
{
	CHomework4Doc* pDoc = GetDocument();	// Document 객체의 포인터를 얻어온다.
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	for (int i = 0; i < pDoc -> mLineCnt1; i++)	// 자유곡선의 개수만큼 돌림
	{
		for (int j = 0; j < pDoc -> mPointCnt[i] - 1; j++)	// 해당 자유곡선의 점 개수만큼 돌림
		{
			pDC->MoveTo(pDoc -> mPoint1[i][j]);	// 점의 시작점
			pDC->LineTo(pDoc -> mPoint1[i][j + 1]);	// 이까지 선을 그려라
		}
	}
	for (int i = 0; i < pDoc -> mLineCnt2; i++)	// 직선의 개수만큼 돌림
	{
			pDC->MoveTo(pDoc -> mPoint2[i][0]);	// 점의 시작점
			pDC->LineTo(pDoc -> mPoint2[i][1]);	// 이까지 선을 그려라
	}
}


// CHomework4View 진단

#ifdef _DEBUG
void CHomework4View::AssertValid() const
{
	CView::AssertValid();
}

void CHomework4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHomework4Doc* CHomework4View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHomework4Doc)));
	return (CHomework4Doc*)m_pDocument;
}
#endif //_DEBUG


// CHomework4View 메시지 처리기


void CHomework4View::OnLButtonDown(UINT nFlags, CPoint point)	// 왼쪽 마우스 버튼을 눌렀을 때
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CHomework4Doc* pDoc = GetDocument();	// Document 객체의 포인터를 얻어온다.
	pDoc -> mCnt = 0;	// 마우스를 누를 때 마다 mCnt를 0으로 초기화. (누를 때 마다 새 선이 생기기 때문)
	pDoc -> mPoint1[pDoc -> mLineCnt1][pDoc -> mCnt] = point; // 지금의 위치를 저장
	pDoc->mCnt++;
	CView::OnLButtonDown(nFlags, point);
}


void CHomework4View::OnLButtonUp(UINT nFlags, CPoint point)	// 왼쪽 마우스버튼을 뗏을 때
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CHomework4Doc* pDoc = GetDocument();	// Document 객체의 포인터를 얻어온다.
	if (pDoc -> mLineCnt1 < 100)	// 자유곡선의 개수가 100보다 작다면
	{
		pDoc -> mPointCnt[pDoc -> mLineCnt1] = pDoc -> mCnt;	// 몇 번째 선에 몇 개의 점이 있는지 저장
		pDoc -> mLineCnt1++;
	}
	CView::OnLButtonUp(nFlags, point);
}


void CHomework4View::OnMouseMove(UINT nFlags, CPoint point)	// 마우스가 움직일 때
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CHomework4Doc* pDoc = GetDocument(); // Document 객체의 포인터를 얻어온다.
	CClientDC dc(this);	// 디바이스 컨텍스트를 사용하겠다.
	if (pDoc -> mCnt < 10000 && nFlags & MK_LBUTTON)	// mCnt가 10000보다 작고 마우스를 누른 상태일 때
	{	
		dc.MoveTo(pDoc -> mPoint1[pDoc -> mLineCnt1][pDoc -> mCnt - 1]);	// 여기서
		dc.LineTo(point);	// 여기까지 선을 그려라
		pDoc -> mPoint1[pDoc -> mLineCnt1][pDoc -> mCnt] = point;	// 지금의 위치를 저장
		pDoc -> mCnt++;
	}
	
	CView::OnMouseMove(nFlags, point);
}


void CHomework4View::OnRButtonDown(UINT nFlags, CPoint point)	// 오른쪽 마우스 버튼을 눌렀을 때
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CHomework4Doc* pDoc = GetDocument();	// Document 객체의 포인터를 얻어온다.
	pDoc -> mPoint2[pDoc -> mLineCnt2][0] = point;	// 시작점
	CView::OnRButtonDown(nFlags, point);
}


void CHomework4View::OnRButtonUp(UINT nFlags, CPoint point)	// 오른쪽 마우스 버튼을 뗏을 때
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CHomework4Doc* pDoc = GetDocument();	// Document 객체의 포인터를 얻어온다.
	CClientDC dc(this);	// 디바이스 컨텍스트를 사용하겠다.
	if (pDoc -> mLineCnt2 < 100)	// mLineCnt2가 100보다 작다면
	{
		dc.MoveTo(pDoc -> mPoint2[pDoc -> mLineCnt2][0]);	// 시작점부터
		dc.LineTo(point);	// 여기까지 선을 그려라
		pDoc -> mPoint2[pDoc -> mLineCnt2][1]=point;	// 지금의 위치를 저장
		pDoc -> mLineCnt2++;
	}
	CView::OnRButtonUp(nFlags, point);
}
