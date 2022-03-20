add_library(algorithms
        algorithms/algorithms.c
        )
add_library(sortArray
        sortArray/sortArray.c
        )
target_link_libraries(sortArray algorithms)