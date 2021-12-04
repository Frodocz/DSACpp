include_directories(.)

set(VECTOR_SRC
        Vector.h
        Vector_Implementation.h
        Vector_Operators.h
        Vector_CopyFrom.h
        Vector_Bubblesort.h
        Vector_Selectionsort.h
        Vector_Insertionsort.h
        Vector_Sort.h
        Vector_Search_Binary.h
        main.cpp)

add_executable(vector ${VECTOR_SRC})