#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {
	int num = 0;    //user input
    int start = 0;
    int i;
    srand((unsigned)time(NULL));

    printf("|||PLAY GAME|||\n");
    printf("*1.UP&Down Game\n");
    printf("*2.Baskin Robbins 31 Game\n");
    printf("*3.Close\n");
    printf("input : ");
    scanf("%d", &start);

    if ( start == 1){
        printf("\n\n***UP&Down Game***\n");
        printf("1. game start\n");
        printf("2. close\n");
        printf("input : ");
        int select = 0;
        scanf("%d",&select);
        if (select == 2) {
            return 0;
        }
        else if (select == 1) {
            printf("\n__________Rule Description__________\n");
            printf("- Guess a number from 1 to 100.\n");
            printf("- There are a total of 10 chances..\n");
			printf("- Please enter a number. \n");
            printf("_________GAME START_________\n\n");

            /* random number setting */
            int set = (rand() % 100+1);

            /* 10 times count loop */
            for (i=1; i<=10; i++) {
                printf("[%dst chance]", i);
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

                /* num inpu == true*/
                else
                {
                    printf("\n\n***%danswer %dst successful.***\n", set, i);
                    printf("--Winning prize, lottery number--\n");
                    
                    /* lotto number generator */
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
                    printf("\nEnd the program\n");
                    
                }
                continue;
            }
            printf ("failure.\n");
            printf ("You lost to the computer.\n");
            return 0;
        }
    }
    
    else if (start == 2) {
        int select = 0;
        printf("***Baskin Robbins 31 Game***\n");
        printf("1. game start\n");
        printf("2. close\n");
        printf(" : ");
        scanf("%d",&select);
        if (select == 2) {
            return 0;
        }
        else if (select == 1) {
            printf("\n\n");
            printf("\n__________Rule Description__________\n");
            printf("- The number between 1 and 31 is called\nby the user and the computer alternately,\n and the number between 1 and 3 \nis added and the number 31 comes out first.\n");
            printf("\n________GAME START________\n");
            
            int computer = 0;
            int user = 0;
            printf("make a choice. [Rock Paper Scissors]\n");
            printf("1. Scissors\n");
            printf("2. Rock\n");
            printf("3. Paper\n");


            /* start first set */
            printf("[user] : ");
            scanf("%d", &user);
            computer = (rand() % 3+1);
            printf("[computer] : %d\n\n", computer);
            
			while(1) {
                /* computer == user */
				if (user == computer) {
					printf("duplicated. [Please enter again]\n");
					printf("[user] : ");
					scanf("%d", &user);

					computer = (rand() % 3+1);
					printf("[computer] : %d\n\n", computer);
				}
				
                /* computer > user */
				else if (user < computer) {
					printf("**computer first.**\n\n");

					int i, c, cnt = 0; //i -> for loop, c -> num count, cnt -> num total count
					int n1, n2; //n1 -> user input, n2 -> computer input
					while(1) {					
                        c = cnt;
                        n2 = (rand() % 3 +1);   //computer random num input
                        printf("[computer] : %d\n", n2);
                        
                        /* num count print */
                        printf("=> ");
                        for (i = c+1; i <= (n2+c); i++) {
                            printf("%d ", i);
                            cnt++;
                        }
                        printf("\n\n");

                        if (cnt >= 31) {
                            printf("you win.");
                            return 0;
                        }
                        else {
                            printf("[user] : ");
                            scanf("%d", &n1);
                            c = cnt;
                            printf("=> ");
                            for (i = c+1; i <= (n1+c); i++) {
                                printf("%d ", i);
                                cnt++;
                            }
                            printf("\n\n");

                            if (cnt >= 31) {
                                printf("computer win.");
                                return 0;
                            }
                        }
					}
				}

				//user first code
				else {
					printf("**user first.**\n\n");
					int i, c, cnt = 0;
					int n1, n2;
					while(1) {

                        printf("[user] : ");
                        scanf("%d", &n1);

                        c = cnt;
                        for (i = c+1; i <= (n1+c); i++) {
                            printf("%d ", i);
                            cnt++;
                        }
                        printf("\n\n");

                        if (cnt >= 31) {
                            printf("computer win.");
                            break;
                        }
                        else
                        {
                            c = cnt;
                            n2 = (rand() % 3 +1);
                            printf("[computer] : %d\n", n2);
                            for (i = c+1; i <= (n2+c); i++) {
                                printf("%d ", i);
                                cnt++;
                            }
                            printf("\n\n");
                            if (cnt >= 31) {
                                printf("you win.");
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
