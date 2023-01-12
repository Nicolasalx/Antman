/*
** EPITECH PROJECT, 2022
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/hooks.h>
#include <stdio.h>

#define TOTAL_NB_TEST (6)

ReportHook(PRE_ALL)(struct criterion_test_set *tests) { // ? executed before all test
    (void) tests;
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);
    puts("\n\033[0;32m--- TEST START ---\033[0m\n");
}

ReportHook(POST_ALL)(struct criterion_global_stats *stats) {
    (void) stats;
    puts("\n\033[0;32m--- TEST END ---\033[0m\n");
}

ReportHook(POST_FINI)(struct criterion_test_stats *test) {
    static int count_test = 1;
    printf("(Test %d / %d end --> in %.2f sec)\n", count_test, TOTAL_NB_TEST, test->elapsed_time);
    ++ count_test;
}

TestSuite(Basic_tests);

Test (Basic_tests, test_cr_expect, .timeout = 1.)
{
    int result = 5 + 5;
    int right_result = 10;
    cr_expect(result == right_result, "\033[0;33mGet \"%d\" but expected \"%d\"\033[0m", result, right_result);
}

Test (Basic_tests, test_cr_assert)
{
    int result = strlen("");
    int right_result = 0;
    cr_assert(result == right_result, "\033[0;33mGet \"%d\" but expected \"%d\"\033[0m", result, right_result);
}

TestSuite(Medium_tests);

Test (Medium_tests, test_3)
{
    int result = 5 + 5;
    int right_result = 10;
    cr_expect(result == right_result, "\033[0;33mGet \"%d\" but expected \"%d\"\033[0m", result, right_result);
}

Test (Medium_tests, test_4)
{
    int result = strlen("");
    int right_result = 0;
    cr_assert(result == right_result, "\033[0;33mGet \"%d\" but expected \"%d\"\033[0m", result, right_result);
}

TestSuite(Hard_tests);

Test (Hard_tests, test_5)
{
    int result = 5 + 5;
    int right_result = 10;
    cr_expect(result == right_result, "\033[0;33mGet \"%d\" but expected \"%d\"\033[0m", result, right_result);
}

Test (Hard_tests, test_6)
{
    int result = strlen("");
    int right_result = 0;
    cr_assert(result == right_result, "\033[0;33mGet \"%d\" but expected \"%d\"\033[0m", result, right_result);
}
