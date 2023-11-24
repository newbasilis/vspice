#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct _node {
	char name[10];		// �̸�
	char address[30];	// �ּ�
	char phone[14];		// ��ȭ��ȣ
	char mobile[14];	// �ڵ���
	char mail[20];		// e-mail
	struct _node *link;	// ���� ���
};

typedef struct _node node;

void Insert(node*);		// ��� ���� �Լ�
void Delete(node*);		// ��� ���� �Լ�
void Display(node*);	// ��� ���� ��� �Լ�
void Search(node*);		// ��� ���� �˻� �Լ�

int main(void) {
	node *ptr;
	int choice;

	/*
	ù��° ��� ����
	�����Ҵ��� ���� ������ �����Ͽ� ��带 �����.
	���� ��� ��ġ�� NULL�� �ʱ�ȭ�Ѵ�
	*/
	ptr = (node *)malloc(sizeof(node));
	ptr->link = NULL;

	/*
	do-while�� �̿��� �ݺ�
	4. ���Ḧ ������ ������ �ݺ��Ѵ�.
	*/
	do {
		// �޴� ���
		printf("�ּҰ��� ���α׷�\n");
		printf("1. ��     ��\n");
		printf("2. ��     ��\n");
		printf("3. ��     ��\n");
		printf("4. ��     ��\n");
		printf("��ɾ �����Ͻÿ�: ");

		// 1���ڸ� �Է¹޾� ���ڷ� ��ȯ
		choice = getchar() - '0';

		// �Է� ���� �ʱ�ȭ
		fflush(stdin);

		/* 
		�Է¹��� ���ڿ� ���� �б�
		1 : ��� -> Insert
		2 : ��� -> Display
		3 : ���� -> Delete
		4 : �˻� -> Search
		*/
		switch(choice) {
		case 1 : 
			Insert(ptr); 
			break;
		case 2 : 
			Display(ptr->link);
			break;
		case 3 : 
			Delete(ptr); 
			break;
		case 4 : 
			Search(ptr); 
			break;

		}
	}while(choice!=5);
}


void Insert(node *ptr) {
	while (ptr->link != NULL)
		ptr = ptr->link;

	ptr->link = (node*)malloc(sizeof(node));
	ptr = ptr->link;

	printf("�̸��� �Է��Ͻÿ�: ");
	gets(ptr->name);
	printf("�ּҸ� �Է��Ͻÿ�: ");
	gets(ptr->address);
	printf("��ȭ��ȣ �Է��Ͻÿ�: ");
	gets(ptr->phone);
	printf("�ڵ����� �Է��Ͻÿ�: ");
	gets(ptr->mobile);
	printf("E-Mail�� �Է��Ͻÿ�: ");
	gets(ptr->mail);

	ptr->link = NULL;
	printf("\n");
}

void Delete(node *ptr)  {
	node *prev;
	char _phone[14];

	printf("������ ��ȭ��ȣ�� �����Ͻÿ�: ");
	gets(_phone);

	while (ptr->link != NULL)  {
		prev = ptr;
		ptr = ptr->link;

		/* ����Ǿ� �ִ� �������߿��� ��ȭ��ȣ�� �������� �����͸� ���� */
		if (strcmp(_phone, ptr->phone) == 0) {
			prev->link = ptr->link;
			free(ptr);
			break;
		}
	}
	return;
}

void Display(node *ptr)  {
	printf("%6s", "��  ��") ;
	printf("%14s", "��   ��");
	printf("%14s", "��ȭ��ȣ");
	printf("%14s", "�ڵ���");
	printf("%10s\n", "E-Mail");

	while (ptr != NULL) {
		printf("%6s", ptr->name);
		printf("%14s", ptr->address);
		printf("%14s", ptr->phone);
		printf("%14s", ptr->mobile);
		printf("%10s", ptr->mail);

		ptr = ptr->link;
		printf("\n");
	}

	printf("\n");
}

void Search(node *ptr) {
	char _name[10];

	printf("�̸��� �Է��Ͻÿ�: ");
	gets(_name); 

	printf("%6s", "��  ��") ;
	printf("%14s", "��   ��");
	printf("%14s", "��ȭ��ȣ");
	printf("%14s", "�ڵ���");
	printf("%10s\n", "E-Mail");

	while (ptr != NULL)  {
		if (strcmp(_name, ptr->name) == 0) {

			printf("%6s", ptr->name);
			printf("%14s", ptr->address);
			printf("%14s", ptr->phone);
			printf("%14s", ptr->mobile);
			printf("%10s", ptr->mail);

			printf("\n");
		}
		ptr = ptr->link;
	}
}
