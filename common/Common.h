#pragma once
#define _CRT_SECURE_NO_WARNINGS//���þ���
#include <iostream>
#include <stdio.h>
#include <io.h>
#include <windows.h>
#include <string>
#include <stdlib.h>
#include "MathHelper.h"
#include "DirectXMath.h"

using namespace DirectX;
using namespace std; 

class Common
{
public:
	struct blockNode
	{
		int id;
		string blockName;
		XMVECTOR position;
		XMVECTOR rotation;
		XMVECTOR scale;
		XMVECTOR localPosition;
		XMVECTOR localRotation;
		XMVECTOR localScale;
		string skinName;
		string skinID;
		blockNode *next;
	};
	struct pointNode
	{
		int id;
		string blockName = "NULL";
		string guid;
		XMVECTOR position;
		pointNode *next;
	};
	struct edgeNode
	{
		int id;
		string blockName = "NULL";
		string guid;
		string guidStart;//���guid
		string guidEnd;//�յ�guid
		XMVECTOR position;
		edgeNode *next;
	};
	struct surfNode
	{
		int id;
		string blockName = "NULL";

		int surfMat = 0;//����
		bool painted = false;//��ɫ
		bool isquad = false;//�Ƿ��ı�
		bool isglass = false;//�Ƿ�Ϊ����

		XMVECTOR RGBA = XMVectorSet(0.0f, 0.0f, 0.0f, 1.0f);
		float sat;//���Ͷ�
		float lum;//����

		string guidEdges[4];//��guid
		float thickness;//���
		string skinName;
		string skinID;
		string matCode;//�����룬����ͬ��ͼ��ͬRGBA��sat��lum�Ĳ���
		surfNode *next;
	};

	static void printLine(int n)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
			FOREGROUND_RED | FOREGROUND_GREEN);
		for (int i = 0; i < n; i++)
			cout << '-';
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY |
			FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout << endl;
	}
	static void printXMVECTOR(XMVECTOR a, bool w)
	{
		cout << a.m128_f32[0] << ",";
		cout << a.m128_f32[1] << ",";
		cout << a.m128_f32[2];
		if (w)
			cout << "," << a.m128_f32[3] << endl;
		else
			cout << endl;
	}
	//��������Ϣ
	static void printBlock(blockNode* block)
	{
		cout << "���ID��" << block->id << endl;
		cout << "�������" << block->blockName << endl;
		cout << "ƽ�����꣺";
		printXMVECTOR(block->position, 0);
		cout << "��Ԫ����";
		printXMVECTOR(block->rotation, 1);
		cout << "���ţ�";
		printXMVECTOR(block->scale, 0);
		cout << "����ƽ�����꣺";
		printXMVECTOR(block->localPosition, 0);
		cout << "������תŷ���ǣ�";
		printXMVECTOR(block->localRotation, 0);
		cout << "�������ţ�";
		printXMVECTOR(block->localScale, 0);
		cout << "Ƥ�����ƣ�" + block->skinName << endl;
		cout << "����ID��" + block->skinID << endl << endl;
	}
	//�������Ϣ
	static void printPoints(pointNode* point)
	{
		cout << "�������" << point->blockName << endl;
		cout << "guid��" << point->guid << endl;
		cout << "��λ���꣺";
		printXMVECTOR(point->position, 0);
		cout << endl;
	}
	//�������Ϣ
	static void printEdges(edgeNode* edge)
	{
		cout << "�������" << edge->blockName << endl;
		cout << "guid��" << edge->guid << endl;
		cout << "��λ���꣺";
		printXMVECTOR(edge->position, 0);
		cout << "���guid��" << edge->guidStart << endl;
		cout << "�յ�guid��" << edge->guidEnd << endl << endl;
	}
	static void printSurfs(surfNode* surf)
	{
		int times = 0;
		cout << "�������" << surf->blockName << endl;
		cout << "���ʣ�" << surf->surfMat << endl;
		cout << "��ɫ��" << surf->painted << endl;
		if (surf->painted)
		{
			cout << "RGBA��";
			printXMVECTOR(surf->RGBA, 1);
			cout << "���Ͷȣ�" << surf->sat << endl;
			cout << "���ȣ�" << surf->lum << endl;
			cout << "�����룺" << surf->matCode << endl;
		}
		cout << "��ȣ�" << surf->thickness << endl;
		cout << "Ƥ�����ƣ�" + surf->skinName << endl;
		cout << "����ID��" + surf->skinID << endl;
		cout << "������";
		if (surf->isquad)
		{
			times = 4;
			cout << 4 << endl;
		}
		else
		{
			times = 3;
			cout << 3 << endl;
		}
		/*for (int i = 0; i < times; i++)
		{
			cout << "��guid��" << surf->guidEdges[i] << endl;
		}*/
		cout << endl;
	}
	static float lengthXMVECTOR(XMVECTOR a)
	{
		float x = a.m128_f32[0];
		float y = a.m128_f32[1];
		float z = a.m128_f32[2];
		float l = sqrt(x * x + y * y + z * z);
		return l;
	}
	static float solveAngleXMVECTOR(XMVECTOR a, XMVECTOR b)
	{
		a = XMVector3Normalize(a);
		b = XMVector3Normalize(b);
		float ab = a.m128_f32[0] * b.m128_f32[0] + a.m128_f32[1] * b.m128_f32[1] + a.m128_f32[2] * b.m128_f32[2];
		float abAngle = acosf(ab);
		if (abAngle < 0.0f)
			abAngle = 0.0f;
		if (abAngle > MathHelper::Pi)
			abAngle = MathHelper::Pi;
		return abAngle;
	}

};