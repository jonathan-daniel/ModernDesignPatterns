cmake_minimum_required (VERSION 2.6)
set (CMAKE_CXX_STANDARD 17)
project (ModernDesignPatterns)

set(PATTERNS
    StrategyPattern
    ObserverPattern
    SingletonPattern
    FactoryPattern
)

macro(add_pattern PATTERN)
    include_directories(${PATTERN})
    file(GLOB_RECURSE PATTERN_FILES "${PATTERN}/*.cpp")
    add_executable(${PATTERN} ${PATTERN_FILES})
endmacro(add_pattern)

foreach(PATTERN IN LISTS PATTERNS)
    message(STATUS "Compiling Pattern: ${PATTERN}")
    add_pattern(${PATTERN})
endforeach(PATTERN)