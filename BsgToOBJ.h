#pragma once
//�����Ϣ����
#define _CRT_SECURE_NO_WARNINGS//���þ���
#include <iostream>
#include <stdio.h>
#include <io.h>
#include <windows.h>
#include <string>
#include <stdlib.h>
#include "DirectXMath.h"//directX��ѧ���ߣ�win10�Դ�
#include "common/MathHelper.h"//������ѧ����
#include "common/Common.h"//���������
#include "common/PathFinder.h"//Ѱַ
#include "common/UTF8String.h"//UTF8��string��ת
#include "common/OBJTransform.h"//OBJģ��ת��
#include "common/SurfaceGenerate.h"//��Ƥ����

using namespace DirectX;
using namespace std;

class BsgToOBJ
{
public:
	BsgToOBJ();
	~BsgToOBJ();

public:
	int blockCount = 74;//bsgĿǰ���ڵ��������
	string SFALSE = "sfalse";//ռλ�ַ���
	string *blockList;//�������
	XMVECTOR *localPositionList;//�������λ�Ʊ�
	XMVECTOR *localRotationList;//���������ת��(ŷ����)
	XMVECTOR *localScaleList;//����������ű�

	int throwerror = 0;//����ʹ��
	string saveDataSName;//�浵��
	string versionNum = "v0.4";//�汾��

	int totalVcount = 0;//�ܶ�����
	int totalVTcount = 0;//������������
	int totalVNcount = 0;//�ܷ�������
	int blocksCount = 1;//�浵�ڵ��������

	float minimalCylinderLength = 0.0f;
	float surfaceStep = 0.0f;
	float surfaceStepAngle = 0.0f;
	float glassAlpha = 0.3f;

	Common::blockNode* blocks = new Common::blockNode;
	Common::blockNode* head = blocks;
	Common::pointNode* points = new Common::pointNode;
	Common::pointNode* phead = points;
	Common::edgeNode* edges = new Common::edgeNode;
	Common::edgeNode* ehead = edges;
	Common::surfNode* surfs = new Common::surfNode;
	Common::surfNode* shead = surfs;

	bool* denyList;//8ɾ����52����64������71-73����Ƥ(��������)��58����ͷ��57�ռ�ê��7�ֽ9Ƥ�45����

public:
	float degReset(float deg);//�ֽ�Ƕȸ�λ
	int initList();//��ʼ�������
	int saveSetting();//��ȡ����
	string savePath(int SW);//0��е��1Ƥ����3��������ȡ�����ļ�����ȡ·��
	string readMachine(string MPath);//��ȡ��е�浵
	void readBlock(string MData);//��ȡ�����Ϣ
	int mainStream();//�����̣�0ʧ�ܣ�1�ɹ�

};