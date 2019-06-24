set(FIND_SUGGESTLIB_PATHS
        ~/Library/Frameworks/suggestLib)

find_path(SUGGESTLIB_INCLUDE_DIR suggestLib.h
        PATH_SUFFIXES include
        PATHS ${FIND_SUGGESTLIB_PATHS})

FIND_LIBRARY(SUGGESTLIB_LIBRARY
        NAMES libsuggestLib.a
        PATH_SUFFIXES lib
        PATHS ${FIND_SUGGESTLIB_PATHS})