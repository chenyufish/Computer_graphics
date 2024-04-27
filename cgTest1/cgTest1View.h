
// cgTest1View.h : CcgTest1View ��Ľӿ�
//

#pragma once

#include <vector>
#include <algorithm>
#include <math.h>

#define STOP 0
#define DrawPolygon 1
#define DrawLine 2
#define DrawRect 3
#define BuildCoordinate 4 
#define DrawPol 5
using namespace std;

class CcgTest1View : public CView
{
protected:
	// �������л�����
	CcgTest1View();
	DECLARE_DYNCREATE(CcgTest1View)

// ����
public:
	CcgTest1Doc* GetDocument() const;

	int m_pointNum;

	int type;
	bool finish;
	vector<CPoint> points; 

	pair<CPoint, CPoint>* line;
	vector<pair<CPoint, CPoint>*> lines;
	pair<CPoint, CPoint> rect;

	int cx, cy;
	int cx1 = 100, cx2 = 150, cy1 = 100, cy2 = 150;
	int xs = 10;
	int ys = 10;
	// ʹ�ö�ά�������洢 Vertex
	double Vertex[62][3]; // ������62���㣬ÿ���������������;
	double FVertex[112][3];
	int F1[8][4][4];
	int FF1[8][4][4];
	double uv[11][11][3];
	double Fuv[11][11][3];
	double F[4][4][3];
	double FF[4][4][3];
	double b[4][4];
	double Fb[4][4];
	void SetBezierPoint();
	void setpoint();
	void FGetv();
	void Faway();
	void FDbezier();
	void Fcontinuity();
	void Getv();
	void away();
	void Dbezier();
	void continuity();
// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CcgTest1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
//	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
//	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPolygon();
	afx_msg void OnFillpolygon();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	void drawLineMid(CPoint p1,CPoint p2);
	afx_msg void OnChangeDc();
	afx_msg void OnDrawline();
	afx_msg void OnDrawrect();
	afx_msg void OnClipping();
	afx_msg void buildCoordinate();
	afx_msg void drawPol();
	afx_msg void moveUp();
	void clear(vector<CPoint> points);
	afx_msg void moveDown();
	afx_msg void moveLeft();
	afx_msg void moveRight();
	afx_msg void symx();
	afx_msg void symy();
	afx_msg void symo();
	afx_msg void symxy();
	afx_msg void protate();
	afx_msg void nrotate();
	afx_msg void smaller();
	afx_msg void larger();
	afx_msg void OnAnm();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void symxny();
	//afx_msg void OnTriangle1();
	//afx_msg void OnTriangle2();
	afx_msg void OnTriangleP1();
	afx_msg
	void rotateTriangle(double angle);
	void rotateAroundPoint(CPoint& point, double angle, int centerX, int centerY);
	void OnTriangleP2();
	afx_msg void OnTriangleP3();
	void Oblique();

	void RotationY();

	afx_msg void HorizontalCut();
	afx_msg void VerticalCut();
	afx_msg void Draw();
	afx_msg void SetPoint();
	afx_msg void Clean();
	afx_msg void BezierLine();
	afx_msg void BezierSurface();
};

#ifndef _DEBUG  // cgTest1View.cpp �еĵ��԰汾
inline CcgTest1Doc* CcgTest1View::GetDocument() const
   { return reinterpret_cast<CcgTest1Doc*>(m_pDocument); }
#endif

