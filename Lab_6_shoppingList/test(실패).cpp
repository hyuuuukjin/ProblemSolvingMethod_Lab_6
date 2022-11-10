#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int new_mem(struct customer* custo);  //신규 회원 가입, 포인트 적립
int ext_mem(struct customer* cus);  //기존 회원, 포인트 적립

//회원 정보 저장하는 구조체
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

	//입력 받을 회원번호
	int mem_num;

	//회원 가입 상태
	int status = 0;

	//홍길동 회원 정보
	strcpy_s(cus[0].name, "홍길동");
	cus[0].num = 1384;
	strcpy_s(cus[0].address, "서울 강남구");
	cus[0].point = 2500;

	//김철수 회원 정보
	strcpy_s(cus[1].name, "김철수");
	cus[1].num = 9954;
	strcpy_s(cus[1].address, "서울 송파구");
	cus[1].point = 2700;

	//김영희 회원 정보
	strcpy_s(cus[2].name, "김영희");
	cus[2].num = 6549;
	strcpy_s(cus[3].address, "경기 성남시");
	cus[2].point = 1900;

	while (1)
	{
		//회원 가입 여부 확인
		printf("\n신규 회원이면 0, 기존 회원이면 1을 입력하세요(나가기: 2): ");
		scanf_s("%d", &status);

		//신규 회원 가입, 정보 표시
		if (status == 0)
		{
			new_mem(&cus[3]);
			printf("--------------------------\n");
			printf("이름: %s님 \n", cus[3].name);
			printf("회원번호: %d \n", cus[3].num);
			printf("주소: %s \n", cus[3].address);
			printf("보유 포인트: %.2f \n", cus[3].point);
			break;
		}
		//기존 회원, 회원 정보 찾기
		else if (status == 1)
		{
			printf("회원번호를 입력하세요(전화번호 끝 4자리): ");
			scanf_s("%d", &mem_num);

			//입력 받은 회원 번호와 일치하는 회원 정보 찾기
				while (mem_num == cus[i].num)  //입력 받은 회원 번호 == 등록된 회원 정보
				{
					if (mem_num == cus[i].num)
					{
						ext_mem(&cus[i]);
						printf("--------------------------\n");
						printf("이름: %s님 \n", cus[i].name);
						printf("회원번호: %d \n", cus[i].num);
						printf("주소: %s \n", cus[i].address);
						printf("보유 포인트: %.2f점 \n", cus[i].point);
						break;
					}
					else if (mem_num != cus[i].num)
					{
						printf("잘못입력하셨습니다.\n");
						break;
					}
				}
			break;
		}
		//포인트 적립 프로그램 종료
		else if (status == 2)
		{
			printf("\n좋은 하루 보내세요.\n");
			break;
		}
		//오입력시 문구 출력 후 프로그램 종료
		else
		{
			printf("\n잘못된 입력입니다.\n");
			break;
		}

	}
}

//신규 회원 가입, 포인트 적립
int new_mem(struct customer* cus)
{
	int price = 0;

	rewind(stdin);
	printf("\n이름을 입력하세요: ");
	gets_s(cus->name);
	printf("\n전화번호 끝 4자리를 입력하세요(회원번호): ");
	scanf_s("%d", &cus->num);
	rewind(stdin);
	printf("\n주소를 입력하세요: ");
	gets_s(cus->address);
	printf("\n결제한 금액을 입력하세요: ");
	scanf_s("%d", &price);
	cus->point = price * 0.02;  //결제 금액의 2% 적립
	printf("\n%.2f점 적립되었습니다.\n", cus->point);

	return 0;
}

//기존 회원, 포인트 적립
int ext_mem(struct customer* cus)
{
	int price;

	printf("\n결제한 금액을 입력하세요: ");
	scanf_s("%d", &price);
	cus->point = cus->point + (price * 0.02); //결제 금액의 2% 적립
	printf("\n%.2f점 적립되었습니다.\n", price * 0.02);

	return 0;
}