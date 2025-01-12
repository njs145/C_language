#include "Standard_IO.h"

static void stdio_example(void);
static void format_escape_string_example(void);
static void actual_number_example(void);
static void scanf_example(void);
static void string_example(void);
static void Standard_IO_test(void);

/* 
desc: 독하게 시작하는 C 프로그래밍 섹션 10장 실행 함수.
*/
void Standard_IO_main(void)
{
    // stdio_example();
    // format_escape_string_example();
    // string_example();
    Standard_IO_test();

}

/* 
desc: 섹션 10장 문자열 입/출력 코드.
*/
static void stdio_example(void)
{
    char szName[256] = { 0 };

    printf("이름을 입력하시오\n");
    scanf("%s", szName);

    printf("당신의 이름은 %s입니다.\n",szName);
}

/* 
desc: 섹션 10장 형식 문자와 이스케이프 시퀀스.
*/
static void format_escape_string_example(void)
{
    int x = 10;

    printf("정수 값을 입력하세요\n");
    scanf("%d", &x);

    printf("입력한 값은 %d입니다.\n",x);
}

/* 
desc: 섹션 10장 실수 출력.
*/
static void actual_number_example(void)
{
     /* NULL */
}

/* 
desc: 섹션 10장 문자, 정수 입력과 개행문자 제거.
*/
static void scanf_example(void)
{
    /* scnaf의 유래: 예전에 키보드에서 입력을 스캔한다고 지칭. stdio는 키보드 이므로 scanf 라고 지칭. */

}

/* 
desc: 섹션 10장 문자, 정수 입력과 개행문자 제거.
*/
static void string_example(void)
{
    char ch = 0;
    __uint32_t x, y;

    printf("문자를 입력하세요 \n");

    /* %*c: 뒤에 \n 문자를 없애기 위한 용도 */
    scanf("%c%*c", &ch);
    printf("입력한 문자는 %c 입니다.\n", ch);

    char szBuffer[4] = { 0 };
    scanf("%s%*c", szBuffer);
    printf("입력한 문자는 %c%c%c%c 입니다.\n",szBuffer[0], szBuffer[1], szBuffer[2], szBuffer[3]);

    printf("정수 2개를 입력하세요.\n");
    scanf("%d%d", &x, &y);
    printf("두 정수의 합은 %d입니다.\n", (x + y));
}

/* 
desc: 섹션 10장 필수 실습 문제.
*/
static void Standard_IO_test(void)
{
    int age;
    char name[10] = { 0 };

    printf("나이를 입력하세요: ");
    scanf("%d", &age);
    
    printf("이름을 입력하세요: ");
    scanf("%s", name);

    printf("당신의 나이는 %d살이고 이름은 '%s' 입니다.", age, name);
    
}