###############################################################################
# MACRO: pump_files
#
# Entrada: ficheros PUMP
# Salida: 
#
# Nota: Los ficheros generados se generan en el directorio 
#       ${CMAKE_CURRENT_SOURCE_DIRECTORY}
#
# Nota: Ejemplo de uso:
#
###############################################################################

if(NOT EXISTS PUMP_SCRIPT OR PUMP_SCRIPT STREQUAL "")
  set(PUMP_SCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/scripts/pump.py)
endif()

macro(pump_files)
  foreach(_in_FILE ${ARGN})

    GET_FILENAME_COMPONENT(_out_FILE ${_in_FILE} NAME_WE)
    GET_FILENAME_COMPONENT(_in_FULLEXT ${_in_FILE} EXT)
    string(REPLACE ".pump" "" _out_EXT ${_in_FULLEXT})
    GET_FILENAME_COMPONENT(_in_PATH ${_in_FILE} PATH)

    set(out_FILE ${CMAKE_CURRENT_SOURCE_DIR}/${_out_FILE}${_out_EXT})

    message(STATUS "${out_FILE} will be generated from ${_in_FILE}")

    add_custom_command(
      OUTPUT ${out_FILE}
      DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${_in_FILE}
      COMMAND ${PUMP_SCRIPT} ${CMAKE_CURRENT_SOURCE_DIR}/${_in_FILE})

    set(pump_generated_files ${pump_generated_files} ${out_FILE})

  endforeach()
endmacro()

