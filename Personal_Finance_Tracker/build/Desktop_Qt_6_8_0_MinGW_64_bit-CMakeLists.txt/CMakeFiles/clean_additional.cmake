# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Personal_Finance_Tracker_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Personal_Finance_Tracker_autogen.dir\\ParseCache.txt"
  "Personal_Finance_Tracker_autogen"
  )
endif()
