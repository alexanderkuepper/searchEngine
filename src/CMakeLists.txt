project(SearchEngine)

set(HEADER_FILES
        TrieNode.h
        )

set(SOURCE_FILES
        TrieNode.cpp

)

add_library(DateConverter_lib STATIC ${SOURCE_FILES} ${HEADER_FILES})