/*
 * testFactorial.c

 *
 *  Created on: 20 Apr 2017
 *      Author: liliana
 */

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <string.h>
#include "factorial.h"

void factorial_testcase1(void){
	CU_ASSERT_EQUAL(factorial(0),1 );
	CU_ASSERT_EQUAL(factorial(1),1 );
	CU_ASSERT_EQUAL(factorial(4),24 );
	/* insert here 2 assertions necessary
	* to verify whether the factorial of 1 is 1
	* and whether the factorial of 4 is 24
	*/
}

void runAllTests(){
	CU_initialize_registry();
	CU_pSuite suite = CU_add_suite("factorial_suite", 0, 0);

	CU_add_test(suite, "factorial_test", factorial_testcase1);

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
}

int main() {
    runAllTests();

    return 0;
}


