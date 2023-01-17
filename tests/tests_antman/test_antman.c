/*
** EPITECH PROJECT, 2022
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/hooks.h>
#include "antman.h"

#define TOTAL_NB_TEST (7)

int main_test_antman(int argc, char **argv);

ReportHook(PRE_ALL)(struct criterion_test_set *tests) {
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
    printf("[Test %d / %d end --> in %.2f sec]\n", count_test, TOTAL_NB_TEST, test->elapsed_time);
    ++ count_test;
}

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

TestSuite(Error_handling, .init = redirect_all_stdout);

Test (Error_handling, error_invalid_file)
{
    int argc = 3;
    char *argv[] = {"./antman", "tests/file_not_exist.lyr", "1"};
    cr_assert_eq(main_test_antman(argc, argv), 84);
}

Test (Error_handling, error_missing_arg)
{
    int argc = 2;
    char *argv[] = {"./antman", "../tests/tests_antman/test_file_1.lyr"};
    cr_assert_eq(main_test_antman(argc, argv), 84);
}

Test (Error_handling, error_too_much_arg)
{
    int argc = 4;
    char *argv[] = {"./antman", "../tests/tests_antman/test_file_1.lyr", "1", "nothing"};
    cr_assert_eq(main_test_antman(argc, argv), 84);
}

Test (Error_handling, error_invalid_option)
{
    int argc = 3;
    char *argv[] = {"./antman", "../tests/tests_antman/test_file_1.lyr", "4"};
    cr_assert_eq(main_test_antman(argc, argv), 84);
}

TestSuite(Unit_test, .init = redirect_all_stdout);

Test (Unit_test, error_manager)
{
    for (int i = -1; i < 6; ++i)
        print_error(i);
}

TestSuite(tests_compression, .init = redirect_all_stdout);

Test (tests_compression, basic_text_1)
{
    int argc = 3;
    char *argv[] = {"./antman", "../tests/tests_antman/test_file_1.lyr", "1"};
    cr_assert_eq(main_test_antman(argc, argv), 0);
}

Test (tests_compression, basic_text_2)
{
    int argc = 3;
    char *argv[] = {"./antman", "../tests/tests_antman/test_file_2.lyr", "1"};
    cr_assert_eq(main_test_antman(argc, argv), 0);
}
