
// glim_MFC_Task1_0808Dlg.h: 헤더 파일
//

#pragma once



// CglimMFCTask10808Dlg 대화 상자
class CglimMFCTask10808Dlg : public CDialogEx
{
	// 생성입니다.
private:
	CRect m_InitRect;
	CImage m_InitImage;
	CString g_strFileImage;

	void UpdateDisplay();
	void Create_BackGround();
	void Deny_Draw(CString msg);
	void Select_rand_num();
	void DrawCircle();
	void SaveImage();
	void DesideMoveAxis();
	void SetTextAxis(int  x, int y);
	void DrawXmark();
	bool IsinCircle(int i, int j);
	bool validimagePos(int x, int y);

	int m_nRand_Radius;
	int m_nCenterX;
	int m_nCenterY;
	int m_nPitch;
	int m_nColor;
	int m_nOpenImageX;
	int m_nOpenImageY;
	bool m_bIsMakedcircle;
	unsigned char* fm;
public:
	CglimMFCTask10808Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	static int m_snSttX, m_snSttY;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GLIM_MFC_TASK1_0808_DIALOG };
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
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedBtnDraw();

	// 시작좌표의 x값
	int m_nbeginX;

	// 시작좌표의 y값
	int m_nbeginY;

	// 종료좌표의 x값
	int m_nEndX;

	// 종료좌표의 y값
	int m_nEndY;
	afx_msg void OnBnClickedBtnAction();
	afx_msg void OnBnClickedBtnOpen();
};
