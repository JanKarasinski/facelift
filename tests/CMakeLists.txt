configure_file(test-driver.sh.in test-driver.sh @ONLY)


if (CMAKE_CONFIGURATION_TYPES)
    add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} --force-new-ctest-process --output-on-failure
                      --build-config "$<CONFIGURATION>")
else()
    add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} --force-new-ctest-process --output-on-failure)
endif()


add_subdirectory(manual)

add_subdirectory(combined)
add_test(NAME combined-local-cpp COMMAND test-driver.sh combined/tst_combined_local.qml cpp)
add_test(NAME combined-local-qml COMMAND test-driver.sh combined/tst_combined_local.qml qml)
add_test(NAME combined-local-singleton-cpp COMMAND test-driver.sh combined/tst_combined_local_singleton.qml cpp)
add_test(NAME combined-local-singleton-qml COMMAND test-driver.sh combined/tst_combined_local_singleton.qml qml)
add_test(NAME combined-inprocess-cpp COMMAND test-driver.sh combined/tst_combined_inprocess.qml cpp)
add_test(NAME combined-inprocess-qml COMMAND test-driver.sh combined/tst_combined_inprocess.qml qml)
add_test(NAME combined-inprocess-singleton-cpp COMMAND test-driver.sh combined/tst_combined_inprocess_singleton.qml cpp)
add_test(NAME combined-inprocess-singleton-qml COMMAND test-driver.sh combined/tst_combined_inprocess_singleton.qml qml)
if (FACELIFT_DBUS_IPC_ENABLED)
add_test(NAME combined-ipc-cpp COMMAND test-driver.sh combined/tst_combined_ipc.qml cpp combined/combined-server.qml)
add_test(NAME combined-ipc-qml COMMAND test-driver.sh combined/tst_combined_ipc.qml qml combined/combined-server.qml)
add_test(NAME combined-ipc-singleton-cpp COMMAND test-driver.sh combined/tst_combined_ipc_singleton.qml cpp
         combined/combined-server-singleton.qml)
add_test(NAME combined-ipc-singleton-qml COMMAND test-driver.sh combined/tst_combined_ipc_singleton.qml qml
         combined/combined-server-singleton.qml)
endif()

add_subdirectory(models)
add_test(NAME models-local-cpp COMMAND test-driver.sh models/tst_models_local.qml cpp)
add_test(NAME models-inprocess-cpp COMMAND test-driver.sh models/tst_models_inprocess.qml cpp)
if (FACELIFT_DBUS_IPC_ENABLED)
add_test(NAME models-ipc-cpp COMMAND test-driver.sh models/tst_models_ipc.qml cpp models/models-server.qml)
endif()

add_subdirectory(asyncfunctions)
add_test(NAME asyncfunctions-local-cpp COMMAND test-driver.sh asyncfunctions/tst_asyncfunctions_local.qml cpp)
add_test(NAME asyncfunctions-inprocess-cpp COMMAND test-driver.sh asyncfunctions/tst_asyncfunctions_inprocess.qml cpp)
if (FACELIFT_DBUS_IPC_ENABLED)
add_test(NAME asyncfunctions-ipc-cpp COMMAND test-driver.sh asyncfunctions/tst_asyncfunctions_ipc.qml cpp asyncfunctions/asyncfunctions-server.qml)
endif()
