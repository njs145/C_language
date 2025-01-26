#include "Iteration.h"

#define WHILE       0
#define FOR         1
#define TEST4_TYPE   FOR

#define BREAK       0
#define CONTINUE    1
#define TEST8_TYPE   CONTINUE


static void Conditional_Iterative_While_Infinite_Loops(void);
static void while_test1(void);
static void Counting_based_Iteration_for(void);
static void while_test2(void);
static void Nesting_Loops(void);
static void while_test3(void);
static void while_test4(void);
static void The_do_while_Statement(void);
static void Break_and_continue(void);

void Iteration_main(void)
{
    // Conditional_Iterative_While_Infinite_Loops();
    // while_test1();
    // Counting_based_Iteration_for();
    // while_test2();
    // Nesting_Loops();
    // while_test3();
    // while_test4();
    // The_do_while_Statement();
    Break_and_continue();
}

/* 
desc: 섹션 13장 조건 기반 반복 while과 무한 루프
*/
static void Conditional_Iterative_While_Infinite_Loops(void)
{
    /*
        - if문과 유사한 구조
        - 조건식이 참일 경우 구간 코드를 계속 반복해서 수행
        - 반복 수행 구간코드 내부에서 반복을 풀수있는 논리가 반드시 있어야 한다.
    */
}

/* 
desc: 섹션 13장 [필수 실습 문제] 한 줄에 '*' 출력
*/
static void while_test1(void)
{
    __uint32_t num;
    __uint32_t i = 1;

    scanf("%d",&num);
    if(num > 9)
    {
        num = 9;
    }

    while((i <= num))
    {
        printf("* ");
        if(i == num)
        {
            printf("\n");
        }
        i ++;
    }
}

/* 
desc: 섹션 13장 계수 기반 반복 for
*/
static void Counting_based_Iteration_for(void)
{
    /*
        - 계수 기반 반복문
        - 반복 회수 조절에 관련된 코드를 한 행에서 볼 수 있어 while문에 비해 상대적으로 실수 가능성이 적음.
    */
}

/* 
desc: 섹션 13장 [필수 실습 문제] 총합 계산하기
*/
static void while_test2(void)
{
    __uint32_t sum = 0;
    __uint32_t i;

#if TEST_TYPE
    for(i = 1; i <= 10; i ++)
    {
        sum += i;
    }

#else
    i = 1;
    while(i <= 10)
    {
        sum += i;
        i ++;
    }
#endif

    printf("Total: %d\n", sum);
}

/* 
desc: 섹션 13장 반복문 중첩
*/
static void Nesting_Loops(void)
{
    /*
        - 1차원적 반복 출력 코드를 다시 반복문으로 묶어 2차원적 구조를 출력
        - 반복에 대한 반복이 발생해 논리적으로 한 층 더 복잡
    */
}

/* 
desc: 섹션 13장 [필수 실습 문제] 국룰 * 출력 놀이
*/
static void while_test3(void)
{
    __uint32_t i, j;

    for(i = 0; i < 5; i ++)
    {
        for(j = 0; j < 5; j ++)
        {
            printf("* ");
        }
        printf("\n");
    }
}

/* 
desc: 섹션 13장 [필수 실습 문제] '*' 출력 놀이 응용
*/
static void while_test4(void)
{
    __int32_t i, j, q;

    for(i = 0; i < 5; i ++)
    {
        for(j = 1; j < 6 + i; j ++)
        {
            if((5 - i) <= j)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }            
        }
        printf("\n");
    }
}

/* 
desc: 섹션 13장 do while문
*/
static void The_do_while_Statement(void)
{
    /*
        - 반복 대상 구간코드가 조건식의 만족여부와 관련없이 무조건 한번은 실행하는 반복문.
        - 기존 while문과 달리 조건식 뒤에 세미콜론이 있음.


    */
}

/* 
desc: 섹션 13장 break와 continue
*/
static void Break_and_continue(void)
{
    /*
        break
        - 반복문과 switch-case 문에서 사용되며 수행 시 스코프를 즉시 벗어나 그 다음 구문으로 이동
        - 반복문 내부에서 break 수행 시 조건과 상관없이 반복문 종료

        continue
        - break문과 달리 반복을 멈추지 않으며 반복문 내부에서 continueaㅜㄴ 이후 코드를 수행하지 않고 그냥 넘어가 반복 시작 조건식 비교
        - 반복은 계속되며 논리적으로 복잡해지는 원인이 있음.
    */  


    #if TEST8_TYPE
    while(1)
    {
        char ch;
        while(1)
        {
            printf("단어를 입력하세요[q를 누르면 처음으로 돌아갑니다.]: ");
            scanf("%s", &ch);

            if(ch == 'q')
            {
                printf("\n");
                continue;
            }
            printf("입력한 문자는 %c입니다.\n",ch);
        }
    }

    #else
    char ch;
    while(1)
    {
        printf("단어를 입력하세요[x를 누르면 종료합니다.]: ");
        scanf("%s", &ch);

        if(ch == 'x')
        {
            printf("x를 누르셔서 종료하겠습니다.");
            printf("\n");
            break;
        }
        printf("입력한 문자는 %s입니다.\n",ch);
    }
    #endif
}