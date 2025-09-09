# [1] This function set properties for a test passed as argument.

set (passRegex "^Test passed" "^All ok")

function(add_custom_test TEST_NAME EXECUTABLE_NAME TEST_SOURCE)
    # Criar o executável do teste
    add_executable(${EXECUTABLE_NAME} ${TEST_SOURCE})

    # Configurar propriedades padrão
    set_target_properties(${EXECUTABLE_NAME} PROPERTIES
        CXX_STANDARD 17
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests
    )


    # Linkar com o arquivo .hpp    
    target_include_directories(${EXECUTABLE_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src )

    # Registrar o teste no CTest com o nome desejado
    add_test(NAME "${TEST_NAME}" COMMAND $<TARGET_FILE:${EXECUTABLE_NAME}>)
    # =================================================================
    # Invert the outcome: 1 -> Ok, 0 -> Failed
    # -----------------------------------------------------------------
    # set_property(TEST "${TEST_NAME}" PROPERTY WILL_FAIL TRUE)
    # =================================================================

    # =================================================================
    # Program must return either "All ok" or "Test passed" to pass.
    # -----------------------------------------------------------------
    set_property (TEST "${TEST_NAME}" 
                  PROPERTY PASS_REGULAR_EXPRESSION "${passRegex}")
    # =================================================================
endfunction()

# [2] Define list of tests to perform

add_custom_test("Testing local_min middle #01" t_01 test_01_ml.cpp)
add_custom_test("Testing local_min right #02" t_02 test_02_ml.cpp)
add_custom_test("Testing local_min left #03" t_03 test_03_ml.cpp)

add_custom_test("Testing local_min_matrix top_left #01" t_04 test_04_mml.cpp)
add_custom_test("Testing local_min_matrix top_right #02" t_05 test_05_mml.cpp)
add_custom_test("Testing local_min_matrix center #03" t_06 test_06_mml.cpp)
add_custom_test("Testing local_min_matrix bottom_left #04" t_07 test_07_mml.cpp)
add_custom_test("Testing local_min_matrix bottom_right #05" t_08 test_08_mml.cpp)

add_custom_test("Testing bitonic_search right #01" t_09 test_09_bts.cpp)
add_custom_test("Testing bitonic_search left #02" t_10 test_10_bts.cpp)
add_custom_test("Testing bitonic_search middle #03" t_11 test_11_bts.cpp)
add_custom_test("Testing bitonic_search empty_array #04" t_12 test_12_bts.cpp)
add_custom_test("Testing bitonic_search missing #05" t_13 test_13_bts.cpp)
add_custom_test("Testing bitonic_search only_crescent #06" t_14 test_14_bts.cpp)
add_custom_test("Testing bitonic_search only_decrescent #07" t_15 test_15_bts.cpp)

add_custom_test("Testing bin_search_dupl left #01" t_16 test_16_bsd.cpp)
add_custom_test("Testing bin_search_dupl right #02" t_17 test_17_bsd.cpp)
add_custom_test("Testing bin_search_dupl middle #03" t_18 test_18_bsd.cpp)
add_custom_test("Testing bin_search_dupl empty_array #04" t_19 test_19_bsd.cpp)
add_custom_test("Testing bin_search_dupl missing #05" t_20 test_20_bsd.cpp)

add_custom_test("Testing flr_ceil_range middle #01" t_21 test_21_fcr.cpp)
add_custom_test("Testing flr_ceil_range left #02" t_22 test_22_fcr.cpp)
add_custom_test("Testing flr_ceil_range right #03" t_23 test_23_fcr.cpp)
add_custom_test("Testing flr_ceil_range target_present #04" t_24 test_24_fcr.cpp)

add_custom_test("Testing identity target_present_left #01" t_25 test_25_id.cpp)
add_custom_test("Testing identity target_present_right #02" t_26 test_26_id.cpp)
add_custom_test("Testing identity target_not_present #03" t_27 test_27_id.cpp)

add_custom_test("Testing duplicate has_dup #01" t_28 test_28_dup.cpp)
add_custom_test("Testing duplicate doesnt_have_dup #02" t_29 test_29_dup.cpp)

