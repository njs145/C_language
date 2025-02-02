#include "Calculator.h"
#include "../common/UI.h"

#define HOURPERSEC  3600
#define MINPERSEC   60

static void arithmetic_operators_example(void);
static void Variant_type_promotion_example(void);
static void Divide_zero_example(void);
static void Calculator_test1(void);
static void Calculator_test2(void);
static void Simple_assignment_operators_example(void);
static void Calculator_test3(void);
static void compound_assignment_operators_example(void);
static void Calculator_test4(void);
static void cast_operators_example(void);
static void unary_increasse_decrease_operators_example(void);
static void bitwise_operators_endianness_example(void);
static void Calculator_test5(void);
static void sizeof_operator_example(void);
static void relational_operator_example(void);
static void logical_operator_example(void);
static void sortcirtuits_checking_common_error_example(void);
static void conditional_ternary_operator_example(void);
static void Calculator_test6(void);
static void Calculator_test7(void);
static void Calculator_test8(void);

exec_test_t Calculator_exec_func[7] = {
    [CHATER_11_TITLE]  = {"Chapter 11. Calculator (By JinSong)", NULL},
    [CHATER_11_TEST_1] = {"1.Standard IO test 1", Calculator_test1},
    [CHATER_11_TEST_2] = {"2.Standard IO test 2", Calculator_test2},
    [CHATER_11_TEST_3] = {"3.Standard IO test 3", Calculator_test3},
    [CHATER_11_TEST_4] = {"4.Standard IO test 4", Calculator_test4},
    [CHATER_11_TEST_5] = {"5.Standard IO test 5", Calculator_test5},
    [CHATER_11_TEST_6] = {"6.Standard IO test 6", Calculator_test6},
};

void Calculator_main(void)
{
    UI_event_loop_exec_test(Calculator_exec_func, sizeof(Calculator_exec_func)/sizeof(exec_test_t));
}

/*#########################################################
연산자
- 연산자는 CPU 연산과 직결되는 문법
- 연산자 자체는 하나의 항
- 여러 항을 모아 연산식 작성
- 연산자와 피연산자로 구성

연산자의 결합성
- 우선순의가 같은 경우 어떤 것을 먼저 연산할 것인지.
- 3 + 4 + 5 연산에서 두 덧셈 연산은 우선 순위가 같고 
  결합성이 L->R 이므로 3 + 4을 먼저 수행.
##########################################################*/

/* 
desc: 섹션 11장 산술 연산자.
*/
static void arithmetic_operators_example(void)
{
    /*
    산술 연산자
    -대표적인 2항 연산자
    - +, -, *, /, %
    */

   int result = 0;
   result = 3; /* 정수와 나눗셈은 정수로 나옴. -> 0 */

   printf("result = %d\n",result - 5);

   /* 강제 형 변환 */
   printf("%f\n",(double)(result) / 2);
}

/* 
desc: 섹션 11장 이형자료 연산과 형승격.
*/
static void Variant_type_promotion_example(void)
{
    /* 
    산술 연산과 형승격
    - 임시 결과는 피연산자 표현범위 이상의 표현이 가능해야 함.
    - char + int 결과는 int(char > char)
    - double * int 결과는 double(double > int)
    - 4 / 3 결과는 정수 결과
    - 4.0 / 3 결과는 실수 결과.
    */

   char ch = 'a';
   
   printf("%c\n", ch);
   printf("%c\n", ch + 1);
   printf("%d\n", ch + 1);
   printf("%d\n", 'a' + 1);

   printf("%d,\n", (int)(5.0 + 2));
   printf("%f,\n", 5.0 + 2);
}

/* 
desc: 섹션 11장 0으로 나누면 안 되는 이유.
*/
static void Divide_zero_example(void)
{
    int input = 0;

    scanf("%d", &input);
    printf("몫: %d\n", 10 / input);

    /* 
    문제점: 나누는 값이 0일수도 있다.
    - 사용자를 절대 신뢰하면 안된다. 사용자는 잘 모르거나 악의적으로 사용할 수 있기 때문에 사용자를 신뢰하면 안된다.
     */
}

/* 
desc: 섹션 11장 [필수 실습 문제] 평균값 구하기.
*/
static void Calculator_test1(void)
{
    int x, y;
    double avg;
    printf("두 정수를 입력하세요.: ");
    scanf("%d%d", &x, &y);

    avg = (double)(x + y) / 2;
    printf("AVG: %.2f\n", avg);
}

/* 
desc: 섹션 11장 [필수 실습 문제] 시 분 초 계산하기.
*/
static void Calculator_test2(void)
{
    int input_sec;
    int hour, min, sec;
    scanf("%d", &input_sec);

    hour = input_sec / HOURPERSEC;
    min = (input_sec - (hour * HOURPERSEC)) / MINPERSEC;
    sec = input_sec % MINPERSEC;

    printf("%d초는 %d시간 %2d분 %2d초 입니다.\n",input_sec, hour, min, sec);
    
}

/* 
desc: 섹션 11장 단순 대입 연산자.
*/
static void Simple_assignment_operators_example(void)
{
    /*
        단순 대입 연산자는 두 피연산자 중 오른쪽 피연산자(r-value)의 값을 왼쪽 피 연산자(l-value)에 저장하는 연산자이다.
        이때 l-value의 l는 location의 의미를 가지고 있다. 따라서 l-value는 무조건 변수여야 한다.
        또한 대입 연산자 (=)는 copy 연산이라고 생각하면 된다. 즉 a = b라 하면 b는 원본 데이터이며, a는 사본 데이터이다.
    */

   int x = 0, nInput = 0;
   scanf("%d", &nInput);

   x = nInput; /* x라는 변수 메모리에 nInput의 값이 overwrite가 된다. */
   printf("%d\n", x);

   /*
        배열의 이름은 '주소상수'이다 . 변수가 아니다!
        char szBuffer[32] = { 0 };

        szBuffer = 'A'; 이렇게는 안된다.
   */

  char szBuffer[32] = { 0 };
  printf("szBuffer 주소는: 0x%p \n",szBuffer);
  printf("szBuffer의 0번 인덱스는: 0x%p\n",&szBuffer[0]);
}

/* 
desc: 섹션 11장 [필수 실습 문제] 두 변수 값 교환.
*/
static void Calculator_test3(void)
{
    int a, b;
    int temp;
    scanf("%d %d", &a, &b);

    temp = a;
    a = b;
    b = temp;

    printf("a:%d, b:%d", a, b);
}

/* 
desc: 섹션 11장 복합 대입 연산자.
*/
static void compound_assignment_operators_example(void)
{

}

/* 
desc: 섹션 11장 [필수 실습 문제] 세 정수 총합 계산하기 (누산)
.
*/
static void Calculator_test4(void)
{
    int input, sum;

    scanf("%d", &input);

    sum = input;

    scanf("%d", &input);

    sum += input;

    scanf("%d", &input);

    sum += input;

    printf("Total : %d", sum);
}

/* 
desc: 섹션 형변환 연산자.
*/
static void cast_operators_example(void)
{
    /*
        형 변환 연산자
        - 피연산자의 형식을 강제로 변경해주는 단항 연산자
        - 부적절한 변환 시 정보가 유실될 수 있음.
    */

   unsigned int data = 256;
   unsigned char ch;

   ch = data; /* ch는 8비트 사이즈의 변수이며, data는 32비트 사이즈의 변수이다. 따라서 ch는 data의 모든 값을 저장할 수 없다. */

   printf("integer data: %d\n", data);
   printf("char ch: %d\n", ch);
}

/* 
desc: 섹션 단항 증/감 연산자.
*/
static void unary_increasse_decrease_operators_example(void)
{
    /*
        전위식, 후위식
        전위식: ++a 모든 연산보다 우선순위가 높다.
        후위식: a++ 모든 연산보다 우선순위가 낮다.
    */

    int a = 3, b = 3;
    
    a = ++b;
    printf("a: %d, b: %d\n", a ,b);

    a = b++;
    printf("a: %d, b: %d\n", a ,b);
}

/* 
desc: 섹션 비트 연산자와 엔디안(Endian).
*/
static void bitwise_operators_endianness_example(void)
{
    /*
        비트 연산자
        - 자료를 비트 단위로 논리 식을 수행하는 연산
        - 보통 2진수 로 변환해 판단.
        - AND, OR, NOT, XOR, Shift left, Shift right

        비트 마스크
        - 데이터에서 특정 영역의 값이 모두 0이 되도록 지우는 연산
        - and의 특징을 이용
        - 0과 AND 연산을 수행하면 결과는 무조건 0
    */

    int nData = 0x11223344;

    printf("%d\n", nData);
    printf("%08x\n", nData & 0x00FFF00);
    printf("%08x\n", nData | 0x00FFF00);
    printf("%08x\n", nData ^ 0x00FFF00);
    printf("%08x\n", ~nData);
    printf("%08x\n", nData >> 8);
    printf("%08x\n", nData << 8);

    /*
        엔디안
        int a = 0x12345678;

        모든 주소는 1Byte 단위로 주소가 할당된다. 따라서 a의 값은 0x12345678이지만 주소 상으로는 0x12, 0x34, 0x56, 0x78 단위로 쪼개진다.

        따라서 integer 변수는 4byte이기 때문에 이 변수를 주소상으로 어떻게 저장을 할지가 고민이 된다.
        여기서 endian 개념이 나온다.
        
        0x12, 0x34, 0x56, 0x78는 숫자적으로 4번째, 3번째, 2번째, 1번째이다.

        big endian일 경우는 1번째 부터 주소에 저장을 한다. 즉 0x78563412로 저장된다.
        little endian는 4번째 부터 주소에 저장한다. 즉 0x12345678로 저장된다.

        우리가 익숙한 변수 저장은 little endian일 것이다.

        하지만 우리가 자주 사용하는 intel cpu는 big endiand이다...
    */
}

/* 
desc: 섹션 11장 [필수 실습 문제] 뺄셈 연산 직접 구현하기.
*/
static void Calculator_test5(void)
{
    int a, b, b_twos_complement, a_sub_b;

    scanf("%d%d", &a, &b);
    
    b_twos_complement = ~b + 1;

    a_sub_b = a + b_twos_complement;
    
    printf("a - b = %d", a_sub_b);
}

/* 
desc: 섹션 11장 sizeof 연산자.
*/
static void sizeof_operator_example(void)
{

}

/* 
desc: 섹션 11장 관계 연산자.
*/
static void relational_operator_example(void)
{

}

/* 
desc: 섹션 11장 논리 연산자
.
*/
static void logical_operator_example(void)
{

}

/* 
desc: 섹션 11장 쇼트 서킷과 범위검사 흔한 오류 예.
*/
static void sortcirtuits_checking_common_error_example(void)
{
    /*
        Short circuit (짧은 회로. 즉 최적화 로직)
        - 논리 식은 왼쪽부터 실행
        - 피연산자 항이 식일 경우 식부터 평가
        - 논리합의 경우 왼쪽 조건이 만족되면 이후식은 연산하지 않음.
        - 논리곱의 경우 마지막 식까지 모두 평가해 모든 결과가 참인지 확인.
    */
}

/* 
desc: 섹션 11장 조건 (3항) 연산자.
*/
static void conditional_ternary_operator_example(void)
{
    
}

/* 
desc: 섹션 11장 [필수 실습 문제] 합격, 불합격 판단하기.
*/
static void Calculator_test6(void)
{
    int score;

    printf("점수를 입력하세요: ");
    scanf("%d", &score);

    printf("결과: %s",score >= 80 ? "합격": "불합격");
}

/* 
desc: 섹션 11장 [필수 실습 문제] 최댓값 구하기 - 서바이벌 방식.
*/
static void Calculator_test7(void)
{
    int nData, Max;

    scanf("%d", &nData);

    Max = nData;

    scanf("%d", &nData);

    Max = Max > nData ? Max : nData;

    scanf("%d", &nData);

    Max = Max > nData ? Max : nData;

    printf("Max : %d\n", Max);
}

/* 
desc: 섹션 11장 [필수 실습 문제] 최댓값 구하기 - 토너먼트 방식.
*/
static void Calculator_test8(void)
{
    int score_1, score_2, score_3, Max;

    scanf("%d%d%d", &score_1, &score_2, &score_3);

    Max = ((score_1 > score_2 ? score_1 : score_2) > score_3 ? (score_1 > score_2 ? score_1 : score_2) : score_3);

    printf("MAX: %d\n",Max);
}