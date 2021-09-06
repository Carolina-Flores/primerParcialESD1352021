/*
 * File:   newcunittest.c
 * Author: Carito Flores
 *
 * Created on 6 sep. 2021, 15:13:30
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>

/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

void leer_archivo_csv(char ubicacion[]);

void testLeer_archivo_csv() {
    char* ubicacion;
    leer_archivo_csv(ubicacion);
    if (1 /*check result*/) {
        CU_ASSERT(1);
    }
}

void generar_matriz();

void testGenerar_matriz() {
    generar_matriz();
    if (1 /*check result*/) {
        CU_ASSERT(1);
    }
}

void transponer_matrices();

void testTransponer_matrices() {
    transponer_matrices();
    if (1 /*check result*/) {
        CU_ASSERT(1);
    }
}

void multiplicar_matrices();

void testMultiplicar_matrices() {
    multiplicar_matrices();
    if (1 /*check result*/) {
        CU_ASSERT(1);
    }
}

const char* integrantes();

void testIntegrantes() {
    const char* result = integrantes();
    if (1 /*check result*/) {
        CU_ASSERT(1);
    }
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("newcunittest", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testLeer_archivo_csv", testLeer_archivo_csv)) ||
            (NULL == CU_add_test(pSuite, "testGenerar_matriz", testGenerar_matriz)) ||
            (NULL == CU_add_test(pSuite, "testTransponer_matrices", testTransponer_matrices)) ||
            (NULL == CU_add_test(pSuite, "testMultiplicar_matrices", testMultiplicar_matrices)) ||
            (NULL == CU_add_test(pSuite, "testIntegrantes", testIntegrantes))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
