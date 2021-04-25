#include <stdlib.h>
#include <stdio.h>

struct List {
    int data[20];
    int len;
};

struct List *map(struct List *list, int (*func)(int)) {
    struct List *newList = malloc(sizeof(struct List));
    newList-> len = list->len;
    for(int i=0;i<newList->len;i++) {
        int oldData = *(list->data + i);
        int newData = func(oldData);
        *(newList->data + i) = newData;
    }
    return newList;
}


struct List *filter(struct List *list, int (*func)(int)) {
    int newSize = 0;
    for(int i=0;i<list->len;i++) {
        int data = *(list->data + i);
        int include = func(data);
        if(include) {
            newSize++;
        }
    }
    struct List *newList = malloc(sizeof(struct List));
    newList-> len = newSize;
    int j=0;
    for(int i=0;i<list->len;i++) {
        int oldData = *(list->data + i);
        int include = func(oldData);
        if(include) {
            *(newList->data + j) = oldData;
            j++;
        }

    }
    return newList;
}

int increment(int a) {
    return a+1;
}

int positive(int a) {
    return a > 0;
}

int main(int argc, char** argv) {
    struct List list;
    printf("Enter the length of the list: ");
    scanf("%d",&list.len);
    if(list.len > 20) {
        printf("Too long!\n");
        exit(1);
    }
    for(int i=0;i<list.len;i++) {
        printf("Enter element %d: ",i);
        scanf("%d", (list.data + i));
    }
    printf("Your list is: ");
    for(int i=0;i<list.len;i++) {
        printf("%d ", *(list.data + i));
    }
    printf("\n");
    printf("Pick a parameter:\n");
    printf("Increment: %p\n",increment);
    printf("Positive: %p\n",positive);
    printf("Abs: %p\n",abs);
    int (*param)(int);
    scanf("%lx", &param);

    printf("Pick a function:\n");
    printf("Map: %p\n",map);
    printf("Filter: %p\n",filter);
    struct List *(*func_ptr)(struct List *, void*);
    scanf("%lx", &func_ptr);

    struct List newList = *func_ptr(&list,param);
    printf("Your list is: ");
    for(int i=0;i<newList.len;i++) {
        printf("%d ", *(newList.data + i));
    }
    printf("\n");
    return 0;
}

//gcc func.c -o func
