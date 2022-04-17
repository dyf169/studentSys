#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Student {
	char name[10];
	char id[10];
	float score;
}Student;

typedef struct Stus 
{
	Student stu[100];
	int len;
}Stus;

#define filename "D:\\E\\data.txt"	
	
void saveData();
void flushData();
void welcome();
void func();
void showData();
bool searchData(char stuName[]);
void modifyData();
void removeData();
void seqScore();

Stus stus = {};
void saveData() {
	Student stu = {};
	FILE* fp = fopen(filename, "a");
	printf("please enter student's data\n");
	scanf_s("%s", stu.name, 10);
	scanf_s("%s", stu.id, 10);
	scanf_s("%f", &stu.score);
	fprintf(fp, "%c%s %s %f", '#',stu.name, stu.id, stu.score);
	fclose(fp);
	printf("�ļ�����ɹ�����\n");
}
void flushData() {
	//static Student stu[10] = {};
	FILE* fp = fopen(filename, "r+");//���ļ�
	if (fp == NULL) {
		perror("�ļ���ʧ�ܣ�����\n");
	}
	int i = 0;
	while (!feof(fp)) {
		fgetc(fp);
		fscanf_s(fp, "%s", stus.stu[i].name, 10);
		fscanf_s(fp, "%s", stus.stu[i].id, 10);
		fscanf_s(fp, "%f", &stus.stu[i].score);
		i++;
	}
	stus.len = i;
	fclose(fp);
	//return stu;
}
void showData() {
	printf("����\t\tѧ��\t\t�ɼ�\n");
	for (int i = 0; i < stus.len; i++) {
		printf("%s\t\t%s\t\t%f\n", stus.stu[i].name, stus.stu[i].id, stus.stu[i].score);
	}
}
bool searchData(char name[]) {
	bool flag = false;
	for (int i = 0; i < stus.len; i++)
	{
		if (strcmp(name, stus.stu[i].name) == 0) {
			flag = true;
			printf("%s %s %f\n", stus.stu[i].name, stus.stu[i].id, stus.stu[i].score);
			return true;
		}
	}
	
	if (flag==false)
	{
		printf("δ�ҵ�ѧ����Ϣ\n");
		return false;
	}
}
void seqScore() {
	Student stu = {};
	for (int i = 0; i < stus.len-1; i++) {
		for (int j = 0; j < stus.len - i-1; j++) {
			if (stus.stu[j].score < stus.stu[j+1].score) {
				strcpy(stu.name, stus.stu[j].name);
				strcpy(stu.id, stus.stu[j].id);
				stu.score = stus.stu[j].score;

				strcpy(stus.stu[j].name, stus.stu[j + 1].name);
				strcpy(stus.stu[j].id, stus.stu[j + 1].id);
				stus.stu[j].score=stus.stu[j + 1].score;

				strcpy(stus.stu[j + 1].name, stu.name);
				strcpy(stus.stu[j + 1].id, stu.id);
				stus.stu[j + 1].score = stu.score;
			}
		}
	}
}
void welcome()

{
	printf(" \n\n                    \n\n");
	printf("  ******************************************************\n\n");
	printf("  *          *    ѧ����Ϣ����ϵͳ     *               *\n \n");
	printf("  ******************************************************\n\n");
	printf("  *******************ϵͳ���ܲ˵�***********************       \n");
	printf("  *   ----------------------   ----------------------  * \n");
	printf("  *   *********************************************    *\n");
	printf("  *  *          1.���ѧ����Ϣ                           \n");
	printf("  * *********************************************      *\n");
	printf("  *             2.ˢ��ѧ����Ϣ                          \n");
	printf("  * *********************************************      *\n");
	printf("  *             3.��ʾѧ����Ϣ                         *\n");
	printf("  *************************************************** *\n");
	printf("                4.����ѧ����Ϣ                                           \n");
	printf("  ******************************************************                         \n");
	printf("                5.�޸�ѧ����Ϣ                                           \n");
	printf("  ******************************************************                         \n");
	printf("                6.ɾ��ѧ����Ϣ                                           \n");
	printf("  ******************************************************                         \n");
	printf("                7.�ɼ�����                                           \n");
	printf("  ******************************************************                         \n");
	printf("                0.�˳�ϵͳ                                           \n");
	printf("     -------------------   ----------------------                           \n");
	printf("������˵����,����0-7֮��ѡ��:\n");
}
void func() {
	
	Student* stu = NULL;
	while (true)
	{
		system("cls");
		welcome();
		int op;
		scanf_s("%d", &op);
		switch (op)
		{
		case 0:exit(0);
		case 1:					//����ѧ����Ϣ
			saveData(); 
			break;
		case 2:					//��ȡѧ����Ϣ
			flushData();
			break;
		case 3:					//��ʾѧ����Ϣ
			showData();
			break;
		case 4:					//����ѧ����Ϣ
			char stuName[10];
			printf("������Ҫ���ҵ�����\n");
			scanf_s("%s", stuName, 10);
			searchData(stuName);
			break;
		case 5:					//�޸�ѧ����Ϣ
			modifyData();
			break;
		case 6:					//ɾ��ѧ����Ϣ
			removeData();
			 break;
		case 7:					//ѧ���ɼ�����
			seqScore();
			break;
		default:
			break;
		}
		system("pause");
	}

}
void modifyData() {
	Student stu = {};
	printf("������Ҫ�޸ĵ�ѧ������\n");
	scanf_s("%s", stu.name, 10);
	if (searchData(stu.name) == false) {
		return func();
	}
	printf("������Ҫ�޸ĵ�ѧ����Ϣ\n");
	scanf_s("%s", stu.id, 10);
	scanf_s("%f", &stu.score);
	for (int i = 0; i < stus.len; i++) {
		if (strcmp(stu.name, stus.stu[i].name) == 0) {
			//strcpy(stus.stu[i].name, stus.stu[i + 1].name);
			strcpy(stus.stu[i].id, stu.id);
			stus.stu[i].score = stu.score;
		}
	}
	//stus.len--;

	FILE* fp = fopen(filename, "w+");
	if (fp == NULL) {
		perror("�ļ���ʧ��\n");
	}
	rewind(fp);
	for (int i = 0; i < stus.len; i++) {
		fprintf(fp, "%c%s %s %f", '#', stus.stu[i].name, stus.stu[i].id, stus.stu[i].score);
	}
	fclose(fp);
	printf("��Ϣ�޸ĳɹ�\n");
}
void removeData() {
	char stuName[10];
	printf("������Ҫɾ����ѧ������\n");
	scanf_s("%s", stuName, 10);
	if (searchData(stuName) == false) {
		return func();
	}
	for (int i = 0; i < stus.len; i++) {
		if (strcmp(stuName, stus.stu[i].name) == 0) {
			strcpy(stus.stu[i].name, stus.stu[i + 1].name);
			strcpy(stus.stu[i].id, stus.stu[i + 1].id);
			stus.stu[i].score = stus.stu[i + 1].score;
		}
	}
	stus.len--;

	FILE* fp = fopen(filename, "w+");
	if (fp == NULL) {
		perror("�ļ���ʧ��\n");
	}
	rewind(fp);
	for (int i = 0; i < stus.len; i++) {
		fprintf(fp, "%c%s %s %f", '#', stus.stu[i].name, stus.stu[i].id, stus.stu[i].score);
	}
	fclose(fp);
	printf("��Ϣɾ���ɹ�\n");
}
int main() {
	
	func();
	return 0;
}