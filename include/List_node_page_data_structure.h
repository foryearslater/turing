//���崢��Ϳɿ��������йص����ݵĽṹ��
typedef struct Data_object_controlled {
	LPCTSTR Image_address;				//
	LPCTSTR Image_address_SRCAND;		//��ǰҳ���£��ɿ�������ͼƬ���ļ���ַָ��1
	LPCTSTR Image_address_SRCPAINT;		//��ǰҳ���£��ɿ�������ͼƬ���ļ���ַָ��2��������ȥ����ɫ�߿�
	int Born_x;							//��ǰҳ���£��ɿ�������ĳ���������꣨��һ��ʼ����ҳ��ʱ���ɿ����������ڵĺ����꣩
	int Born_y;							//��ǰҳ���£��ɿ�������ĳ����������꣨��һ��ʼ����ҳ��ʱ���ɿ����������ڵ������꣩
	int Speed_x;						//��ǰҳ���£��ɿ�������ĺ������ٶ�
	int Speed_y;						//��ǰҳ���£��ɿ���������������ٶ�
	int Width;							//��ǰҳ���£��ɿ��������ͼƬ��ȣ�
	int Height;							//��ǰҳ���£��ɿ��������ͼƬ�߶ȣ�
} Data_object_controlled;

typedef struct Data_NPC {
	void (*Meet)();											//��ǰҳ���£���ײ1��NPC�ĺ���ָ��
	int Sum_rectangle_chat_bubble;							//��ǰҳ���£�������������ͼƬ������
	LPCTSTR Image_address_rectangle_chat_bubble[20];
	int Sum_phone_chat_bubble;
	LPCTSTR Image_address_phone_chat_bubble[20];
	LPCTSTR Image_address_phone_chat_bubble_SRCAND;
} Data_NPC;

typedef struct Data_object_mobile {
	LPCTSTR Image_address_SRCAND;				//��ǰҳ���£��Զ��ƶ�����ͼƬ���ļ���ַָ�롪������Ϸ�ؿ���
	LPCTSTR Image_address_SRCPAINT;				//��ǰҳ���£��ɿ�������ͼƬ���ļ���ַָ��2��������ȥ����ɫ�߿�
	LPCTSTR Image_address_scoreboard_SRCPAINT;	//�Ƿ��Ƶ�ͼƬ�ļ���ַָ��
	void (*Meet)();								//��ǰҳ���£���ײ�Զ��ƶ�������ĺ���ָ��
	int Object_mobile_born_x;					//��ǰҳ���£��Զ��ƶ�����ĳ����������
	int Object_mobile_born_y;					//��ǰҳ���£��Զ��ƶ�����ĳ�����������
	int Object_mobile_speed_x;					//��ǰҳ���£��Զ��ƶ�����ĺ������ƶ��ٶ�
	int Object_mobile_speed_y;					//��ǰҳ���£��Զ��ƶ�������������ƶ��ٶ�
	int Width;									//��ǰҳ���£��Զ��ƶ������ͼƬ��ȣ�
	int Height;									//��ǰҳ���£��Զ��ƶ������ͼƬ�߶ȣ�
} Data_ojbect_mobile;

//����洢һ��ҳ���������ݵĽṹ�����͡���ҳ����
typedef struct Node_page {
	long long Editor_qq;						//��д��ҳ��ڵ��д�ߵ�qq����
	int Type;									//��ҳ�������ͣ�0ΪƬͷ��1Ϊ�����л���2Ϊ�ƶ����嵽�������л���3Ϊ������Ϸ�����л���4ΪƬβ
	struct Node_page *Next_page;				//��һ��ҳ������׵�ַ
	int Chapter;								//��ǰҳ���������ڵ��½�
	long long Name_number;								//ҳ��������֡����������ڲ���ҳ��ʱ��ȷ��ҳ��
	LPCTSTR Image_address_background;			//����ͼƬ���ļ���ַָ��
	Data_object_controlled Object_controlled;
	Data_NPC NPC_1;
	Data_NPC NPC_2;
	Data_NPC NPC_3;
	void (*Meet_page_wall)();					//��ǰҳ���£���ײǽ�ڵĺ���ָ��
	void (*Meet_page_door)();					//��ǰҳ���£���ײ�����ŵĺ���ָ��
	void (*Meet_page_door_2)();					//��ǰҳ���£���ײ�����ŵĺ���ָ��
	Data_object_mobile Object_mobile;
	void (*Meet_finish_game)();					//���������Ϸ�����ĺ�����
} Node_page;			//�˴��������ǣ����ýṹ�����Ƶļ�д���ṹ��ȫ��Ϊstruct Node_page����дΪNode_page��

//����һ����ҳ����������������
typedef struct List_page {
	Node_page Head;					//ͷ�Ž��
	int Length;						//�����ܳ���
} List_page;						//��дΪList_page��


//�ӵ���صĽṹ��
typedef struct bullet {
	int current_x, current_y;					//�ӵ���ǰ����
	int destination_x, destination_y;			//�ӵ�����Ŀ�ĵ�����
	int birth_x, birth_y;						//�ӵ�����������
	bool live;									//�ӵ��Ƿ���
} bullet;










































/*

	//LPCTSTR Image_address[10];								//��ǰҳ���£�1��NPC��ͼƬ�ļ���ַָ�룬NPC���ö����ӡ��������ڵ�ͼ�����С����������ֽ���ˣ����ĳ�ʼ���ķ�ʽ��
	//IMAGE Rectangle_chat_bubble[10];						//������logСѧ�������⣻
	//������������һ�����飬ȫ��һ���ʼ�������������ѭ��������ȡ

	//LPCTSTR Image_address_rectangle_chat_bubble_1;			//��ǰҳ���£�������������ͼƬ���ļ���ַ
	//bug�����ֳ���
	//IMAGE Rectangle_chat_bubble[10];							//���������ֶ��巽ʽ���ڽṹ���ж���󣬳�ʼ��������⣺��ǰҳ���£�������������ͼƬ���ļ���ַָ������
	//LPCTSTR Image_address[10];								//��ǰҳ���£�1��NPC��ͼƬ�ļ���ַָ�룬NPC���ö����ӡ��������ڵ�ͼ������


	/*
	LPCTSTR Image_address_object_controlled;	//��ǰҳ��Ŀɿ�������ͼƬ���ļ���ַָ��
	int Object_controlled_born_x;				//�ɿ��������ڵ�ǰҳ��ĵĳ���������꣨��һ��ʼ����ҳ��ʱ���ɿ����������ڵĺ����꣩
	int Object_controlled_born_y;				//�ɿ��������ڵ�ǰҳ��ĵĳ����������꣨��һ��ʼ����ҳ��ʱ���ɿ����������ڵ������꣩
	//int Object_controlled_x;					//�ɿ�������ĵ�ǰ�����ꡪ������������̫��Ҫ������ȫ�ֱ�������ʱע�͵�
	//int Object_controlled_y;					//�ɿ�������ĵ�ǰ������
	int Object_controlled_speed_x;				//�ɿ��������ڵ�ǰҳ��ĺ������ٶ�
	int Object_controlled_speed_y;				//�ɿ��������ڵ�ǰҳ����������ٶ�
	*/


	/*
	LPCTSTR Image_address_object_mobile;		//��ǰҳ����Զ��ƶ�����ͼƬ���ļ���ַָ�롪������Ϸ�ؿ���
	int Object_mobile_born_x;					//�Զ��ƶ������ڵ�ǰҳ��ĳ����������
	int Object_mobile_born_y;					//�Զ��ƶ������ڵ�ǰҳ��ĳ�����������
	//int Object_mobile_x;
	//int Object_mobile_y;
	int Object_mobile_speed_x;					//��ǰҳ���£��Զ��ƶ�����ĺ������ƶ��ٶ�
	int Object_mobile_speed_y;					//��ǰҳ���£��Զ��ƶ�������������ƶ��ٶ�
	*/


	/*
	LPCTSTR Image_address_NPC_1;				//��ǰҳ���£�1��NPC��ͼƬ�ļ���ַָ��
	LPCTSTR Image_address_NPC_2;				//��ǰҳ���£�1��NPC��ͼƬ�ļ���ַָ��
	LPCTSTR Image_address_NPC_3;				//��ǰҳ���£�1��NPC��ͼƬ�ļ���ַָ��
	void (*Meet_page_NPC_1)();					//��ǰҳ���£���ײ1��NPC�ĺ���ָ��
	void (*Meet_page_NPC_2)();					//��ǰҳ���£���ײ2��NPC�ĺ���ָ��
	void (*Meet_page_NPC_3)();					//��ǰҳ���£���ײ3��NPC�ĺ���ָ��
	int Sum_rectangle_chat_bubble;							//��ǰҳ���£�������������ͼƬ������
	LPCTSTR Image_address_rectangle_chat_bubble[20];			//��ǰҳ���£�������������ͼƬ���ļ���ַָ������
	int Sum_phone_chat_bubble;								//��ǰҳ���£��ֻ���������ͼƬ������
	LPCTSTR Image_address_phone_chat_bubble[20];				//��ǰҳ���£��ֻ���������ͼƬ���ļ���ַָ������
	*/


