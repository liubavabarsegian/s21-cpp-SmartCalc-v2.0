// #include <check.h>
// #include <math.h>
// #include <stdio.h>
// #include <stdlib.h>

// #include "../s21_smart_calc/scan_rpn.h"

// START_TEST(test_1) {
//   char input[] = "100 + 100";
//   double result_real = 100 + 100;
//   char result_s21[255] = "";
//   scan_rpn(input, result_s21);
//   ck_assert_float_eq(atof(result_s21), result_real);
// }
// END_TEST

// START_TEST(test_2) {
//   char input[] = "-200 + 200";
//   double result_real = -200 + 200;
//   char result_s21[255] = "";
//   scan_rpn(input, result_s21);
//   ck_assert_float_eq(atof(result_s21), result_real);
// }
// END_TEST

// START_TEST(test_3) {
//   char input[] = "-15";
//   double result_real = -15;
//   char result_s21[255] = "";
//   scan_rpn(input, result_s21);
//   ck_assert_float_eq(atof(result_s21), result_real);
// }
// END_TEST

// START_TEST(test_4) {
//   char input[] = "-5";
//   double result_real = -5;
//   char result_s21[255] = "";
//   scan_rpn(input, result_s21);
//   ck_assert_float_eq(atof(result_s21), result_real);
// }
// END_TEST

// START_TEST(test_5) {
//   char input[] = "15.4 + 1.2";
//   double result_real = 15.4 + 1.2;
//   char result_s21[255] = "";
//   scan_rpn(input, result_s21);
//   ck_assert_float_eq(atof(result_s21), result_real);
// }
// END_TEST

// START_TEST(test_6) {
//   char input[] = "9^4 - 78 / 5";
//   double result_real = pow(9, 4) - 78 / 5.0;
//   char result_s21[255] = "";
//   scan_rpn(input, result_s21);
//   ck_assert_float_eq(atof(result_s21), result_real);
// }
// END_TEST

// START_TEST(test_7) {
//   char input[] = "-45.6/5-67*4-(+8*2-5)";
//   double result_real = -45.6 / 5 - 67 * 4 - (+8 * 2 - 5);
//   char result_s21[255] = "";
//   scan_rpn(input, result_s21);
//   ck_assert_float_eq(atof(result_s21), result_real);
// }
// END_TEST

// START_TEST(test_8) {
//   char input[] = "-45%-5";
//   double result_real = -45 % -5;
//   char result_s21[255] = "";
//   scan_rpn(input, result_s21);
//   ck_assert_float_eq(atof(result_s21), result_real);
// }
// END_TEST

// START_TEST(test_9) {
//   char input[] = "999.99999 + 0.0001 + (9000^4 - 78 / 5)";
//   float result_real = 999.99999 + 0.0001 + (pow(9000, 4) - 78 / 5.0);
//   char result_s21[255] = "";
//   scan_rpn(input, result_s21);
//   ck_assert_float_eq(atof(result_s21), result_real);
// }
// END_TEST

// START_TEST(test_10) {
//   char input[] = "-45.6/5-67*4-(+8*2-5)";
//   double result_real = -45.6 / 5 - 67 * 4 - (+8 * 2 - 5);
//   char result_s21[255] = "";
//   scan_rpn(input, result_s21);
//   ck_assert_float_eq(atof(result_s21), result_real);
// }
// END_TEST

// START_TEST(test_11) {
//   char input[] = "0.00001 % 0.999";
//   double result_real = fmod(0.00001, 0.999);
//   char result_s21[255] = "";
//   scan_rpn(input, result_s21);
//   ck_assert_float_eq(atof(result_s21), result_real);
// }
// END_TEST

// START_TEST(test_12) {
//   char input[] = "0.00001 %(0.999 + 9)";
//   double result_real = fmod(0.00001, 9.999);
//   char result_s21[255] = "";
//   scan_rpn(input, result_s21);
//   ck_assert_float_eq(atof(result_s21), result_real);
// }
// END_TEST

// START_TEST(test_13) {  // error
//   char input[] = "0.000.01 + 0.999";
//   char result_s21[255] = "";
//   int s21_flag = scan_rpn(input, result_s21);
//   ck_assert_int_eq(s21_flag, FAILURE);
// }
// END_TEST

// START_TEST(test_14) {  // error
//   char input[] = "0.99 modulo 0.999";
//   char result_s21[255] = "";
//   int s21_flag = scan_rpn(input, result_s21);
//   ck_assert_int_eq(s21_flag, FAILURE);
// }
// END_TEST

// START_TEST(test_15) {  // error
//   char input[] = "0.99 + 0.999 =";
//   char result_s21[255] = "";
//   int s21_flag = scan_rpn(input, result_s21);
//   ck_assert_int_eq(s21_flag, FAILURE);
// }
// END_TEST

// START_TEST(test_16) {  // error
//   char input[] = "0.00001+- 0.999=";
//   char result_s21[255] = "";
//   int s21_flag = scan_rpn(input, result_s21);
//   ck_assert_int_eq(s21_flag, FAILURE);
// }
// END_TEST

// START_TEST(test_17) {  // error
//   char input[] = "--+";
//   char result_s21[255] = "";
//   int s21_flag = scan_rpn(input, result_s21);
//   ck_assert_int_eq(s21_flag, FAILURE);
// }
// END_TEST

// START_TEST(test_18) {  // error
//   char input[] = "^0.999";
//   char result_s21[255] = "";
//   int s21_flag = scan_rpn(input, result_s21);
//   ck_assert_int_eq(s21_flag, FAILURE);
// }
// END_TEST

// START_TEST(test_19) {
//   char input[] = "sqrt(35)";
//   double result_real = sqrt(35);
//   char result_s21[255] = "";
//   scan_rpn(input, result_s21);
//   ck_assert_float_eq(atof(result_s21), result_real);
// }
// END_TEST

// START_TEST(test_20) {
//   char input[] = "sin(5.89*67)-cos(4.99)-log(45.78)";
//   double result_real = sin(5.89 * 67) - cos(4.99) - log10(45.78);
//   char result_s21[255] = "";
//   scan_rpn(input, result_s21);
//   ck_assert_float_eq_tol(atof(result_s21), result_real, 1e-6);
// }
// END_TEST

// START_TEST(test_21) {
//   char input[] = "sin(5.8*67)";
//   double result_real = sin(5.8 * 67);
//   char result_s21[255] = "";
//   scan_rpn(input, result_s21);
//   ck_assert_float_eq_tol(atof(result_s21), result_real, 1e-6);
// }
// END_TEST

// START_TEST(test_22) {
//   char input[] = "cos(5.8*67)";
//   double result_real = cos(5.8 * 67);
//   char result_s21[255] = "";
//   scan_rpn(input, result_s21);
//   ck_assert_float_eq_tol(atof(result_s21), result_real, 1e-6);
// }
// END_TEST

// START_TEST(test_23) {
//   char input[] = "asin(0.2)";
//   double result_real = asin(0.2);
//   char result_s21[255] = "";
//   scan_rpn(input, result_s21);
//   ck_assert_float_eq_tol(atof(result_s21), result_real, 1e-6);
// }
// END_TEST

// START_TEST(test_24) {  // error
//   char input[] = "((";
//   char result_s21[255] = "";
//   int s21_flag = scan_rpn(input, result_s21);
//   ck_assert_int_eq(s21_flag, FAILURE);
// }
// END_TEST

// START_TEST(test_25) {  // error
//   char input[] = "))";
//   char result_s21[255] = "";
//   int s21_flag = scan_rpn(input, result_s21);
//   ck_assert_int_eq(s21_flag, FAILURE);
// }
// END_TEST

// START_TEST(test_26) {  // error
//   char input[] = "(4+(2 + 3)";
//   char result_s21[255] = "";
//   int s21_flag = scan_rpn(input, result_s21);
//   ck_assert_int_eq(s21_flag, FAILURE);
// }
// END_TEST

// START_TEST(test_27) {  // error
//   char input[] = "4+(2 + 3) /3)";
//   char result_s21[255] = "";
//   int s21_flag = scan_rpn(input, result_s21);
//   ck_assert_int_eq(s21_flag, FAILURE);
// }
// END_TEST

// START_TEST(test_28) {
//   char input[] = "1/0";
//   char result_s21[255] = "";
//   scan_rpn(input, result_s21);
//   ck_assert_double_infinite(atof(result_s21));
// }
// END_TEST

// START_TEST(test_29) {
//   char input[] = "+5+6";
//   char result_s21[255] = "";
//   double result_real = +5 + 6;
//   scan_rpn(input, result_s21);
//   ck_assert_float_eq(atof(result_s21), result_real);
// }
// END_TEST

// START_TEST(test_30) {  // error
//   char input[] = "+-5+6";
//   char result_s21[255] = "";
//   int s21_flag = scan_rpn(input, result_s21);
//   ck_assert_int_eq(s21_flag, FAILURE);
// }
// END_TEST

// START_TEST(test_31) {  // error
//   char input[] = "(56+67";
//   char result_s21[255] = "";
//   int s21_flag = scan_rpn(input, result_s21);
//   ck_assert_int_eq(s21_flag, FAILURE);
// }
// END_TEST

// START_TEST(test_32) {  // error
//   char input[] = "-8)";
//   char result_s21[255] = "";
//   int s21_flag = scan_rpn(input, result_s21);
//   ck_assert_int_eq(s21_flag, FAILURE);
// }
// END_TEST

// START_TEST(test_33) {
//   char input[] =
//       "tan(atan(0.5)) + acos(0.05 - 0.003) - cos(3^(2)) - "
//       "ln(107-cos(sin(3.14)))";
//   double result_real = tan(atan(0.5)) + acos(0.05 - 0.003) - cos(pow(3, 2)) -
//                        log(107 - cos(sin(3.14)));
//   char result_s21[255] = "";
//   scan_rpn(input, result_s21);
//   ck_assert_float_eq_tol(atof(result_s21), result_real, 1e-6);
// }
// END_TEST

// START_TEST(test_34) {
//   char input[] = "-ln(200)";
//   double result_real = -log(200);
//   char result_s21[255] = "";
//   scan_rpn(input, result_s21);
//   ck_assert_float_eq_tol(atof(result_s21), result_real, 1e-6);
// }
// END_TEST

// START_TEST(test_35) {
//   char input[] = "2^0.5 - 2^20";
//   double result_real = pow(2, 0.5) - pow(2, 20);
//   char result_s21[255] = "";
//   scan_rpn(input, result_s21);
//   ck_assert_float_eq_tol(atof(result_s21), result_real, 1e-6);
// }
// END_TEST

// START_TEST(test_36) {
//   char input[] =
//       "sin(500) + cos(-200) - tan(15) - atan(0.33) + acos(-1) * asin(1) + "
//       "ln(sqrt(144))";
//   double result_real = sin(500) + cos(-200) - tan(15) - atan(0.33) +
//                        acos(-1) * asin(1) + log(sqrt(144));
//   char result_s21[255] = "";
//   scan_rpn(input, result_s21);
//   ck_assert_float_eq_tol(atof(result_s21), result_real, 1e-6);
// }
// END_TEST

// START_TEST(test_37) {  // error
//   char input[] = "-8)";
//   char *result_s21 = NULL;
//   int s21_flag = scan_rpn(input, result_s21);
//   ck_assert_int_eq(s21_flag, FAILURE);
// }
// END_TEST

// START_TEST(test_38) {  // error
//   char input[] = "";
//   char result_s21[255] = "";
//   int s21_flag = scan_rpn(input, result_s21);
//   ck_assert_int_eq(s21_flag, FAILURE);
// }
// END_TEST

// START_TEST(test_39) {  // error
//   char input[] = ".";
//   char result_s21[255] = "";
//   int s21_flag = scan_rpn(input, result_s21);
//   ck_assert_int_eq(s21_flag, FAILURE);
// }
// END_TEST

// START_TEST(test_40) {  // error
//   char input[] = "!";
//   char result_s21[255] = "";
//   int s21_flag = scan_rpn(input, result_s21);
//   ck_assert_int_eq(s21_flag, FAILURE);
// }
// END_TEST

// START_TEST(test_41) {
//   char input[] = "log(-10)";
//   char result_s21[255] = "";
//   int s21_flag = scan_rpn(input, result_s21);
//   ck_assert_float_nan(atof(result_s21));
//   ck_assert_int_eq(s21_flag, SUCCESS);
// }
// END_TEST

// START_TEST(test_42) {
//   char input[] = "asin(1)";
//   double result_real = asin(1);
//   char result_s21[255] = "";
//   scan_rpn(input, result_s21);
//   ck_assert_float_eq_tol(atof(result_s21), result_real, 1e-6);
// }
// END_TEST

// START_TEST(test_43) {
//   char input[] = "1 # 3";
//   char result_s21[255] = "";
//   int s21_flag = scan_rpn(input, result_s21);
//   ck_assert_int_eq(s21_flag, FAILURE);
// }
// END_TEST


#include <iostream>
#include "gtest/gtest.h"
#include "../models/s21_calc_model.h"

TEST(CalcTest, GetResultCalc) {
  s21::CalcModel a;
  EXPECT_EQ(a.GetResult(), 0);
}

TEST(CalcTest, SimpleCalc0) {
  s21::CalcModel a;
  std::string input = "-2+2";
  a.Calculate(input);
  EXPECT_EQ(a.GetResult(), 0);
  input = "0.2/2";
  a.Calculate(input);
  EXPECT_EQ(a.GetResult(), 0.1);
  input = "A(0)*B(0)";
  a.Calculate(input);
  EXPECT_EQ(a.GetResult(), 0);
}
TEST(CalcTest, SimpleCalc1) {
  s21::CalcModel a;
  std::string input = "-2+2";
  a.Calculate(input);
  EXPECT_EQ(a.GetResult(), 0);

  input = "0.2/2";
  a.Calculate(input);
  EXPECT_EQ(a.GetResult(), 0.1);

  input = "A(0)*B(0)";
  a.Calculate(input);
  EXPECT_EQ(a.GetResult(), 0);
}

TEST(CalcTest, SimpleCalc2) {
  s21::CalcModel a;
  std::string input = "-222-3";
  a.Calculate(input);
  EXPECT_EQ(a.GetResult(), -225);

  input = "0.2*2";
  a.Calculate(input);
  EXPECT_EQ(a.GetResult(), 0.4);

  input = "@(0)";
  a.Calculate(input);
  EXPECT_EQ(a.GetResult(), 1);
}

TEST(CalcTest, SimpleCalc3) {
  s21::CalcModel a;
  std::string input = "C(1)-B(1)+E(1)";
  a.Calculate(input);
  EXPECT_DOUBLE_EQ(a.GetResult(), -0.77200956125745379);

  input = "2^2*2";
  a.Calculate(input);
  EXPECT_DOUBLE_EQ(a.GetResult(), 8);

  input = "H100+G2.7182818284";
  a.Calculate(input);
  EXPECT_DOUBLE_EQ(a.GetResult(), 2.9999999999782783);
}

TEST(CalcTest, SimpleCalc4) {
  s21::CalcModel a;
  std::string input = "10M3";
  a.Calculate(input);
  EXPECT_EQ(a.GetResult(), 1.0);
}

TEST(CalcTest, SimpleCalc5) {
  s21::CalcModel a;
  std::string input = "A(0)";
  a.Calculate(input);
  EXPECT_EQ(a.GetResult(), 0);
}

TEST(CalcTest, SimpleCalc6) {
  s21::CalcModel a;
  std::string input = "G(1)";
  a.Calculate(input);
  EXPECT_EQ(a.GetResult(), 0);
}

TEST(CalcTest, SimpleCalc7) {
  s21::CalcModel a;
  std::string input = "H(1)";
  a.Calculate(input);
  EXPECT_EQ(a.GetResult(), 0);
}

TEST(CalcTest, SimpleCalc8) {
  s21::CalcModel a;
  std::string input = "F(0)";
  a.Calculate(input);
  EXPECT_EQ(a.GetResult(), 0);
}

TEST(CalcTest, SimpleCalc9) {
  s21::CalcModel a;
  std::string input = "B(1)";
  a.Calculate(input);
  EXPECT_EQ(a.GetResult(), 1.5574077246549022);
}

TEST(CalcTest, SimpleCalc10) {
  s21::CalcModel a;
  std::string input = "A(1)";
  a.Calculate(input);
  EXPECT_EQ(a.GetResult(), 0.8414709848078965);
}

TEST(CalcTest, SimpleCalc11) {
  s21::CalcModel a;
  std::string input = "D(0)";
  a.Calculate(input);
  EXPECT_EQ(a.GetResult(), 0);
}

TEST(CalcTest, DifferentCalc) {
  s21::CalcModel a;

  std::string input;

  input = "2+2";
  a.Calculate(input);
  EXPECT_EQ(a.GetResult(), 4);

  input = "2+";
  a.Calculate(input);
  EXPECT_EQ(a.GetResult(), 2);

  input = "4-";
  a.Calculate(input);
  EXPECT_EQ(a.GetResult(), -4);

  input = "1e4";
  a.Calculate(input);
  EXPECT_EQ(a.GetResult(), 10000);

  input = "X";
  a.Calculate(input);
  EXPECT_EQ(a.GetResult(), 5);

  input = "1+2*3/2+4^1";
  a.Calculate(input);
  EXPECT_EQ(a.GetResult(), 8);

  input = "4*2+1";
  a.Calculate(input);
  EXPECT_EQ(a.GetResult(), 9);

  input = "(1+2";
  a.Calculate(input);
  EXPECT_EQ(a.GetResult(), 3);

  // Uncomment the following lines if Reset functionality is implemented
  // a.Reset();
  // EXPECT_EQ(a.GetResult(), 0);
}

TEST(CalcTest, TrigonometricFunctions) {
  s21::CalcModel a;

  std::string input;

  input = "@(0)";
  a.Calculate(input);
  EXPECT_EQ(a.GetResult(), 1.0);

  input = "A(0)";
  a.Calculate(input);
  EXPECT_EQ(a.GetResult(), 0.0);

  input = "B(0)";
  a.Calculate(input);
  EXPECT_EQ(a.GetResult(), 0.0);

  input = "C(1)";
  a.Calculate(input);
  EXPECT_EQ(a.GetResult(), 0.0);

  input = "D(0.5)";
  a.Calculate(input);
  EXPECT_EQ(a.GetResult(), 0.5235987755982989);

  input = "E(1)";
  a.Calculate(input);
  EXPECT_EQ(a.GetResult(), 0.7853981633974483);
}

TEST(CalcTest, OtherFunctions) {
  s21::CalcModel a;

  std::string input;

  input = "F(9)";
  a.Calculate(input);
  EXPECT_EQ(a.GetResult(), 3.0);

  input = "G(1)";
  a.Calculate(input);
  EXPECT_EQ(a.GetResult(), 0.0);

  input = "H(1)";
  a.Calculate(input);
  EXPECT_EQ(a.GetResult(), 0.0);
}

// TEST(ControlTest, CreateControl) {
//   s21::CalcModel a;
//   s21::CalcController *control = new s21::CalcController(&a);
//   control->Calculate("1+1");
//   EXPECT_NE(control, nullptr);
//   delete control;
// }

// TEST(ControlTest, ControlExeption) {
//   s21::CalcModel a;
//   s21::CalcController *control = new s21::CalcController(&a);
//   EXPECT_THROW(control->Calculate("+", 0), std::exception);
//   EXPECT_THROW(control->Calculate("9m", 0), std::exception);
//   EXPECT_THROW(control->Calculate("9*", 0), std::exception);
//   EXPECT_THROW(control->Calculate("*+/", 0), std::exception);
//   EXPECT_NE(control, nullptr);
//   delete control;
// }
