typedef struct point {

	int xpos;
	int ypos;
}Point;


int Distance() {
	int i = 0;

	Point pos[10];

	int xdis = 0;
	int ydis = 0;


	printf("10개의 좌표를 입력하세요\n");

	for (i = 0; i < 3; i++) {
		scanf("%d %d", &pos[i].xpos, &pos[i].ypos);
	}

	for (i = 0; i < 3; i++) {
		if (pos[i].xpos < pos[i + 1].xpos) {
			if (xdis < pos[i + 1].xpos)
				xdis = pos[i + 1].xpos;
		}
		else
			if (xdis < pos[i].xpos) {
				xdis = pos[i].xpos;
			}
	}
	for (i = 0; i < 3; i++) {
		if (pos[i].ypos < pos[i + 1].ypos) {
			if (ydis < pos[i + 1].ypos)
				ydis = pos[i + 1].ypos;
		}
		else
			if (ydis < pos[i].ypos) {
				ydis = pos[i].ypos;
			}
	}


	int xsmall = pos[0].xpos;
	int ysmall = pos[0].ypos;

	for (i = 0; i < 3; i++) {
		if (xsmall > pos[i].xpos)
			xsmall = pos[i].xpos;
	}
	for (i = 0; i < 3; i++) {
		if (ysmall > pos[i].ypos)
			ysmall = pos[i].ypos;
	}

	printf("가장 먼 점은:%d %d\n", xdis, ydis);
	printf("가장 가까운 점은: %d %d\n", xsmall, ysmall);
	printf("두 점 사이의 거리는: %lf\n\n\n", sqrt((xdis - xsmall) * (xdis - xsmall) + (ydis - ysmall) * (ydis - ysmall)));

	return 0;
}

int Prime() {


	int inte;
	int inte2;
	int  i, j;
	printf("정수 m과 n을 입력해주세요\n");
	scanf("%d %d", &inte, &inte2);


	for (i = inte; i <= inte2; i++)
	{
		for (j = 2; j < i; j++)
			if (i % j == 0)
				break;
		if (i == j)
			printf("%d ", i);
	}
	puts("\n\n");

}

int Birth() {

	int i = 0;
	int j = 0;
	char birth1[9] = "20000101";
	char late[9] = { 0 ,};

	late[9] = birth1;

	printf("%s", late);/*
	for (i = 0; i < 10; i++) {


		if (!strcmp(late, birth1[i])) {
			continue;
		}
		else if (strcmp(late, birth1[i])) {
			continue;
		}
		else
			late[0] = birth1[i];
	}
	printf("%s\n", late[0]);*/
	return 0;
}


int str_Birth() {

	typedef struct birthday {
		int year[4];
		int month[2];
		int date[2];

	}BIRTHDAY;

	BIRTHDAY birth[3] = { 0, };
	int i = 0;
	int yearlate[] = { 0, };
	int monthlate = 0;
	int datelate = 0;

	for (i = 0; i < 2; i++) {
		printf("4자리 태어난 연도 입력");
		scanf("%d", &birth[i].year);
		printf("4자리 태어난 달 입력");
		scanf("%d", &birth[i].month);
		printf("4자리 태어난 날짜 입력");
		scanf("%d", &birth[i].date);
	}

	for (i = 0; i < 3; i++) {

		if (yearlate <= birth[i].year) {
			yearlate[0] = birth[i].year;
			printf("%d  %d", yearlate[0], birth[i].year);
			if (monthlate <= birth[i].month) {
				monthlate = birth[i].month;

				if (datelate <= birth[i].date) {
					datelate = birth[i].date;
				}
			}

		}
	}

	printf("가장 늦은 생년월일은: %d\n\n", yearlate[0]);

}


int BirthArray() {

	char birth[2][5];
	int i, j = 0;
	char late = 0;
	printf("생년월일을 입력하세요");



	for (i = 0; i < 2; i++) {
		for (j = 0; j < 4; j++) {
			scanf("%s", &birth[i][j]);
		}
	}

	for (i = 0; i < 2; i++) {
		for (j = 0; j < 4; j++) {
			if ((strcmp(birth[i][j], birth[i][j + 1])) == 1)
				late = birth[i][j];
			else if ((strcmp(birth[i][j], birth[i][j + 1])) == -1)
				late = birth[i][j + 1];
			else
				late = birth[i][j];

		}

	}





	for (i = 0; i < 2; i++) {
		for (j = 0; j < 4; j++) {
			birth[i][j] = atoi(birth[i][j]);
		}
	}
	printf("가장 느린 생일은 %s", late);
	return 0;
}








int main() {
	int num1;

start:

	printf("1은 좌표\n2는 6자리 생년월일 배열에 저장\n\
3은 2차원 배열에 저장\n4는 구조체에 저장\n5는 m부터 n사이의 소수 찾기\n\
다른 키는 중지하기\n\n숫자를 입력하세요:");

	scanf("%d", &num1);

	switch (num1)
	{
	case 1:
		Distance();
		goto start;
	case 2:
		Birth();
		goto start;
	case 3:
		//Birtharray();
		goto start;
	case 4:
		str_Birth();
		goto start;
	case 5:
		Prime();
		goto start;
	default:
		break;
	}


}