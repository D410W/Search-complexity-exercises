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


    # Linkar com a biblioteca principal
    target_link_libraries(${EXECUTABLE_NAME} PRIVATE ${LIB_NAME})
    target_include_directories(${EXECUTABLE_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/math_lib)

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

add_custom_test("Testing sum #01" t_01 test_01.cpp)
add_custom_test("Testing sum #02" t_02 test_02.cpp)
add_custom_test("Testing exp #01" t_03 test_03.cpp)


