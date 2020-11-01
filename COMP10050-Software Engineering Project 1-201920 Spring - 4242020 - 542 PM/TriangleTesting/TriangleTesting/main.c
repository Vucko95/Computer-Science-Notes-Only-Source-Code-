#include <stdio.h>

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.c
 * Author: lpasqua
 *
 * Created on 26 April 2019, 08:07
 */

#include <stdio.h>
#include <stdlib.h>
#include "CUnit.h"
#include "Basic.h"
#include "triangle.h"

/*
 *
 */
void triangle_testcase1(void){
    CU_ASSERT(strcmp("Equilateral", checkTriangle(60,60,60)) == 0);
    CU_ASSERT_STRING_EQUAL("Right", checkTriangle(40,90,50));
    CU_ASSERT_STRING_NOT_EQUAL("Isosceles", checkTriangle(80,80,50));
}

void runAllTests(){
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("triangle_suite", 0, 0);
    CU_add_test(suite, "triangle_test", triangle_testcase1);
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
}

int main() {
    runAllTests();
    return 0;
}


