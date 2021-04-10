
// Homework4Doc.h: CHomework4Doc 클래스의 인터페이스
//


#pragma once


class CHomework4Doc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CHomework4Doc() noexcept;
	DECLARE_DYNCREATE(CHomework4Doc)

// 특성입니다.
public:
	CPoint mPoint1[100][10000];	// 자유곡선의 선 개수(최대 100개)와 점 개수(최대 10000개)를 담는다.
	CPoint mPoint2[100][2];	// 직선의 선 개수(최대 100개)와 시작점과 끝점을 담는다.
	int mPointCnt[100];	// 자유곡선의 몇 번째 선에 몇 개의 점을 담는다.
	int mCnt, mLineCnt1, mLineCnt2; // mCnt는 자유곡선 하나의 점을 센다. mLineCnt1과 2는 각각 자유곡선과 직선의 개수를 센다.
// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CHomework4Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
