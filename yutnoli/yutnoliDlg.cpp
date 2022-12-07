
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

void CyutnoliDlg::SendFrameData(SOCKET ah_socket, unsigned char a_msg_id, const char* ap_data, unsigned short int a_data_size)
//어떤 소켓으로,어떤 메세지인지, 어떤데이터를, 얼마만큼 보낼지가 매개변수로 전달된다.
{
	int send_data_size = a_data_size + 4;
	char* p_send_data = new char[send_data_size];//여기까지가 전송할 크기를 만들어냄

	*p_send_data = 27; //유효한 메세지인지 확인시킴 //첫번째 헤더
	*(p_send_data + 1) = a_msg_id; // 두번째 1바이트에 msg_id
	*(unsigned short int*)(p_send_data + 2) = a_data_size; // 포인터의 변위를 2바이트로 캐스팅한다.
	memcpy(p_send_data + 4, ap_data, a_data_size);
	//ap_data를 a_data_size의 크기만큼 복사해서 p_send_data[4]에 복사하겠다.
	send(ah_socket, p_send_data, send_data_size, 0);

	delete[] p_send_data;
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

LPARAM CyutnoliDlg::OnReceive(WPARAM wPara, LPARAM lPara) {

	// 접속된 곳에서 데이터가 도착했을 때
	UpdateData(TRUE);
	char pTmp[256];
	CString strTmp;
	memset(pTmp, '\0', 256);

	// 데이터를 pTmp에 받는다.
	m_socCom.Receive(pTmp, 256);
	strTmp.Format(_T("%s"), pTmp);

	// 서버로 부터 연결완료 메세지를 받으면
	if (strTmp.Find(_T(SOC_CLIENT_CONNECT)) == 0) {
		// Right 함수를 이용해 가장 오른쪽에 있는 번호 추출. 0은 \0이다.
		m_strUserID = _T("사용자 : ") + strTmp.Right(1);
	}
	else {
		// 리스트박스에 보여준다.
		int i = m_list.GetCount();
		m_list.AddString(strTmp);
	}
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


void CyutnoliDlg::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_socCom.Send(SOC_CLIENT_DISCONNECT, 256);        // 서버로 종료 메시지 보냄
	this->EndDialog(IDCANCEL);                        // Dialog 닫기
	CDialogEx::OnCancel();
}


void CyutnoliDlg::OnClickedButtonSend()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	char pTmp[256];
	CString strTmp;

	// pTmp에 전송할 데이터 입력
	memset(pTmp, '\0', 256);
	strcpy_s(pTmp, (char*)(LPCTSTR)m_strSend);
	m_strSend = "";

	// 전송
	m_socCom.Send(pTmp, 256);

	// 전송한 데이터도 리스트박스에 보여준다.
	strTmp.Format(_T("%s"), pTmp);
	int i = m_list.GetCount();
	m_list.AddString(strTmp);

	UpdateData(FALSE);
}


void CyutnoliDlg::OnBnClickedThrow()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	UpdateData(TRUE);
	CString str;
	if (turn) {
		int rollv = roll(roll_m);
		switch (rollv)
		{
		case -1:
		{
			m_list.AddString(_T("백도가 나왔습니다."));
			str = "백도가 나왔습니다.";
			break;
		}
		case 1: {
			m_list.AddString(_T("도가 나왔습니다."));
			str = "도가 나왔습니다.";
			break;
		}
		case 2: {
			m_list.AddString(_T("개가 나왔습니다."));
			str = "개가 나왔습니다.";
			break;
		}
		case 3: {
			m_list.AddString(_T("걸이 나왔습니다"));
			str = "걸이 나왔습니다.";
			break;
		}
		case 4: {
			m_list.AddString(_T("윷이 나왔습니다"));
			str = "윷이 나왔습니다.";
			break;
		}
		case 0: {
			m_list.AddString(_T("모가 나왔습니다"));
			str = "모가 나왔습니다.";
			break;
		}

		}
	}
	else
		MessageBox(L"당신의 차례가 아닙니다.");
	m_socCom.Send(str, str.GetLength() + 1);
	roll_m++;
	UpdateData(FALSE);
}


void CyutnoliDlg::OnClickedPlayer11()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_list.AddString(_T("백도가 나왔습니다."));
	UpdateData(FALSE);

}


void CyutnoliDlg::OnClickedReady()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
}

