#include "init_globle_variable.h"

int main() {
	initgraph(Window_width, Window_height);
	printf("sizeof(IMAGE) = %lld\n", sizeof(IMAGE));
	printf("sizeof(LPCTSTR) = %lld\n", sizeof(LPCTSTR));

	Init_game_data_chapter_0();
	Init_game_data_chapter_1();
	Init_game_data_chapter_2();
	Init_game_data_chapter_3();
	Init_game_data_chapter_4();

	while (1) {
		If_new_page();				//�ж��Ƿ����µ�һҳ���ǵĻ��������������ꡢ�Զ��ƶ������������ȵȣ�
		Draw_page();				//��ӡҳ����������
		Key_control();				//���̿���
		Meet();						//��ײ�ж�
		Sleep(50);
	}
	getchar();
	return 0;
}
































//���ڰ汾�е�ע��

	/*
	//����ҳ�����������ݽṹ����ɾ����������
	srand(time(0));

	List_page* Game_data_under_turing = Get_list_page();
	int op, ind, qq;
	printf("��ʼ������Game_data_under_turing->length = %d\n", Game_data_under_turing->length);

	printf("׼������ѭ��\n");
	printf("---------------------------\n");
	for (int i = 0; i < max_op; i++) {
		printf("����ѭ����i = %d\n", i);
		printf("�����������ǰ�������ȣ�Game_data_under_turing->length = %d\n", Game_data_under_turing->length);
		op = rand() % 4;
		ind = rand() % (Game_data_under_turing->length + 3) - 1;
		qq = rand() % 100;
		printf("�����������ǰ��������ݣ�\n");
		printf("��������op = %d, ����������ڵ���±꣺ind = %d, ���qq�ţ�qq = %d\n", op, ind, qq);
		switch (op) {
		case 0:
		case 1:
		case 2:
			printf("insert qq: %d at %d to List = %d\n", qq, ind, Insert_new_node_page(Game_data_under_turing, ind, qq));
			break;
		case 3:
			printf("erase item at %d from List = %d\n", ind, Erase_node_page(Game_data_under_turing, ind));
			break;
		}
		Output_all_node_page(Game_data_under_turing);
		printf("\n");
	}
	Clear_list_page(Game_data_under_turing);


	�ο����룺

	srand(time(0));
#define max_op 20
	List* l = getLinkList();
	int op, ind, val;
	for (int i = 0; i < max_op; i++) {
		op = rand() % 4;
		ind = rand() % (l->length + 3) - 1;
		val = rand() % 100;
		switch (op) {
			case 0:
			case 1: {
				printf("insert %d at %d to List = %d\n", val, ind, insert(l, ind, val));
			} break;
			case 2: {
				printf("reverse the list\n");
				rev(l);
			} break;
			case 3: {
				printf("erase item at %d from List = %d\n", ind, erase(l, ind));
			} break;
		}
		output(l);
		printf("\n");
	}
	clear_list(l);
	*/