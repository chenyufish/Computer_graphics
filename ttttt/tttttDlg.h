
// tttttDlg.h: 头文件
//

#pragma once


// CtttttDlg 对话框
class CtttttDlg : public CDialogEx
{
// 构造
public:
	CtttttDlg(CWnd* pParent = nullptr);	// 标准构造函数


// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TTTTT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	double P[37][72][3];//存储初始的点
	double F[36][72][4][3];//存储每个面的四个顶点
	double P1[4][3], Pdown[4][3], Pright[4][3], Pdownright[4][3];//表示循环使用的四个方格的四个点
	double inx[3];//表示后面index顺序
	double N1[3], Nd[3], Nr[3], Ndr[3];//四个面的法向量
	double Lv[3];//光矢量
	double v1[3];//视点坐标
	double Uv2[3];//未单位化的视矢量
	double Uv[3];//单位视矢量
	double I1[3] = { 1.0,1.0,1.0 };//环境光强
	double I2[3] = { 1.0,1.0,1.0 };//漫反射光强
	double I3[3] = { 1.0,1.0,1.0 };//镜面反射光强
	double k1[3] = { 0.175,0.012,0.012 };//环境光反射率
	double k2[3] = { 0.614,0.041,0.041 };//漫反射率
	double k3[3] = { 0.728,0.527,0.527 };//镜面反射率
	double k4[9];//透视投影变换系数
	double R = 300, Fei = 90, Thta = 90, D = 800;//视点参数
	double n = 5;//高光指数
	double aa[3] = { 300,300,-300 };//点光源坐标(右上)
	//衰减因子（（1，0，0）则为不衰减）
	double cc[3] = { 0.65,0.00002,0.000001 };
	double L[3][3];//存放三个点的光强
	double L1[3];//某个点的光强
	double ScreenP[2];//表示屏幕坐标系
	double Point[3][2];//存放透视投影的点
public:
	void ReadPoint();//去取点
	void ReadFace();//读入面坐标
	void divid();//逐面计算
	void ligth(double p[3][3], bool First);//计算光强
	void environment();//环境光
	void diffuse(double v[3], int index);//漫反射
	void mirror(double v[3], int index);//镜面反射
	void Project(double p[3]);//透视投影
	void fillup();//双线性插值
	void countFX(double v[3][3], int index);//计算法向量
	void Init();//透视变换所需要的系数
	afx_msg void OnBnClickedButton1();
};
