#include "init_globle_variable.h"

//���������ݽṹ��Ҫ�ĺ���
//�����µĹ�������Ϊ1��ҳ����
Node_page* Get_new_node_page(long long qq) {
	Node_page *p = (Node_page*)malloc(sizeof(Node_page));
	p->Editor_qq = qq;
	p->Next_page = NULL;
	p->Image_address_background = NULL;
	p->Object_controlled.Image_address = NULL;
	p->Object_controlled.Image_address_SRCAND = NULL;
	p->Object_controlled.Image_address_SRCPAINT = NULL;
	p->NPC_1.Image_address_phone_chat_bubble_SRCAND = NULL;
	p->Meet_page_door = NULL;
	p->Meet_page_door_2 = NULL;
	p->Meet_page_wall = NULL;
	p->NPC_1.Meet = NULL;
	p->NPC_2.Meet = NULL;
	p->NPC_3.Meet = NULL;
	p->Object_mobile.Image_address_SRCAND = NULL;
	p->Object_mobile.Image_address_SRCPAINT = NULL;
	p->Object_mobile.Image_address_scoreboard_SRCPAINT = NULL;
	p->Object_mobile.Meet = NULL;
	p->NPC_1.Image_address_rectangle_chat_bubble[0] = NULL;
	p->NPC_2.Image_address_rectangle_chat_bubble[0] = NULL;
	p->NPC_3.Image_address_rectangle_chat_bubble[0] = NULL;
	p->NPC_1.Image_address_phone_chat_bubble[0] = NULL;
	p->NPC_2.Image_address_phone_chat_bubble[0] = NULL;
	p->NPC_3.Image_address_phone_chat_bubble[0] = NULL;
	p->Meet_finish_game = NULL;
	return p;
};

/*
�ο����룺
ListNode* getNewNode(int val) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));		//����һ������ڵ����͵�ָ�����p����ʼ����ָ�룺����һƬ�洢�ռ䣬��ָ��pָ��ÿռ���׵�ַ
	p->data = val;											//�ô������ֵ�����浽������ڵ����������
	p->next = NULL;											//��ʼ��������ڵ��ָ��������ָ��գ�NULL��
	return p;												//�����뵽��25�У�˵���µ�����ڵ㴴����ɣ����ؽڵ����͵�ָ��p�����ڵ��ַ��
}
typedef struct Node_page {
	long long Editor_qq;						//��д��ҳ��ڵ��д�ߵ�qq����
	int Type;									//��ҳ�������ͣ�0ΪƬͷ��1Ϊ�����л���2Ϊ�ƶ����嵽�������л���3Ϊ������Ϸ�����л���4ΪƬβ
	struct Node_page *Next_page;				//��һ��ҳ������׵�ַ
	int Chapter;								//��ǰҳ���������ڵ��½�
	char Name[30];								//ҳ��������֡����������ڲ���ҳ��ʱ��ȷ��ҳ��
	LPCTSTR Image_address_background;							//����ͼƬ���ļ���ַָ��
	LPCTSTR Image_address_object_controlled;					//��ǰҳ��Ŀɿ�������ͼƬ���ļ���ַָ��
	int Object_controlled_born_x;				//�ɿ��������ڵ�ǰҳ��ĵĳ���������꣨��һ��ʼ����ҳ��ʱ���ɿ����������ڵĺ����꣩
	int Object_controlled_born_y;				//�ɿ��������ڵ�ǰҳ��ĵĳ����������꣨��һ��ʼ����ҳ��ʱ���ɿ����������ڵ������꣩
	//int Object_controlled_x;					//�ɿ�������ĵ�ǰ�����ꡪ������������̫��Ҫ������ȫ�ֱ�������ʱע�͵�
	//int Object_controlled_y;					//�ɿ�������ĵ�ǰ������
	int Object_controlled_speed_x;				//�ɿ��������ڵ�ǰҳ��ĺ������ٶ�
	int Object_controlled_speed_y;				//�ɿ��������ڵ�ǰҳ����������ٶ�
	LPCTSTR Image_address_object_mobile;						//��ǰҳ����Զ��ƶ�����ͼƬ���ļ���ַָ�롪����Ϸ�ؿ�
	int Object_mobile_born_x;					//�Զ��ƶ������ڵ�ǰҳ��ĳ����������
	int Object_mobile_born_y;					//�Զ��ƶ������ڵ�ǰҳ��ĳ�����������
	//int Object_mobile_x;
	//int Object_mobile_y;
	int Object_mobile_speed_x;					//��ǰҳ���£��Զ��ƶ�����ĺ������ƶ��ٶ�
	int Object_mobile_speed_y;					//��ǰҳ���£��Զ��ƶ�������������ƶ��ٶ�
	LPCTSTR Image_address_NPC_1;						//��ǰҳ���£�1��NPC��ͼƬ�ļ���ַָ��
	LPCTSTR Image_address_NPC_2;						//��ǰҳ���£�1��NPC��ͼƬ�ļ���ַָ��
	LPCTSTR Image_address_NPC_3;						//��ǰҳ���£�1��NPC��ͼƬ�ļ���ַָ��
	void (*Meet_page_wall)();					//��ǰҳ���£���ײǽ�ڵĺ���ָ��
	void (*Meet_page_door)();					//��ǰҳ���£���ײ�����ŵĺ���ָ��
	void (*Meet_page_NPC_1)();					//��ǰҳ���£���ײ1��NPC�ĺ���ָ��
	void (*Meet_page_NPC_2)();					//��ǰҳ���£���ײ2��NPC�ĺ���ָ��
	void (*Meet_page_NPC_3)();					//��ǰҳ���£���ײ3��NPC�ĺ���ָ��
	int Sum_rectangle_chat_bubble;							//��ǰҳ���£�������������ͼƬ������
	LPCTSTR Image_address_rectangle_chat_bubble[20];		//��ǰҳ���£�������������ͼƬ���ļ���ַָ������
	int Sum_phone_chat_bubble;								//��ǰҳ���£��ֻ���������ͼƬ������
	LPCTSTR Image_address_phone_chat_bubble[20];			//��ǰҳ���£��ֻ���������ͼƬ���ļ���ַָ������
} Node_page;			//�˴��������ǣ����ýṹ�����Ƶļ�д���ṹ��ȫ��Ϊstruct Node_page����дΪNode_page��
*/



List_page* Get_list_page() {
	List_page* p = (List_page*)malloc(sizeof(List_page));
	p->Head.Next_page = NULL;
	p->Length = 0;
	return p;
};

/*
�ο����룺
List* getLinkList() {
	List* l = (List*)malloc(sizeof(List));		//����һ���������͵�ָ�����l����ʼ��ָ��lָ�������׵�ַ�������µĴ洢�ռ䣬��СΪ����������͵Ĵ�С
	l->head.next = NULL;						//��ʼ��������ͷָ���ָ����ָ��գ�NULL
	l->Length = 0;								//��ʼ��������Ϊ0��
	return l;
}
*/


//д���������һ�����⣬�Ǿ��ǣ����뺯��ind��Ҳ���ò���ɶ��סÿһ�ţ����ǣ���һ��ƪ���������Ƹ�ƪ���ʼ��ind�������Ķ���ind + 1, ind + 2, ..., ind + i;
//�ڶ��������ǣ�ָ���ڲ��ϵ�ָ����һ���ı��������У����ܲ��ϵر任ָ�����ͣ�
int Insert_new_node_page(List_page* Under_turing, int ind, long long qq) {
	if (Under_turing == NULL) return 0;
	if (ind < 0 || ind > Under_turing->Length) return 0;
	Node_page* p = &(Under_turing->Head), * node = Get_new_node_page(qq);
	while (ind--) p = p->Next_page;
	node->Next_page = p->Next_page;
	p->Next_page = node;
	Under_turing->Length += 1;
	return 1;
};

/*
int insert(List* l, int ind, int val) {
	if (l == NULL) return 0;								//���ָ�������׵�ַ��ָ��Ϊ�գ�����ʧ�ܣ��򷵻�0��
	if (ind < 0 || ind > l->Length) return 0;				//������λ��С��0�����ߴ�����λ�ô��������ȣ�����ʧ�ܣ�����0��
	ListNode* p = &(l->head), * node = getNewNode(val);		//����һ������ڵ����͵�ָ��p����ʼ��Ϊͷ�ڵ���׵�ַ�������������ͱ����е�head��������һ������ڵ����͵�ָ��node��ָ��һ���¿��ٽڵ���׵�ַ
	while (ind--) p = p->next;								//p��ָ��ͷ�ڵ㿪ʼ��ָ��p����һ���ڵ���׵�ַ�����ѭ��ind�Σ���ζ�ţ�ͷ�ڵ����-1��λ�õĽڵ㣬ָ��ĵ�һ���ڵ���0��λ�õĽڵ㣩
	node->next = p->next;									//���½ڵ��ָ����ָ���ͷ�ڵ���������ind���Ժ󣬵Ľڵ����һ���ڵ���׵�ַ�������;�������ָ��ָ�����ˣ�p->next �� node->next��
	p->next = node;											//����ԭ�������������n����ָ����ָ��Ľڵ㣬��ָ����ָ���¿��ٽڵ���׵�ַ
	l->Length += 1;											//������ִ�е�42�е�ʱ��˵������ڵ㣬����ָ��Ĳ�����ɣ������ȼ�1��
	return 1;												//������ִ�е���43�е�ʱ��˵������ڵ㣬��������Ĳ�����ɣ�����1��
}
*/



int Erase_node_page(List_page* Under_turing, int ind) {
	if (Under_turing == NULL) return 0;							//����֪����Щָ���пղ����ж���Ҫ��
	if (ind < 0 || ind > Under_turing->Length) return 0;
	Node_page* p = &(Under_turing->Head), * q;
	while (ind--) p = p->Next_page;
	q = p->Next_page;
	if (q != NULL) p->Next_page = q->Next_page;					//ԭ���Ĵ����� p->Next_page = q->Next_page��q�п����ǿ�ָ�룬ʹ�õ�����NULLָ�룬��;�˳����˳�����Ϊ��-1073741819
	else p->Next_page = q;
	free(q);
	Under_turing->Length -= 1;
	return 1;
}


/*
�ο����룺
//���庯����ɾ���ڵ����
//��������������������ڵ���׵�ַ�����������͵�ָ�����l�����գ���ɾ������λ��
//������������ͱ�����ɾ���ɹ�����1�����򷵻�0��
int erase(List* l, int ind) {
	if (l == NULL) return 0;						//��ָ�������׵�ַ��ָ��Ϊ�գ����Ҳ�������ɾ��ʧ�ܣ�����0��
	if (ind < 0 || ind >= l->Length) return 0;		//��ɾ��λ��С��0�����߳���������Length�����Ҳ�����ɾ��������ڵ㣬ɾ��ʧ�ܣ�����0��
	ListNode* p = &(l->head), * q;					//����һ������ڵ��ָ�����p����ʼ��Ϊָ������ͷ�ڵ㣬����һ������ڵ��ָ�����q��δ��ʼ����
	while (ind--) p = p->next;						//ָ��p��ͷָ��ָ��ָ�����д������һ������ڵ���׵�ַ�����������ind������-1��ʼ�ߣ�
	q = p->next;									//��ָ��qָ���ɾ���ڵ���׵�ַ������ind�Ľڵ��׵�ַ��������-1����ind�������ڽڵ��ָ�����д������һ���ڵ��׵�ַ
	p->next = q->next;								//��ָ��p��ָ����ָ���ɾ���ڵ㣨Ҳ����p->next��q��ָ��Ľڵ��׵�ַ)����һ���ڵ㣬������ɾ������ָ����ָ����һ��������һ�������׵�ַ����Ϊʲô�����ﲻ��ֻ�ã�һ��ָ�룬p->next = (p->next)->next ?)
	free(q);										//�ͷŴ�ɾ�����Ŀռ䣬����ָ��q�Ŀռ䣻
	l->Length -= 1;									//�����ȼ�1
	return 1;										//������ִ�е���58�У���ζ��ɾ��������ɣ�����1��
}


*/

void Output_all_node_page(List_page* Under_turing) {
	printf("List_page(Length = %d) = [", Under_turing->Length);
	int N_level = 0;
	for (Node_page* p = Under_turing->Head.Next_page; p; p = p->Next_page) {
		printf("(%d, %lld)->",N_level, p->Editor_qq);
		N_level++;
	}
	printf("NULL] \n");
	return;
}

/*
�ο����룺
//���庯���������������
//���������������������׵�ַ�����������͵�ָ�����������
//�����������
void output(List *l) {
	printf("List(%d) = [", l->Length);						//��ӡ�������䳤��
	for (ListNode* p = l->head.next; p; p = p->next) {		//����һ��ѭ�����̣�ָ��pָ���0λ�ýڵ��׵�ַ��������ͷָ���ָ����ʼ����ָ�벻Ϊ��ʱ������ѭ����ÿ���һ��ѭ����ָ��ָ��ǰ�ڵ��ָ����
		printf("%d->", p->data);							//��ӡ�ڵ�
	}
	printf("NULL]\n");										//������ִ�е�69�У�ѭ����������ζ��p->nextΪ�գ����һ�������ָ����Ϊ�գ���ӡNULL
	return;													//������ִ�е�70�У���ζ�Ŵ�ӡ������ɣ����ؿ�ֵ��
}
*/

void Clear_node_page(Node_page* node) {
	if (node == NULL) return;
	free(node);
	return;
}

/*
�ο����룺
//���庯������սڵ�
//�������������սڵ���׵�ַ��������ڵ����͵�ָ�����������
//�����������ֵ
void clear_ListNode(ListNode* node) {
	if (node == NULL) return;			//���ָ��ڵ��׵�ַ��ָ��Ϊ�գ��򷵻ؿ�ֵ
	free(node);							//������ִ�е���100�У�˵����Ϊ�գ��ͷŸ�ָ����ָ��Ľڵ���ռ�ݵĴ洢�ռ�
	return;								//�ͷ���ɣ����ؿ�ֵ
}
*/

void Clear_list_page(List_page* Under_turing) {
	if (Under_turing == NULL) return;
	Node_page* p = Under_turing->Head.Next_page, * q;
	while (p) {
		q = p->Next_page;
		Clear_node_page(p);
		p = q;
	}
	free(Under_turing);
	return;
}

/*
�ο����룺
//���庯��������������
//�������������յ������׵�ַ�����������͵�ָ�����������
//�����������ֵ
void clear_list(List* l) {
	if (l == NULL) return;				//��ָ�������׵�ַ��ָ��Ϊ�գ���˵���Ҳ�������յ��������ʧ�ܣ����ؿ�ֵ
	ListNode* p = l->head.next, * q;	//����2������ڵ����͵�ָ�����p��q����ʼ��ָ��p������ָ��0�Žڵ�
	while (p) {							//��ָ��p��Ϊ��ʱ
		q = p->next;					//��ָ��qָ��ָ��pָ��Ľڵ����һ���ڵ�
		clear_ListNode(p);				//���ָ��p
		p = q;							//��ָ��pָ��ָ��qָ��Ľڵ㣬ֱ��qΪ�գ���p->nextΪ�գ�
	}
	free(l);							//������ִ�е���115�У�������������ڵ����ղ�����ɣ�������������ͷ�ָ��lָ��Ĵ�������Ŀռ�
	return;								//������ִ�е���116�У�������������ɣ����ؿ�ֵ��
}
*/
