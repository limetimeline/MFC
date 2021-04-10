
// homework3Dlg.h: 헤더 파일
//

#pragma once


// Chomework3Dlg 대화 상자
class Chomework3Dlg : public CDialogEx
{
// 생성입니다.
public:
	Chomework3Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HOMEWORK3_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//int GetFindCharCount(CString parm_string, char parm_find_char);
	void SpliteArray(CString strData, CString Seperator, CStringArray& arr);
	void bubble_sort(int list[], int n);
	int nodup(char w[], int n, char s);
	DECLARE_MESSAGE_MAP()
public:
	CString mvalEdit1;
	CString mvalEdit2;
	CString mvalEdit3;
	CButton mctrlRadio1;
	CButton mctrlCheck1;
	CButton mctrlCheck2;
	CButton mctrlCheck3;
	afx_msg void OnBnClickedOk();
	CButton mctrlRadio3;
	CString mvalResult;
	CButton mctrlRadio2;
	CEdit mctrlEdit1;
	CEdit mctrlEdit2;
	CEdit mctrlEdit3;
};

//void deleteValue(int a[], int size, int index);
