#pragma once
// yutnoliDlg.h: 헤더 파일
//
#include "CSocCom.h"
#include "YutnoriClass.h"


// CyutnoliDlg 대화 상자
class CyutnoliDlg : public CDialogEx, YutnoriClass
{
// 생성입니다.
public:
	CyutnoliDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	CSocCom m_socCom;
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_YUTNOLI_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.

	CImage c_image;
	HBITMAP h_bmp;

// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg LRESULT OnReceive(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
	CString CH2CS(char* strInput);
	char* CS2CHAR(CString strInput);
	void SendChat(CString str, int check);
	void SendFrameData(SOCKET ah_socket, unsigned char a_msg_id, const char* ap_data, unsigned short int a_data_size);
	CStatic g1;
	CStatic g2;
	CStatic g3;
	CStatic g4;
	CStatic g5;
	CStatic g6;
	CStatic g7;
	CStatic g8;
	CStatic g9;
	CStatic g10;
	CStatic g11;
	CStatic g12;
	CStatic g13;
	CStatic g14;
	CStatic g15;
	CStatic g16;
	CStatic g17;
	CStatic g18;
	CStatic g19;
	CStatic g20;
	CStatic g21;
	CStatic g22;
	CStatic g23;
	CStatic g24;
	CStatic g25;
	CStatic g26;
	CStatic g27;
	CStatic g28;
	CStatic g29;


	CStatic p11;
	CStatic p12;
	CStatic p13;
	CStatic p14;
	CStatic p21;
	CStatic p22;
	CStatic p23;
	CStatic p24;

	CStatic st1;
	CStatic st2;
	CStatic st3;
	CStatic st4;
	CString m_strSend;
	afx_msg void OnClickedButtonConnect();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnClickedButtonSend();
	CListBox m_list;
	CString m_strUserID;
	CString m_strIP;
	afx_msg void OnBnClickedThrow();
	afx_msg void OnClickedPlayer11();
	afx_msg void OnClickedReady();
};
