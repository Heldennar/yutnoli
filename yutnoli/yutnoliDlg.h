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
	CImage c_image2;
	HBITMAP h_bmp2;
	CImage c_imageS;
	HBITMAP h_bmpS;
	CImage c_image1;
	HBITMAP h_bmp1;
	CImage c_imageY;
	HBITMAP h_bmpY;

// 구현입니다.
protected:
	HICON m_hIcon;
	bool inpath;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg LRESULT OnReceive(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
	int roll();
	int checkPath(int pos, int pl);
	void TOver();
	void cngB(int dest, int www);
	CString CH2CS(char* strInput);
	char* CS2CHAR(CString strInput);
	void SendChat(CString str, int check);
	void checkMv(int go);
	bool IsDead(); 
	void Refresh();
	bool InPath();
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
	CStatic m_useID;
	CListBox m_move_list;
	afx_msg void OnClickedP1b();
	afx_msg void OnClickedP2b();
	afx_msg void OnClickedP3b();
	afx_msg void OnClickedP4b();
	CBitmapButton m_picture;
	void showMove0(int mvpl, int pos);
	CStatic g30;
	void Moving(int go);
	afx_msg void OnClickedPlayer12();
	afx_msg void OnClickedPlayer13();
	afx_msg void OnClickedPlayer14();
	afx_msg void OnClickedPosition1();
	afx_msg void OnClickedPosition10();
	afx_msg void OnClickedPosition11();
	afx_msg void OnClickedPosition12();
	afx_msg void OnClickedPosition13();
	afx_msg void OnClickedPosition14();
	afx_msg void OnClickedPosition15();
	afx_msg void OnClickedPosition16();
	afx_msg void OnClickedPosition17();
	afx_msg void OnClickedPosition18();
	afx_msg void OnClickedPosition19();
	afx_msg void OnClickedPosition2();
	afx_msg void OnClickedPosition20();
	afx_msg void OnClickedPosition21();
	afx_msg void OnClickedPosition22();
	afx_msg void OnClickedPosition23();
	afx_msg void OnClickedPosition24();
	afx_msg void OnClickedPosition25();
	afx_msg void OnClickedPosition26();
	afx_msg void OnClickedPosition27();
	afx_msg void OnClickedPosition28();
	afx_msg void OnClickedPosition29();
	afx_msg void OnClickedPosition3();
	afx_msg void OnClickedPosition30();
	afx_msg void OnClickedPosition4();
	afx_msg void OnClickedPosition5();
	afx_msg void OnClickedPosition6();
	afx_msg void OnClickedPosition7();
	afx_msg void OnClickedPosition8();
	afx_msg void OnClickedPosition9();

	bool checkPos(int pos, int mov);
	CString dice_v();
};
