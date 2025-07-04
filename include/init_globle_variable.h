#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <easyx.h>
#include <conio.h>
#include <graphics.h>
#include <time.h>
#include "List_node_page_data_structure.h"
//Ԫ����ʿ������Ҫ��ͷ�ļ���
# pragma once
# include <process.h>
# include <math.h>
# include <mmsystem.h>
# pragma comment (lib,"winmm.lib")

#define max_op 20

/*
��ȫ�ֱ������������ơ��������淶����
1��ȫ��Ӣ��ȫ�ƣ�
2���ո����»���_�����ÿһ������֮�䶼��Ҫһ���»��ߡ�_����
3��ֻ�����Ƶĵ�һ�����ʵĿ�ͷ��ĸ�Ǵ�д������ȫ��Сд��ĸ��
*/


void Key_control();						//���̿��ƺ������������һ�ı���Ҫ��ӡ�Ŀ��ƶ�����ĺ�������

void If_new_page();					//�ж��Ƿ����µ�һҳ���Ӷ�ȷ���Ƿ���Ҫ������������

//��ͼ��صĺ���
void Draw_page();						//��������ҳ������Ҫ������
void Draw_page_background();			//����ҳ���Ӧ�ı���ͼ�񣬼���(0, 0)λ���ϴ�ӡ���ʹ��ڴ�С��ȵ�ȫҳ���ͼ��
void Draw_object_controlled();			//����ҳ���Ӧ�Ŀɿ��������ͼ��
void Draw_object_mobile();				//����ҳ���Ӧ���Զ��ƶ������ͼ��
void Draw_rectangle_chat_bubble();		//����������������
void Draw_phone_chat_bubble();			//�����ֻ��������
void Draw_scoreboard();					//������Ϸ�ؿ��ļǷ���
void Draw_blood();						//����BOSS�ؿ�������͹����Ѫ��
void Draw_bullet();						//���������Ϣ���ƶ��ӵ����ӵ���ײ�ж��������ӵ����ӵ��ϼ�
void Create_bullet();					//���������Ϣ�������ӵ���
void Draw_each_bullet();				//����ÿһ���ӵ�
void Move_bullet();						//�ӵ��ƶ�����
void Hit_BOSS_bullet();					//�ӵ���ײ�ж�
void Draw_door_to_essay();				//��ͨ��С���ĵĴ�����

//BGM����
void Bgm_shadow();
void Bgm_adventure_island_1();
void Bgm_adventure_island_2();
void Bgm_end_credit();
void Bgm_birthday();
//�ж���ײ��صĺ���
void Meet();							//��ײ�ж��ϼ�
void Meet_door();						//��ײ�������ж�
void Meet_NPC();						//��ײNPC�ж�
void Meet_wall();						//��ײΧǽ�ж�
void Meet_finish_game();				//������Ϸ�����ж�
void Meet_object_mobile();				//��ײ�Զ��ƶ������ж�
void Meet_auto_play();					//�Զ����Ż����ҳ�棬ͣ��һ��ʱ����Զ���ת

//��ײ�����ź���
void Meet_door_to_next_page();
void Meet_door_bilibili_vedio_end();
void Meet_door_communication_group();
void Meet_door_right_choice_box();
void Meet_door_wrong_choice_box();
void Meet_door_girls_on_the_snow();
void Meet_door_corridor();
void Meet_door_station();
void Meet_door_computer();
void Meet_door_group_introduction_meeting();

void Meet_door_chapter_2_library();
void Meet_door_2_chapter_2_library();
void Meet_door_chapter_2_game_easter_eggs();
void Meet_door_chapter_2_game_easter_eggs_to_library();

void Meet_door_chapter_3_library();

void Meet_door_chapter_4_cycle_1_40km();
void Meet_door_chapter_4_cycle_2_25km();
void Meet_door_chapter_4_cycle_3_10km();
void Meet_door_chapter_4_cycle_4();
void Meet_door_chapter_4_lobby_conversation();

//��ײNPC��������Ե���ƪ��
void Meet_NPC_1_brother_east_on_the_snow();
void Meet_NPC_1_girls_on_the_snow();
void Meet_NPC_1_corridor();
void Meet_NPC_1_group_meeting();
void Meet_NPC_1_station();
void Meet_NPC_2_station();
void Meet_NPC_3_station();
//��ײNPC��������Ʒ����ƪ��
void Meet_NPC_1_chapter_2_library();
void Meet_NPC_2_chapter_2_library();
//��ײNPC������������¼��ƪ��
void Meet_NPC_1_chapter_3_library_phone();
//��ײNPC������������ƪ��
void Meet_NPC_1_chapter_4_lobby_conversation();
void Meet_NPC_2_chapter_4_lobby_conversation();


//��ײΧǽ����
void Meet_wall_video_left();
void Meet_wall_tree_house_on_the_snow();
void Meet_wall_tree_house_girls_on_the_snow();
void Meet_wall_corridor();
void Meet_wall_station();
void Meet_wall_computer();
void Meet_wall_group_introduction_left();
void Meet_wall_big_coin_computer();

void Meet_wall_chapter_2_library();
void Meet_wall_chapter_2_game_easter_eggs_room();

void Meet_wall_chapter_4_cycle_1_40km();
void Meet_wall_chapter_4_cycle_2_25km();
void Meet_wall_chapter_4_cycle_3_10km();
void Meet_wall_chapter_4_cycle_4();
void Meet_wall_chapter_4_lobby_conversation();

//��Ϸ�ؿ���ײΧǽ����
void Meet_object_mobile_big_coin();
void Meet_object_mobile_document_icon();

//��Ϸ�ؿ������������Ϸ�����ĺ���
void Meet_finish_game_get_3_big_coin();
void Meet_finish_game_get_1_document_icon();
void Meet_finish_game_get_6_document_icon();
void Meet_NPC_1_chapter_3_level_2_game_over();

//�������������ݽṹ��Ҫ�ĺ���������ɾ
Node_page* Get_new_node_page(long long qq);												//�����µ�ҳ����
List_page* Get_list_page();																//��ȡ�µ�����

int Insert_new_node_page(List_page* Under_turing, int ind, long long qq);				//����������µ�ҳ��ڵ㣬����Ҫ�Ĳ���������1�������׵�ַ��2������ĵڼ���λ�ã�3�������ߵ�qq�ţ�
int Erase_node_page(List_page* Under_turing, int ind);									//������������ҳ���㣬����Ҫ�Ĳ���������1�������׵�ַ��2������ĵڼ���λ��
void Output_all_node_page(List_page* Under_turing);									//����������е�ҳ���㣬����Ҫ�Ĳ���������1�������׵�ַ

void Clear_node_page(Node_page* Node_page);												//���ҳ���㣬����Ҫ�Ĳ���������ҳ������׵�ַ
void Clear_list_page(List_page* Under_turing);											//�����������Ҫ�Ĳ��������������׵�ַ

//��ʼ�����ݶ�Ӧ�ĺ���
void Init_game_data_chapter_0();
void Init_game_data_chapter_1();
void Init_game_data_chapter_2();
void Init_game_data_chapter_3();
void Init_game_data_chapter_4();
void Init_game_data_chapter_4_push_computer();
void Init_BOSS_chapter();
void Init_game_date_end_credit();
//������ȫ�ֱ���������

//��¼��Ϸ���ڴ�С
extern int Window_width;		//��Ϸ���ڵĳ���
extern int Window_height;		//��Ϸ���ڵĸ߶�

extern List_page* Game_data_under_turing;		//ָ�������׵�ַ��ָ�룬��������ʽ��¼��ͼ��֮�¡����˾�����ҹ��������Ϸ����
extern Node_page* Pointer_present_node_page;	//ָ��ҳ�����׵�ַ��ָ�룬��¼��ǰ����ҳ��
extern Node_page* Pointer_indicator_new_page;	//�͵�ǰҳ�����Ƚϣ���������˸ı䣬��ζ�ŵ����µ�һҳ����Ҫ�����������ꣻ

//һЩ�����е�ͼ�ж��õ��ϵ�ȫ�ֱ���
extern int Signal_page_level;					//��¼��ǰҳ����������ڵڼ������в�ͬ�ĵ�ͼ����������������ԼΪ70�����ң�
extern int Signal_meet_NPC_1;					//��¼��ɫ��ǰ�Ƿ���ײ��NPC1����ײ��Ϊ1��û����Ϊ0��
extern int Signal_meet_NPC_2;					//��¼��ɫ��ǰ�Ƿ���ײ��NPC2����ײ��Ϊ1��û����Ϊ0��
extern int Signal_meet_NPC_3;					//��¼��ɫ��ǰ�Ƿ���ײ��NPC3����ײ��Ϊ1��û����Ϊ0��
extern int Signal_meet_door;					//��¼��ɫ��ǰ�Ƿ���ײ�������ţ���ײ��Ϊ1��û����Ϊ0��
extern int Signal_meet_coin;					//��¼��ɫ��ǰ�Ƿ�������Ϸ�ڵĽ�ң���ײ������1����û����Ϊ0��
extern int Signal_meet_document_icon;			//��¼��ɫ��ǰ�Ƿ�������Ϸ�ڵ��ĵ�ͼ�꣬��ײ������1����û����Ϊ0��
extern int Signal_meet_choice_box;							//��¼��ɫ��ǰ�Ƿ�����ѡ����������ˡ�����1��������5��������2��������6��������3��������7��������4��û����Ϊ0
extern int Signal_rectangle_chat_bubble_1_level;				//��¼��ǰӦ�ô�ӡ�ľ����������ݡ���������ͬ�������£������������ݲ�����10�㣬������ȷ����һ����ӡ�ĸ�������������
extern int Signal_rectangle_chat_bubble_2_level;				//��¼��ǰӦ�ô�ӡ�ľ����������ݡ���������ͬ�������£������������ݲ�����10�㣬������ȷ����һ����ӡ�ĸ�������������
extern int Signal_rectangle_chat_bubble_3_level;				//��¼��ǰӦ�ô�ӡ�ľ����������ݡ���������ͬ�������£������������ݲ�����10�㣬������ȷ����һ����ӡ�ĸ�������������

extern int Signal_phone_chat_bubble_1_level;					//��¼��ǰӦ�ô�ӡ���ֻ�������桰��������ͬ�������£��ֻ�������治����10�㣬������ȷ����һ����ӡ�ĸ��ֻ��������
extern int Signal_phone_chat_bubble_2_level;
extern int Signal_phone_chat_bubble_3_level;

//��¼�ɿ��Ƶ�λ�ĺ������꣬�Լ���Ӧ���ƶ��ٶȣ��Է��������̽��б仯
extern int Object_controlled_x;				//�ɱ������ƶ�������ĺ�����
extern int Object_controlled_y;				//�ɱ������ƶ��������������

//��¼�Զ��ƶ���λ�ĺ�������
extern int Object_mobile_x;							//�Զ��ƶ�������ĺ�����
extern int Object_mobile_big_coin_y1;				//�Զ��ƶ��Ľ��1��������
extern int Object_mobile_big_coin_y2;
extern int Object_mobile_big_coin_y3;
extern int Signal_exist_object_mobile_big_coin_1;				//�ж����1���Ƿ���ڣ�1Ϊ���ڣ����ӡ�����ҿɱ���ײ��0Ϊ�����ڣ��򲻴�ӡ�����Ҳ��ɱ���ײ
extern int Signal_exist_object_mobile_big_coin_2;
extern int Signal_exist_object_mobile_big_coin_3;
extern int Signal_scoreboard;


//�����Է����������ƻ��������ĵ�����������ͼ����Ʒԭ��ͼ����ϸ���ܸ���
extern int Object_mobile_document_icon_y1;
extern int Object_mobile_document_icon_y[];
extern int Object_mobile_document_icon_x[];
extern int Signal_exist_object_mobile_document_icon_1;
extern int Signal_exist_object_mobile_document_icon[];

//Ƭβ����������
extern int End_credit_y;


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------
//Ԫ����ʿ��Ϸ����Ҫ���ļ�����������

//���ڵĿ�͸�
# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720

//����Ŀ��
# define PEOPLE_WIDTH 120
# define PEOPLE_HEIGHT 120

//�ƶ��ٶ�
# define wjsd 25//����ٶ�
# define drsd 10//�����ٶ�

//�ӵ��Ĵ�С
# define zidan_WIDTH 16
# define zidan_HEIGHT 16

//�ӵ�����
# define zidan_slwj 30//��ҵ�
# define zidan_slgw 1//�����

//�ӵ��ٶ�
# define wjzdsd 60//����ӵ��ٶ�
# define gwzdsd 40//�����ӵ��ٶ�


//��������
# define gwsl 2

//����ͼƬ
extern IMAGE jiemian[5];
extern IMAGE DTSJ;
extern IMAGE z, Z;
extern IMAGE move0, move1, move2, move3;
extern IMAGE zd1, zd2;
extern IMAGE jszd1, jszd11;
extern IMAGE bjy, bjz;
extern IMAGE zt, ztcd;
extern IMAGE yxjs;
//������Ϸ���뷵�ز˵�����
extern int t;




void huiji(void);//�����㼯

void show1(void);//��ʾ�������ͼƬ����
void wjkz(void);// ������Һ���
void ycgwyd1(void);//Զ�̹����ƶ�����1
void ycgwyd2(char, char, char, struct gwjg*);//Զ�̹����ƶ�����2
void initzd(struct zdjg*, int);//��ʼ���ӵ����Ժ���
void createwjzd(void);//����һ������ӵ�����
void creategwzd(void);//����һ�������ӵ�����
void gyzdydhs(struct zdjg*, int, int);//���õ��ӵ��ƶ�����
void wjzdpz(struct zdjg*, int, int);//����ӵ���ײ����
void gwzdpz(struct zdjg*, int, int);//�����ӵ���ײ����
int ztks(void);//��ͣ��ʼ����
void initxy(void);//���ز˵����³�ʼ������
void xuetiao(void);//Ѫ������
void initgwwz(void);//��ʼ���������λ��
bool gwbch(int);//���ﲻ�غϺ���


void load_img(void);				//����ͼƬ����

//---------------------------------------------------------------
//BOSS�ؿ�����Ҫ�ĺ�����
//void BOSS(void);					//BOSS�ؿ�
void Draw_player();					//�������﷽�򣬻������
//�����BOSS����Ҫ��ȫ�ֱ���
extern int Signal_exist_boss;				//BOSS�Ƿ����ָ�꣬1Ϊ��0Ϊ������
extern int Signal_exist_player;				//����Ƿ����ָ�꣬1Ϊ��0Ϊ������
extern int Gif_n;							//��¼��ͼ��ѭ��
extern int BOSS_x;							//��¼BOSS���ڵĺ�����
extern int BOSS_y;							//��¼BOSS���ڵĺ�����
extern int BOSS_blood_number;				//���Ѫ������
extern int BOSS_blood_rectangle;			//���Ѫ�����γ���
extern int Player_x;						//��¼BOSS���ڵĺ�����
extern int Player_y;						//��¼BOSS���ڵĺ�����
extern int Player_direction;				//��¼��ҷ���
extern int Player_blood_number;				//���Ѫ������
extern int Player_blood_rectangle;			//���Ѫ�����γ���
extern ExMessage Player_action;				//��ҵ���Ϊ��Ϣ
extern int Bullet_amount;					//����ӵ�����
extern bullet Player_bullet[];				//����ӵ�
extern int Speed_bullet;					//����ӵ��ƶ��ٶ�

//�ӵ�����ҡ�����ͼƬ����
extern IMAGE BOSS;								//BOSSͼ��
extern IMAGE img_player_left;					//��ҳ���
extern IMAGE img_player_right;					//��ҳ���
extern IMAGE img_boss_bullet_SRCAND;			//�����ӵ�
extern IMAGE img_boss_bullet_SRCPAINT;			//�����ӵ�
extern IMAGE img_player_bullet_SRCAND;			//����ӵ�
extern IMAGE img_player_bullet_SRCPAINT;		//����ӵ�






//������Ӧ��ѧ����������д�����ҵ�������Ҫ��ʾ�Ķ������ٰ�������д������������
//�����ǣ�������������д�����ҵ�������Ū��






























//------------------------------------------------------------------------------------------------------------------------
//���������ǵ�һ���汾�����ݽṹ���巽ʽ������ʽ

/*

//Singal�������ݣ���Ҫ���ڼ�¼������Ϣ��
//��ǰҳ��Ĺ������ͣ���ǰҳ���������ǰ�Ƿ���ײ��NPC����ǰ�Ƿ���ײ�������ţ�����Ϣ��
extern int Signal_page_type[100];			//��¼��ͬlevelҳ��Ĺ������ͣ�0ΪƬͷҳ�棬1Ϊ����ֱ�������ľ���ҳ�棻2Ϊ������ƶ��ľ���ҳ�棻3Ϊ��Ϸ�ؿ�ҳ�棻
extern int Signal_page_level;				//��¼��ǰҳ����������ڵڼ������в�ͬ�ĵ�ͼ����������������ԼΪ70�����ң�
extern int Signal_meet_NPC_1;					//��¼��ɫ��ǰ�Ƿ���ײ��NPC1����ײ��Ϊ1��û����Ϊ0��
extern int Signal_meet_NPC_2;					//��¼��ɫ��ǰ�Ƿ���ײ��NPC2����ײ��Ϊ1��û����Ϊ0��
extern int Signal_meet_NPC_3;					//��¼��ɫ��ǰ�Ƿ���ײ��NPC3����ײ��Ϊ1��û����Ϊ0��
extern int Signal_meet_door;				//��¼��ɫ��ǰ�Ƿ���ײ�������ţ���ײ��Ϊ1��û����Ϊ0��
extern int Signal_meet_coin;				//��¼��ɫ��ǰ�Ƿ�������Ϸ�ڵĽ�ң���ײ������1����û����Ϊ0��
extern int Signal_meet_document_icon;		//��¼��ɫ��ǰ�Ƿ�������Ϸ�ڵ��ĵ�ͼ�꣬��ײ������1����û����Ϊ0��
extern int Signal_meet_choice_box;							//��¼��ɫ��ǰ�Ƿ�����ѡ����������ˡ�����1��������5��������2��������6��������3��������7��������4��û����Ϊ0
extern int Signal_rectangle_chat_bubble_level;				//��¼��ǰӦ�ô�ӡ�ľ����������ݡ���������ͬ�������£������������ݲ�����10�㣬������ȷ����һ����ӡ�ĸ�������������
extern int Signal_phone_chat_bubble_level;					//��¼��ǰӦ�ô�ӡ���ֻ�������桰��������ͬ�������£��ֻ�������治����10�㣬������ȷ����һ����ӡ�ĸ��ֻ��������


//��¼��ǰ�ƶ���λ�ĺ������꣬�Լ���Ӧ���ƶ��ٶȣ��Է��������̽��б仯
extern int Object_controlled_x;				//�ɱ������ƶ�������ĺ�����
extern int Object_controlled_y;				//�ɱ������ƶ��������������
extern int Object_controlled_speed_x;		//�ɱ������ƶ�������ĺ������ƶ��ٶ�
extern int Object_controlled_speed_y;		//�ɱ������ƶ���������������ƶ��ٶ�

extern int Object_mobile_x;					//�Զ��ƶ�������ĺ�����
extern int Object_mobile_y1;					//�Զ��ƶ��������������
extern int Object_mobile_y2;
extern int Object_mobile_speed_x;			//�Զ��ƶ�������ĺ������ƶ��ٶ�
extern int Object_mobile_speed_y1;			//�Զ��ƶ���������������ƶ��ٶ�
extern int Object_mobile_speed_y2;


extern LPCTSTR Image_address_page_background[100];				//����ͼƬ��ͼƬ��ַ
extern LPCTSTR Image_address_object_controlled[100];			//�ɿ����ƶ������ͼƬ��ַ

extern IMAGE Image_address_rectangle_chat_bubble[100];			//�����������ݵ�ͼƬ��ַ



*/