#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {
	int num = 0;    //사용자 입력
    int start = 0;
    int i;
    srand((unsigned)time(NULL));

    printf("|||PLAY GAME|||\n");
    printf("*1.UP&Down 숫자 맞추기 게임\n");
    printf("*2.베스킨라빈스31 게임\n");
    printf("*3.Close\n");
    printf("입력 : ");
    scanf("%d", &start);

    if ( start == 1){
        printf("\n\n***UP&Down 숫자 맞추기 게임***\n");
        printf("1. game start\n");
        printf("2. close\n");
        printf("입력 : ");
        int select = 0;
        scanf("%d",&select);
        if (select == 2) {
            return 0;
        }
        else if (select == 1) {
            printf("\n__________규칙 설명__________\n");
            printf("- 1~50의 사이의 숫자를 맞추세요.\n");
            printf("- 기회는 총 10회 입니다.\n");
			printf("- 수를 입력하세요. \n");
            printf("_________GAME START_________\n\n");

            //난수 설정
            int set = (rand() % 50+1);

            //10회 횟수 count 반복문
            for (i=1; i<=10; i++) {
                printf("[%d번째 기회]", i);
                printf(" : ");
                scanf("%d", &num);

                if (num < set)
                {
                    printf("***UP***\n\n");
                }
                else if(num > set)
                {
                    printf("***Down***\n\n");
                }
                else
                {
                    printf("\n\n***%d정답 %d번째 성공하셨습니다.***\n", set, i);
                    printf("--우승상품, 로또 번호--\n");
                    
                    //로또 번호 생성기
                    int i, r, j, random[7];
                    srand(time(NULL));
                    for(i=0;i<=6;i++) {
                        again:;
                        r=rand()%45+1;
                        for(j=0;j<=i-1;j++) {
                            if(r==random[j])
                                goto again;
                        }
                        random[i]=r;
                    }
                    for(i=0;i<=6;i++) {
                        printf("%d  ", random[i]);
                    }
                    printf("\n");
                    printf("\n프로그램 종료\n");
                    return 0;
                }
            }
            printf ("실패.\n");
            printf ("당신은 컴퓨터에게 졌습니다.\n");
        }
    }
    
    else if (start == 2) {
        int select = 0;
        printf("***베스킨라빈스31***\n");
        printf("1. game start\n");
        printf("2. close\n");
        printf(" : ");
        scanf("%d",&select);
        if (select == 2) {
            return 0;
        }
        else if (select == 1) {
            printf("\n\n\n");
            printf("\n__________규칙 설명__________\n");
            printf("- 1~31의 숫자를 사용자와 컴퓨터가 번갈아 1~3\n");
            printf("- 사이의 숫자를 부르고 더해서 31이 먼저 나오면 패.\n");
            printf("\n________GAME START________\n");
            
            //선 결정
            //컴퓨터 난수 설정
            int computer = 0;
            int user = 0;
            printf("선 정하기 [1~6 중 하나의 수를 입력하세요.]\n");
            printf("[user] : ");
            scanf("%d", &user);

            computer = (rand() % 6+1);
            printf("[computer] : %d\n\n", computer);
            
			while(1) {
				if (user == computer) {
					printf("중복되었습니다. [다시 입력하세요]\n");
					printf("[user] : ");
					scanf("%d", &user);

					computer = (rand() % 6+1);
					printf("[computer] : %d\n\n", computer);
				}
				//컴퓨터 선
				else if (user < computer) {
					printf("**컴퓨터가 선입니다.**\n\n");

					int i, c, cnt = 0;
					int n1, n2;
					while(1) {
						if(cnt >= 31)
							break;
						else {
							c = cnt;
							n2 = (rand() % 3 +1);
							printf("[computer] : %d\n", n2);
							for (i = c+1; i <= (n2+c); i++) {
								printf("%d ", i);
								cnt++;
							}
							printf("\n\n");
							if (cnt == 31) {
								printf("컴퓨터가 이겼습니다.");
								break;
							}

							printf("[user] : ");
							scanf("%d", &n1);

							c = cnt;
							for (i = c+1; i <= (n1+c); i++) {
								printf("%d ", i);
								cnt++;
							}
							printf("\n\n");

							if (cnt == 31) {
								printf("당신이 이겼습니다.");
								break;
							}


						}
					}
				}

				//사용자 선
				else {
					printf("**사용자가 선입니다.**\n\n");
					int i, c, cnt = 0;
					int n1, n2;
					while(1) {
						if(cnt >= 31)
							break;
						else {
							printf("[user] : ");
							scanf("%d", &n1);

							c = cnt;
							for (i = c+1; i <= (n1+c); i++) {
								printf("%d ", i);
								cnt++;
							}
							printf("\n\n");

							if (cnt == 31) {
								printf("당신이 이겼습니다.");
								break;
							}

							c = cnt;
							n2 = (rand() % 3 +1);
							printf("[computer] : %d\n", n2);
							for (i = c+1; i <= (n2+c); i++) {
								printf("%d ", i);
								cnt++;
							}
							printf("\n\n");
							if (cnt == 31) {
								printf("컴퓨터가 이겼습니다.");
								break;
							}
						}
					}
					break;
				}			
			}        
        }
    }
	return 0;
}