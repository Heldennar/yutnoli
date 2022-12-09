
// yutnoliDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "yutnoli.h"
#include "yutnoliDlg.h"
#include "afxdialogex.h"
#include <atlimage.h>
#include <afxsock.h>
#include "YutnoriClass.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:

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


void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CyutnoliDlg 대화 상자



CyutnoliDlg::CyutnoliDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_YUTNOLI_DIALOG, pParent)
	, m_strIP(_T("127.0.0.1"))
	, m_strSend(_T(""))
	, m_strUserID(_T("대기 중"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CyutnoliDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, position1, g1);
	DDX_Control(pDX, position2, g2);
	DDX_Control(pDX, position3, g3);
	DDX_Control(pDX, position4, g4);
	DDX_Control(pDX, position5, g5);
	DDX_Control(pDX, position6, g6);
	DDX_Control(pDX, position7, g7);
	DDX_Control(pDX, position8, g8);
	DDX_Control(pDX, position9, g9);
	DDX_Control(pDX, position10, g10);
	DDX_Control(pDX, position11, g11);
	DDX_Control(pDX, position12, g12);
	DDX_Control(pDX, position13, g13);
	DDX_Control(pDX, position14, g14);
	DDX_Control(pDX, position15, g15);
	DDX_Control(pDX, position16, g16);
	DDX_Control(pDX, position17, g17);
	DDX_Control(pDX, position18, g18);
	DDX_Control(pDX, position19, g19);
	DDX_Control(pDX, position20, g20);
	DDX_Control(pDX, position21, g21);
	DDX_Control(pDX, position22, g22);
	DDX_Control(pDX, position23, g23);
	DDX_Control(pDX, position24, g24);
	DDX_Control(pDX, position25, g25);
	DDX_Control(pDX, position26, g26);
	DDX_Control(pDX, position27, g27);
	DDX_Control(pDX, position28, g28);
	DDX_Control(pDX, position29, g29);
	DDX_Control(pDX, position30, g30);


	DDX_Control(pDX, player11, p11);
	DDX_Control(pDX, player12, p12);
	DDX_Control(pDX, player13, p13);
	DDX_Control(pDX, player14, p14);
	DDX_Control(pDX, player21, p21);
	DDX_Control(pDX, player22, p22);
	DDX_Control(pDX, player23, p23);
	DDX_Control(pDX, player24, p24);

	DDX_Control(pDX, stick1, st1);
	DDX_Control(pDX, stick2, st2);
	DDX_Control(pDX, stick3, st3);
	DDX_Control(pDX, stick4, st4);

	DDX_Text(pDX, IDC_CHAT_EDIT, m_strSend);
	DDX_Text(pDX, IDC_STATIC_USERID, m_strUserID);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_EDIT_IP, m_strIP);
	DDX_Control(pDX, IDC_STATIC_USERID, m_useID);
	DDX_Control(pDX, IDC_MOVE_LIST, m_move_list);
	DDX_Control(pDX, position30, g30);
}

BEGIN_MESSAGE_MAP(CyutnoliDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(UM_RECEIVE, OnReceive)
	ON_BN_CLICKED(IDC_BUTTON_CONNECT, &CyutnoliDlg::OnClickedButtonConnect)
	ON_BN_CLICKED(IDCANCEL, &CyutnoliDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON_SEND, &CyutnoliDlg::OnClickedButtonSend)
	ON_BN_CLICKED(IDC_THROW, &CyutnoliDlg::OnBnClickedThrow)
	ON_STN_CLICKED(player11, &CyutnoliDlg::OnClickedPlayer11)
	ON_BN_CLICKED(IDC_READY, &CyutnoliDlg::OnClickedReady)
	ON_BN_CLICKED(IDC_P1B, &CyutnoliDlg::OnClickedP1b)
	ON_BN_CLICKED(IDC_P2B, &CyutnoliDlg::OnClickedP2b)
	ON_BN_CLICKED(IDC_P3B, &CyutnoliDlg::OnClickedP3b)
	ON_BN_CLICKED(IDC_P4B, &CyutnoliDlg::OnClickedP4b)
	ON_STN_CLICKED(player12, &CyutnoliDlg::OnClickedPlayer12)
	ON_STN_CLICKED(player13, &CyutnoliDlg::OnClickedPlayer13)
	ON_STN_CLICKED(player14, &CyutnoliDlg::OnClickedPlayer14)
	ON_STN_CLICKED(position1, &CyutnoliDlg::OnClickedPosition1)
	ON_STN_CLICKED(position10, &CyutnoliDlg::OnClickedPosition10)
	ON_STN_CLICKED(position11, &CyutnoliDlg::OnClickedPosition11)
	ON_STN_CLICKED(position12, &CyutnoliDlg::OnClickedPosition12)
	ON_STN_CLICKED(position13, &CyutnoliDlg::OnClickedPosition13)
	ON_STN_CLICKED(position14, &CyutnoliDlg::OnClickedPosition14)
	ON_STN_CLICKED(position15, &CyutnoliDlg::OnClickedPosition15)
	ON_STN_CLICKED(position16, &CyutnoliDlg::OnClickedPosition16)
	ON_STN_CLICKED(position17, &CyutnoliDlg::OnClickedPosition17)
	ON_STN_CLICKED(position18, &CyutnoliDlg::OnClickedPosition18)
	ON_STN_CLICKED(position19, &CyutnoliDlg::OnClickedPosition19)
	ON_STN_CLICKED(position2, &CyutnoliDlg::OnClickedPosition2)
	ON_STN_CLICKED(position20, &CyutnoliDlg::OnClickedPosition20)
	ON_STN_CLICKED(position21, &CyutnoliDlg::OnClickedPosition21)
	ON_STN_CLICKED(position22, &CyutnoliDlg::OnClickedPosition22)
	ON_STN_CLICKED(position23, &CyutnoliDlg::OnClickedPosition23)
	ON_STN_CLICKED(position24, &CyutnoliDlg::OnClickedPosition24)
	ON_STN_CLICKED(position25, &CyutnoliDlg::OnClickedPosition25)
	ON_STN_CLICKED(position26, &CyutnoliDlg::OnClickedPosition26)
	ON_STN_CLICKED(position27, &CyutnoliDlg::OnClickedPosition27)
	ON_STN_CLICKED(position28, &CyutnoliDlg::OnClickedPosition28)
	ON_STN_CLICKED(position29, &CyutnoliDlg::OnClickedPosition29)
	ON_STN_CLICKED(position3, &CyutnoliDlg::OnClickedPosition3)
	ON_STN_CLICKED(position30, &CyutnoliDlg::OnClickedPosition30)
	ON_STN_CLICKED(position4, &CyutnoliDlg::OnClickedPosition4)
	ON_STN_CLICKED(position5, &CyutnoliDlg::OnClickedPosition5)
	ON_STN_CLICKED(position6, &CyutnoliDlg::OnClickedPosition6)
	ON_STN_CLICKED(position7, &CyutnoliDlg::OnClickedPosition7)
	ON_STN_CLICKED(position8, &CyutnoliDlg::OnClickedPosition8)
	ON_STN_CLICKED(position9, &CyutnoliDlg::OnClickedPosition9)
END_MESSAGE_MAP()


// CyutnoliDlg 메시지 처리기

BOOL CyutnoliDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	
	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	

	

	

	c_image.Load(L"images\\circle.png");
	h_bmp = (HBITMAP)c_image;
	g1.SetBitmap(h_bmp);
	g2.SetBitmap(h_bmp);
	g3.SetBitmap(h_bmp);
	g4.SetBitmap(h_bmp);
	g5.SetBitmap(h_bmp);
	g6.SetBitmap(h_bmp);
	g7.SetBitmap(h_bmp);
	g8.SetBitmap(h_bmp);
	g9.SetBitmap(h_bmp);
	g10.SetBitmap(h_bmp);
	g11.SetBitmap(h_bmp);
	g12.SetBitmap(h_bmp);
	g13.SetBitmap(h_bmp);
	g14.SetBitmap(h_bmp);
	g15.SetBitmap(h_bmp);
	g16.SetBitmap(h_bmp);
	g17.SetBitmap(h_bmp);
	g18.SetBitmap(h_bmp);
	g19.SetBitmap(h_bmp);
	g20.SetBitmap(h_bmp);
	g21.SetBitmap(h_bmp);
	g22.SetBitmap(h_bmp);
	g23.SetBitmap(h_bmp);
	g24.SetBitmap(h_bmp);
	g25.SetBitmap(h_bmp);
	g26.SetBitmap(h_bmp);
	g27.SetBitmap(h_bmp);
	g28.SetBitmap(h_bmp);
	g29.SetBitmap(h_bmp);

	c_image.Detach();
	c_image.Load(L"images\\redcircle.png");
	h_bmp = (HBITMAP)c_image;
	p11.SetBitmap(h_bmp);
	p12.SetBitmap(h_bmp);
	p13.SetBitmap(h_bmp);
	p14.SetBitmap(h_bmp);
	
	c_image.Detach();
	c_image.Load(L"images\\yellowcircle.png");
	h_bmp = (HBITMAP)c_image;
	p21.SetBitmap(h_bmp);
	p22.SetBitmap(h_bmp);
	p23.SetBitmap(h_bmp);
	p24.SetBitmap(h_bmp);

	c_image.Detach();
	c_image.Load(L"images\\stick.png");
	h_bmp = (HBITMAP)c_image;
	st1.SetBitmap(h_bmp);
	st2.SetBitmap(h_bmp);
	st3.SetBitmap(h_bmp);
	st4.SetBitmap(h_bmp);
	c_image.Detach();


	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CyutnoliDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if (nID == SC_CLOSE) {    // 클라이언트 종료시 서버로 메세지 보냄.
		m_socCom.Send(SOC_CLIENT_DISCONNECT, 256);
		this->EndDialog(IDCANCEL);
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}



// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CyutnoliDlg::OnPaint()
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
HCURSOR CyutnoliDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

LPARAM CyutnoliDlg::OnReceive(WPARAM wParam, LPARAM lParam) {

	// 접속된 곳에서 데이터가 도착했을 때
	UpdateData(TRUE);
	CString strTmp;

	unsigned char check, msg_id;//message_id
	unsigned short int body_size;

	m_socCom.Receive((char*)&check, 1, 0);    // wParam = 클라이언트 번호/헤더 1바이트 읽기
	m_socCom.Receive((int*)&body_size, 1, 0);
	char* pTmp = new char[body_size];
	memset(pTmp, '\0', body_size);
	m_socCom.Receive(pTmp, body_size, 0);
	strTmp = CH2CS(pTmp);
	CString chstrg = _T("상대 사용자 : ");

	// 서버로 부터 연결완료 메세지를 받으면
	if (strTmp.Find(_T(SOC_CLIENT_CONNECT)) == 0) {
		// Right 함수를 이용해 가장 오른쪽에 있는 번호 추출. 0은 \0이다.
		m_strUserID = _T("사용자 : ") + strTmp.Right(1);
		m_useID.SetWindowTextW(_T("접속중"));
	}
	else {
		switch (check)
		{
		case(20)://채팅
		{
			m_list.AddString(chstrg + strTmp);
			break;
		}
		case(91)://준비 87시작 88선턴 89후턴
		{
			m_list.AddString(chstrg + strTmp);
			break;
		}
		case(87): {
			playing = TRUE;
			m_list.AddString(strTmp);
			break;
		}
		case(88): 
		{
			playing = TRUE;
			turn = TRUE;
			diceT = TRUE;
			m_list.AddString(strTmp);
			break;
		}
		case(89):
		{
			playing = TRUE;
			turn = FALSE;
			diceT = FALSE;
			m_list.AddString(strTmp);
			break;
		}
		case(90): // 준비해제
		{
			m_list.AddString(chstrg + strTmp);
			break;
		}
		case(100) ://턴 전환
		{
			turn = TRUE;
			diceT = TRUE;
			m_list.AddString(strTmp);
			m_list.AddString(_T("윷을 굴려주십시오."));
			break;
		}
		case(45): // 상대 1~4번말 움직이기
		case(44):
		case(43):
		case(42):
		case(41):
		case(35):
		case(34):
		case(33):
		case(32):
		case(31):
		case(25):
		case(24):
		case(23):
		case(22):
		case(21):
		case(15):
		case(14):
		case(13):
		case(12):
		case(11): 
		{
			int vsplay = check / 10;
			int vsmove = check % 10;
			cngB(1,player2[vsplay]);
			for (int k = 0; k < 4; k++) {
				if (player2[vsplay] == player2[k])
					player2[k] += vsmove;
			}
			m_list.AddString(chstrg + strTmp);
			checkMv(vsplay);
			break;
		}
		case(46):
		case(36):
		case(26):
		case(16):
		{
			int vsplay = check / 10;
			player2[vsplay] -= 1;
			m_list.AddString(chstrg + strTmp);
			checkMv(vsplay);
			break;
		}
		case(6): //상대 도개걸윷모 출력
		case(5):
		case(4):
		case(3):
		case(2):
		case(1):
		{
			m_list.AddString(chstrg + strTmp);
			break;
		}
		case(99): //상대 승리
		{
			m_list.AddString(strTmp);
			break;
		}

		}
	}
	delete []pTmp;
	UpdateData(FALSE);
	return TRUE;
}



void CyutnoliDlg::OnClickedButtonConnect()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_socCom.Create();
	// IP 주소와 포트 번호를 지정
	m_socCom.Connect(m_strIP, 5000);
	m_socCom.Init(this->m_hWnd);
}

CString CyutnoliDlg:: CH2CS(char* strInput)

{

	// ## char* -> wchar_t -> CString ##

	wchar_t* strWCHAR;
	CString strOutput;
	int iLength;

	iLength = MultiByteToWideChar(CP_ACP, 0, strInput, strlen(strInput), NULL, NULL);
	strWCHAR = SysAllocStringLen(NULL, iLength);
	MultiByteToWideChar(CP_ACP, 0, strInput, strlen(strInput), strWCHAR, iLength);

	strOutput.Format(_T("%s"), strWCHAR);

	return strOutput;
}

char* CyutnoliDlg::CS2CHAR(CString strInput)

{

	// ## CString -> wchar_t -> char* ##
	wchar_t* strWCHAR;
	char* strOutput;
	int iLength;

	strWCHAR = strInput.GetBuffer(strInput.GetLength());

	iLength = WideCharToMultiByte(CP_ACP, 0, strWCHAR, -1, NULL, 0, NULL, NULL);

	strOutput = new char[iLength];

	WideCharToMultiByte(CP_ACP, 0, strWCHAR, -1, strOutput, iLength, 0, 0);
	
	return strOutput;

}

void CyutnoliDlg::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_socCom.Send(SOC_CLIENT_DISCONNECT, 256);        // 서버로 종료 메시지 보냄
	this->EndDialog(IDCANCEL);                        // Dialog 닫기
	CDialogEx::OnCancel();
}

void CyutnoliDlg::SendChat(CString str, int check)
{
	if (check == 100)
		m_list.AddString(_T("턴을 넘깁니다."));
	unsigned short int strlen = str.GetLength();
	m_list.AddString(str);
	int len_s = (sizeof(char) * strlen * 2) + 1;
	char * pTmp = new char[strlen];
	pTmp = CS2CHAR(str);
	char* buff = new char[len_s + 2];
	*buff = check;//20 = 채팅, NXY(N플레이어가X말을 Y만큼 움직임)
	*(buff + 1) = len_s;
	memcpy(buff + 2, pTmp, len_s);
	m_socCom.Send(buff,len_s+2);

	
	delete[] buff;
	delete[] pTmp;
}

void CyutnoliDlg::OnClickedButtonSend()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	TCHAR pTmp[256];
	CString strTmp;

	// pTmp에 전송할 데이터 입력
	memset(pTmp, '\0', 256);
	strTmp = m_strSend;
	_tcsncpy_s(pTmp, strTmp, _countof(pTmp));
	m_strSend = "";

	// 전송
	SendChat(strTmp, 20);

	/* 전송한 데이터도 리스트박스에 보여준다.
	strTmp.Format(_T("%s"), pTmp);
	int i = m_list.GetCount();
	m_list.AddString(strTmp);
	*/
	UpdateData(FALSE);
}


void CyutnoliDlg::OnBnClickedThrow()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	UpdateData(TRUE);
	CString str;
	if (!moveT && turn && playing && diceT) {
		roll_m++;
		int rollv = roll(roll_m);
		switch (rollv)
		{
		case -1:
		{
			str = "백도가 나왔습니다.";
			SendChat(str, 6);
			diceT = FALSE;
			for (int j = 0; j < 4; j++)
			{
				if (player1[j] == 0)
				{
					str = "이동 가능한 말이 없습니다.";
					SendChat(str, 100);
				}
			}
			break;
		}
		case 1: {
			str = "도가 나왔습니다.";
			SendChat(str, 1);
			diceT = FALSE;
			m_list.AddString(_T("이동시킬 말을 골라주십시오."));
			break;
		}
		case 2: {
			str = "개가 나왔습니다.";
			SendChat(str, 2);
			diceT = FALSE;
			m_list.AddString(_T("이동시킬 말을 골라주십시오."));
			break;
		}
		case 3: {
			str = "걸이 나왔습니다.";
			SendChat(str, 3);
			diceT = FALSE;
			m_list.AddString(_T("이동시킬 말을 골라주십시오."));
			break;
		}
		case 4: {
			str = "윷이 나왔습니다.";
			SendChat(str, 4);
			m_list.AddString(_T("한번 더 윷을 굴려주십시오."));
			break;
		}
		case 0: {
			str = "모가 나왔습니다.";
			SendChat(str, 5);
			m_list.AddString(_T("한번 더 윷을 굴려주십시오."));
			break;
		}

		}
		
	}
	else
		MessageBox(L"당신의 차례가 아닙니다.");
	CString mvstr;
	UpdateData(FALSE);
	dice_v();

	
}

CString CyutnoliDlg::dice_v()
{
	m_move_list.ResetContent();
	CString temp = _T("");

	for (int i = 0; i <= roll_m; i++) {
		if (moveNum[i] == 1)
		{
			temp.Append(_T("도 /"));
		}
		else if (moveNum[i] == 2)
		{
			temp.Append(_T("개 /"));
		}
		else if (moveNum[i] == 3)
		{
			temp.Append(_T("걸 /"));
		}
		else if (moveNum[i] == 4)
		{
			temp.Append(_T("윷 /"));
		}
		else if (moveNum[i] == 5)
		{
			temp.Append(_T("모 /"));
		}
		else if (moveNum[i] == -1)
		{
			temp.Append(_T("백도 /"));
		}
	}
	m_move_list.AddString(temp);
	return temp;
}

void CyutnoliDlg::cngB(int dest, int www) //1= 중립화 2=파랑 3 = 빨강
{
	if (1)
	{
		h_bmp = (HBITMAP)c_image;
		switch (www)
		{
		case 1: {
			c_image.Load(L"images\\circle.png"); 
			break;
		}
		case 2: {
			c_image.Load(L"images\\bluecircle.png");
			break;
		}
		case 3: {
			c_image.Load(L"images\\redcircle.png");
			break;
		}

		}
		
		switch (dest) {
		case 1: {
			g2.SetBitmap(h_bmp);
			break;
		}
		case 2: {
			g3.SetBitmap(h_bmp);
			break;
		}
		case 3: {
			g4.SetBitmap(h_bmp);
			break;
		}
		case 4: {
			g5.SetBitmap(h_bmp);
			break;
		}
		case 5: {
			g6.SetBitmap(h_bmp);
			break;
		}
		case 6: {
			g7.SetBitmap(h_bmp);
			break;
		}
		case 7: {
			g8.SetBitmap(h_bmp);
			break;
		}
		case 8: {
			g9.SetBitmap(h_bmp);
			break;
		}
		case 9: {
			g10.SetBitmap(h_bmp);
			break;
		}
		case 10: {
			g11.SetBitmap(h_bmp);
			break;
		}
		case 11: {
			g2.SetBitmap(h_bmp);
			break;
		}
		case 12: {
			g2.SetBitmap(h_bmp);
			break;
		}
		case 13: {
			g2.SetBitmap(h_bmp);
			break;
		}
		case 14: {
			g2.SetBitmap(h_bmp);
			break;
		}
		case 15: {
			g2.SetBitmap(h_bmp);
			break;
		}
		case 16: {
			g2.SetBitmap(h_bmp);
			break;
		}
		case 17: {
			g2.SetBitmap(h_bmp);
			break;
		}
		case 18: {
			g2.SetBitmap(h_bmp);
			break;
		}
		case 19: {
			g2.SetBitmap(h_bmp);
			break;
		}
		case 20: {
			g2.SetBitmap(h_bmp);
			break;
		}

		}
		c_image.Detach();

	}
}



void CyutnoliDlg::showMove0(int mvpl, int pos)
{
	moveT = TRUE;
	c_image.Load(L"images\\yellowcircle.png");
	h_bmp = (HBITMAP)c_image;
	if (player1[mvpl] == pos)
	{
		for (int i = 0; i <= roll_m; i++)
		{
			int go = player1[mvpl] + moveNum[i];
			board[go] = moveNum[i];
		}
		if (board[1] != 0)
			g2.SetBitmap(h_bmp);
		else if (board[2] != 0)
			g3.SetBitmap(h_bmp);
		else if (board[3] != 0)
			g4.SetBitmap(h_bmp);
		else if (board[4] != 0)
			g5.SetBitmap(h_bmp);
		else if (board[5] != 0)
			g6.SetBitmap(h_bmp);
		else if (board[6] != 0)
			g7.SetBitmap(h_bmp);
		else if (board[7] != 0)
			g8.SetBitmap(h_bmp);
		else if (board[8] != 0)
			g9.SetBitmap(h_bmp);
		else if (board[9] != 0)
			g10.SetBitmap(h_bmp);
		else if (board[10] != 0)
			g11.SetBitmap(h_bmp);
		else if (board[11] != 0)
			g12.SetBitmap(h_bmp);
		else if (board[12] != 0)
			g13.SetBitmap(h_bmp);
		else if (board[13] != 0)
			g14.SetBitmap(h_bmp);
		else if (board[14] != 0)
			g15.SetBitmap(h_bmp);
		else if (board[15] != 0)
			g16.SetBitmap(h_bmp);
		else if (board[16] != 0)
			g17.SetBitmap(h_bmp);
		else if (board[17] != 0)
			g18.SetBitmap(h_bmp);
		else if (board[18] != 0)
			g19.SetBitmap(h_bmp);
		else if (board[19] != 0)
			g20.SetBitmap(h_bmp);
		else if (board[20] != 0)
			g1.SetBitmap(h_bmp);
		else if (board[21] != 0)
			g30.SetBitmap(h_bmp);
		else
			m_list.AddString(_T("이동 가능한 위치가 없습니다."));
	}
	c_image.Detach();
}
void CyutnoliDlg::checkMv(int go) //상대 움직임
{
	
	
	for (int i = 0; i < 4; i++) //상대가 잡았을때
	{
		for (int j = 0; j < 4; j++)
		{
			if (player2[i] == player1[j]) {
				h_bmp = (HBITMAP)c_image;
				c_image.Load(L"images\\bluecircle.png");
				player1[j] = 0;
				m_list.AddString(_T("상대 말이 당신의 말을 잡았습니다. 추가 턴"));
				switch (j) {
				case 0: {
					p11.SetBitmap(h_bmp);
					break;
				}
				case 1: {
					p12.SetBitmap(h_bmp);
					break;
				}
				case 2: {
					p13.SetBitmap(h_bmp);
					break;
				}
				case 3: {
					p14.SetBitmap(h_bmp);
					break;
				}
				}
			}
		}
	}
	c_image.Detach();
	for (int i = 0; i < 4; i++) {
		if (player2[i] > 20) {
			player2[i] = -1;
			m_list.AddString(_T("상대의 말이 골인하였습니다."));
		}
	}
	cngB(3, player2[go]);
	//if(player2[go])
}


void CyutnoliDlg::Moving(int go) //2
{
	CString str;
	int check;
	for (int i = 0; i <= roll_m; i++)
	{
		if (moveNum[i] == board[go])
		{
			for (int j = 0; j < 4; j++)
			{
				if (player1[j] == player1[i]) {
					player1[j] += board[go];
				}
			}
			
			for (int j = i; j < roll_m; j++)
			{
				moveNum[j] = moveNum[j + 1];
			}
			roll_m--;
			str = _T("말이 이동하였습니다.");
			m_list.AddString(str);
			check = (choPl * 10) + 10 + board[go];
			SendChat(str, check);
			for (int j = 0; j < 4; j++)
			{
				if (player2[j] == player1[i]) {
					player2[j] = 0;
					m_list.AddString(_T("상대 말을 잡았습니다. 추가 턴"));
					diceT = TRUE;
					moveT = FALSE;
				}
			}
			break;
		}
	}
	
	board[go] = 0;
	moveT = false;
	choPl = 0;
	for (int i = 0; i < 4; i++) {
		if (player1[i] > 20)
		{
			player1[i] = -1;
			int temp = i + 1;
			str = temp + (_T("번 말이 골인하였습니다."));
			SendChat(str, 100); 
			int final = 0;
			for (int j = 0; j < 4; j++)
				final += player1[j];
			if (final == -4)
			{
				check = 99;
				str = _T("승리하였습니다.");
				m_list.AddString(_T("당신이") + str);
				SendChat(str, 99);
			}

		}
	}
	if (moveNum == 0)
	{
		turn = false;
		str = _T("턴을 종료합니다.");
		m_list.AddString(str);
		SendChat(str, 100);
	}
	
}
void CyutnoliDlg::OnClickedPlayer11()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	choPl = 0;
	if (turn && playing && player1[0] == 0)
		showMove0(choPl, 0);
	else
		MessageBox(L"이동 대상이 아닙니다.");
	
	UpdateData(FALSE);

}


void CyutnoliDlg::OnClickedPlayer12()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	choPl = 1;
	if (turn && playing && player1[0] == 0)
		showMove0(choPl, 0);
	else
		MessageBox(L"이동 대상이 아닙니다.");

	UpdateData(FALSE);
}


void CyutnoliDlg::OnClickedPlayer13()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	choPl = 2;
	if (turn && playing && player1[0] == 0)
		showMove0(choPl, 0);
	else
		MessageBox(L"이동 대상이 아닙니다.");

	UpdateData(FALSE);
}


void CyutnoliDlg::OnClickedPlayer14()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	choPl = 3;
	if (turn && playing && player1[0] == 0)
		showMove0(choPl, 0);
	else
		MessageBox(L"이동 대상이 아닙니다.");

	UpdateData(FALSE);
}



void CyutnoliDlg::OnClickedReady()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	if (!ready && !playing) {
		str = _T("<<<준비 완료>>>");
		SendChat(str, 91);
		ready = true;
	}
	else if (ready && !playing)
	{
		str = _T("<<<준비 해제>>>");
		SendChat(str, 90);
		ready = false;
	}
	else if (playing)
	{
		MessageBox(L"이미 게임 중입니다.");
	}
	
}



void CyutnoliDlg::OnClickedP1b()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
}


void CyutnoliDlg::OnClickedP2b()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CyutnoliDlg::OnClickedP3b()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CyutnoliDlg::OnClickedP4b()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

bool CyutnoliDlg::checkPos(int pos, int mov) //체크
{
	for (int i = 0; i < 4; i++) {
		if (!moveT && turn && playing && (player1[i] == board[pos])) {
			choPl = i;
			showMove0(choPl, 1);
			return false;
			break;
		}
		else if (moveT && turn && playing)
		{
			Moving(pos);
			return true;
		}
		else
			return false;
	}
}

void CyutnoliDlg::OnClickedPosition1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (checkPos(20, 21))
	{
		c_image.Load(L"images\\bluecircle.png");
		h_bmp = (HBITMAP)c_image;
		g1.SetBitmap(h_bmp);
		c_image.Detach();
	}
	UpdateData(FALSE);
}

void CyutnoliDlg::OnClickedPosition2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (checkPos(1, 2)) //t = 움직이기/ f = 말 선택
	{
		c_image.Load(L"images\\bluecircle.png");
		h_bmp = (HBITMAP)c_image;
		g1.SetBitmap(h_bmp);
		c_image.Detach();
	}
	UpdateData(FALSE);
}
void CyutnoliDlg::OnClickedPosition3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (checkPos(2, 3))
	{
		c_image.Load(L"images\\bluecircle.png");
		h_bmp = (HBITMAP)c_image;
		g1.SetBitmap(h_bmp);
		c_image.Detach();
	}
	UpdateData(FALSE);
}


void CyutnoliDlg::OnClickedPosition4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (checkPos(3, 4))
	{
		c_image.Load(L"images\\bluecircle.png");
		h_bmp = (HBITMAP)c_image;
		g1.SetBitmap(h_bmp);
		c_image.Detach();
	}
	UpdateData(FALSE);
}


void CyutnoliDlg::OnClickedPosition5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (checkPos(4, 5))
	{
		c_image.Load(L"images\\bluecircle.png");
		h_bmp = (HBITMAP)c_image;
		g1.SetBitmap(h_bmp);
		c_image.Detach();
	}
	UpdateData(FALSE);
	
}


void CyutnoliDlg::OnClickedPosition6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (checkPos(5, 6))
	{
		c_image.Load(L"images\\bluecircle.png");
		h_bmp = (HBITMAP)c_image;
		g1.SetBitmap(h_bmp);
		c_image.Detach();
	}
	UpdateData(FALSE);
}


void CyutnoliDlg::OnClickedPosition7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (checkPos(6, 7))
	{
		c_image.Load(L"images\\bluecircle.png");
		h_bmp = (HBITMAP)c_image;
		g1.SetBitmap(h_bmp);
		c_image.Detach();
	}
	UpdateData(FALSE);
}


void CyutnoliDlg::OnClickedPosition8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (checkPos(7, 8))
	{
		c_image.Load(L"images\\bluecircle.png");
		h_bmp = (HBITMAP)c_image;
		g1.SetBitmap(h_bmp);
		c_image.Detach();
	}
	UpdateData(FALSE);
}


void CyutnoliDlg::OnClickedPosition9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (checkPos(8, 9))
	{
		c_image.Load(L"images\\bluecircle.png");
		h_bmp = (HBITMAP)c_image;
		g1.SetBitmap(h_bmp);
		c_image.Detach();
	}
	UpdateData(FALSE);
}


void CyutnoliDlg::OnClickedPosition10()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (checkPos(9, 10))
	{
		c_image.Load(L"images\\bluecircle.png");
		h_bmp = (HBITMAP)c_image;
		g1.SetBitmap(h_bmp);
		c_image.Detach();
	}
	UpdateData(FALSE);
}


void CyutnoliDlg::OnClickedPosition11()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (checkPos(10, 11))
	{
		c_image.Load(L"images\\bluecircle.png");
		h_bmp = (HBITMAP)c_image;
		g1.SetBitmap(h_bmp);
		c_image.Detach();
	}
	UpdateData(FALSE);
}


void CyutnoliDlg::OnClickedPosition12()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (checkPos(11, 12))
	{
		c_image.Load(L"images\\bluecircle.png");
		h_bmp = (HBITMAP)c_image;
		g1.SetBitmap(h_bmp);
		c_image.Detach();
	}
	UpdateData(FALSE);
}


void CyutnoliDlg::OnClickedPosition13()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (checkPos(12, 13))
	{
		c_image.Load(L"images\\bluecircle.png");
		h_bmp = (HBITMAP)c_image;
		g1.SetBitmap(h_bmp);
		c_image.Detach();
	}
	UpdateData(FALSE);
}


void CyutnoliDlg::OnClickedPosition14()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (checkPos(13, 14))
	{
		c_image.Load(L"images\\bluecircle.png");
		h_bmp = (HBITMAP)c_image;
		g1.SetBitmap(h_bmp);
		c_image.Detach();
	}
	UpdateData(FALSE);
}


void CyutnoliDlg::OnClickedPosition15()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (checkPos(14, 15))
	{
		c_image.Load(L"images\\bluecircle.png");
		h_bmp = (HBITMAP)c_image;
		g1.SetBitmap(h_bmp);
		c_image.Detach();
	}
	UpdateData(FALSE);
}


void CyutnoliDlg::OnClickedPosition16()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (checkPos(15, 16))
	{
		c_image.Load(L"images\\bluecircle.png");
		h_bmp = (HBITMAP)c_image;
		g1.SetBitmap(h_bmp);
		c_image.Detach();
	}
	UpdateData(FALSE);
}


void CyutnoliDlg::OnClickedPosition17()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (checkPos(16, 17))
	{
		c_image.Load(L"images\\bluecircle.png");
		h_bmp = (HBITMAP)c_image;
		g1.SetBitmap(h_bmp);
		c_image.Detach();
	}
	UpdateData(FALSE);
}


void CyutnoliDlg::OnClickedPosition18()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (checkPos(17,18))
	{
		c_image.Load(L"images\\bluecircle.png");
		h_bmp = (HBITMAP)c_image;
		g1.SetBitmap(h_bmp);
		c_image.Detach();
	}
	UpdateData(FALSE);
}


void CyutnoliDlg::OnClickedPosition19()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (checkPos(18, 19))
	{
		c_image.Load(L"images\\bluecircle.png");
		h_bmp = (HBITMAP)c_image;
		g1.SetBitmap(h_bmp);
		c_image.Detach();
	}
	UpdateData(FALSE);
}


void CyutnoliDlg::OnClickedPosition20()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (checkPos(19, 20))
	{
		c_image.Load(L"images\\bluecircle.png");
		h_bmp = (HBITMAP)c_image;
		g1.SetBitmap(h_bmp);
		c_image.Detach();
	}
	UpdateData(FALSE);
}


void CyutnoliDlg::OnClickedPosition21()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
}


void CyutnoliDlg::OnClickedPosition22()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
}


void CyutnoliDlg::OnClickedPosition23()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
}


void CyutnoliDlg::OnClickedPosition24()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
}


void CyutnoliDlg::OnClickedPosition25()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

}


void CyutnoliDlg::OnClickedPosition26()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CyutnoliDlg::OnClickedPosition27()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CyutnoliDlg::OnClickedPosition28()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CyutnoliDlg::OnClickedPosition29()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CyutnoliDlg::OnClickedPosition30()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	//checkPos(21, ); //골인처리
	UpdateData(FALSE);
}
