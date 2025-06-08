//20252242 컴퓨터공학과 지헤미
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define ROOM_WIDTH 5
#define HME_POS 1
#define BWL_PO (ROOM_WIDTH -2)
#define ROOM_HEIGHT 4

int main(void) {
	int stew = 0; //<-수프 숫자
	int cp = 0;//<-코인. 코인도박하지말아요~
	int kitty_s_feeling = 3;//-<고영희 기분이랍니다.
	int beforeFeeling;//<-기분 전의 상태 표시	
	int closeness = 2; //<-친밀도
	int kitty = 2; //<-고양이 위치
	int before = 2; //<-고양이 전 위치
	int scratcher = 0;//idk 스크래쳐 임시위치
	int catTower = 0;//idk 캣 타워 임시위치
	srand((unsigned int)time(NULL));

	//인트로
	printf("****야옹이와수프****\n");
	printf("@@@@/\\/\\@@@@@\n@@@(0-0)@@@@@\n@@@(|||  )@@@\n@@@@@@@@@@@@@\n");
	printf("야옹이 띨뻥이는 자신을 위해 식빵을 굽고 있습니다.\n");
	Sleep(2500);
	system("cls");

	//화면전환
	while (1) {
		printf("====================현재상태====================\n");
		printf("현재까지 만든 수프: %d개\n", stew);
		printf("CP: %d 포인트\n", cp);
		printf("띨뻥이 기분(0~3): %d\n", kitty_s_feeling);
		switch (kitty_s_feeling) {// 기분 표시
		case 0: printf("기분이 매우 나쁩니다.\n");
			break;
		case 1: printf("심심해집니다.\n");
			break;
		case 2: printf("식빵을 굽습니다.\n");
			break;
		case 3: printf("골골송을 부릅니다.\n");
			break;
		}
		printf("집사와의관계(0~4): %d\n", closeness);
		switch (closeness) {//집사와의 관계
		case 0: printf("곁에 오는 것조차 싫어합니다.\n");
			break;
		case 1: printf("간식 자판기 취급입니다.\n");
			break;
		case 2: printf("그럭저럭 쓸만한 집사입니다.\n");
			break;
		case 3: printf("훌룡한 집사로 인정 받고 있습니다.\n");
			break;
		case 4: printf("집사 껌딱지입니다.\n");
		}
		printf("================================================\n");
		printf("\n");

		Sleep(1000);

		before = kitty;//고양이 전 위치
		beforeFeeling = kitty_s_feeling;//CP변화 전
		

		//고양이 기분
		int r = rand() % 6 + 1;
		int standard = 6 - closeness;
		printf("6-%d: 주사위 눈이 %d이하이면 그냥 기분이 나빠집니다.\n", closeness, standard);
		printf("주사위를 굴립니다. 또르르...\n");
		printf("%d이(가) 나왔습니다.\n", r);
		if (standard >= r) {
			if (kitty_s_feeling >= 0 && kitty_s_feeling <= 3) {
				kitty_s_feeling -= 1;
			}
			printf("띨뻥이의 기분이 나빠집니다: %d->%d\n", kitty_s_feeling, beforeFeeling);
		}


		//고양이 이동
		switch (kitty_s_feeling) {
		case 0: printf("기분이 매우 나쁜 띨뻥이는 집으로 향합니다.\n");
			if (kitty == 2) {
				kitty;
				kitty_s_feeling += 1;
				printf("집에 있어 기분이 나아집니다. %d->%d\n", beforeFeeling, kitty_s_feeling);
			}
			else {
				kitty -= 1;
			}break;
		case 1: //if 사용해 더 가까운 놀이기구 (스크래쳐 OR 캣 타워) 쪽으로 이동
			printf("띨뻥이는 심심해서");
			if (scratcher - kitty > catTower - kitty) {
				printf("스크래쳐 쪽으로 이동합니다.\n");
				if (kitty == scratcher) {
					if (kitty_s_feeling >= 0 && kitty_s_feeling <= 3) {
						kitty_s_feeling += 1;
					}
					printf("띨뻥이는 스크래쳐를 긁고놀았습니다.\n");
					printf("기분이 조금 좋아졌습니다. %d->%d", beforeFeeling, kitty_s_feeling);
				}
				else {
					if (kitty_s_feeling >= 0 && kitty_s_feeling <= 3) {
						kitty_s_feeling -= 1;
					}
					printf("놀 거리가 없어서 기분이 매우 나빠집니다. %d->%d\n", beforeFeeling, kitty_s_feeling);
				}
			}
			else {
				printf("캣 타워 쪽으로 이동합니다.\n");
				if (kitty == catTower) {
					if (kitty_s_feeling >= 0 && kitty_s_feeling <= 3) {
						kitty_s_feeling += 2;
						if (kitty_s_feeling >= 3) {
							kitty_s_feeling == 3;
						}
					}
					printf("띨뻥이는 캣타워를 뛰어다닙니다.\n");
					printf("기분이 조금 좋아졌습니다. %d->%d", beforeFeeling, kitty_s_feeling);
				}
				else {
					if (kitty_s_feeling >= 0 && kitty_s_feeling <= 3) {
						kitty_s_feeling -= 1;
					}
					printf("놀 거리가 없어서 기분이 매우 나빠집니다. %d->%d\n", beforeFeeling, kitty_s_feeling);
				}
			}
			break;
		case 2:printf("띨뻥이는 기분좋게 식빵을 굽고 있습니다.\n");
			break;
		case 3: printf("띨뻥이는 골골송을 부르며 수프를 만들러 갑니다.\n");
			if (kitty == ROOM_WIDTH - 1) {
				kitty;
			}
			else {
				kitty += 1;
			}
			break;
		}
		//수프 만들기
		if (kitty == ROOM_WIDTH - 1) {
			int soup = rand() % 3;
			switch (soup) {
			case 0: printf("띨뻥이가 감자 수프를 만들었습니다!\n");
				break;
			case 1: printf("띨뻥이가 감자 수프를 만들었습니다!\n");
				break;
			case 2: printf("띨뻥이가 감자 수프를 만들었습니다!\n");
				break;
			}
			stew += 1;
		}
		printf("현재까지 만든 수프: %d\n", stew);
		printf("\n");

		Sleep(1000);

		//이동
		for (int i = 1; i <= ROOM_HEIGHT; i++) {
			for (int j = 1; j <= ROOM_WIDTH; j++) {
				if (i == 1 || i == ROOM_HEIGHT) {
					printf("#");
				}
				else if (j == 1 || j == ROOM_WIDTH) {
					printf("#");
				}
				else if (j == 2 && i == 2) {
					printf("H");
				}
				else if (j == catTower && i == 2) {
					printf("T");
				}
				else if (j == scratcher && i == 2) {
					printf("S");
				}
				else if (j == ROOM_WIDTH - 1 && i == 2) {
					printf("B");
				}
				else if (j == kitty && i == 3) {
					printf("C");
				}
				else if (j == before && i == 3 && before != kitty) {
					printf(".");
				}
				else {
					printf(" ");
				}
			}
			printf("\n");
		}
		printf("\n");

		Sleep(1000);

		//상호작용
		int x = 0;
		printf("어떤 상호작용을 하시겠습니까?\n");
		//배열이용(?)
		printf("아무것도 하지 않음\n");
		printf("긁어주기\n");
		printf("장난감 쥐로 놀아주기\n");
		printf("레이져 포인터로 놀아 주기\n");
		do {
			printf(">>");
 			scanf_s("%d", &x);
 		} while (x != 1 && x != 0);

		int rr = rand() % 6 + 1;

		switch (x) {
		case 0:
			if (kitty_s_feeling > 0) {
				kitty_s_feeling -= 1;
			}
			printf("띨뻥이의 기분이 나빠집니다: %d->%d\n", beforeFeeling, kitty_s_feeling);

			printf("아무것도 하지 않습니다.\n4/6의 확률로 친밀도가 떨어집니다.\n주사위를 굴립니다. 또르륵...\n");
			printf("%d이(가) 나왔습니다!\n", rr);
			if (rr <= 5) {//친밀도
				printf("집사와의 관계가 나빠집니다.\n");
				if (closeness <= 0) {
					closeness = 0;
				}
				else {
					closeness -= 1;
				}
				printf("현재 친밀도: %d\n", closeness);
			}
			else {
				printf("친밀도가 그대로입니다.\n");
				printf("현재 친밀도: %d\n", closeness);
			}
			break;
		case 1:
			printf("띨뻥이의 기분은 그대로입니다: %d", kitty_s_feeling);
			printf("띨뻥이의 턱을 긁어주었습니다.\n2/6의 확률로 친밀도가 높아집니다.\n주사위를 굴립니다. 또르륵...\n");
			printf("%d이(가) 나왔습니다!\n", rr);
			if (rr >= 5) {
				printf("친밀도가 높아집니다.\n");
				if (closeness >= 4) {
					closeness = 4;
				}
				else { closeness += 1; }
				printf("현재 친밀도: %d\n", closeness);
			}
			else {
				printf("친밀도는 그대로입니다.\n");
				printf("현재 친밀도: %d\n", closeness);
			}
			break;
		case 2:
			if (kitty_s_feeling < 3) {
				kitty_s_feeling += 1;
			}
			printf("장남감 쥐로 띨뻥이와 놀아 주었습니다.\n");
			printf("띨뻥이의 기분이 조금 좋아졌습니다: %d->%d\n",beforeFeeling, kitty_s_feeling);
			break;
		case 3:
			if (kitty_s_feeling >= 0 && kitty_s_feeling < 3) {
				kitty_s_feeling += 2;
				if (kitty_s_feeling >= 3) {
					kitty_s_feeling = 3;
				}
			}
			printf("레이져 포인터로 띨뻥이와 놀아 주었습니다.\n");
			printf("띨뻥이의 기분이 꽤 좋아졌습니다: %d->%d\n", beforeFeeling, kitty_s_feeling);
			break;
		}
		printf("\n");

		Sleep(2000);
		system("cls");

		//재화 생산
		int max = (kitty_s_feeling - 1) + closeness;
		max = cp;
		printf("띨뻥이의 기분(0~3): %d\n", kitty_s_feeling);
		printf("집사와의 친밀도(0~4): %d\n", closeness);
		printf("띨뻥이의 기분과 찬밀도에 따라서 CP가 %d 포인트 생산되었습니다.\n", max);
		printf("보유 CP: %d 포인트\n", max);

		Sleep(2000);
		system("cls");

		//상점구매
		int shopping = 0;
		printf("상점에서 물건을 살 수 있습니다.\n");
		printf("어떤 물건을 구매할까요?\n");
		printf("0. 아무 것도 사지 않는다.\n");
		printf("1. 장난감 쥐: 1CP");
		if (ratToy > 0) {
			printf("(품절)");
		}
		printf("\n");
		printf("2. 레이져 포인터: 2CP");
		if (lazer > 0) {
			printf("(품절)");
		}
		printf("\n");
		printf("3. 스크래처: 4CP");
		if (scratcher > 0) {
			printf("(품절)");
		}
		printf("\n");
		printf("4. 캣 타워: 6CP");
		if (catTower > 0) {
			printf("(품절)");
		}
		printf("\n");
		 do{
			printf(">>");
			scanf_s("%d", &shopping);
		 } while (shopping <= 0 && shopping >= 4);


		 switch (shopping){
		 case 0:
			 kitty_s_feeling = 0;
			 printf("정말 아무것도 안사시는군요.\n");
			 printf("집사 자격 박탈입니다.\n");
			 printf("띨뻥이의 기분이 0으로 됩니다. =(ㅡ^ㅡ)=\n");
			 break;
		 case 1:
			 if (cp >= 1) {
				 cp -= 1;
				 ratToy = 1;
				 printf("장난감 쥐를 구매했습니다.\n");
				 printf("보유 CP %d 포인트\n", cp);
			 }
			 else if (cp < 1) {
				 printf("CP가 부족합니다.");
			 }
			 else if (ratToy = 1) {
				 printf("장난감 쥐를 이미 구매했습니다.\n");
			 }
			 break;
		 case 2:
			 if (cp >= 2) {
				 cp -= 2;
				 lazer = 1;
				 printf("레이져 포인터를 구매했습니다.\n");
				 printf("보유 CP %d 포인트\n", cp);
			 }
			 else if (cp < 2) {
				 printf("CP가 부족합니다.");

			 }
			 else if (lazer = 1) {
				 printf("레이져 포인터를 이미 구매했습니다.\n");
			 }
			 break;
		 case 3:
			 if (cp >= 4) {
				 cp -= 4;
				 scratcher += 1;
				 printf("스크래쳐를 구매했습니다.\n");
				 printf("보유 CP %d 포인트\n", cp);
			 }
			 else if (cp < 4) {
				 printf("CP가 부족합니다.\n");
			 }
			 else if (scratcher > 0) {
				 printf("스크래쳐를 이미 구매했습니다.\n");
			 }
			 break;
		 case 4:
			 if (cp >= 6) {
				 cp -= 6;
				 catTower += 1;
				 printf("캣 타워를 구매했습니다.\n");
				 printf("보유 CP %d 포인트\n", cp);
			 }
			 else if (cp < 6) {
				 printf("CP가 부족합니다.\n");
			 }
			 else if (catTower > 0) {
				 printf("캣 타워를 이미 구매했습니다.\n");
			 }
			 break;
			 
		 }
		 turnCount++;
		Sleep(2000);
		system("cls");

		//돌발 퀘스트
		if (kitty_s_feeling == 0) {
			printf("띨뻥이가 기분이 매우 나쁩니다!\n");
			printf("앞발바닥으로 집사를 공격합니다.\n");
		}
		else if (kitty_s_feeling == 1 || kitty_s_feeling == 2) {
			printf("띨뻥이는 심심해 집사에게 재롱을 부려보라 합니다.\n");
			printf("무엇을 하시겠습니까?\n");
			printf("0. \n");
		}
		else if (kitty_s_feeling == 3) {
			printf("\n");
		}
		Sleep(2000);
		system("cls");

	}
	return 0;
}