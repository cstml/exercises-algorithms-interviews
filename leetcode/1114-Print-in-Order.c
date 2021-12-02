typedef struct {
    int state;
} Foo;

// Initialize user defined data here.
Foo* fooCreate() {
    Foo* obj = (Foo*) malloc(sizeof(Foo));
    obj -> state = 0;
    return obj;
}

void first(Foo* obj) {
        printFirst();
        obj -> state++;
}

void second(Foo* obj) {
    while (obj -> state < 1){}
    printSecond();
    obj -> state++;
}

void third(Foo* obj) {
    while (obj -> state < 2){}
    printThird();
}

// User defined data may be cleaned up here.
void fooFree(Foo* obj) {    
    free(obj);
}
