#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int Booknum = 5;
int Num = 5;
typedef struct book
{
	char day[30];
	int price;
	int num;
	char id[30];
	char name[20];
	char actor[20];
	
}book;
typedef struct booknode
{
	book data;
	struct booknode* next;
}booknode;
typedef struct user
{
	char number[20];
	char password[20];
	int Flag;
}user;
typedef struct userstore
{
	user data;
}userstore;
void creat_u(userstore p[])
{
	FILE* fp = fopen("userinfo.txt", "r");//ֻ����
	if (!fp)
	{
		printf("userinfo.txt�ļ���ʧ��\n");
	}
	int i = 0;
	fscanf(fp, "%d", &Num);
	for (i = 0; i < Num; i++)
	{
		fscanf(fp, "%s", p[i].data.number);
		fscanf(fp, "%s", p[i].data.password);
		fscanf(fp, "%d", &p[i].data.Flag);
	}
}
void up_u(userstore p[])
{
	FILE* fp = fopen("userinfo.txt", "w");//ֻ����
	if (!fp)
	{
		printf("userinfo.txt�ļ���ʧ��\n");
	}
	int i = 0;
	fprintf(fp, "%d\n", Num);
	for (i = 0; i < Num; i++)
	{
		if (p[i].data.Flag > -1)
		{
			fprintf(fp, "%s ", p[i].data.number);
			fprintf(fp, "%s ", p[i].data.password);
			fprintf(fp, "%d ", p[i].data.Flag);
		}
		fprintf(fp, "\n");
	}
}
void creat(booknode* phead)
{
	booknode* r = (booknode*)malloc(sizeof(booknode));
	phead->next = NULL;
	r = phead;
	FILE* fp = fopen("bookinfo.txt", "r");//ֻ����
	if (!fp)
	{
		printf("bookinfo.txt�ļ���ʧ��\n");
	}
	int i = 0;
	fscanf(fp, "%d", &Booknum);
	for (i = 0; i < Booknum; i++)
	{
		booknode* p = (booknode*)malloc(sizeof(booknode));
		fscanf(fp, "%s", p->data.id);
		fscanf(fp, "%s", p->data.name);
		fscanf(fp, "%s", p->data.actor);
		fscanf(fp, "%s", p->data.day);
		fscanf(fp, "%d", &p->data.price);
		fscanf(fp, "%d", &p->data.num);
		p->next = NULL;
		r->next = p;
		r = p;
	}
}
void updata(booknode* phead)
{
	booknode* p = (booknode*)malloc(sizeof(booknode));
	p = phead->next;
	FILE* fp = fopen("bookinfo.txt", "w");//д���ļ�
	if (!fp)
	{
		printf("bookinfo.txt�ļ���ʧ��\n");
	}
	char arr[30] = { '\0' };
	fprintf(fp, "%d\n", Booknum);
	while (p)
	{
		if (p->data.price > 0)
		{
			fprintf(fp, "%s ", p->data.id);
			fprintf(fp, "%s ", p->data.name);
			fprintf(fp, "%s ", p->data.actor);
			fprintf(fp, "%s ", p->data.day);
			fprintf(fp, "%d ", p->data.price);
			fprintf(fp, "%d", p->data.num);
			fprintf(fp, "\n");
		}
		p = p->next;
	}
}
void add(booknode* phead)
{
	booknode* s = (booknode*)malloc(sizeof(booknode));
	s = phead;
	booknode* p = (booknode*)malloc(sizeof(booknode));
	printf("��������ı��\n");
	scanf("%s", p->data.id);
	printf("�������������\n");
	scanf("%s", p->data.name);
	printf("�������������\n");
	scanf("%s", p->data.actor);
	printf("��������ĳ�������,�м���.����\n");
	scanf("%s", p->data.day);
	printf("��������ļ۸�\n");
	scanf("%d", &p->data.price);
	printf("��������Ŀ��\n");
	scanf("%d", &p->data.num);
	p->next = s->next;
	s->next = p;
	Booknum++;
	printf("�������\n");
	updata(phead);
}
void delete(booknode* phead)
{
	booknode* p = (booknode*)malloc(sizeof(booknode));
	p = phead->next;
	int n = -1;
	int flag = 0;
	char arr[30] = { '\0' };
	while (n)
	{
		printf("��ѡ��ɾ���ĸ���\n");
		printf("1.���\n");
		printf("2.����ʱ������ɾ��\n");
		printf("0.�˳�����\n");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			printf("��������ı��\n");
			scanf("%s", arr);
			while (p)
			{
				if (strcmp(arr, p->next->data.id) == 0)
				{
					booknode* s = p->next;
					p->next = s->next;
					free(s);
					flag = 1;
					Booknum--;
					printf("ɾ�����\n");
					break;
				}
				p = p->next;
			}
			if (flag == 0)
			{
				printf("δ�ҵ����ͼ��\n");
			}
			break;
		case 2:
			printf("��������ĳ�������\n");
			scanf("%s", arr);
			while (p)
			{
				if (strcmp(arr, p->data.day) == 0)
				{
					p->data.price = -1;
					Booknum--;
					flag = 1;
				}
				p = p->next;
			}
			if (flag == 0)
			{
				printf("δ�ҵ����ͼ��\n");
			}
			break;
		case 0:
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	}
	updata(phead);
}
void change(booknode* phead)
{
	booknode* p = (booknode*)malloc(sizeof(booknode));
	p = phead->next;
	int n = -1;
	int flag = 0;
	char arr[30] = { '\0' };
	printf("��������ı��\n");
	scanf("%s", arr);
	while (p)
	{
		if (strcmp(arr, p->data.id) == 0)
		{
			flag = 1;
			break;
		}
		p = p->next;
	}
	if (flag == 0)
	{
		printf("δ�ҵ����ͼ��\n");
	}
	while (n)
	{
		printf("��ѡ���޸ĵ�����\n");
		printf("1.���\n");
		printf("2.����\n");
		printf("3.����\n");
		printf("4.�۸�\n");
		printf("5.���������м���.����\n");
		printf("6.���\n");
		printf("0.�˳�����\n");
		scanf("%d", &n);
		switch (n)
		{
		case 0:
			break;
		case 1:
			printf("�������޸ĺ���\n");
			scanf("%s", p->data.id);
			break;
		case 2:
			printf("�������޸ĺ�����\n");
			scanf("%s", p->data.name);
			break;

		case 3:
			printf("�������޸ĺ�����\n");
			scanf("%s", p->data.actor);
			break;

		case 4:
			printf("�������޸ĺ�۸�\n");
			scanf("%d", &p->data.price);
			break;

		case 5:
			printf("�������޸ĺ�����\n");
			scanf("%s", p->data.day);
			break;
		case 6:
			printf("�������޸ĺ�Ŀ��\n");
			scanf("%d", &p->data.num);
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	}
	updata(phead);
}
void find(booknode* phead)
{
	booknode* p = phead->next;
	int n = -1;
	int flag = 0;
	char arr[30] = { '\0' };
	char brr[30] = { '\0' };
	while (n)
	{
		printf("1.������ѯ\n");
		printf("2.���߲�ѯ\n");
		printf("3.���������߲�ѯ\n");
		printf("0.�˳�\n");
		scanf("%d", &n);
		switch (n)
		{
		case 0:
			break;
		case 1:
			printf("����������\n");
			scanf("%s", arr);
			p = phead->next;
			while (p)
			{
				if (strcmp(arr, p->data.name) == 0)
				{
					printf("��ı��Ϊ:");
					printf("%s\n", p->data.id);
					printf("�������Ϊ:");
					printf("%s\n", p->data.name);
					printf("�������Ϊ:");
					printf("%s\n", p->data.actor);
					printf("��ĳ�������Ϊ:");
					printf("%s\n", p->data.day);
					printf("��ļ۸�Ϊ:");
					printf("%d\n", p->data.price);
					printf("��Ŀ��Ϊ:");
					printf("%d\n", p->data.num);
				}
				printf("\n");
				p = p->next;
			}
			break;
		case 2:
			printf("������������\n");
			scanf("%s", brr);
			p = phead->next;
			while (p)
			{
				if (strcmp(brr, p->data.actor) == 0)
				{
					printf("��ı��Ϊ:");
					printf("%s\n", p->data.id);
					printf("�������Ϊ:");
					printf("%s\n", p->data.name);
					printf("�������Ϊ:");
					printf("%s\n", p->data.actor);
					printf("��ĳ�������Ϊ:");
					printf("%s\n", p->data.day);
					printf("��ļ۸�Ϊ:");
					printf("%d\n", p->data.price);
					printf("��Ŀ��Ϊ:");
					printf("%d\n", p->data.num);
				}
				printf("\n");
				p = p->next;
			}
			break;
		case 3:
			printf("����������\n");
			scanf("%s", arr);
			getchar();
			printf("������������\n");
			scanf("%s", brr);
			p = phead->next;
			while (p)
			{
				if (strcmp(arr, p->data.name) == 0 && strcmp(brr, p->data.actor) == 0)
				{
					printf("��ı��Ϊ:");
					printf("%s\n", p->data.id);
					printf("�������Ϊ:");
					printf("%s\n", p->data.name);
					printf("�������Ϊ:");
					printf("%s\n", p->data.actor);
					printf("��ĳ�������Ϊ:");
					printf("%s\n", p->data.day);
					printf("��ļ۸�Ϊ:");
					printf("%d\n", p->data.price);
					printf("��Ŀ��Ϊ:");
					printf("%d\n", p->data.num);
				}
				p = p->next;
			}
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	}
}
void add_u(userstore p[])
{
	int m = 0;
	printf("������Ҫ�����˻��ĸ���\n");
	scanf("%d", &m);
	int n = Num;
	Num = Num + m;
	int i = 0;
	for (i = n; i < Num; i++)
	{
		char arr[20] = { '\0' };
		printf("�������˺�\n");
		scanf("%s", p[i].data.number);
		char brr[20] = "12345";
		strcpy(p[i].data.password, brr);
		printf("����Ȩ��0�û�1����Ա\n");
		scanf("%d", &p[i].data.Flag);
	}
	printf("�������\n");
	up_u(p);
}
void delete_u(userstore p[])
{
	int m = 0;
	printf("������Ҫɾ���˻��ĸ���\n");
	scanf("%d", &m);
	int n = Num;
	Num = Num - m;
	int i = 0;
	for (i = n; i > Num; i--)
	{
		p[i].data.Flag = -2;
	}
	printf("ɾ�����\n");
	up_u(p);
}
void change_u(userstore p[])
{
	printf("1.�޸�����\n");
	printf("2.��������\n");
	int s = 0;
	scanf("%d", &s);
	getchar();
	char arr[20] = { '\0' };
	printf("�������˺�\n");
	scanf("%s", arr);
	getchar();
	int i = 0;
	if (s == 1)
	{
		for (i = 0; i < Num; i++)
		{
			if (strcmp(p[i].data.number, arr) == 0)
			{
				printf("������������\n");
				scanf("%s", p[i].data.password);
				printf("�޸����\n");
				break;
			}
		}
	}
	if (s == 2)
	{
		for (i = 0; i < Num; i++)
		{
			if (strcmp(p[i].data.number, arr) == 0)
			{
				memset(p[i].data.password, '\0', sizeof(p[i].data.password));
				char brr[20] = { "12345" };
				strcpy(p[i].data.password, brr);
				printf("�������\n");
				break;
			}
		}
	}
	up_u(p);
}
int find_u(userstore p[], char arr[20])
{
	int i = 0;
	int n = -1;
	for (i = 0; i < Num; i++)
	{
		if (strcmp(arr, p[i].data.number) == 0)
		{
			n = i;
		}
	}
	return n;
}
int secure(userstore p[], int m)
{
	char b[20] = { '\0' };
	printf("����������\n");
	scanf("%s", b);
	int flag = 0;
	if (strcmp(p[m].data.password, b) == 0)
	{
		flag = 1;
	}
	return flag;
}
void menu()
{
	printf("1.����ͼ����Ϣ\n");
	printf("2.ɾ��ͼ����Ϣ\n");
	printf("3.�޸�ͼ����Ϣ\n");
	printf("4.����ͼ����Ϣ\n");
	printf("5.¼���Ա�˺���Ϣ\n");
	printf("6.ɾ����Ա�˺���Ϣ\n");
	printf("7.�޸�����\n");
	printf("0.�˳�\n");
}
int main()
{
	userstore people[20];
	booknode* p = (booknode*)malloc(sizeof(booknode));
	creat(p);
	creat_u(people);
	int choose = -1;
	int m = -1;
	char arr[20] = { '\0' };
	while (choose)
	{
		menu();
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			printf("�������˺�\n");
			scanf("%s", arr);
			m = find_u(people, arr);
			if (m > -1)
			{
				if (secure(people, m) == 1 && people[m].data.Flag == 1)
				{
					add(p);
				}
				else
				{
					printf("��������Ȩ�޲���\n");
				}
			}
			else
			{
				printf("�˺Ŵ���\n");
			}
			break;
		case 2:
			printf("�������˺�\n");
			scanf("%s", arr);
			m = find_u(people, arr);
			if (m > -1)
			{
				if (secure(people, m) == 1 && people[m].data.Flag == 1)
				{
					delete(p);
				}
				else
				{
					printf("��������Ȩ�޲���\n");
				}
			}
			else
			{
				printf("�˺Ŵ���\n");
			}
			break;
		case 3:
			printf("�������˺�\n");
			scanf("%s", arr);
			m = find_u(people, arr);
			if (m > -1)
			{
				if (secure(people, m) == 1 && people[m].data.Flag == 1)
				{
					change(p);
				}
				else
				{
					printf("��������Ȩ�޲���\n");
				}
			}
			else
			{
				printf("�˺Ŵ���\n");
			}
			break;
		case 4:
			printf("�������˺�\n");
			scanf("%s", arr);
			m = find_u(people, arr);
			if (m > -1)
			{
				if (secure(people, m) == 1)
				{
					find(p);
				}
				else
				{
					printf("������󲻹�\n");
				}
			}
			else
			{
				printf("�˺Ŵ���\n");
			}
			break;
		case 5:
			printf("�������˺�\n");
			scanf("%s", arr);
			m = find_u(people, arr);
			if (m > -1)
			{
				if (secure(people, m) == 1 && people[m].data.Flag == 1)
				{
					add_u(people);
				}
				else
				{
					printf("��������Ȩ�޲���\n");
				}
			}
			else
			{
				printf("�˺Ŵ���\n");
			}
			break;
		case 6:
			printf("�������˺�\n");
			scanf("%s", arr);
			m = find_u(people, arr);
			if (m > -1)
			{
				if (secure(people, m) == 1 && people[m].data.Flag == 1)
				{
					delete_u(people);
				}
				else
				{
					printf("��������Ȩ�޲���\n");
				}
			}
			else
			{
				printf("�˺Ŵ���\n");
			}
			break;
		case 7:
			change_u(people);
			break;
		case 0:
			break;
		default:
			printf("ѡ�����������ѡ��\n");
		}
	}
	return 0;
}