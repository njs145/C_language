#include "branching_statement.h"
#include "../common/UI.h"

#define BUS_CHARGE  1000

static void If_Statements_Scopes(void);
static void branching_statement_test1(void);
static void branching_statement_test2(void);
static void If_Else_Statements(void);
static void Nesting_if_else_statements(void);
static void branching_statement_test3(void);
static void Multiple_if_Statements(void);
static void Nested_Scopes_Identifier_Search_Order(void);
static void Switch_Case_Statements(void);
static void Unconditional_goto_statements(void);

exec_test_t branching_statement_func[CHATER_12_MAX_OF_TEST] = {
    [CHATER_12_TITLE]  = {"Chapter 12. branching statement (By JinSong)", NULL},
    [CHATER_12_TEST_1] = {"1.branching statement test 1", branching_statement_test1},
    [CHATER_12_TEST_2] = {"2.branching statement test 2", branching_statement_test2},
    [CHATER_12_TEST_3] = {"3.branching statement test 3", branching_statement_test3},
};

void branching_statement_main(void)
{
    UI_event_loop_exec_test(branching_statement_func, sizeof(branching_statement_func)/sizeof(exec_test_t));
}

/* 
desc: 섹션 12장 if문과 스코프
*/
static void If_Statements_Scopes(void)
{

}

/* 
desc: 섹션 12장 [필수 실습 문제] 최댓값 구하기 - if문 버전
*/
static void branching_statement_test1(void)
{
    int input, max;

    scanf("%d", &input);

    max = input;

    scanf("%d", &input);

    if(input > max)
    {
        max = input;
    }

    scanf("%d", &input);

    if(input > max)
    {
        max = input;
    }

    printf("MAX: %d\n",max);
}

/* 
desc: 섹션 12장 [필수 실습 문제] 버스요금 계산
*/
static void branching_statement_test2(void)
{
    int age, charge;

    scanf("%d", &age);

    if(age >= 20)
    {
        age = 20;
        charge = BUS_CHARGE;
    }
    else
    {
        charge = (BUS_CHARGE / 4) * 3;
    }

    printf("나이: %d,최종요금: %d\n",age, charge);
}

/* 
desc: 섹션 12장 if else문
*/
static void If_Else_Statements(void)
{

}

/* 
desc: 섹션 12장 if else문 중첩 (분류와 선택)
*/
static void Nesting_if_else_statements(void)
{

}

/* 
desc: 섹션 12장 [필수 실습 문제] 연령별 버스요금 계산
*/
static void branching_statement_test3(void)
{
    int age;
    double discount_rate;
    int charge;

    printf("나이를 입력하세요:");

    scanf("%d", &age);

    if((age >= 0) && (age <= 3))
    {
        discount_rate = 1;
    }
    else if((age >= 4) && (age <= 13))
    {
        discount_rate = 0.5;
    }
    else if((age >= 14) && (age <= 19))
    {
        discount_rate = 0.25;
    }
    else
    {
        discount_rate = 0;
    }

    charge = BUS_CHARGE - (int)(BUS_CHARGE * discount_rate);

    printf("버스 요금: %d [나이: %d]\n",charge,age);
}

/* 
desc: 섹션 12장 다중 if문
*/
static void Multiple_if_Statements(void)
{

}

/* 
desc: 섹션 12장 중첩 스코프와 식별자 검색 순서
*/
static void Nested_Scopes_Identifier_Search_Order(void)
{
    /*
        스코프 중첩과 식별자 검색 순서
        - 변수의 접근 간의 범위는 선언된 스코프로 제한됨. (지역 변수)
        - 현재 까지 배우고 사용한 모든 변수는 지역변수 및 자동변수
        - 자동변수는 선언된 스코프를 넘어서면 자동으로 소멸
        - 식별자가 같은 경우 최근 스코프가 우선.

        if문의 한 스코프는 하나의 스택 구조로 관리 됨. 각 스택 구조에 if문의 로컬 변수가 선언이 된다.
        만약 if문이 소멸하게 되면 해당 스택 구조도 소멸하여 if문의 로컬 변수도 소멸한다.
    */

   int nInput = 0;
   scanf("%d", &nInput);

   if(nInput > 10)
   {
        printf("Before : %d\n", nInput);

        int nInput = 20;
        printf("After : %d\n", nInput);
   }

   printf("%d\n", nInput);
}

/* 
desc: 섹션 12장 switch-case문
*/
static void Switch_Case_Statements(void)
{
    int input_a, input_b;
    char operator;
    double result;

    scanf("%d%c%d",&input_a,&operator,&input_b);

    switch(operator)
    {
        case '+':
            result = input_a + input_b; 
            break;

        case '-':
            result = input_a - input_b; 
            break;

        case '*':
            result = input_a * input_b; 
            break;

        case '/':
            result = input_a / input_b; 
            break;
    }

    printf("result: %f\n",result);
}


/* 
desc: 섹션 12장 무조건 goto문
*/
static void Unconditional_goto_statements(void)
{
    /*
        무조건 goto
        - 프로그램의 흐름을 조건 없이 즉시 변경하는 제어문
        - 프로그램의 흐름이 엉킬 수 있어 대부분 사용을 권하지 않음
    */

   int nInput;

    INPUT :
        printf("Input number : ");
        scanf("%d", &nInput);

        if (nInput < 0 || nInput > 10)
            goto INPUT;
        
        printf("end\n");

}