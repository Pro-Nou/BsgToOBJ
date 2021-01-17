#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include "MathHelper.h"
#include "DirectXMath.h"
#include "Common.h"


using namespace DirectX;
using namespace std;

class SurfaceGenerate
{
public:
	SurfaceGenerate(bool isquad, float thickness, float surfStep, float surfStepAngle);
	~SurfaceGenerate();

	XMVECTOR positions[8];//����Ƥ��׼��
	XMVECTOR bmap[3][3];//�����������׼��
	XMVECTOR **posmap;//���������
	XMVECTOR **posmap2;//���������
	XMVECTOR *bezierSpline;//�����������ݴ�
	XMVECTOR **fnmap;//�淨��
	XMVECTOR **vnmap;//�㷨��
	XMVECTOR **uvmap;//uvͼ

	int U;//���±�
	int V;//���±�
	float surfStep;//�ֱ��ʲ���
	float surfStepAngle;//�ֱ��ʲ���(���ڽǶ�)
	float thickness;//���
	int Vcount = 0;
	int VTcount = 0;
	int VNcount = 0;
	int totalVcount = 0;
	int totalVTcount = 0;
	int totalVNcount = 0;
	string TVData;
	string TVTData;
	string TVNData;
	string TFData;
	string SmoothingGroup = "s 1\n";

	int edgeCount;//����
	bool isquad;
	int getPos(XMVECTOR position, int i);//ֱ�Ӵ������ǳ�������֪��Ϊʲô
	void setmap();//bmap��ʼ��
	void generateBezier(XMVECTOR p0, XMVECTOR p1, XMVECTOR p2, int n);//���ɱ���������
	void setpos();//���ɵ���
	XMVECTOR generateNormal(XMVECTOR p0, XMVECTOR p1, XMVECTOR p2);//���ɷ���
	void setfn();//�����淨��
	void setvn();//���ɵ㷨��
	void setuv();//����UVͼ
	void generateMesh();//��������Ƥ����

	void printmap();
	void printPosmap();
	void printPosmap2();
	void printfnmap();
	void printvnmap();

	int mainStream();
private:

};
