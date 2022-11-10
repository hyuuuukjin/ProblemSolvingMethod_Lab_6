#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int new_mem(struct customer* custo);  //�ű� ȸ�� ����, ����Ʈ ����
int ext_mem(struct customer* cus);  //���� ȸ��, ����Ʈ ����

//ȸ�� ���� �����ϴ� ����ü
struct customer
{
	char name[20];
	int num;
	float point;
	char address[20];
};

int main()
{
	typedef customer custo;
	custo cus[6];

	//�Է� ���� ȸ����ȣ
	int mem_num;

	//ȸ�� ���� ����
	int status = 0;

	//ȫ�浿 ȸ�� ����
	strcpy_s(cus[0].name, "ȫ�浿");
	cus[0].num = 1384;
	strcpy_s(cus[0].address, "���� ������");
	cus[0].point = 2500;

	//��ö�� ȸ�� ����
	strcpy_s(cus[1].name, "��ö��");
	cus[1].num = 9954;
	strcpy_s(cus[1].address, "���� ���ı�");
	cus[1].point = 2700;

	//�迵�� ȸ�� ����
	strcpy_s(cus[2].name, "�迵��");
	cus[2].num = 6549;
	strcpy_s(cus[3].address, "��� ������");
	cus[2].point = 1900;

	while (1)
	{
		//ȸ�� ���� ���� Ȯ��
		printf("\n�ű� ȸ���̸� 0, ���� ȸ���̸� 1�� �Է��ϼ���(������: 2): ");
		scanf_s("%d", &status);

		//�ű� ȸ�� ����, ���� ǥ��
		if (status == 0)
		{
			new_mem(&cus[3]);
			printf("--------------------------\n");
			printf("�̸�: %s�� \n", cus[3].name);
			printf("ȸ����ȣ: %d \n", cus[3].num);
			printf("�ּ�: %s \n", cus[3].address);
			printf("���� ����Ʈ: %.2f \n", cus[3].point);
			break;
		}
		//���� ȸ��, ȸ�� ���� ã��
		else if (status == 1)
		{
			printf("ȸ����ȣ�� �Է��ϼ���(��ȭ��ȣ �� 4�ڸ�): ");
			scanf_s("%d", &mem_num);

			//�Է� ���� ȸ�� ��ȣ�� ��ġ�ϴ� ȸ�� ���� ã��
				while (mem_num == cus[i].num)  //�Է� ���� ȸ�� ��ȣ == ��ϵ� ȸ�� ����
				{
					if (mem_num == cus[i].num)
					{
						ext_mem(&cus[i]);
						printf("--------------------------\n");
						printf("�̸�: %s�� \n", cus[i].name);
						printf("ȸ����ȣ: %d \n", cus[i].num);
						printf("�ּ�: %s \n", cus[i].address);
						printf("���� ����Ʈ: %.2f�� \n", cus[i].point);
						break;
					}
					else if (mem_num != cus[i].num)
					{
						printf("�߸��Է��ϼ̽��ϴ�.\n");
						break;
					}
				}
			break;
		}
		//����Ʈ ���� ���α׷� ����
		else if (status == 2)
		{
			printf("\n���� �Ϸ� ��������.\n");
			break;
		}
		//���Է½� ���� ��� �� ���α׷� ����
		else
		{
			printf("\n�߸��� �Է��Դϴ�.\n");
			break;
		}

	}
}

//�ű� ȸ�� ����, ����Ʈ ����
int new_mem(struct customer* cus)
{
	int price = 0;

	rewind(stdin);
	printf("\n�̸��� �Է��ϼ���: ");
	gets_s(cus->name);
	printf("\n��ȭ��ȣ �� 4�ڸ��� �Է��ϼ���(ȸ����ȣ): ");
	scanf_s("%d", &cus->num);
	rewind(stdin);
	printf("\n�ּҸ� �Է��ϼ���: ");
	gets_s(cus->address);
	printf("\n������ �ݾ��� �Է��ϼ���: ");
	scanf_s("%d", &price);
	cus->point = price * 0.02;  //���� �ݾ��� 2% ����
	printf("\n%.2f�� �����Ǿ����ϴ�.\n", cus->point);

	return 0;
}

//���� ȸ��, ����Ʈ ����
int ext_mem(struct customer* cus)
{
	int price;

	printf("\n������ �ݾ��� �Է��ϼ���: ");
	scanf_s("%d", &price);
	cus->point = cus->point + (price * 0.02); //���� �ݾ��� 2% ����
	printf("\n%.2f�� �����Ǿ����ϴ�.\n", price * 0.02);

	return 0;
}