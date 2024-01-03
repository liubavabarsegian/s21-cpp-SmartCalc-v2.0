#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_smart_calc/scan_rpn.h"

START_TEST(test_1) {
  char input[] = "100 + 100";
  double result_real = 100 + 100;
  char result_s21[255] = "";
  scan_rpn(input, result_s21);
  ck_assert_float_eq(atof(result_s21), result_real);
}
END_TEST

START_TEST(test_2) {
  char input[] = "-200 + 200";
  double result_real = -200 + 200;
  char result_s21[255] = "";
  scan_rpn(input, result_s21);
  ck_assert_float_eq(atof(result_s21), result_real);
}
END_TEST

START_TEST(test_3) {
  char input[] = "-15";
  double result_real = -15;
  char result_s21[255] = "";
  scan_rpn(input, result_s21);
  ck_assert_float_eq(atof(result_s21), result_real);
}
END_TEST

START_TEST(test_4) {
  char input[] = "-5";
  double result_real = -5;
  char result_s21[255] = "";
  scan_rpn(input, result_s21);
  ck_assert_float_eq(atof(result_s21), result_real);
}
END_TEST

START_TEST(test_5) {
  char input[] = "15.4 + 1.2";
  double result_real = 15.4 + 1.2;
  char result_s21[255] = "";
  scan_rpn(input, result_s21);
  ck_assert_float_eq(atof(result_s21), result_real);
}
END_TEST

START_TEST(test_6) {
  char input[] = "9^4 - 78 / 5";
  double result_real = pow(9, 4) - 78 / 5.0;
  char result_s21[255] = "";
  scan_rpn(input, result_s21);
  ck_assert_float_eq(atof(result_s21), result_real);
}
END_TEST

START_TEST(test_7) {
  char input[] = "-45.6/5-67*4-(+8*2-5)";
  double result_real = -45.6 / 5 - 67 * 4 - (+8 * 2 - 5);
  char result_s21[255] = "";
  scan_rpn(input, result_s21);
  ck_assert_float_eq(atof(result_s21), result_real);
}
END_TEST

START_TEST(test_8) {
  char input[] = "-45%-5";
  double result_real = -45 % -5;
  char result_s21[255] = "";
  scan_rpn(input, result_s21);
  ck_assert_float_eq(atof(result_s21), result_real);
}
END_TEST

START_TEST(test_9) {
  char input[] = "999.99999 + 0.0001 + (9000^4 - 78 / 5)";
  float result_real = 999.99999 + 0.0001 + (pow(9000, 4) - 78 / 5.0);
  char result_s21[255] = "";
  scan_rpn(input, result_s21);
  ck_assert_float_eq(atof(result_s21), result_real);
}
END_TEST

START_TEST(test_10) {
  char input[] = "-45.6/5-67*4-(+8*2-5)";
  double result_real = -45.6 / 5 - 67 * 4 - (+8 * 2 - 5);
  char result_s21[255] = "";
  scan_rpn(input, result_s21);
  ck_assert_float_eq(atof(result_s21), result_real);
}
END_TEST

START_TEST(test_11) {
  char input[] = "0.00001 % 0.999";
  double result_real = fmod(0.00001, 0.999);
  char result_s21[255] = "";
  scan_rpn(input, result_s21);
  ck_assert_float_eq(atof(result_s21), result_real);
}
END_TEST

START_TEST(test_12) {
  char input[] = "0.00001 %(0.999 + 9)";
  double result_real = fmod(0.00001, 9.999);
  char result_s21[255] = "";
  scan_rpn(input, result_s21);
  ck_assert_float_eq(atof(result_s21), result_real);
}
END_TEST

START_TEST(test_13) {  // error
  char input[] = "0.000.01 + 0.999";
  char result_s21[255] = "";
  int s21_flag = scan_rpn(input, result_s21);
  ck_assert_int_eq(s21_flag, FAILURE);
}
END_TEST

START_TEST(test_14) {  // error
  char input[] = "0.99 modulo 0.999";
  char result_s21[255] = "";
  int s21_flag = scan_rpn(input, result_s21);
  ck_assert_int_eq(s21_flag, FAILURE);
}
END_TEST

START_TEST(test_15) {  // error
  char input[] = "0.99 + 0.999 =";
  char result_s21[255] = "";
  int s21_flag = scan_rpn(input, result_s21);
  ck_assert_int_eq(s21_flag, FAILURE);
}
END_TEST

START_TEST(test_16) {  // error
  char input[] = "0.00001+- 0.999=";
  char result_s21[255] = "";
  int s21_flag = scan_rpn(input, result_s21);
  ck_assert_int_eq(s21_flag, FAILURE);
}
END_TEST

START_TEST(test_17) {  // error
  char input[] = "--+";
  char result_s21[255] = "";
  int s21_flag = scan_rpn(input, result_s21);
  ck_assert_int_eq(s21_flag, FAILURE);
}
END_TEST

START_TEST(test_18) {  // error
  char input[] = "^0.999";
  char result_s21[255] = "";
  int s21_flag = scan_rpn(input, result_s21);
  ck_assert_int_eq(s21_flag, FAILURE);
}
END_TEST

START_TEST(test_19) {
  char input[] = "sqrt(35)";
  double result_real = sqrt(35);
  char result_s21[255] = "";
  scan_rpn(input, result_s21);
  ck_assert_float_eq(atof(result_s21), result_real);
}
END_TEST

START_TEST(test_20) {
  char input[] = "sin(5.89*67)-cos(4.99)-log(45.78)";
  double result_real = sin(5.89 * 67) - cos(4.99) - log10(45.78);
  char result_s21[255] = "";
  scan_rpn(input, result_s21);
  ck_assert_float_eq_tol(atof(result_s21), result_real, 1e-6);
}
END_TEST

START_TEST(test_21) {
  char input[] = "sin(5.8*67)";
  double result_real = sin(5.8 * 67);
  char result_s21[255] = "";
  scan_rpn(input, result_s21);
  ck_assert_float_eq_tol(atof(result_s21), result_real, 1e-6);
}
END_TEST

START_TEST(test_22) {
  char input[] = "cos(5.8*67)";
  double result_real = cos(5.8 * 67);
  char result_s21[255] = "";
  scan_rpn(input, result_s21);
  ck_assert_float_eq_tol(atof(result_s21), result_real, 1e-6);
}
END_TEST

START_TEST(test_23) {
  char input[] = "asin(0.2)";
  double result_real = asin(0.2);
  char result_s21[255] = "";
  scan_rpn(input, result_s21);
  ck_assert_float_eq_tol(atof(result_s21), result_real, 1e-6);
}
END_TEST

START_TEST(test_24) {  // error
  char input[] = "((";
  char result_s21[255] = "";
  int s21_flag = scan_rpn(input, result_s21);
  ck_assert_int_eq(s21_flag, FAILURE);
}
END_TEST

START_TEST(test_25) {  // error
  char input[] = "))";
  char result_s21[255] = "";
  int s21_flag = scan_rpn(input, result_s21);
  ck_assert_int_eq(s21_flag, FAILURE);
}
END_TEST

START_TEST(test_26) {  // error
  char input[] = "(4+(2 + 3)";
  char result_s21[255] = "";
  int s21_flag = scan_rpn(input, result_s21);
  ck_assert_int_eq(s21_flag, FAILURE);
}
END_TEST

START_TEST(test_27) {  // error
  char input[] = "4+(2 + 3) /3)";
  char result_s21[255] = "";
  int s21_flag = scan_rpn(input, result_s21);
  ck_assert_int_eq(s21_flag, FAILURE);
}
END_TEST

START_TEST(test_28) {
  char input[] = "1/0";
  char result_s21[255] = "";
  scan_rpn(input, result_s21);
  ck_assert_double_infinite(atof(result_s21));
}
END_TEST

START_TEST(test_29) {
  char input[] = "+5+6";
  char result_s21[255] = "";
  double result_real = +5 + 6;
  scan_rpn(input, result_s21);
  ck_assert_float_eq(atof(result_s21), result_real);
}
END_TEST

START_TEST(test_30) {  // error
  char input[] = "+-5+6";
  char result_s21[255] = "";
  int s21_flag = scan_rpn(input, result_s21);
  ck_assert_int_eq(s21_flag, FAILURE);
}
END_TEST

START_TEST(test_31) {  // error
  char input[] = "(56+67";
  char result_s21[255] = "";
  int s21_flag = scan_rpn(input, result_s21);
  ck_assert_int_eq(s21_flag, FAILURE);
}
END_TEST

START_TEST(test_32) {  // error
  char input[] = "-8)";
  char result_s21[255] = "";
  int s21_flag = scan_rpn(input, result_s21);
  ck_assert_int_eq(s21_flag, FAILURE);
}
END_TEST

START_TEST(test_33) {
  char input[] =
      "tan(atan(0.5)) + acos(0.05 - 0.003) - cos(3^(2)) - "
      "ln(107-cos(sin(3.14)))";
  double result_real = tan(atan(0.5)) + acos(0.05 - 0.003) - cos(pow(3, 2)) -
                       log(107 - cos(sin(3.14)));
  char result_s21[255] = "";
  scan_rpn(input, result_s21);
  ck_assert_float_eq_tol(atof(result_s21), result_real, 1e-6);
}
END_TEST

START_TEST(test_34) {
  char input[] = "-ln(200)";
  double result_real = -log(200);
  char result_s21[255] = "";
  scan_rpn(input, result_s21);
  ck_assert_float_eq_tol(atof(result_s21), result_real, 1e-6);
}
END_TEST

START_TEST(test_35) {
  char input[] = "2^0.5 - 2^20";
  double result_real = pow(2, 0.5) - pow(2, 20);
  char result_s21[255] = "";
  scan_rpn(input, result_s21);
  ck_assert_float_eq_tol(atof(result_s21), result_real, 1e-6);
}
END_TEST

START_TEST(test_36) {
  char input[] =
      "sin(500) + cos(-200) - tan(15) - atan(0.33) + acos(-1) * asin(1) + "
      "ln(sqrt(144))";
  double result_real = sin(500) + cos(-200) - tan(15) - atan(0.33) +
                       acos(-1) * asin(1) + log(sqrt(144));
  char result_s21[255] = "";
  scan_rpn(input, result_s21);
  ck_assert_float_eq_tol(atof(result_s21), result_real, 1e-6);
}
END_TEST

START_TEST(test_37) {  // error
  char input[] = "-8)";
  char *result_s21 = NULL;
  int s21_flag = scan_rpn(input, result_s21);
  ck_assert_int_eq(s21_flag, FAILURE);
}
END_TEST

START_TEST(test_38) {  // error
  char input[] = "";
  char result_s21[255] = "";
  int s21_flag = scan_rpn(input, result_s21);
  ck_assert_int_eq(s21_flag, FAILURE);
}
END_TEST

START_TEST(test_39) {  // error
  char input[] = ".";
  char result_s21[255] = "";
  int s21_flag = scan_rpn(input, result_s21);
  ck_assert_int_eq(s21_flag, FAILURE);
}
END_TEST

START_TEST(test_40) {  // error
  char input[] = "!";
  char result_s21[255] = "";
  int s21_flag = scan_rpn(input, result_s21);
  ck_assert_int_eq(s21_flag, FAILURE);
}
END_TEST

START_TEST(test_41) {
  char input[] = "log(-10)";
  char result_s21[255] = "";
  int s21_flag = scan_rpn(input, result_s21);
  ck_assert_float_nan(atof(result_s21));
  ck_assert_int_eq(s21_flag, SUCCESS);
}
END_TEST

START_TEST(test_42) {
  char input[] = "asin(1)";
  double result_real = asin(1);
  char result_s21[255] = "";
  scan_rpn(input, result_s21);
  ck_assert_float_eq_tol(atof(result_s21), result_real, 1e-6);
}
END_TEST

START_TEST(test_43) {
  char input[] = "1 # 3";
  char result_s21[255] = "";
  int s21_flag = scan_rpn(input, result_s21);
  ck_assert_int_eq(s21_flag, FAILURE);
}
END_TEST

void calc_tests(TCase *tc1_1) {
  tcase_add_test(tc1_1, test_1);
  tcase_add_test(tc1_1, test_2);
  tcase_add_test(tc1_1, test_3);
  tcase_add_test(tc1_1, test_4);
  tcase_add_test(tc1_1, test_5);
  tcase_add_test(tc1_1, test_6);
  tcase_add_test(tc1_1, test_7);
  tcase_add_test(tc1_1, test_8);
  tcase_add_test(tc1_1, test_9);
  tcase_add_test(tc1_1, test_10);
  tcase_add_test(tc1_1, test_11);
  tcase_add_test(tc1_1, test_12);
  tcase_add_test(tc1_1, test_13);
  tcase_add_test(tc1_1, test_14);
  tcase_add_test(tc1_1, test_15);
  tcase_add_test(tc1_1, test_16);
  tcase_add_test(tc1_1, test_17);
  tcase_add_test(tc1_1, test_18);
  tcase_add_test(tc1_1, test_19);
  tcase_add_test(tc1_1, test_20);
  tcase_add_test(tc1_1, test_21);
  tcase_add_test(tc1_1, test_22);
  tcase_add_test(tc1_1, test_23);
  tcase_add_test(tc1_1, test_24);
  tcase_add_test(tc1_1, test_25);
  tcase_add_test(tc1_1, test_26);
  tcase_add_test(tc1_1, test_27);
  tcase_add_test(tc1_1, test_28);
  tcase_add_test(tc1_1, test_29);
  tcase_add_test(tc1_1, test_30);
  tcase_add_test(tc1_1, test_31);
  tcase_add_test(tc1_1, test_32);
  tcase_add_test(tc1_1, test_33);
  tcase_add_test(tc1_1, test_34);
  tcase_add_test(tc1_1, test_35);
  tcase_add_test(tc1_1, test_36);
  tcase_add_test(tc1_1, test_37);
  tcase_add_test(tc1_1, test_38);
  tcase_add_test(tc1_1, test_39);
  tcase_add_test(tc1_1, test_40);
  tcase_add_test(tc1_1, test_41);
  tcase_add_test(tc1_1, test_42);
  tcase_add_test(tc1_1, test_43);
}

int main(void) {
  Suite *s1 = suite_create("RPN");
  TCase *tc1_1 = tcase_create("RP");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);

  calc_tests(tc1_1);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}