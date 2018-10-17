//# include <iostream>
//# include <string>
//# include <fstream>
//# include <stdlib>
#include <stdio.h>
# include "math.h"
# include <string.h>

#include <stdlib.h>

#include <windows.h>

//#include "score.h"


typedef struct
{
	char id[10];
	char name[20];
	double fscore;  //ƽʱ�ɼ�
	double escore;  //ʵ��ɼ�
	double lscore;  //��ĩ�ɼ�
	double tscore;  //�ܳɼ�

}SS;





//����ѧ���ɼ���Ϣ


//���ļ��ж�ȡѧ����Ϣ
SS*Readfile(int *N)
{
	SS *stu;  //����SS���͵�ָ��stu
	FILE *fp = NULL;//����һ��ָ���ļ���ָ��
	int count;
	int index = 0;

	fp = fopen("data.txt", "r");  //��fopen��ֻ���ķ�ʽ���ļ�data������ָ��fpָ���ļ�


	if (fp = NULL)
	{
		printf("error");  //���ָ��fpָ��գ���ô�ļ���ʧ��
		getchar();
	}
	else
	{

		fscanf(fp, "%d", &count);  //�ļ��ɹ��򿪣���ָ��ָ��ĵ�һ��������ֵ������count
		*N = count;
	}

	printf("ѧ��������Ϊ��%d\n", count);
	getchar();

	stu = (SS*)malloc(count * sizeof(SS));//��̬����ռ�


										  //��ȡÿ��ͬѧ����Ϣ
	while ((!feof(fp)) && (index < count))
	{
		//�����ļ����ݵ��ڴ�
		fscanf(fp, "%s%s%lf%lf%lf", (stu[index].id, stu[index].name, stu[index].fscore, stu[index].escore, stu[index].lscore));
		//��������ڴ��ѧ����Ϣ
		printf("ѧ�ţ�%s    ������%s    ƽʱ�ɼ���%lf    ʵ��ɼ���%lf     ��ĩ�ɼ���%lf", stu[index].id, stu[index].name, stu[index].fscore, stu[index].escore, stu[index].lscore);
		index++;

	}


	fclose(fp);
	return stu;  //??
}


//����ѧ�����ܳɼ�
void Lscore(SS stu[], int N)
{
	int i = 0;
	//	float p = 0.2;
	//float q = 0.6;
	for (i = 0; i < N; i++)
	{
		stu[i].tscore = 0.2 *stu[i].fscore + 0.2*stu[i].escore + 0.6*stu[i].lscore;
		printf("ѧ�ţ�%s    ������%s    �ܳɼ���%4.2lf", stu[i].id, stu[i].name, stu[i].tscore);
	}

	printf("ѧ���ܳɼ��������\n\n");
}



int Sort(SS stu[], int N)
{
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i < N; i++)
		for (j = i + 1; j < N; j++)
		{
			if (stu[i].tscore < stu[j].tscore)
			{
				k = i;

				strcpy(stu[i].id, stu[j].id);
				strcpy(stu[i].name, stu[j].name);
				stu[i].fscore = stu[j].fscore;
				stu[i].escore = stu[j].escore;
				stu[i].lscore = stu[j].lscore;
				stu[i].tscore = stu[j].tscore;
				strcpy(stu[j].id, stu[k].id);
				strcpy(stu[j].name, stu[k].name);
				stu[j].fscore = stu[k].fscore;
				stu[j].escore = stu[k].escore;
				stu[j].lscore = stu[k].lscore;
				stu[j].tscore = stu[k].tscore;

			}
		}
	for (i = 0; i < N; i++)
	{
		printf("ѧ�ţ�%s    ������%s    ƽʱ�ɼ���%lf    ʵ��ɼ���%lf   ��ĩ�ɼ���%lf    �ܳɼ���%4.2lf  \n  ", stu[i].id, stu[i].name, stu[i].fscore, stu[i].escore, stu[i].lscore, stu[i].tscore);

	}
	return 0;
}


int main()
{
	int N = 0;
	SS *pstu = NULL;  //�ṹ�����飿��

	pstu = Readfile(&N);
	Lscore(pstu, N);
	Sort(pstu, N);


	free(pstu);

	system("pause");  //ͣ�ٳɼ�����

	return 0;

}