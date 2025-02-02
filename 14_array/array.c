#include "array.h"
#include "../common/UI.h"

#define DEASCENDING     0
#define ASCENDING       1

#define BUS_CHARGE      1000;

static void Basic_Syntax_for_Arrays(void);
static void array_test1(void);
static void array_test2(void);
static void array_test3(void);
static void Multidimensional_Arrays(void);
static void array_test4(void);
static void array_test5(void);
static void Advanced_Techniques_Lookup_Arrays(void);

exec_test_t array_func[CHATER_14_MAX_OF_TEST] = {
    [CHATER_14_TITLE]  = {"Chapter 14. array (By JinSong)", NULL},
    [CHATER_14_TEST_1] = {"1.array_test 1", array_test1},
    [CHATER_14_TEST_2] = {"2.array_test 2", array_test2},
    [CHATER_14_TEST_3] = {"3.array_test 3", array_test3},
    [CHATER_14_TEST_4] = {"4.array_test 4", array_test4},
    [CHATER_14_TEST_5] = {"5.array_test 5", array_test5},
};

void array_main(void)
{
    UI_event_loop_exec_test(array_func, sizeof(array_func)/sizeof(exec_test_t));
}

/* 
desc: 섹션 14장 배열의 기본 문법
*/
static void Basic_Syntax_for_Arrays(void)
{
    /*
        array
        - 형식이 같은 자료 여러 개를 모아 한 덩어리로 관리하는 문법
        - 여러 요소를 식별하기 위해 인덱스를 사용하여 0부터 시작 (Zero-based index)
        - 배열의 이름은 0번 요소의 메모리 주소에 대한 식별자이며 상수 (l-value 아님)

        문자 배열
        - 문자열의 실체는 char[]
        - 문자열 상수란 쓰기가 혀용되지 않은 이름이 없는 char[]
        - 문자열의 끝은 반드시 \n (null)
        - 문자열 상수는 보통 포인터를 사용해 관리
    */
}

/* 
desc: 섹션 14장 [필수 실습 문제] 배열에서 최댓값 찾기
*/
static void array_test1(void)
{
    __uint32_t array[5] = {50, 40, 10, 50, 20};
    __uint32_t i;
    __uint32_t max = 0;
    
    for(i = 0; i < (sizeof(array)/sizeof(__uint32_t)); i ++)
    {
        max = max > array[i] ? max : array[i];
    }

    printf("MAX: %d\n", max);
}

/* 
desc: 섹션 14장 [필수 실습 문제] 버블정렬(오름차순)
*/
static void array_test2(void)
{
    /*
        버블 정렬
        1. 반복문을 돌리면서 현재값을 비교한다.
        2. 만약 조건에 충족한다면 서로의 값을 바꾼다.
        - 지속적 교환
    */
    __uint32_t array[] = {6, 3, 7, 5, 1, 8, 4, 2, 9};
    __uint32_t i, j, q;
    __uint32_t min_value, temp_value;
    for(i = 0; i < (sizeof(array)/sizeof(__uint32_t)); i++)
    {
        for(j = i; j < (sizeof(array)/sizeof(__uint32_t)); j++)
        {
            temp_value = array[i];
            if((array[i] >= array[j]))
            {
                array[i] = array[j];
                array[j] = temp_value;
            }
        }
    }

    for(q = 0; q < (sizeof(array)/sizeof(__uint32_t)); q ++)
    {
        printf("%d ", array[q]);
    }
    printf("\n");
    
}

/* 
desc: 섹션 14장 [필수 실습 문제] 선택정렬
*/
static void array_test3(void)
{
    /*
        선택 정렬
        1. 반복문을 돌리면서 모든 후보들과 비교한다.
        2. 조건에 가장 부합하는 후보와 서로 값을 바꾼다.
        - 필요시 교환

        버블 정렬과 선택 정렬의 차이점.
        - 버블 정렬은 비교하면서 조건이 충족 할 때마다 값에 대입한다,
        - 선택 정렬은 모든 값과 비교해서 조건에 가장 충족한 값에 대해서 값에 대입한다.
    */

    __uint32_t array[] = {6, 3, 7, 5, 1, 8, 4, 2, 9};
    __uint32_t i, j, q;
    __uint32_t min_index, min_value, temp_value;
    for(i = 0; i < (sizeof(array)/sizeof(__uint32_t)); i++)
    {
        temp_value = array[i];
        min_index = i;
        for(j = i; j < (sizeof(array)/sizeof(__uint32_t)); j++)
        {
            if((array[min_index] >= array[j]))
            {
                min_index = j;
            }
        }
        
        if(i != min_index)
        {
            array[i] = array[min_index];
            array[min_index] = temp_value;
        }
    }

    for(q = 0; q < (sizeof(array)/sizeof(__uint32_t)); q ++)
    {
        printf("%d ", array[q]);
    }
    printf("\n");


}

/* 
desc: 섹션 14장 다차원 배열
*/
static void Multidimensional_Arrays(void)
{

}

/* 
desc: 섹션 14장 [필수 실습 문제] 교차와 달팽이 숙제
*/
static void array_test4(void)
{
    /*
        출력 
         1  2  3  4  5
        10  9  8  7  6
        11 12 13 14 15
        20 19 18 17 16
        21 22 23 24 25
    */

    __uint8_t array[5][5];
    __uint8_t *addr = array[0];

    for(__uint8_t x = 0; x <= sizeof(array); x ++)
    {
        addr[x] = x + 1;
    }

    __uint32_t i, j, q;
    __uint32_t max_index, min_index, max_value, min_value, temp_value;
    __uint8_t type_sequencing = ASCENDING;

    for(q = 0; q < sizeof(array)/sizeof(array[q]); q++)
    {
        if(type_sequencing == ASCENDING)
        {
            for(i = 0; i < (sizeof(array[q])/sizeof(__uint8_t)); i++)
            {
                temp_value = array[q][i];
                min_index = i;
                for(j = i; j < (sizeof(array[q])/sizeof(__uint8_t)); j++)
                {
                    if((array[q][min_index] >= array[q][j]))
                    {
                        min_index = j;
                    }
                }
                if(i != min_index)
                {
                    array[q][i] = array[q][min_index];
                    array[q][min_index] = temp_value;
                }
            }
        }
        else
        {
            for(i = 0; i < (sizeof(array[q])/sizeof(__uint8_t)); i++)
            {
                temp_value = array[q][i];
                max_index = i;
                for(j = i; j < (sizeof(array[q])/sizeof(__uint8_t)); j++)
                {
                    if((array[q][max_index] <= array[q][j]))
                    {
                        max_index = j;
                    }
                }
                if(i != max_index)
                {
                    array[q][i] = array[q][max_index];
                    array[q][max_index] = temp_value;
                }
            }            
        }
        type_sequencing = type_sequencing ^ 1;
    }
    
    for(__uint8_t a = 0; a < sizeof(array)/sizeof(array[q]); a ++)
    {
        for(__uint8_t b = 0; b < (sizeof(array[q])/sizeof(__uint8_t)); b++)
        {
            printf("%2d ",array[a][b]);
        }
        printf("\n");
    }
}

static void array_test5(void)
{
    /*
        달팽이 패턴 원리
        정사각형이기 때문에 한변의 사이즈가 x라고 가정.
        * 한변을 그리는 크기는 x, x-1, x-1, x-2, x-3, x-3, ..... , x-(x-1), x-(x-1)
        
        값 설정 로직.
        * 왼쪽에서 오른쪽으로 출력은 raw가 증가하는대로 cnt 증가.
        * 위에서 아래로 출력은 col이 증가하는대로 cnt 증가.
        * 오른쪽에서 왼쪽으로 출력은 raw가 감소하는대로 cnt 증가.
        * 아래에서 위로 출력은 col이 감소하는대로 cnt 증가.
    */
    __uint8_t cnt;
    __uint8_t i = 0, j = 0;
    __uint8_t col = 0, raw = 0;
    __uint8_t array[12][12] = { 0 };
    __uint8_t side_value[1024] = { 0 };
    __uint8_t corner_value[1024] = { 0 };
    __uint8_t temp_side, temp_corner;
    __uint8_t side_size_index = 0, corner_value_index = 0;
    __uint8_t copy_type = 0;

    /* side 값 구하기 */
    for(temp_side = sizeof(array[0]); temp_side > 0;)
    {
        side_value[side_size_index] = temp_side;
        // printf("side size = %d\n",side_value[side_size_index]);
        side_size_index ++;
        if(side_size_index % 2)
        {
            temp_side --;
        }
    }

    /* corner값 구하기 */
    side_size_index = 0;
    for(temp_corner = 1; temp_corner <= sizeof(array);)
    {
        corner_value[corner_value_index] = temp_corner;
        // printf("corner value: %d\n",corner_value[corner_value_index]);
        temp_corner += side_value[side_size_index];
        corner_value_index ++;
        side_size_index ++;
    }

    corner_value_index = 0;
    for(cnt = 1; cnt <= sizeof(array); cnt ++)
    {
        if(cnt == corner_value[corner_value_index])
        {
            copy_type = corner_value_index % 4;
            switch(copy_type)
            {
                case 0:
                    if(corner_value_index != 0)
                    {
                        col ++;
                        raw ++;
                    }
                break;
                case 1:
                    raw --;
                    col ++;
                break;
                case 2:
                    col --;
                    raw --;
                break;
                case 3:
                    raw ++;
                    col --;
                break;
            }            
            corner_value_index ++;
        }

        switch(copy_type)
        {
            case 0:
                array[col][raw] = cnt;
                raw ++;
            break;

            case 1:
                array[col][raw] = cnt;
                col ++;
            break;

            case 2:
                array[col][raw] = cnt;
                raw --;
            break;

            case 3:
                array[col][raw] = cnt;
                col --;
            break;
        }
    }
   
    printf("\n");
    for(i = 0; i < sizeof(array[0]); i ++)
    {
        for(j = 0; j < sizeof(array[0]); j ++)
        {
            printf("%03d ",array[i][j]);
        }
        printf("\n");
    }
}

/* 
desc: 섹션 14장 고급 기법 Lookup 배열
*/
static void Advanced_Techniques_Lookup_Arrays(void)
{
    /*
        Lookup 배열
        * 데이터를 검색 혹은 참조하기 위해 사용하는 배열
        * 보통 기준에 따라 인덱스 값을 계산하고 식별한 요소를 활용하는 구조
        * 배열의 한 요소가 초리할 하나의 경우로 활용
    */

    /* 전체 경우에 대한 과금률 결과를 담은 배열의 선언 및 정의 */

    __uint32_t age;
    __uint32_t charge;
    double aRate[10] = {
        0.0, 0.1, 0.25, /* 1 ~ 3세 */
        0.5, 0.5, /* 4 ~ 5세 */
        0.6, 0.65, /* 6 ~ 7세 */
        0.8, 0.82, 0.97 /* 8 ~ 10세 */
    };
    
    while(1)
    {
        printf("<요금 안내>\n");
        printf("나이를 입력하세요[1세부터 10세까지만 입력하세요]\n");
        printf("나이: ");

        scanf("%d", &age);
        if((age > 0) && (age <= 10))
        {
            charge =  aRate[age] * BUS_CHARGE;
            break;
        }
        else
        {
            printf("나이를 올바르게 입력하지 않았습니다. [1세부터 10세까지만 입력하세요.]\n\n");
            continue;
        }
    }
    printf("%d세의 버스 요금은 %d원입니다.\n",age, charge);
}