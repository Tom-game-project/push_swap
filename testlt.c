#include "src/strnumtools/strnumtools.h"
#include "src/input_checker/input_checker.h"
#include <stdio.h>

int main(int argc, char *a[]){
    if (argc == 3){
        if (is_valid_all(argc, a)){
            printf("lt %d\n",lt(a[1],a[2]));
        }else {
            printf("wrong args (0)\n");
        }
    }else {
        printf("wrong args (1)\n");
    }
    return (0);
}