#include <check.h>

#include "../3dmainwindow/parcer.h"

START_TEST(basic_test_1) {
  main_struct obj = {0};
  parser("tests/test.obj", &obj);
  ck_assert_ldouble_eq_tol(0.187828, obj.v->vertex_matrix[0][0], 1e-6);
  ck_assert_ldouble_eq_tol(-0.800000, obj.v->vertex_matrix[0][1], 1e-6);
  ck_assert_ldouble_eq_tol(0.073543, obj.v->vertex_matrix[0][2], 1e-6);

  ck_assert_ldouble_eq_tol(-0.546060, obj.v->vertex_matrix[1][0], 1e-6);
  ck_assert_ldouble_eq_tol(-0.568866, obj.v->vertex_matrix[1][1], 1e-6);
  ck_assert_ldouble_eq_tol(0.351313, obj.v->vertex_matrix[1][2], 1e-6);

  ck_assert_ldouble_eq_tol(-0.091480, obj.v->vertex_matrix[2][0], 1e-6);
  ck_assert_ldouble_eq_tol(-0.046637, obj.v->vertex_matrix[2][1], 1e-6);
  ck_assert_ldouble_eq_tol(-0.034593, obj.v->vertex_matrix[2][2], 1e-6);

  ck_assert_ldouble_eq_tol(0.401537, obj.v->vertex_matrix[3][0], 1e-6);
  ck_assert_ldouble_eq_tol(-0.231646, obj.v->vertex_matrix[3][1], 1e-6);
  ck_assert_ldouble_eq_tol(-0.177578, obj.v->vertex_matrix[3][2], 1e-6);

  ck_assert_ldouble_eq_tol(0.171941, obj.v->vertex_matrix[4][0], 1e-6);
  ck_assert_ldouble_eq_tol(0.257271, obj.v->vertex_matrix[4][1], 1e-6);
  ck_assert_ldouble_eq_tol(-0.231903, obj.v->vertex_matrix[4][2], 1e-6);

  ck_assert_ldouble_eq_tol(0.546060, obj.v->vertex_matrix[5][0], 1e-6);
  ck_assert_ldouble_eq_tol(0.240871, obj.v->vertex_matrix[5][1], 1e-6);
  ck_assert_ldouble_eq_tol(-0.351313, obj.v->vertex_matrix[5][2], 1e-6);

  ck_assert_ldouble_eq_tol(-0.362076, obj.v->vertex_matrix[6][0], 1e-6);
  ck_assert_ldouble_eq_tol(0.349007, obj.v->vertex_matrix[6][1], 1e-6);
  ck_assert_ldouble_eq_tol(-0.044331, obj.v->vertex_matrix[6][2], 1e-6);

  ck_assert_ldouble_eq_tol(0.078155, obj.v->vertex_matrix[7][0], 1e-6);
  ck_assert_ldouble_eq_tol(0.582191, obj.v->vertex_matrix[7][1], 1e-6);
  ck_assert_ldouble_eq_tol(-0.277514, obj.v->vertex_matrix[7][2], 1e-6);

  ck_assert_ldouble_eq_tol(-0.534273, obj.v->vertex_matrix[8][0], 1e-6);
  ck_assert_ldouble_eq_tol(0.800000, obj.v->vertex_matrix[8][1], 1e-6);
  ck_assert_ldouble_eq_tol(-0.106855, obj.v->vertex_matrix[8][2], 1e-6);
  ck_assert_int_eq(7, obj.p[0]->poligon_arr[0]);
  ck_assert_int_eq(2, obj.p[0]->poligon_arr[1]);
  ck_assert_int_eq(7, obj.p[0]->poligon_arr[2]);

  ck_assert_int_eq(0, obj.p[1]->poligon_arr[0]);
  ck_assert_int_eq(4, obj.p[1]->poligon_arr[1]);
  ck_assert_int_eq(5, obj.p[1]->poligon_arr[2]);

  ck_assert_int_eq(1, obj.p[2]->poligon_arr[0]);
  ck_assert_int_eq(5, obj.p[2]->poligon_arr[1]);
  ck_assert_int_eq(2, obj.p[2]->poligon_arr[2]);
  s21_free_matrix(obj.v->vertex_mount, &obj);
  s21_free_poligon(&obj);
}
END_TEST

START_TEST(basic_test_2) {
  main_struct obj = {0};
  ck_assert_int_eq(1, parser("tests/tes.obj", &obj));
  if (obj.v) {
    s21_free_matrix(obj.v->vertex_mount, &obj);
  } else {
    free(obj.v);
  }
  s21_free_poligon(&obj);
}
END_TEST

START_TEST(basic_test_3) {
  main_struct obj = {0};
  parser("tests/test.obj", &obj);
  double rad = M_PI * 5.0 / 180;
  spin(1, rad, &obj);
  ck_assert_ldouble_eq_tol(0.193523, obj.v->vertex_matrix[0][0], 1e-6);
  ck_assert_ldouble_eq_tol(-0.800000, obj.v->vertex_matrix[0][1], 1e-6);
  ck_assert_ldouble_eq_tol(0.056892, obj.v->vertex_matrix[0][2], 1e-6);

  ck_assert_ldouble_eq_tol(-0.513363, obj.v->vertex_matrix[1][0], 1e-6);
  ck_assert_ldouble_eq_tol(-0.568866, obj.v->vertex_matrix[1][1], 1e-6);
  ck_assert_ldouble_eq_tol(0.397569, obj.v->vertex_matrix[1][2], 1e-6);

  ck_assert_ldouble_eq_tol(-0.094147, obj.v->vertex_matrix[2][0], 1e-6);
  ck_assert_ldouble_eq_tol(-0.046637, obj.v->vertex_matrix[2][1], 1e-6);
  ck_assert_ldouble_eq_tol(-0.026489, obj.v->vertex_matrix[2][2], 1e-6);

  ck_assert_ldouble_eq_tol(0.384533, obj.v->vertex_matrix[3][0], 1e-6);
  ck_assert_ldouble_eq_tol(-0.231646, obj.v->vertex_matrix[3][1], 1e-6);
  ck_assert_ldouble_eq_tol(-0.211899, obj.v->vertex_matrix[3][2], 1e-6);

  ck_assert_ldouble_eq_tol(0.151075, obj.v->vertex_matrix[4][0], 1e-6);
  ck_assert_ldouble_eq_tol(0.257271, obj.v->vertex_matrix[4][1], 1e-6);
  ck_assert_ldouble_eq_tol(-0.246006, obj.v->vertex_matrix[4][2], 1e-6);

  ck_assert_ldouble_eq_tol(0.513363, obj.v->vertex_matrix[5][0], 1e-6);
  ck_assert_ldouble_eq_tol(0.240871, obj.v->vertex_matrix[5][1], 1e-6);
  ck_assert_ldouble_eq_tol(-0.397569, obj.v->vertex_matrix[5][2], 1e-6);

  ck_assert_ldouble_eq_tol(-0.364561, obj.v->vertex_matrix[6][0], 1e-6);
  ck_assert_ldouble_eq_tol(0.349007, obj.v->vertex_matrix[6][1], 1e-6);
  ck_assert_ldouble_eq_tol(-0.012605, obj.v->vertex_matrix[6][2], 1e-6);

  ck_assert_ldouble_eq_tol(0.053671, obj.v->vertex_matrix[7][0], 1e-6);
  ck_assert_ldouble_eq_tol(0.582191, obj.v->vertex_matrix[7][1], 1e-6);
  ck_assert_ldouble_eq_tol(-0.283270, obj.v->vertex_matrix[7][2], 1e-6);

  ck_assert_ldouble_eq_tol(-0.541553, obj.v->vertex_matrix[8][0], 1e-6);
  ck_assert_ldouble_eq_tol(0.800000, obj.v->vertex_matrix[8][1], 1e-6);
  ck_assert_ldouble_eq_tol(-0.059883, obj.v->vertex_matrix[8][2], 1e-6);

  spin(2, rad, &obj);
  ck_assert_ldouble_eq_tol(0.193523, obj.v->vertex_matrix[0][0], 1e-6);
  ck_assert_ldouble_eq_tol(-0.791997, obj.v->vertex_matrix[0][1], 1e-6);
  ck_assert_ldouble_eq_tol(0.126401, obj.v->vertex_matrix[0][2], 1e-6);

  ck_assert_ldouble_eq_tol(-0.513363, obj.v->vertex_matrix[1][0], 1e-6);
  ck_assert_ldouble_eq_tol(-0.532051, obj.v->vertex_matrix[1][1], 1e-6);
  ck_assert_ldouble_eq_tol(0.445636, obj.v->vertex_matrix[1][2], 1e-6);

  ck_assert_ldouble_eq_tol(-0.094147, obj.v->vertex_matrix[2][0], 1e-6);
  ck_assert_ldouble_eq_tol(-0.048768, obj.v->vertex_matrix[2][1], 1e-6);
  ck_assert_ldouble_eq_tol(-0.022323, obj.v->vertex_matrix[2][2], 1e-6);

  ck_assert_ldouble_eq_tol(0.384533, obj.v->vertex_matrix[3][0], 1e-6);
  ck_assert_ldouble_eq_tol(-0.249233, obj.v->vertex_matrix[3][1], 1e-6);
  ck_assert_ldouble_eq_tol(-0.190903, obj.v->vertex_matrix[3][2], 1e-6);

  ck_assert_ldouble_eq_tol(0.151075, obj.v->vertex_matrix[4][0], 1e-6);
  ck_assert_ldouble_eq_tol(0.234851, obj.v->vertex_matrix[4][1], 1e-6);
  ck_assert_ldouble_eq_tol(-0.267492, obj.v->vertex_matrix[4][2], 1e-6);

  ck_assert_ldouble_eq_tol(0.513363, obj.v->vertex_matrix[5][0], 1e-6);
  ck_assert_ldouble_eq_tol(0.205304, obj.v->vertex_matrix[5][1], 1e-6);
  ck_assert_ldouble_eq_tol(-0.417049, obj.v->vertex_matrix[5][2], 1e-6);

  ck_assert_ldouble_eq_tol(-0.364561, obj.v->vertex_matrix[6][0], 1e-6);
  ck_assert_ldouble_eq_tol(0.346580, obj.v->vertex_matrix[6][1], 1e-6);
  ck_assert_ldouble_eq_tol(-0.042975, obj.v->vertex_matrix[6][2], 1e-6);

  ck_assert_ldouble_eq_tol(0.053671, obj.v->vertex_matrix[7][0], 1e-6);
  ck_assert_ldouble_eq_tol(0.555287, obj.v->vertex_matrix[7][1], 1e-6);
  ck_assert_ldouble_eq_tol(-0.332933, obj.v->vertex_matrix[7][2], 1e-6);

  ck_assert_ldouble_eq_tol(-0.541553, obj.v->vertex_matrix[8][0], 1e-6);
  ck_assert_ldouble_eq_tol(0.791737, obj.v->vertex_matrix[8][1], 1e-6);
  ck_assert_ldouble_eq_tol(-0.129380, obj.v->vertex_matrix[8][2], 1e-6);
  spin(3, rad, &obj);
  ck_assert_ldouble_eq_tol(0.123760, obj.v->vertex_matrix[0][0], 1e-6);
  ck_assert_ldouble_eq_tol(-0.805850, obj.v->vertex_matrix[0][1], 1e-6);
  ck_assert_ldouble_eq_tol(0.126401, obj.v->vertex_matrix[0][2], 1e-6);

  ck_assert_ldouble_eq_tol(-0.557781, obj.v->vertex_matrix[1][0], 1e-6);
  ck_assert_ldouble_eq_tol(-0.485284, obj.v->vertex_matrix[1][1], 1e-6);
  ck_assert_ldouble_eq_tol(0.445636, obj.v->vertex_matrix[1][2], 1e-6);

  ck_assert_ldouble_eq_tol(-0.098039, obj.v->vertex_matrix[2][0], 1e-6);
  ck_assert_ldouble_eq_tol(-0.040377, obj.v->vertex_matrix[2][1], 1e-6);
  ck_assert_ldouble_eq_tol(-0.022323, obj.v->vertex_matrix[2][2], 1e-6);

  ck_assert_ldouble_eq_tol(0.361347, obj.v->vertex_matrix[3][0], 1e-6);
  ck_assert_ldouble_eq_tol(-0.281799, obj.v->vertex_matrix[3][1], 1e-6);
  ck_assert_ldouble_eq_tol(-0.190903, obj.v->vertex_matrix[3][2], 1e-6);

  ck_assert_ldouble_eq_tol(0.170969, obj.v->vertex_matrix[4][0], 1e-6);
  ck_assert_ldouble_eq_tol(0.220790, obj.v->vertex_matrix[4][1], 1e-6);
  ck_assert_ldouble_eq_tol(-0.267492, obj.v->vertex_matrix[4][2], 1e-6);

  ck_assert_ldouble_eq_tol(0.529303, obj.v->vertex_matrix[5][0], 1e-6);
  ck_assert_ldouble_eq_tol(0.159780, obj.v->vertex_matrix[5][1], 1e-6);
  ck_assert_ldouble_eq_tol(-0.417049, obj.v->vertex_matrix[5][2], 1e-6);

  ck_assert_ldouble_eq_tol(-0.332968, obj.v->vertex_matrix[6][0], 1e-6);
  ck_assert_ldouble_eq_tol(0.377035, obj.v->vertex_matrix[6][1], 1e-6);
  ck_assert_ldouble_eq_tol(-0.042975, obj.v->vertex_matrix[6][2], 1e-6);

  ck_assert_ldouble_eq_tol(0.101863, obj.v->vertex_matrix[7][0], 1e-6);
  ck_assert_ldouble_eq_tol(0.548496, obj.v->vertex_matrix[7][1], 1e-6);
  ck_assert_ldouble_eq_tol(-0.332933, obj.v->vertex_matrix[7][2], 1e-6);

  ck_assert_ldouble_eq_tol(-0.470488, obj.v->vertex_matrix[8][0], 1e-6);
  ck_assert_ldouble_eq_tol(0.835923, obj.v->vertex_matrix[8][1], 1e-6);
  ck_assert_ldouble_eq_tol(-0.129380, obj.v->vertex_matrix[8][2], 1e-6);
  s21_free_matrix(obj.v->vertex_mount, &obj);
  s21_free_poligon(&obj);
}
END_TEST

int main() {
  Suite *s1 = suite_create("3d_tests");
  TCase *tc1_1 = tcase_create("3d_tests ");
  SRunner *sr = srunner_create(s1);
  int result;
  suite_add_tcase(s1, tc1_1);

  tcase_add_test(tc1_1, basic_test_1);
  tcase_add_test(tc1_1, basic_test_2);
  tcase_add_test(tc1_1, basic_test_3);
  srunner_run_all(sr, CK_ENV);
  result = srunner_ntests_failed(sr);
  srunner_free(sr);
  return result == 0 ? 0 : 1;
}
