#include "init_globle_variable.h"

//�����и��ط���Ҫע�⣺һ�����ڰ����л�ҳ���ҳ���У��л�ҳ��;����һ�����ڰ����л�ҳ���ҳ���У��л��Ի�����������������

void Key_control() {
	switch (Pointer_present_node_page->Type) {
	case 1://����ǰҳ������Ϊ1���������л���һҳ
	case 9:
		if (GetAsyncKeyState(VK_RETURN)) {													//���ո��л���һҳ
			Pointer_present_node_page = Pointer_present_node_page->Next_page;				//ָ��ָ��ǰҳ�������һ��ҳ�����׵�ַ
			Object_controlled_x = Pointer_present_node_page->Object_controlled.Born_x;
			Object_controlled_y = Pointer_present_node_page->Object_controlled.Born_y;
			printf("�س���\n");
			printf("%d\n", Pointer_present_node_page->Editor_qq);
			printf("Pointer_present_node_page->Type = %d\n", Pointer_present_node_page->Type);
			Sleep(300);
		}

		if (GetAsyncKeyState(VK_ESCAPE)) {
			closegraph();
			Clear_list_page(Game_data_under_turing);
			printf("�˳���'ESC'��\n");
			Sleep(300);
		}


		break;
	case 2:
		if (GetAsyncKeyState('w') || GetAsyncKeyState('W') || GetAsyncKeyState(VK_UP)) {
			Object_controlled_y -= Pointer_present_node_page->Object_controlled.Speed_y;
			if (Object_controlled_y <= 0) {
				Object_controlled_y = 0;
			}
			printf("�ϣ�w:\n");
			printf("Pointer_present_node_page->Type = %d\n", Pointer_present_node_page->Type);
			printf("Ojbect_controlled_(x,y) = (%d, %d)\n", Object_controlled_x, Object_controlled_y);
			printf("Signal_meet_NPC_1 = %d\n", Signal_meet_NPC_1);
			printf("Signal_meet_NPC_2 = %d\n", Signal_meet_NPC_2);
			printf("Signal_meet_NPC_3 = %d\n", Signal_meet_NPC_3);
			printf("Signal_rectangle_chat_bubble_1_level = %d\n", Signal_rectangle_chat_bubble_1_level);
			printf("Signal_rectangle_chat_bubble_2_level = %d\n", Signal_rectangle_chat_bubble_2_level);
			printf("Signal_rectangle_chat_bubble_3_level = %d\n", Signal_rectangle_chat_bubble_3_level);
		}
		if (GetAsyncKeyState('s') || GetAsyncKeyState('S') || GetAsyncKeyState(VK_DOWN)) {
			Object_controlled_y += Pointer_present_node_page->Object_controlled.Speed_y;
			if (Object_controlled_y >= Window_height) {
				Object_controlled_y = Window_height;
			}
			printf("�£�s:\n");
			printf("Pointer_present_node_page->Type = %d\n", Pointer_present_node_page->Type);
			printf("Ojbect_controlled_(x,y) = (%d, %d)\n", Object_controlled_x, Object_controlled_y);
			printf("Signal_meet_NPC_1 = %d\n", Signal_meet_NPC_1);
			printf("Signal_meet_NPC_2 = %d\n", Signal_meet_NPC_2);
			printf("Signal_meet_NPC_3 = %d\n", Signal_meet_NPC_3);
			printf("Signal_rectangle_chat_bubble_1_level = %d\n", Signal_rectangle_chat_bubble_1_level);
			printf("Signal_rectangle_chat_bubble_2_level = %d\n", Signal_rectangle_chat_bubble_2_level);
			printf("Signal_rectangle_chat_bubble_3_level = %d\n", Signal_rectangle_chat_bubble_3_level);
		}
		if (GetAsyncKeyState('a') || GetAsyncKeyState('A') || GetAsyncKeyState(VK_LEFT)) {
			Object_controlled_x -= Pointer_present_node_page->Object_controlled.Speed_x;
			if (Object_controlled_x <= 0) {
				Object_controlled_x = 0;

			}
			printf("��a:\n");
			printf("Pointer_present_node_page->Type = %d\n", Pointer_present_node_page->Type);
			printf("Ojbect_controlled_(x,y) = (%d, %d)\n", Object_controlled_x, Object_controlled_y);
			printf("Signal_meet_NPC_1 = %d\n", Signal_meet_NPC_1);
			printf("Signal_meet_NPC_2 = %d\n", Signal_meet_NPC_2);
			printf("Signal_meet_NPC_3 = %d\n", Signal_meet_NPC_3);
			printf("Signal_rectangle_chat_bubble_1_level = %d\n", Signal_rectangle_chat_bubble_1_level);
			printf("Signal_rectangle_chat_bubble_2_level = %d\n", Signal_rectangle_chat_bubble_2_level);
			printf("Signal_rectangle_chat_bubble_3_level = %d\n", Signal_rectangle_chat_bubble_3_level);
		}
		if (GetAsyncKeyState('d') || GetAsyncKeyState('D') || GetAsyncKeyState(VK_RIGHT)) {
			Object_controlled_x += Pointer_present_node_page->Object_controlled.Speed_x;
			if (Object_controlled_x >= Window_width) {
				Object_controlled_x = Window_width;
			}
			printf("�ң�d:\n");
			printf("Pointer_present_node_page->Type = %d\n", Pointer_present_node_page->Type);
			printf("Ojbect_controlled_(x,y) = (%d, %d)\n", Object_controlled_x, Object_controlled_y);
			printf("Signal_meet_NPC_1 = %d\n", Signal_meet_NPC_1);
			printf("Signal_meet_NPC_2 = %d\n", Signal_meet_NPC_2);
			printf("Signal_meet_NPC_3 = %d\n", Signal_meet_NPC_3);
			printf("Signal_rectangle_chat_bubble_1_level = %d\n", Signal_rectangle_chat_bubble_1_level);
			printf("Signal_rectangle_chat_bubble_2_level = %d\n", Signal_rectangle_chat_bubble_2_level);
			printf("Signal_rectangle_chat_bubble_3_level = %d\n", Signal_rectangle_chat_bubble_3_level);
		}

		if (GetAsyncKeyState(VK_RETURN)) {
			if (Signal_meet_NPC_1 == 1) {
				Signal_rectangle_chat_bubble_1_level++;
				Signal_rectangle_chat_bubble_1_level %= Pointer_present_node_page->NPC_1.Sum_rectangle_chat_bubble;
				Signal_phone_chat_bubble_1_level++;
				Signal_phone_chat_bubble_1_level %= Pointer_present_node_page->NPC_1.Sum_phone_chat_bubble;
			}
			if (Signal_meet_NPC_2 == 1) {
				Signal_rectangle_chat_bubble_2_level++;
				Signal_rectangle_chat_bubble_2_level %= Pointer_present_node_page->NPC_2.Sum_rectangle_chat_bubble;
				Signal_phone_chat_bubble_2_level++;
				Signal_phone_chat_bubble_2_level %= Pointer_present_node_page->NPC_2.Sum_phone_chat_bubble;
			}
			if (Signal_meet_NPC_3 == 1) {
				Signal_rectangle_chat_bubble_3_level++;
				Signal_rectangle_chat_bubble_3_level %= Pointer_present_node_page->NPC_3.Sum_rectangle_chat_bubble;
				Signal_phone_chat_bubble_3_level++;
				Signal_phone_chat_bubble_3_level %= Pointer_present_node_page->NPC_3.Sum_phone_chat_bubble;
			}
			Sleep(200);
			printf("Enter:\n");
			printf("Signal_meet_NPC_1 = %d\n", Signal_meet_NPC_1);
			printf("Signal_meet_NPC_2 = %d\n", Signal_meet_NPC_2);
			printf("Signal_meet_NPC_3 = %d\n", Signal_meet_NPC_3);
			printf("Pointer_present_node_page->Type = %d\n", Pointer_present_node_page->Type);
			printf("Signal_phone_chat_bubble_level = %d\n", Signal_phone_chat_bubble_1_level);
			printf("Signal_rectangle_chat_bubble_1_level = %d\n", Signal_rectangle_chat_bubble_1_level);
			printf("Signal_rectangle_chat_bubble_2_level = %d\n", Signal_rectangle_chat_bubble_2_level);
			printf("Signal_rectangle_chat_bubble_3_level = %d\n", Signal_rectangle_chat_bubble_3_level);
			printf("Ojbect_controlled_(x,y) = (%d, %d)\n", Object_controlled_x, Object_controlled_y);
			printf("Ojbect_controlled_(x,y) = (%d, %d)\n", Object_controlled_x, Object_controlled_y);
		}

		if (GetAsyncKeyState(VK_ESCAPE)) {
			closegraph();
			Clear_list_page(Game_data_under_turing);
			printf("�˳���'ESC'��\n");
			Sleep(300);
		}
		break;
	case 3:
		if (GetAsyncKeyState('w') || GetAsyncKeyState('W') || GetAsyncKeyState(VK_UP)) {
			Object_controlled_y -= Pointer_present_node_page->Object_controlled.Speed_y;
			if (Object_controlled_y <= 0) {
				Object_controlled_y = 0;
			}
			printf("�ϣ�w:\n");
			printf("Ojbect_controlled_(x,y) = (%d, %d)\n", Object_controlled_x, Object_controlled_y);
		}
		if (GetAsyncKeyState('s') || GetAsyncKeyState('S') || GetAsyncKeyState(VK_DOWN)) {
			Object_controlled_y += Pointer_present_node_page->Object_controlled.Speed_y;
			if (Object_controlled_y >= Window_height) {
				Object_controlled_y = Window_height;
			}
			printf("�£�s:\n");
			printf("Ojbect_controlled_(x,y) = (%d, %d)\n", Object_controlled_x, Object_controlled_y);
		}
		if (GetAsyncKeyState('a') || GetAsyncKeyState('A') || GetAsyncKeyState(VK_LEFT)) {
			Object_controlled_x -= Pointer_present_node_page->Object_controlled.Speed_x;
			if (Object_controlled_x <= 0) {
				Object_controlled_x = 0;

			}
			printf("��a:\n");
			printf("Ojbect_controlled_(x,y) = (%d, %d)\n", Object_controlled_x, Object_controlled_y);
		}
		if (GetAsyncKeyState('d') || GetAsyncKeyState('D') || GetAsyncKeyState(VK_RIGHT)) {
			Object_controlled_x += Pointer_present_node_page->Object_controlled.Speed_x;
			if (Object_controlled_x >= Window_width) {
				Object_controlled_x = Window_width;
			}
			printf("�ң�d:\n");
			printf("Ojbect_controlled_(x,y) = (%d, %d)\n", Object_controlled_x, Object_controlled_y);
		}

		if (GetAsyncKeyState(VK_ESCAPE)) {
			closegraph();
			Clear_list_page(Game_data_under_turing);
			printf("�˳���'ESC'��\n");
			Sleep(300);
		}
		break;
	case 5:

		if (GetAsyncKeyState('W') && Player_y > 0) {
			Player_y -= Pointer_present_node_page->Object_controlled.Speed_y;

			//mciSendString("play tupian//��·.mp3", NULL, NULL, NULL);
		}
		if (GetAsyncKeyState('S')) {
			Player_y += Pointer_present_node_page->Object_controlled.Speed_y;
			if (Signal_exist_boss == 1 && Player_y >= 450) Player_y = 450;
			if (Signal_exist_boss == 0 && Player_y >= 450 && Player_x >= 300) Player_y = 450;
			//mciSendString("play tupian//��·.mp3", NULL, NULL, NULL);
		}
		if (GetAsyncKeyState('A') && Player_x > 0) {
			Player_x -= Pointer_present_node_page->Object_controlled.Speed_x;
			//mciSendString("play tupian//��·.mp3", NULL, NULL, NULL);
			Player_direction = 1;
		}
		if (GetAsyncKeyState('D') && Player_x < 860) {
			Player_x += Pointer_present_node_page->Object_controlled.Speed_x;
			//mciSendString("play tupian//��·.mp3", NULL, NULL, NULL);
			Player_direction = 0;
		}
		break;
	}
	return;
}