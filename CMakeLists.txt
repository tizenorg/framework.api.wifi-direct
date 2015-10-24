CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(wifi-direct C)

#SET(PREFIX $(CMAKE_INSTALL_PREFIX))
SET(prefix "/usr")
SET(EXEC_PREFIX "\${prefix}")
SET(LIBDIR "\${prefix}/lib")
SET(INCLUDEDIR "\${prefix}/include")

SET(dependents "capi-base-common")
SET(pc_dependents "capi-base-common")

ADD_SUBDIRECTORY(src)
#ADD_SUBDIRECTORY(test)
