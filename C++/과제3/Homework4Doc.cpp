
// Homework4Doc.cpp: CHomework4Doc 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Homework4.h"
#endif

#include "Homework4Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CHomework4Doc

IMPLEMENT_DYNCREATE(CHomework4Doc, CDocument)

BEGIN_MESSAGE_MAP(CHomework4Doc, CDocument)
END_MESSAGE_MAP()


// CHomework4Doc 생성/소멸

CHomework4Doc::CHomework4Doc() noexcept
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.
	mCnt = mLineCnt1 = mLineCnt2 = 0;	// Doc클래스가 생성될 때 해당 변수들을 0으로 초기화.

}

CHomework4Doc::~CHomework4Doc()
{
}

BOOL CHomework4Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CHomework4Doc serialization

void CHomework4Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
		AfxMessageBox(L"저장되었습니다.");	// 메시지박스 출력
		ar << mLineCnt1;	// 자유곡선의 개수 저장
		ar << mLineCnt2;	// 직선의 개수 저장
		for (int i = 0; i < mLineCnt1; i++)	// 자유곡선의 개수만큼 돌림
		{
			ar << mPointCnt[i];	// 해당 자유곡선의 점 개수를 저장
			for (int j = 0; j < mPointCnt[i]; j++)	// 점 개수만큼 돌림
			{
				
				ar << mPoint1[i][j];	// 실질적인 자유곡선의 위치와 점을 값을 저장
			}
		}
		for (int i = 0; i < mLineCnt2; i++)	// 직선의 개수만큼 돌림
		{
			for (int j = 0; j < 2; j++)	// 점의 시작과 끝
			{
				ar << mPoint2[i][j];	// 실질적인 직선의 위치와 점을 값으로 저장
				
			}
		}
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
		AfxMessageBox(L"불러왔습니다.");	// 메시지박스 출력
		ar >> mLineCnt1;	// 자유곡선의 개수 불러오기
		ar >> mLineCnt2;	// 직선의 개수 불러오기
		for (int i = 0; i < mLineCnt1; i++)	// 자유곡선의 개수만큼 돌림
		{
			ar >> mPointCnt[i];	// 해당 자유곡선의 점을 불러오기
			for (int j = 0; j < mPointCnt[i]; j++)	// 점의 개수만큼 돌림
			{
				
				ar >> mPoint1[i][j];	// 실직적인 자유곡선의 위치, 점 값을 불러오기
			}
		}
		for (int i = 0; i < mLineCnt2; i++)	// 직선의 개수 불러오기
		{
			for (int j = 0; j < 2; j++)	// 점의 시작과 끝
			{
				ar >> mPoint2[i][j];	//실질적인 직선의 위치와 점을 값으로 저장

			}
		}
		UpdateAllViews(NULL);	// OnDraw()를 강제로 호출!
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CHomework4Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void CHomework4Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CHomework4Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CHomework4Doc 진단

#ifdef _DEBUG
void CHomework4Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHomework4Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CHomework4Doc 명령
