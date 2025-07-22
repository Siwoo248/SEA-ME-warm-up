# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\phone_book_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\phone_book_autogen.dir\\ParseCache.txt"
  "phone_book_autogen"
  )
endif()
