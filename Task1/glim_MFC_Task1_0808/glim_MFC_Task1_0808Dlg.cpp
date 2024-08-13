
// glim_MFC_Task1_0808Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "glim_MFC_Task1_0808.h"
#include "glim_MFC_Task1_0808Dlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.
int CglimMFCTask10808Dlg::m_snSttX = 0;
int CglimMFCTask10808Dlg::m_snSttY = 0;
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

// CglimMFCTask10808Dlg 대화 상자

CglimMFCTask10808Dlg::CglimMFCTask10808Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GLIM_MFC_TASK1_0808_DIALOG, pParent)
	, m_nbeginX(0)
	, m_nbeginY(0)
	, m_nEndX(0)
	, m_nEndY(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CglimMFCTask10808Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDV_MinMaxInt(pDX, m_nbeginX, 0, 1000);
	DDX_Text(pDX, IDC_EDIT_BEGIN_X, m_nbeginX);
	DDX_Text(pDX, IDC_EDIT_BEGIN_Y, m_nbeginY);
	DDX_Text(pDX, IDC_EDIT_END_X, m_nEndX);
	DDX_Text(pDX, IDC_EDIT_END_Y, m_nEndY);
}

BEGIN_MESSAGE_MAP(CglimMFCTask10808Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CglimMFCTask10808Dlg::OnBnClickedOk)
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_BTN_DRAW, &CglimMFCTask10808Dlg::OnBnClickedBtnDraw)
	ON_BN_CLICKED(IDC_BTN_ACTION, &CglimMFCTask10808Dlg::OnBnClickedBtnAction)
	ON_BN_CLICKED(IDC_BTN_OPEN, &CglimMFCTask10808Dlg::OnBnClickedBtnOpen)
END_MESSAGE_MAP()


// CglimMFCTask10808Dlg 메시지 처리기

BOOL CglimMFCTask10808Dlg::OnInitDialog()
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

	m_bIsMakedcircle = false;
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}
///////////////////////////////////////////////////////////////////////////////

void CglimMFCTask10808Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CglimMFCTask10808Dlg::OnPaint()
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

HCURSOR CglimMFCTask10808Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CglimMFCTask10808Dlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}
/// <summary>
/// ///////////////////////////////////////////////////////////////////////////////////////
/// </summary>

void CglimMFCTask10808Dlg::OnBnClickedBtnDraw() // Draw 버튼 클릭 이벤트
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData();
	//////////////////////////////////
	if (m_nbeginX < 0 || m_nbeginX >1000 || m_nEndX < 0 || m_nEndX >1000)
	{
		Deny_Draw(_T("x 값은 0과 1000 사이의 값이어야 합니다."));
	}
	else if (m_nbeginY < 0 || m_nbeginY >450 || m_nEndY < 0 || m_nEndY > 450)
	{
		Deny_Draw(_T("y 값은 0과 450 사이의 값이어야 합니다."));
	}
	else if (m_nbeginX == m_nEndX && m_nbeginY == m_nEndY)
	{
		Deny_Draw(_T("시작좌표와 종료좌표는 동일할 수 없습니다."));
	}
	else
	{
		m_bIsMakedcircle = false; //Draw 누를때마다 static int 값 0으로 초기화
		Create_BackGround(); //배경 그리기
		Select_rand_num(); //난수 반지름 뽑기
		DrawCircle(); //원 그리기
		DesideMoveAxis(); // static int값으로 축 이동 방향 정하기
		SetTextAxis(m_nCenterX,m_nCenterY); // static Text 좌푯값 보여주기
		UpdateDisplay(); // 이미지 새로고침
	}
}

void CglimMFCTask10808Dlg::Create_BackGround()
{
	m_InitImage.Destroy();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int nWidth = 1000;
	int nHeight = 450;
	int nBpp = 8;
	int nSetcolor = 256;

	m_InitImage.Create(nWidth, -nHeight, nBpp);
	if (nBpp == 8)
	{
		static RGBQUAD rgb[256]; //RGB 색상 정의 256가지의 색상. 각 색상은 같은 값을 가진다ㅓ.
		for (int i = 0; i < 256; i++)
		{
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		}
		m_InitImage.SetColorTable(0, nSetcolor, rgb);
	}

	m_nPitch = m_InitImage.GetPitch(); // pitch 정의
	fm = (unsigned char*)m_InitImage.GetBits(); //fm 정의
	m_nColor = 80; //원의 색상 정의
	memset(fm, nSetcolor, nWidth * nHeight);

	UpdateDisplay();

}

void CglimMFCTask10808Dlg::Select_rand_num()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	int nBegin_randnum = 1;
	int nEnd_randnum = 122;
	std::uniform_int_distribution<int> dis(nBegin_randnum, nEnd_randnum);
	m_nRand_Radius = dis(gen);
	SetDlgItemInt(IDC_STATIC_RADIUS, m_nRand_Radius);
}

void CglimMFCTask10808Dlg::Deny_Draw(CString msg)
{
	CString x_range_error_msg = msg;
	AfxMessageBox(x_range_error_msg);
	m_nbeginX = m_nbeginY = m_nEndX = m_nEndY = 0;
	UpdateData(false);
}

void CglimMFCTask10808Dlg::DrawCircle()
{
	UpdateData();
	if (m_bIsMakedcircle == false)
	{
		m_snSttX = 0, m_snSttY = 0;
		if ((_waccess(_T(".\\image"), 0)) == -1)
			CreateDirectory(_T(".\\image"), NULL);
	}

	m_nCenterX = m_nbeginX + m_snSttX;
	m_nCenterY = m_nbeginY + m_snSttY;

	for (int j = m_nCenterY - m_nRand_Radius; j < m_nCenterY + m_nRand_Radius; j++)
	{
		for (int i = m_nCenterX - m_nRand_Radius; i < m_nCenterX + m_nRand_Radius; i++)
		{
			if (IsinCircle(i, j) && validimagePos(i, j))
			{
				fm[j * m_nPitch + i] = m_nColor;
			}
		}
	}

	m_bIsMakedcircle = true; //원이 한 번 생겼으니 true로 바꿔서 Action 버튼 가능하게만듦.
}

void CglimMFCTask10808Dlg::DesideMoveAxis()
{
	UpdateData();

	if (m_nCenterX < m_nEndX)
		m_snSttX++;
	else if (m_nCenterX > m_nEndX)
		m_snSttX--;
	else {/*축 이동 없음*/ }

	if (m_nCenterY < m_nEndY)
		m_snSttY++;
	else if (m_nCenterY > m_nEndY)
		m_snSttY--;
	else {/*축 이동 없음*/ }

	if (m_nCenterX == m_nEndX && m_nCenterY == m_nEndY)
	{
		MessageBox(_T("목표좌표에 도달했습니다. 초기화를 진행합니다."));
		m_nbeginX = m_nbeginY = m_nEndX = m_nEndY = 0;
		SetDlgItemText(IDC_STATIC_CURRENT_XY, _T(" "));
		SetDlgItemText(IDC_STATIC_RADIUS, _T(" "));
		memset(fm, 256, m_InitImage.GetHeight() * m_InitImage.GetWidth()); //직전 배경은 검은 화면으로
		UpdateData(false);
		UpdateDisplay();
		m_bIsMakedcircle = false;
	}
}

void CglimMFCTask10808Dlg::SetTextAxis(int x, int y)
{
	std::string strBeginXY = "(" + /*std::to_string(m_nCenterX) */std::to_string(x) + "," + std::to_string(y) + ")";
	CString csStaticbeginXY;
	csStaticbeginXY = strBeginXY.c_str();
	SetDlgItemText(IDC_STATIC_BEGIN_XY, csStaticbeginXY);
	UpdateData(false);
}

void CglimMFCTask10808Dlg::UpdateDisplay()
{
	CClientDC dc(this); //이곳에 작업공간이 있다는 것을 명시적으로 알리는 역할
	m_InitImage.Draw(dc, 0, 50); //dc에해당하는 그림을 창에 그리는데, 그림이 시작되는 x,y좌푯값은 (0,0)이다
}

void CglimMFCTask10808Dlg::OnBnClickedBtnAction() // Action 버튼 클릭 이벤트
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_bIsMakedcircle == true) //CImage 인스턴스 생성이 되었음을 확인한다면
	{
		while (true)
		{
			if (m_bIsMakedcircle == false)
			{
				break;
			}
			memset(fm, 256, m_InitImage.GetHeight() * m_InitImage.GetWidth()); //직전 배경은 검은 화면으로
			DrawCircle(); // 원 그리기
			SaveImage(); // 이미지 저장
			DesideMoveAxis(); // static int값으로 축 이동 방향 정하기
			SetTextAxis(m_nCenterX, m_nCenterY); // static Text 좌푯값 보여주기
			UpdateDisplay(); // 이미지 새로고침
		}

	}
	else //아직 CImage 생성이 안됐다고 판단
	{
		AfxMessageBox(_T("Please Click Draw button."));
	}
}

bool CglimMFCTask10808Dlg::IsinCircle(int i, int j)
{
	bool bRet = false;

	double dX = i - m_nCenterX;
	double dY = j - m_nCenterY;
	double dDist = dX * dX + dY * dY;
	if (dDist < m_nRand_Radius * m_nRand_Radius) //반지름의 제곱보다 두 제곱의 합이 작다면
	{
		bRet = true; 
	}
	return bRet;
}

bool CglimMFCTask10808Dlg::validimagePos(int x, int y)
{
	CRect rect(0, 0, m_InitImage.GetWidth(), m_InitImage.GetHeight());
	return rect.PtInRect(CPoint(x, y));
}

void CglimMFCTask10808Dlg::SaveImage()
{
	UpdateData();

	std::time_t now1 = std::time(nullptr);
	tm tm_1;
	localtime_s(&tm_1, &now1);
	std::string folderlocation = ".\\image\\_" + std::to_string(tm_1.tm_year + 1900) + std::to_string(tm_1.tm_mon+1)  + std::to_string(tm_1.tm_mday + 1)
		+ "_" + std::to_string(tm_1.tm_hour) +"h"+ std::to_string(tm_1.tm_min)+"m" + std::to_string(tm_1.tm_sec)+"s"
		+ "_" + "(" + std::to_string(m_nCenterX) + "," + std::to_string(m_nCenterY) + ")"+"_to_"+ "(" + std::to_string(m_nEndX) +"," 
		+ std::to_string(m_nEndY) + ").bmp";
	CString filename;
	filename = folderlocation.c_str();
	m_InitImage.Save(filename);
}

void CglimMFCTask10808Dlg::OnBnClickedBtnOpen()
{

	CString str = _T("All files(*.*)|*.*|"); // 모든 파일 표시
	CFileDialog dlg(TRUE, _T("*.dat"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, str, this);
	CString strPathName;
	CClientDC dc(this);

	if (dlg.DoModal() == IDOK)
	{
		if (m_InitImage == NULL)
		{
			Create_BackGround();
		}
		m_InitImage.Destroy();
		strPathName = dlg.GetPathName();
		m_InitImage.Load(strPathName);
		m_InitImage.Draw(dc,0,50, m_InitImage.GetWidth(), m_InitImage.GetHeight());
		m_nPitch = m_InitImage.GetPitch(); //한 행의 메모리에서 차지하는 바이트 수 반환, 즉, 이미지의 너비가 npitch 만큼의 메모리 공간을 차지
		fm = (unsigned char*)m_InitImage.GetBits();
		UpdateDisplay();

		int nStart_index = NULL, nComma_index = NULL, nEnd_index = NULL;
		for (int i = 0; i < strPathName.GetLength(); i++)
		{
			if (strPathName[i] == '(')
			{
				nStart_index = i;
			}
			else if (strPathName[i] == ',')
			{
				nComma_index = i;
			}
			else if (strPathName[i] == ')')
			{
				nEnd_index = i;
				break;
			}
		}
		/////////////////////////////////////////////////////////////////////////////////////////////
		std::string OpenImageXY = (CT2CA)strPathName;
		m_nOpenImageX = stoi(OpenImageXY.substr(nStart_index + 1, nComma_index - nStart_index - 1));
		m_nOpenImageY = stoi(OpenImageXY.substr(nComma_index + 1, nEnd_index - nComma_index - 1));
		SetTextAxis(m_nOpenImageX, m_nOpenImageY);
		m_bIsMakedcircle = false;
		/////////////////////////////////////////////////////////////////////////////////////////////
		DrawXmark();

		UpdateDisplay();
		CString Image_XYtxt;
		Image_XYtxt.Format(_T("(%d, %d)"), m_nOpenImageX, m_nOpenImageY);
		std::cout << m_nOpenImageX + 55 << "," << m_nOpenImageY << std::endl;
		dc.TextOutW(m_nOpenImageX + 55, m_nOpenImageY, Image_XYtxt);
	}
	else{/*파일 탐색기 취소버튼*/ }

}

void CglimMFCTask10808Dlg::DrawXmark()
{
	for (int i = -5; i < 6; i++)
	{
		for (int j = -5; j < 6; j++)
		{
			if (i == j && validimagePos(m_nOpenImageX + j, m_nOpenImageY + i))
			{
				fm[(m_nOpenImageY + i) * m_nPitch + (m_nOpenImageX + j)] = 255;
			}
		}
	}
	for (int i = -5; i < 6; i++)
	{
		for (int j = -5; j < 6; j++)
		{
			if (i == j && validimagePos(m_nOpenImageX + j, m_nOpenImageY + i))
			{
				fm[(m_nOpenImageY + i) * m_nPitch + (m_nOpenImageX - j)] = 255;
			}
		}
	}
	CClientDC dc(this);



}
