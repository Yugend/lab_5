#ifdef __linux__
    #include <dlfcn.h>

    #define LOAD_LIB(arg) dlopen (arg , RTLD_LAZY)
    #define GET_FUNC dlsym
    #define LIB_CAST
    #define FREE_LIBRARY dlclose
#endif

#include <stdio.h>
#include <stdlib.h>

void* load_lib(const char* const lib_name){
    void* lib;
    lib = LOAD_LIB(lib_name);
    if(!lib){
        printf("cannot open library '%s'\n", lib_name);
        return NULL;
    }
    return lib;
}

int main()
{
    //����������� ������� � �������
    int size_arr = 12;
    int length1 = 4;
    int length2 = 6;

    void* lib;
    int* obj;
    char choise, flag = 1;
    printf("Choose what you want to use\n1. Array\n2. Matrix\n3/ Quit\n");
    while(flag){
        scanf("%c", &choise);
        if(choise == '1'){
            lib = load_lib("libarray.dll");
            obj = ((int* (*)(int)) GET_FUNC(LIB_CAST lib, "create_array"))(size_arr);
            ((int* (*)(int*, int)) GET_FUNC(LIB_CAST lib, "init_array"))(obj, size_arr);
            ((void (*)(int*, int))GET_FUNC(LIB_CAST lib, "print_array"))(obj, size_arr);
            printf("sum of the maximum negative elements in the array: ");
            printf("%d\n", ((int (*)(int*, int))GET_FUNC(LIB_CAST lib, "sum_max_arr"))(obj, size_arr));
            flag = 0;
        }
        else if(choise == '2'){
            lib = load_lib("libmatrix.dll");
            obj = ((int* (*)(int, int)) GET_FUNC(LIB_CAST lib, "create_matrix"))(length1, length2);
            ((int* (*)(int*, int, int)) GET_FUNC(LIB_CAST lib, "init_matrix"))(obj, length1, length2);
            ((void (*)(int*, int, int))GET_FUNC(LIB_CAST lib, "print_matrix"))(obj, length1, length2);
            printf("sum of the maximum negative elements in the matrix: ");
            printf("%d\n", ((int (*)(int*, int, int))GET_FUNC(LIB_CAST lib, "sum_max_matr"))(obj, length1, length2));
            flag = 0;
        }
        else if(choise == '3'){
            free(obj);
            FREE_LIBRARY(LIB_CAST lib);
            return 0;
        }
    }
    free(obj);
    FREE_LIBRARY(LIB_CAST lib);
    return 0;
}
