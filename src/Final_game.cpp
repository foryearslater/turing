#include "init_globle_variable.h"

typedef struct wjjg
{
	int x1 = 200, y1 = 200;//���x����,���y����
	int direction = 0;//��ҵķ���
	int dz = 0;//��ɫ�İ˸�����
	int sm = 9;//�����������
	int xl = 0;//��ҵ�Ѫ��
}WJJG;

typedef struct gwjg
{
	int x1 = 500, y1 = 200;//����x��y����
	int x2 = 0, y2 = 0;//�������һ��x��y����,Ҳ���ǹ���Ŀ�ĵ�����
	int zy = 0;//�ǹ����ڵ��˵���߻����ұ�a
	int jljsjl = 0;//�����ɫ����
	int sm = 9, xl = 0;//sm�ǹ��������������xl�ǹ����Ѫ��
	bool live = false;//�жϹ�����
}GWJG;

typedef struct zdjg
{
	int x1 = 0, y1 = 0;//�ӵ�x, y����
	int x2 = 0, y2 = 0;//�ӵ�Ŀ�ĵ�x, y����
	int x3 = 0, y3 = 0;//�ӵ���ʼ����
	int zdbj = 0;//�ӵ��ı߽��ж�
	bool live = false;//�ж��ӵ��Ƿ�ִ�Ŀ�ĵ�
}ZDJG;

ExMessage wjxx;//��������߼�����Ϣ
WJJG wj;//��ҽ�ɫ
GWJG gw[gwsl];//��������
ZDJG wjzd[zidan_slwj], gwzd[zidan_slgw];//wjzd����ҵ��ӵ���gwzd�ǹ�����ӵ�
int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };//��ֹ��������ӵ���������
int dtqh = 0;//�˵��л�
char ch[10][5] = { "0/9","1/9", "2/9", "3/9", "4/9", "5/9", "6/9", "7/9", "8/9", "9/9" };//���Ѫ��
char gwsm[10][5] = { "0/9","1/9", "2/9", "3/9", "4/9", "5/9", "6/9", "7/9", "8/9", "9/9" };//����Ѫ��
int gwch = gwsl;//�жϹ����Ƿ����
int dt[WINDOW_WIDTH][WINDOW_HEIGHT];
int mydr = gwsl;

IMAGE jiemian[5];
IMAGE DTSJ;
IMAGE z, Z;
IMAGE move0, move1, move2, move3;
IMAGE zd1, zd2;
IMAGE jszd1, jszd11;
IMAGE bjy, bjz;
IMAGE zt, ztcd;
IMAGE yxjs;

void load_img(void)
{
	//��ʼ�˵���
	loadimage(&jiemian[0], "./resource/Images/tupian//��Ϸ����.png", WINDOW_WIDTH, WINDOW_HEIGHT);
	loadimage(&jiemian[1], "./resource/Images/tupian//����.png", WINDOW_WIDTH, WINDOW_HEIGHT);
	loadimage(&jiemian[2], "./resource/Images/tupian//�汾��Ϣ2.png", WINDOW_WIDTH, WINDOW_HEIGHT);
	loadimage(&jiemian[3], "./resource/Images/tupian//����.png", WINDOW_WIDTH, WINDOW_HEIGHT);
	loadimage(&jiemian[4], "./resource/Images/tupian//������.png", WINDOW_WIDTH, WINDOW_HEIGHT);
	//��Ϸ��
	loadimage(&DTSJ, "./resource/Images/tupian//DTSJ.png", WINDOW_WIDTH, WINDOW_HEIGHT);
	loadimage(&Z, "./resource/Images/tupian//Little monster_2.png");
	loadimage(&z, "./resource/Images/tupian//Little monster_1.png");
	loadimage(&move0, "./resource/Images/tupian//move0.png");
	loadimage(&move1, "./resource/Images/tupian//move1.png");
	loadimage(&move2, "./resource/Images/tupian//move2.png");
	loadimage(&move3, "./resource/Images/tupian//move3.png");
	loadimage(&zd1, "./resource/Images/tupian//zd2.png", zidan_WIDTH, zidan_HEIGHT);
	loadimage(&zd2, "./resource/Images/tupian//zd22.png", zidan_WIDTH, zidan_HEIGHT);
	loadimage(&jszd1, "./resource/Images/tupian//jszd1.png", zidan_WIDTH, zidan_HEIGHT);
	loadimage(&jszd11, "./resource/Images/tupian//jszd11.png", zidan_WIDTH, zidan_HEIGHT);
	loadimage(&bjy, _T("./resource/Images/tupian/�˽���.png"));
	loadimage(&bjz, _T("./resource/Images/tupian/�˽���.png"));
	//loadimage(&bjy, "tupian//�˽���.png"); 
	//loadimage(&bjz, "tupian//�˽���.png");
	loadimage(&zt, "./resource/Images/tupian//��Ϸ��ͣ.png");
	loadimage(&ztcd, "./resource/Images/tupian//��Ϸ����.png", 300, 300);
	loadimage(&yxjs, "./resource/Images/tupian//��Ϸ����.png", 300, 300);

	return;
}


//�㼯����
void huiji(void)
{
	load_img();
	initgwwz();
	initzd(wjzd, zidan_slwj);
	initzd(gwzd, zidan_slgw);
	int t = 1;
	while (1 == t)
	{
		show1();
		Sleep(80);
		++wj.dz;
		wj.dz %= 8;
		if (0 == dtqh)
		{
			wjkz();										//��ҿ���
			//Sleep(80);
			//++wj.dz;
			/*
			if (wj.dz > 4)//��֤n��0-3֮��
			{
				wj.dz = 0;
			}
			*/
			ycgwyd1();									//�����ƶ�������ˢ��
			createwjzd();								//���������Ϣ��������ҷ�����ӵ�
			creategwzd();								//���﷢����ӵ�
			gyzdydhs(wjzd, zidan_slwj, wjzdsd);			//ÿһ�ָı�һ����������ӵ�������
			gyzdydhs(gwzd, zidan_slgw, gwzdsd);			//ÿһ�ָı�һ�����й����ӵ�������
		}
		t = ztks();
		if (0 == t)
		{
			initxy();
		}
		if (dtqh == 2) {
			if (wj.x1 <= 300 && wj.x1 >= 50 && wj.y1 >= 580) t = 0;
		}
	}

	return;
}

//�������˵����г�ʼ������
void initxy(void)
{
	//��ʼ����ҽṹ
	wj.x1 = 200, wj.y1 = 200, wj.direction = 0; wj.sm = 9, wj.xl = 0;
	//��ʼ������ṹ
	for (int i = 0; i < gwsl; ++i)
	{
		gw[i].x1 = 500, gw[i].y1 = 200;
		gw[i].x2 = wj.x1, gw[i].y2 = wj.y1;
		gwzd[0].x1 = gw[i].x1, gwzd[0].y1 = gw[i].y1;
		gwzd[0].x2 = wj.x1, gwzd[0].y2 = wj.y1;
		gw[i].sm = 9, gw[i].xl = 0;
		gw[i].live = false;
	}
	gwch = gwsl;

	return;
}

//��ʾ����
void show1(void)
{
	//��ͣ�˵�
	if (1 == dtqh)
	{
		putimage(500, 200, &ztcd);
	}
	else if (0 == dtqh)
	{
		//��ͼ
		putimage(0, 0, &DTSJ);
		//��ͣ��
		putimage(1180, 0, &zt);
		//Ѫ��
		xuetiao();
		//����ƶ�
		switch (wj.direction)
		{
		case 1:
			putimage(wj.x1, wj.y1,
				PEOPLE_WIDTH, PEOPLE_HEIGHT,
				&bjz,
				wj.dz * PEOPLE_WIDTH, 0, SRCAND);
			putimage(wj.x1, wj.y1,
				PEOPLE_WIDTH, PEOPLE_HEIGHT,
				&bjz,
				wj.dz * PEOPLE_WIDTH, PEOPLE_HEIGHT, SRCPAINT);
			break;
		case 0:
			putimage(wj.x1, wj.y1,
				PEOPLE_WIDTH, PEOPLE_HEIGHT,
				&bjy,
				wj.dz * PEOPLE_WIDTH, 0, SRCAND);
			putimage(wj.x1, wj.y1,
				PEOPLE_WIDTH, PEOPLE_HEIGHT,
				&bjy,
				wj.dz * PEOPLE_WIDTH, PEOPLE_HEIGHT, SRCPAINT);
			break;
		}
		//�����ƶ�
		for (int i = 0; i < gwsl; ++i)
		{
			if (!gw[i].live)
			{
				if ((i & 1) == 1) {
					putimage(gw[i].x1, gw[i].y1,
						PEOPLE_WIDTH, PEOPLE_HEIGHT,
						&z,
						(wj.dz % 6) * PEOPLE_WIDTH, 0, SRCAND);
					putimage(gw[i].x1, gw[i].y1,
						PEOPLE_WIDTH, PEOPLE_HEIGHT,
						&z,
						(wj.dz % 6) * PEOPLE_WIDTH, PEOPLE_HEIGHT, SRCPAINT);
				}
				if ((i & 1) == 0) {
					putimage(gw[i].x1, gw[i].y1,
						PEOPLE_WIDTH, PEOPLE_HEIGHT,
						&Z,
						(wj.dz % 6) * PEOPLE_WIDTH, 0, SRCAND);
					putimage(gw[i].x1, gw[i].y1,
						PEOPLE_WIDTH, PEOPLE_HEIGHT,
						&Z,
						(wj.dz % 6) * PEOPLE_WIDTH, PEOPLE_HEIGHT, SRCPAINT);
				}
				//putimage(gw[i].x1, gw[i].y1, &z, SRCAND);
				//putimage(gw[i].x1, gw[i].y1, &Z, SRCPAINT);
			}
		}

		//��ҵ��ӵ�
		for (int i = 0; i < zidan_slwj; i++)
		{
			if (wjzd[i].live)
			{
				putimage(wjzd[i].x1, wjzd[i].y1, &jszd11, SRCAND);
				putimage(wjzd[i].x1, wjzd[i].y1, &jszd1, SRCPAINT);
				//��飬ÿһ�δ�ӡ�ӵ���ʱ���ӵ�������ı��Ƿ��ǶԵ�
				//printf("�ӵ�����(%d, %d)\n", wjzd[i].x1, wjzd[i].y1);
				//printf("�ӵ��ٶ� = %d\n", wjzdsd);
				//printf("�ӵ��������ƶ��ٶ� = %f\n", wjzdsd * ((wjzd[i].x2 - wjzd[i].x3) / sqrt((wjzd[i].x2 - wjzd[i].x3) * (wjzd[i].x2 - wjzd[i].x3) + (wjzd[i].y2 - wjzd[i].y3) * (wjzd[i].y2 - wjzd[i].y3))));
				//printf("�ӵ��������ƶ��ٶ� = %f\n", wjzdsd * ((wjzd[i].y2 - wjzd[i].y3) / sqrt((wjzd[i].x2 - wjzd[i].x3) * (wjzd[i].x2 - wjzd[i].x3) + (wjzd[i].y2 - wjzd[i].y3) * (wjzd[i].y2 - wjzd[i].y3))));
			}
		}
		//���˵��ӵ�
		for (int i = 0; i < zidan_slgw; i++)
		{
			if (gwzd[0].live)
			{
				putimage(gwzd[0].x1, gwzd[0].y1, &zd1, SRCAND);
				putimage(gwzd[0].x1, gwzd[0].y1, &zd2, SRCPAINT);
			}
		}
	}
	else if (2 == dtqh)
	{
		//putimage(490, 200, &yxjs);								//��ʾ��ͣ����
		printf("����ҳ������Ϊ��dtqh = %d\n", dtqh);
		wjkz();
		//��ͼ
		putimage(0, 0, &DTSJ);
		//��ͣ��
		putimage(1180, 0, &zt);
		//Ѫ��
		xuetiao();
		//����ƶ�
		switch (wj.direction)
		{
		case 1:
			putimage(wj.x1, wj.y1,
				PEOPLE_WIDTH, PEOPLE_HEIGHT,
				&bjz,
				wj.dz * PEOPLE_WIDTH, 0, SRCAND);
			putimage(wj.x1, wj.y1,
				PEOPLE_WIDTH, PEOPLE_HEIGHT,
				&bjz,
				wj.dz * PEOPLE_WIDTH, PEOPLE_HEIGHT, SRCPAINT);
			break;
		case 0:
			putimage(wj.x1, wj.y1,
				PEOPLE_WIDTH, PEOPLE_HEIGHT,
				&bjy,
				wj.dz * PEOPLE_WIDTH, 0, SRCAND);
			putimage(wj.x1, wj.y1,
				PEOPLE_WIDTH, PEOPLE_HEIGHT,
				&bjy,
				wj.dz * PEOPLE_WIDTH, PEOPLE_HEIGHT, SRCPAINT);
			break;
		}
		//
		IMAGE door1, door2;
		loadimage(&door1, "./resource/Images/tupian/transfer_gate.png");
		loadimage(&door2, "./resource/Images/tupian/transfer_gate.png");
		putimage(100, 580, PEOPLE_WIDTH, PEOPLE_HEIGHT, &door1, wj.dz * PEOPLE_WIDTH, 0, SRCAND);
		putimage(100, 580, PEOPLE_WIDTH, PEOPLE_HEIGHT, &door2, wj.dz * PEOPLE_WIDTH, PEOPLE_HEIGHT, SRCPAINT);
		//++wj.dz;
	}

	FlushBatchDraw();

	return;
}

//��ͣ��ʼ����
int ztks(void)
{
	peekmessage(&wjxx, EX_MOUSE);

	switch (wjxx.message)
	{
	case WM_LBUTTONDOWN:
		if (wjxx.x > 1180 && wjxx.y < 85 && 0 == dtqh)
		{
			dtqh = 1;//��ͣ����
		}
		else if (wjxx.x > 585 && wjxx.x < 710 && wjxx.y > 400 && wjxx.y < 480 && 1 == dtqh)
		{
			dtqh = 0;//������Ϸ
		}
		else if (wjxx.x > 500 && wjxx.x < 580 && wjxx.y > 400 && wjxx.y < 480 && 1 == dtqh)
		{
			dtqh = 0;//��ͣ�������˵�
			return 0;
		}
		/*
		else if (wjxx.x > 585 && wjxx.x < 680 && wjxx.y > 400 && wjxx.y < 480 && 2 == dtqh)
		{
			dtqh = 2;																		//��Ϸ�����������˵�
			return 0;
		}
		*/
		break;
	}

	return 1;
}

//��ҿ��ƺ���
void wjkz(void)
{
	if (dtqh == 0 || dtqh == 1) {																//�����е��˵Ĺؿ��У����ǻῼ�Ǻ͵��˵������ײ�����غ�
		if (GetAsyncKeyState('W') && wj.y1 > 0)//W		
		{
			int i;
			mydr = gwsl;
			for (i = 0; i < gwsl; ++i)
			{
				if ((gw[i].y1 < (wj.y1 - wjsd)) && ((gw[i].y1 + 102) > (wj.y1 - wjsd)) &&
					((gw[i].x1 < wj.x1) && ((gw[i].x1 + 74) > wj.x1) ||
						(wj.x1 < gw[i].x1) && ((wj.x1 + 120) > gw[i].x1)))
				{
					--mydr;
				}
			}
			if (gwsl == mydr)
			{
				wj.y1 -= wjsd;
				mciSendString("play ./resource/Images/tupian/��·.mp3", NULL, NULL, NULL);
			}
		}
		if (GetAsyncKeyState('S') && wj.y1 < 450)//S
		{
			int i;
			mydr = gwsl;
			for (i = 0; i < gwsl; ++i)
			{
				if (((wj.y1 + wjsd) < gw[i].y1) && ((wj.y1 + wjsd + 120) > gw[i].y1) &&
					((gw[i].x1 < wj.x1) && ((gw[i].x1 + 74) > wj.x1) ||
						(wj.x1 < gw[i].x1) && ((wj.x1 + 120) > gw[i].x1)))
				{
					--mydr;
				}
			}
			if (gwsl == mydr)
			{
				wj.y1 += wjsd;
				mciSendString("play ./resource/Images/tupian/��·.mp3", NULL, NULL, NULL);;
			}
		}
		if (GetAsyncKeyState('A') && wj.x1 > 0)//A
		{
			int i;
			mydr = gwsl;
			for (i = 0; i < gwsl; ++i)
			{
				if ((gw[i].x1 < (wj.x1 - wjsd)) && ((gw[i].x1 + 74) > (wj.x1 - wjsd)) &&
					((gw[i].y1 < wj.y1) && ((gw[i].y1 + 102) > wj.y1) ||
						(wj.y1 < gw[i].y1) && ((wj.y1 + 120) > gw[i].y1)))
				{
					--mydr;
				}
			}
			if (gwsl == mydr)
			{
				wj.x1 -= wjsd;
				mciSendString("play ./resource/Images/tupian/��·.mp3", NULL, NULL, NULL);;
			}
			wj.direction = 1;
		}
		if (GetAsyncKeyState('D') && wj.x1 < 860)//D
		{
			int i;
			mydr = gwsl;
			for (i = 0; i < gwsl; ++i)
			{
				if (((wj.x1 + wjsd) < gw[i].x1) && ((wj.x1 + wjsd + 120) > gw[i].x1) &&
					((gw[i].y1 < wj.y1) && ((gw[i].y1 + 102) > wj.y1) ||
						(wj.y1 < gw[i].y1) && ((wj.y1 + 120) > gw[i].y1)))
				{
					--mydr;
				}
			}
			if (gwsl == mydr)
			{
				wj.x1 += wjsd;
				mciSendString("play ./resource/Images/tupian/��·.mp3", NULL, NULL, NULL);;
			}
			wj.direction = 0;
		}
	}

	if (dtqh == 2) {															//���������е��˺󣬲���������˵������ײ
		if (GetAsyncKeyState('W') && wj.y1 > 0)//W		
		{
			wj.y1 -= wjsd;
			mciSendString("play ./resource/Images/tupian/��·.mp3", NULL, NULL, NULL);
		}
		if (GetAsyncKeyState('S') && ((wj.y1 < 450 && wj.x1 >= 300) || wj.x1 <= 300))//S
		{

			wj.y1 += wjsd;
			mciSendString("play ./resource/Images/tupian/��·.mp3", NULL, NULL, NULL);;

		}
		if (GetAsyncKeyState('A') && wj.x1 > 0)//A
		{
			wj.x1 -= wjsd;
			mciSendString("play ./resource/Images/tupian/��·.mp3", NULL, NULL, NULL);;
			wj.direction = 1;
		}
		if (GetAsyncKeyState('D') && wj.x1 < 860)//D
		{
			wj.x1 += wjsd;
			mciSendString("play ./resource/Images/tupian/��·.mp3", NULL, NULL, NULL);;
			wj.direction = 0;
		}
	}
	//�����Χǽ
	if (wj.y1 <= 100) wj.y1 = 100;
	return;
}

//Զ�̹����ƶ�����1
void ycgwyd1(void)
{
	for (int i = 0; i < gwsl; ++i)
	{
		//��������
		if (wj.x1 >= 0 && wj.x1 <= 120)
		{
			//����Һ͹����ÿһ����������֮�ͳ�2�������˵�Ŀ�ĵ�
			gw[i].x2 = wj.x1 - gw[i].jljsjl, gw[i].y2 = wj.y1 - gw[i].jljsjl;
			gw[i].x2 += 130, gw[i].y2 += 17;
			gw[i].zy = 0;
		}
		//��������
		else if (wj.x1 >= 740 && wj.x1 <= 860)
		{
			//����ҵ�ÿһ���������긳�����˵�Ŀ�ĵ�
			gw[i].x2 = wj.x1 - gw[i].jljsjl, gw[i].y2 = wj.y1 - gw[i].jljsjl;
			gw[i].x2 -= 130, gw[i].y2 += 17;
			gw[i].zy = 1;
		}
		//��������
		else if (0 == gw[i].zy)
		{
			gw[i].x2 = wj.x1 - gw[i].jljsjl, gw[i].y2 = wj.y1 + gw[i].jljsjl;
			gw[i].x2 += 130, gw[i].y2 += 17;
		}
		//��������
		else if (1 == gw[i].zy)
		{
			gw[i].x2 = wj.x1 - gw[i].jljsjl, gw[i].y2 = wj.y1 - gw[i].jljsjl;
			gw[i].x2 -= 130, gw[i].y2 += 17;
		}
		//�����м�
		if (gw[i].x1 < gw[i].x2 && gw[i].y1 == gw[i].y2)
		{
			if (gwbch(0))
			{
				ycgwyd2(0, 'x', 0, &gw[i]);
			}
		}
		else if (gw[i].x1 > gw[i].x2 && gw[i].y1 == gw[i].y2)
		{
			if (gwbch(1))
			{
				ycgwyd2(1, 'x', 0, &gw[i]);
			}
		}
		else if (gw[i].y1 < gw[i].y2 && gw[i].x1 == gw[i].x2)
		{
			if (gwbch(2))
			{
				ycgwyd2(2, 0, 'y', &gw[i]);
			}
		}
		else if (gw[i].y1 > gw[i].y2 && gw[i].x1 == gw[i].x2)
		{
			if (gwbch(3))
			{
				ycgwyd2(3, 0, 'y', &gw[i]);
			}
		}
		else if (gw[i].x1 < gw[i].x2 && gw[i].y1 < gw[i].y2)
		{
			if (gwbch(4))
			{
				ycgwyd2(4, 'x', 'y', &gw[i]);
			}
		}
		else if (gw[i].x1 > gw[i].x2 && gw[i].y1 > gw[i].y2)
		{
			if (gwbch(5))
			{
				ycgwyd2(5, 'x', 'y', &gw[i]);
			}
		}
		else if (gw[i].x1 < gw[i].x2 && gw[i].y1 > gw[i].y2)
		{
			if (gwbch(6))
			{
				ycgwyd2(6, 'x', 'y', &gw[i]);
			}
		}
		else if (gw[i].x1 > gw[i].x2 && gw[i].y1 < gw[i].y2)
		{
			if (gwbch(7))
			{
				ycgwyd2(7, 'x', 'y', &gw[i]);
			}
		}
	}

	return;
}
//Զ�̹����ƶ�����2
void ycgwyd2(char ch, char chx, char chy, struct gwjg* pgw)
{
	int t = 0;

	switch (ch)
	{
	case 0:
		for (int i = 0; i < 10; i++)
		{
			if (pgw->x1 + a[i] == pgw->x2)
			{
				pgw->x1 += a[i];
				t = 1;
				break;
			}
		}
		if (0 == t)
		{
			pgw->x1 += drsd;
			break;
		}
	case 1:
		for (int i = 0; i < 10; i++)
		{
			if (pgw->x1 - a[i] == pgw->x2)
			{
				pgw->x1 -= a[i];
				t = 1;
				break;
			}
		}
		if (0 == t)
		{
			pgw->x1 -= drsd;
			break;
		}

	case 2:
		for (int i = 0; i < 10; i++)
		{
			if (pgw->y1 + a[i] == pgw->y2)
			{
				pgw->y1 += a[i];
				t = 1;
				break;
			}
		}
		if (0 == t)
		{
			pgw->y1 += drsd;
			break;
		}

	case 3:
		for (int i = 0; i < 10; i++)
		{
			if (pgw->y1 - a[i] == pgw->y2)
			{
				pgw->y1 -= a[i];
				t = 1;
				break;
			}
		}
		if (0 == t)
		{
			pgw->y1 -= drsd;
			break;
		}
	case 4:
		for (int i = 0; i < 10; i++)
		{
			if (pgw->x1 + a[i] == pgw->x2)
			{
				pgw->x1 += a[i];
				t = 1;
				break;
			}
			else if (pgw->y1 + a[i] == pgw->y2)
			{
				pgw->y1 += a[i];
				t = 1;
				break;
			}
		}
		if (0 == t)
		{
			pgw->x1 += drsd;
			pgw->y1 += drsd;
			break;
		}
	case 5:
		for (int i = 0; i < 10; i++)
		{
			if (pgw->x1 - a[i] == pgw->x2)
			{
				pgw->x1 -= a[i];
				t = 1;
				break;
			}
			else if (pgw->y1 - a[i] == pgw->y2)
			{
				pgw->y1 -= a[i];
				t = 1;
				break;
			}
		}
		if (0 == t)
		{
			pgw->x1 -= drsd;
			pgw->y1 -= drsd;
			break;
		}
	case 6:
		for (int i = 0; i < 10; i++)
		{
			if (pgw->x1 + a[i] == pgw->x2)
			{
				pgw->x1 += a[i];
				t = 1;
				break;
			}
			else if (pgw->y1 - a[i] == pgw->y2)
			{
				pgw->y1 -= a[i];
				t = 1;
				break;
			}
		}
		if (0 == t)
		{
			pgw->x1 += drsd;
			pgw->y1 -= drsd;
			break;
		}
	case 7:
		for (int i = 0; i < 10; i++)
		{
			if (pgw->x1 - a[i] == pgw->x2)
			{
				pgw->x1 -= a[i];
				t = 1;
				break;
			}
			else if (pgw->y1 + a[i] == pgw->y2)
			{
				pgw->y1 += a[i];
				t = 1;
				break;
			}
		}
		if (0 == t)
		{
			pgw->x1 -= drsd;
			pgw->y1 += drsd;
			break;
		}
	}

	return;
}

//��ʼ���ӵ�����
void initzd(struct zdjg* pzd, int zdsl)
{
	int i;
	for (i = 0; i < zdsl; i++)
	{
		pzd[i].x1 = 0;
		pzd[i].y1 = 0;
		pzd[i].x2 = 0;
		pzd[i].y2 = 0;
		pzd[i].x3 = 0;
		pzd[i].y3 = 0;
		pzd[i].zdbj = 0;
		pzd[i].live = false;
	}

	return;
}

//��������ӵ�����
void createwjzd(void)
{
	while (peekmessage(&wjxx, EX_MOUSE))
	{
		switch (wjxx.message)
		{
		case WM_LBUTTONDOWN:
			for (int i = 0; i < zidan_slwj; i++)
			{
				if (!wjzd[i].live && (wjxx.x < 860 || wjxx.y > 85))
				{
					wjzd[i].x1 = wj.x1;
					wjzd[i].y1 = wj.y1;
					wjzd[i].x2 = wjxx.x;
					wjzd[i].y2 = wjxx.y;
					wjzd[i].x3 = wj.x1;
					wjzd[i].y3 = wj.y1;
					wjzd[i].zdbj = 0;
					wjzd[i].live = true;
					//��飬ÿ�ε������Ժ󣬼�������ӵ����ٶ�ʸ�������������Ƿ���ȷ
					//printf("�����������Ϊ(%d, %d)\n", wjxx.x, wjxx.y);
					//printf("��ҵ�ǰ������Ϊ(%d, %d)\n", wj.x1, wj.y1);
					//printf("�ӵ������굥λʱ���ƶ����ȣ�%d\n",wjxx.x - wj.x1);
					//printf("�ӵ������굥λʱ���ƶ����ȣ�%d\n", wjxx.y - wj.y1);
					//printf("�ӵ�����(%d, %d)\n", wjzd[i].x1, wjzd[i].y1);
					//printf("�ӵ��ٶ� = %d\n", wjzdsd);
					//printf("�ӵ��������ƶ��ٶ� = %f\n", wjzdsd * ((wjzd[i].x2 - wjzd[i].x3) / sqrt((wjzd[i].x2 - wjzd[i].x3) * (wjzd[i].x2 - wjzd[i].x3) + (wjzd[i].y2 - wjzd[i].y3) * (wjzd[i].y2 - wjzd[i].y3))));
					//printf("�ӵ��������ƶ��ٶ� = %f\n", wjzdsd * ((wjzd[i].y2 - wjzd[i].y3) / sqrt((wjzd[i].x2 - wjzd[i].x3) * (wjzd[i].x2 - wjzd[i].x3) + (wjzd[i].y2 - wjzd[i].y3) * (wjzd[i].y2 - wjzd[i].y3))));
					//printf("�ӵ��ٶ����û�����⣬�Ǿ��ǻ��������ˣ�\n");
					mciSendString("play ./resource/Images/tupian/�ӵ�����.mp3", NULL, NULL, NULL);
					break;
				}
			}
			break;
		}
	}

	return;
}

//���������ӵ�����
void creategwzd(void)
{
	for (int i = 0; i < zidan_slgw; ++i)
	{
		if (!gw[i].live && !gwzd[i].live && sqrt(pow((wj.x1 - gw[i].x1), 2) + pow(wj.y1 - gw[i].y1, 2)) <= 600)
		{
			gwzd[i].x1 = gw[i].x1;
			gwzd[i].y1 = gw[i].y1;
			gwzd[i].x2 = wj.x1;
			gwzd[i].y2 = wj.y1;
			gwzd[i].x3 = gw[i].x1;
			gwzd[i].y3 = gw[i].y1;
			gwzd[i].zdbj = 0;
			gwzd[i].live = true;
		}
	}

	return;
}





//���õ��ӵ��ƶ�����
void gyzdydhs(struct zdjg* pzd, int zdsl, int zdsd)
{
	//�����ӵ�ÿһ�ֱ仯�Ժ������
	for (int i = 0; i < zdsl; ++i)
	{
		if (pzd[i].live)
		{
			wjzdpz(pzd, zdsl, i);
			gwzdpz(pzd, zdsl, i);
			pzd[i].x1 += zdsd * ((pzd[i].x2 - pzd[i].x3) / sqrt((pzd[i].x2 - pzd[i].x3) * (pzd[i].x2 - pzd[i].x3) + (pzd[i].y2 - pzd[i].y3) * (pzd[i].y2 - pzd[i].y3)));
			pzd[i].y1 += zdsd * ((pzd[i].y2 - pzd[i].y3) / sqrt((pzd[i].x2 - pzd[i].x3) * (pzd[i].x2 - pzd[i].x3) + (pzd[i].y2 - pzd[i].y3) * (pzd[i].y2 - pzd[i].y3)));
			//printf("�ӵ�����(%d, %d)\n", pzd[i].x1, pzd[i].y1);
			//printf("�ӵ��ٶ� = %d\n", zdsd);
			//printf("�ӵ��������ƶ��ٶ� = %f\n", zdsd * ((pzd[i].x2 - pzd[i].x3) / sqrt((pzd[i].x2 - pzd[i].x3) * (pzd[i].x2 - pzd[i].x3) + (pzd[i].y2 - pzd[i].y3) * (pzd[i].y2 - pzd[i].y3))));
			//printf("�ӵ��������ƶ��ٶ� = %f\n", zdsd * ((pzd[i].y2 - pzd[i].y3) / sqrt((pzd[i].x2 - pzd[i].x3) * (pzd[i].x2 - pzd[i].x3) + (pzd[i].y2 - pzd[i].y3) * (pzd[i].y2 - pzd[i].y3))));
			if (pzd[i].x1 <= -200 || pzd[i].x1 >= 1500 || pzd[i].y1 <= -200 || pzd[i].y1 >= 1500)
			{
				pzd[i].live = false;
			}
		}
	}
	return;
}

//����ӵ���ײ����
void wjzdpz(struct zdjg* pzd, int zdsl, int i)
{
	for (int j = 0; j < gwsl; ++j)
	{
		if (!gw[j].live && zdsl == zidan_slwj && pzd[i].x1 > gw[j].x1 && pzd[i].x1 < gw[j].x1 + 80 &&
			pzd[i].y1 > gw[j].y1 && pzd[i].y1 < gw[j].y1 + 110)
		{
			if (0 == gw[j].sm)
			{
				--gwch;
				gw[j].live = true;
				mciSendString("play ./resource/Images/tupian/��������.mp3", NULL, NULL, NULL);
				if (0 == gwch)																//����������Ϊ0��ʱ�򣬼����������й���
				{
					dtqh = 2;
				}
			}
			else if (++gw[j].xl && 0 != --gw[j].sm)
			{
				pzd[i].live = false;
			}
		}
	}

	return;
}

//�����ӵ���ײ����
void gwzdpz(struct zdjg* pzd, int zdsl, int i)
{
	if (zdsl == zidan_slgw && pzd[i].x1 >= wj.x1 && pzd[i].x1 <= wj.x1 + 120 &&
		pzd[i].y1 >= wj.y1 && pzd[i].y1 <= wj.y1 + 120)
	{

		if (0 == wj.sm)
		{
			dtqh = 2;
		}
		else if (++wj.xl && 0 != --wj.sm)
		{
			pzd[i].live = false;
		}
	}
}

//����Ѫ������
void xuetiao(void)
{
	//���������������
	settextcolor(WHITE);
	settextstyle(20, 0, "����");
	outtextxy(0, 0, "������");
	//�������Ѫ���߿�
	setlinecolor(BLACK);
	roundrect(55, 0, 208, 20, 10, 10);
	//�������Ѫ�����
	setfillcolor(RED);
	solidroundrect(55, 0, 208 - 17 * wj.xl, 20, 10, 10);
	outtextxy(110, 0, ch[wj.sm]);

	for (int i = 0; i < gwsl; ++i)
	{
		if (!gw[i].live)
		{
			//���ƹ���Ѫ���߿�
			setlinecolor(BLACK);
			roundrect(gw[i].x1, gw[i].y1 - 20, gw[i].x1 + 90, gw[i].y1, 10, 10);
			//���ƹ���Ѫ�����
			setfillcolor(RED);
			solidroundrect(gw[i].x1, gw[i].y1 - 20, gw[i].x1 + 90 - 10 * gw[i].xl, gw[i].y1, 10, 10);
			outtextxy(gw[i].x1 + 30, gw[i].y1 - 20, gwsm[gw[i].sm]);
		}
	}

	return;
}

//��ʼ������λ��
void initgwwz(void)
{
	srand(time(NULL));
	for (int i = 0; i < gwsl; i++)
	{
		gw[i].jljsjl = 60 + (int)rand() % 101;			//��������ɫ�ľ���
		gw[i].x1 = 800 + (int)rand() % 201;				//0 - 1280
		gw[i].y1 = 300 + (int)rand() % 201;
		printf("%d\n", gw[i].jljsjl);
	}

	return;
}

//�����໥���غϺ���
bool gwbch(int gwdzbh)//gwdzbh�ǹ��ﶯ���ı��
{
	int wdr = gwsl;//�����޵���
	for (int i = 0; i < gwsl; ++i)
	{
		switch (gwdzbh)
		{
		case 0:
			for (int j = 0; j < gwsl; ++j)
			{
				if (i != j && ((gw[i].x1 + drsd) < gw[j].x1) && ((gw[i].x1 + drsd + 50) > gw[j].x1) &&
					((gw[j].y1 < gw[i].y1) && ((gw[j].y1 + 50) > gw[i].y1) ||
						(gw[i].y1 < gw[j].y1) && ((gw[i].y1 + 50) > gw[j].y1)))
				{
					--wdr;
				}
			}
			if (gwsl == wdr)
			{
				return true;
			}
			else
			{
				return false;
			}
			break;
		case 1:
			for (int j = 0; j < gwsl; ++j)
			{
				if (i != j && (gw[j].x1 < (gw[i].x1 - drsd)) && (gw[j].x1 + 50 > (gw[i].x1 - drsd)) &&
					((gw[j].y1 < gw[i].y1) && ((gw[j].y1 + 50) > gw[i].y1) ||
						(gw[i].y1 < gw[j].y1) && ((gw[i].y1 + 50) > gw[j].y1)))
				{
					--wdr;
				}
			}
			if (gwsl == wdr)
			{
				return true;
			}
			else
			{
				return false;
			}
			break;
		case 2:
			for (int j = 0; j < gwsl; ++j)
			{
				if (i != j && ((gw[i].y1 + drsd) < gw[j].y1) && ((gw[i].y1 + drsd + 50) > gw[j].y1) &&
					((gw[j].x1 < gw[i].x1) && ((gw[j].x1 + 50) > gw[i].x1) ||
						(gw[i].x1 < gw[j].x1) && ((gw[i].x1 + 50) > gw[j].x1)))
				{
					--wdr;
				}
			}
			if (gwsl == wdr)
			{
				return true;
			}
			else
			{
				return false;
			}
			break;
		case 3:
			for (int j = 0; j < gwsl; ++j)
			{
				if (i != j && (gw[j].y1 < (gw[i].y1 - drsd)) && ((gw[j].y1 + 50) > (gw[i].y1 - drsd)) &&
					((gw[j].x1 < gw[i].x1) && ((gw[j].x1 + 50) > gw[i].x1) ||
						(gw[i].x1 < gw[j].x1) && ((gw[i].x1 + 50) > gw[j].x1)))
				{
					--wdr;
				}
			}
			if (gwsl == wdr)
			{
				return true;
			}
			else
			{
				return false;
			}
			break;
		case 4:
			for (int j = 0; j < gwsl; ++j)
			{
				if (i != j && ((gw[i].x1 + drsd) < gw[j].x1) && ((gw[i].x1 + drsd + 50) > gw[j].x1) &&
					((gw[j].y1 < gw[i].y1 + drsd) && ((gw[j].y1 + 50) > (gw[i].y1 + drsd)) ||
						((gw[i].y1 + drsd) < gw[j].y1) && ((gw[i].y1 + drsd + 50) > gw[j].y1)))
				{
					--wdr;
				}
			}
			if (gwsl == wdr)
			{
				return true;
			}
			else
			{
				return false;
			}
			break;
		case 5:
			for (int j = 0; j < gwsl; ++j)
			{
				if (i != j && (gw[j].x1 < (gw[i].x1 - drsd)) && (gw[j].x1 + 74 > (gw[i].x1 - drsd)) &&
					((gw[j].y1 < gw[i].y1 - drsd) && ((gw[j].y1 + 102) > (gw[i].y1 - drsd)) ||
						((gw[i].y1 - drsd) < gw[j].y1) && ((gw[i].y1 - drsd + 102) > gw[j].y1)))
				{
					--wdr;
				}
			}
			if (gwsl == wdr)
			{
				return true;
			}
			else
			{
				return false;
			}
			break;
		case 6:
			for (int j = 0; j < gwsl; ++j)
			{
				if (i != j && ((gw[i].x1 + drsd) < gw[j].x1) && ((gw[i].x1 + drsd + 50) > gw[j].x1) &&
					((gw[j].y1 < gw[i].y1 - drsd) && ((gw[j].y1 + 50) > (gw[i].y1 - drsd)) ||
						((gw[i].y1 - drsd) < gw[j].y1) && ((gw[i].y1 - drsd + 50) > gw[j].y1)))
				{
					--wdr;
				}
			}
			if (gwsl == wdr)
			{
				return true;
			}
			else
			{
				return false;
			}
			break;
		case 7:
			for (int j = 0; j < gwsl; ++j)
			{
				if (i != j && (gw[j].x1 < (gw[i].x1 - drsd)) && ((gw[j].x1 + 50) > (gw[i].x1 - drsd)) &&
					((gw[j].y1 < gw[i].y1 + drsd) && ((gw[j].y1 + 50) > (gw[i].y1 + drsd)) ||
						((gw[i].y1 + drsd) < gw[j].y1) && ((gw[i].y1 + drsd + 50) > gw[j].y1)))
				{
					--wdr;
				}
			}
			if (gwsl == wdr)
			{
				return true;
			}
			else
			{
				return false;
			}
			break;
		}
	}
}



//BOSS�ؿ�-------------------------------------------------------------------------
//������Ҫ�ĺ�����
