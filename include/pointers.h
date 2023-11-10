typedef struct Element_ {
    int data;
    struct Element_* next;
} Element;

void get_pointer_value(int* iptr);
int* alloc_single_pointer();
int* create_dangling_pointer();

void linked_list();