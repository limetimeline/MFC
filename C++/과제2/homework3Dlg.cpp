
// homework3Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "homework3.h"
#include "homework3Dlg.h"
#include "afxdialogex.h"

/* 정렬하고 중복 숫자 삭제를 위한 것들 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Chomework3Dlg 대화 상자



Chomework3Dlg::Chomework3Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_HOMEWORK3_DIALOG, pParent)
	, mvalEdit1(_T(""))
	, mvalEdit2(_T(""))
	, mvalEdit3(_T(""))
	, mvalResult(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Chomework3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, mvalEdit1);
	DDX_Text(pDX, IDC_EDIT2, mvalEdit2);
	DDX_Text(pDX, IDC_EDIT3, mvalEdit3);
	DDX_Control(pDX, IDC_RADIO1, mctrlRadio1);
	DDX_Control(pDX, IDC_CHECK1, mctrlCheck1);
	DDX_Control(pDX, IDC_CHECK2, mctrlCheck2);
	DDX_Control(pDX, IDC_CHECK3, mctrlCheck3);
	DDX_Control(pDX, IDC_RADIO3, mctrlRadio3);
	DDX_Text(pDX, IDC_RESULT, mvalResult);
	DDX_Control(pDX, IDC_RADIO2, mctrlRadio2);
	DDX_Control(pDX, IDC_EDIT1, mctrlEdit1);
	DDX_Control(pDX, IDC_EDIT2, mctrlEdit2);
	DDX_Control(pDX, IDC_EDIT3, mctrlEdit3);
}

BEGIN_MESSAGE_MAP(Chomework3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &Chomework3Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Chomework3Dlg 메시지 처리기

BOOL Chomework3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	mctrlCheck1.SetCheck(TRUE); // 처음부터 체크박스 1이 체크되어 있다.
	mctrlCheck2.SetCheck(TRUE); // 처음부터 체크박스 2이 체크되어 있다.
	mctrlCheck3.SetCheck(TRUE); // 처음부터 체크박스 3이 체크되어 있다.
	mctrlRadio3.SetCheck(TRUE); // 처음부터 라디오버튼 3이 체크되어 있다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void Chomework3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void Chomework3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR Chomework3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Chomework3Dlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData();	// 컨트롤이 입력 받은 값을 value형 변수에 담기위함.
	CStringArray itemInfors;	// 입력받은 숫자를 공백 기준 쪼개서 저장함.
	CString A, s,b,c;	// A는 Edit1, Edit2, Edit3의 각각 입력받은 값을 모두 합쳐서 저장.
	int arr[100] = {};	// itemInfors를 정수로 변환하여 다시 저장. (정렬하기 위함.)

	
	/* 체크박스가 체크되어 있는 여부에 따라 A에 해당 Edit컨트롤에 입력된 값을 A에 합쳐서 저장 */
	if (mctrlCheck1.GetCheck() && mctrlCheck2.GetCheck() && mctrlCheck3.GetCheck()) {
		A = mvalEdit1 + " " + mvalEdit2 + " " + mvalEdit3;
	}
	else if (mctrlCheck1.GetCheck() && mctrlCheck2.GetCheck()) {
		A = mvalEdit1 + " " + mvalEdit2;
	}
	else if (mctrlCheck2.GetCheck() && mctrlCheck3.GetCheck()) {
		A = mvalEdit2 + " " +mvalEdit3;
	}
	else if (mctrlCheck1.GetCheck() && mctrlCheck3.GetCheck()) {
		A = mvalEdit1 + " " + mvalEdit3;
	}
	else if (mctrlCheck1.GetCheck()) {
		A = mvalEdit1;
	}
	else if (mctrlCheck2.GetCheck()) {
		A = mvalEdit2;
	}
	else if (mctrlCheck3.GetCheck()) {
		A = mvalEdit3;
	}

	/* SpliteArray 함수 : A에 저장된 문자열을 공백을 기준으로 잘라서 itemInfors에 저장 */
	SpliteArray(A, L" ", itemInfors);

	int a = itemInfors.GetSize();	// a에 itemInfors의 배열의 크기를 저장 (정수로 변환, 정렬할 때 사용)
	
	/* itemInfors에 담긴 값들을 정수로 변환하여 arr에 저장 */
	for (int i = 0; i < a; i++) {
		arr[i] = _ttoi(itemInfors[i]);
	}

	/* bubble_sort 함수 : arr에 담긴 값들을 오름차순 정렬, a는 배열의 크기가 담김 */
	bubble_sort(arr, a); 

	/* 라디오버튼 체크 여부에 따라 실행 */
	if (mctrlRadio1.GetCheck()) {	// 오름차순 정렬.
		for (int j = 0; j < a; j++) {
			b.Format(L"%d ", arr[j]);	// 정렬된 arr의 값을 b에 저장
			s.Append(b);	// s에 b의 값을 쌓는다.
		}
		mvalResult.Format(s);	// Result에 출력.
		
	}
	else if (mctrlRadio2.GetCheck()) { // 가장 큰 값.
		mvalResult.Format(L"%d", arr[a-1]);	// 정렬된 숫자 중 제일 마지막 값이 제일 큼.
	}
	else{	// 라디오버튼 3이 체크될 시. 오름차순 정렬 + 중복 숫자 제거.
		vector<int> vc;	// 정수형 벡터 vc
		for (int i = 0; i < a; i++) {
			vc.push_back(arr[i]);	// arr의 값들을 vc에 저장
		}
		sort(vc.begin(), vc.end());	// vc의 값을 정렬
		vc.erase(unique(vc.begin(), vc.end()),vc.end());	//vc에 정렬된 값들 중 중복된 값들을 끝으로 몰아내고 제거.
		
		/* vc에 저장된 사이즈 만큼 반복. */
		for (int j = 0; j < vc.size(); j++) {
			s.Format(L"%d ", vc[j]);	// vc에 저장된 값을 s에 저장
			b.Append(s);	// s의 값을 b에 쌓는다.
		}
		mvalResult = b;	// Result에 출력
	}
	

	UpdateData(FALSE);	// value형 변수에 저장된 값들을 컨트롤에 표시.
	/* 체크박스와 라디오버튼을 초기화. */
	mctrlCheck1.SetCheck(TRUE);
	mctrlCheck2.SetCheck(TRUE);
	mctrlCheck3.SetCheck(TRUE);
	mctrlRadio1.SetCheck(FALSE);
	mctrlRadio2.SetCheck(FALSE);
	mctrlRadio3.SetCheck(TRUE);
	/* Edit1,2,3에 표시된 값들을 삭제. */
	mctrlEdit1.SetSel(0, -1); // 처음부터 끝까지 선택
	mctrlEdit1.Clear();	// 선택된 값을 제거
	mctrlEdit2.SetSel(0, -1);
	mctrlEdit2.Clear();
	mctrlEdit3.SetSel(0, -1);
	mctrlEdit3.Clear();
}

/* 자를 문자열을 담고 있는 배열, 자르는 기준이 되는 문자, 잘라진 결과를 저장할 배열의 주소를 인자로 받는다. */
void Chomework3Dlg::SpliteArray(CString strData, CString Seperator, CStringArray& arr)
{
	CStringArray datas;
	CString Sep = Seperator;	// 구분할 기준이 담김
	CString data = strData;	// 받은 배열 저장
	int Position = 0;
	CString Token;
	Token = data.Tokenize(Seperator, Position);	// Token에 구분자로 구분한 첫번째 값이 저장됨.
	if (Token != L"") arr.Add(Token); // Token이 비어 있지 않으면 arr에 첫번째 값을 저장.
	while (!Token.IsEmpty())	// Token이 비어 있지 않을 동안 (배열에 저장되어 있는 값이 없는 인덱스가 나올 때 까지)
	{
		// Get next token
		Token = data.Tokenize(Seperator, Position);	// 구분자로 구분한 data의 값을 Token에 넣는다.
		if (Token != L"")	// Token이 비어 있지 않다면
		{
			arr.Add(Token);	// arr에 Token의 값을 넣는다.
		}
	}
}

/* 버블 정렬 알고리즘 */
void Chomework3Dlg::bubble_sort(int list[], int n) {
	int temp;
	/* 자신과 다음 숫자와 비교 했을 때 내가 작으면 그대로, 크면 temp에 실려 다음 숫자의 자리에 저장된다. */
	for (int i = 0 ; i < n; i++) {
		for (int j = 0; j < n-1; j++) {
			if (list[j] > list[j + 1]) { // list[j]의 값이 크면 
				temp = list[j];	// temp에 list[j]의 값이 저장
				list[j] = list[j + 1]; // list[j] 자리에  list[j+1]의 값을 저장
				list[j + 1] = temp; // list[j+1] 자리에 temp의 값을 저장.
			}
		}
	}
}

