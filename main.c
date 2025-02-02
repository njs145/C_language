#include <stdio.h>
#include "Hello/Hello.h"
#include "10_Standard_IO/Standard_IO.h"
#include "11_Calculator/Calculator.h"
#include "12_branching_statement/branching_statement.h"
#include "13_Iteration/Iteration.h"
#include "14_array/array.h"

#include "common/UI.h"

void printf_hello(void)
{
    printf("hello\n");
}

exec_test_t c_language_exec_func[6] = {
    [TITLE]  = {"C Language TEST (By JinSong)", NULL},
    [TEST_1] = {"1.Standard IO test", Standard_IO_main},
    [TEST_2] = {"2.Calculator test", Calculator_main},
    [TEST_3] = {"3.Branching test", branching_statement_main},
    [TEST_4] = {"4.Iteration test", Iteration_main},
    [TEST_5] = {"5.Array test", array_main},
};

int main(void)
{
    UI_event_loop_exec_test(c_language_exec_func, sizeof(c_language_exec_func)/sizeof(exec_test_t));
    return 0;
}

                                      