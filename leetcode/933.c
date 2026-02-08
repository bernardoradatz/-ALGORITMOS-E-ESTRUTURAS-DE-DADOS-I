
typedef struct {
    int *queue;
    int head;
    int tail;
    int capacity;
} RecentCounter;

RecentCounter* recentCounterCreate() {
    RecentCounter* obj = (RecentCounter*)malloc(sizeof(RecentCounter));
    obj->capacity = 10000; 
    obj->queue = (int*)malloc(sizeof(int) * obj->capacity);
    obj->head = 0;
    obj->tail = 0;
    return obj;
}

int recentCounterPing(RecentCounter* obj, int t) {
    obj->queue[obj->tail] = t;
    obj->tail++;

    while (obj->queue[obj->head] < t - 3000) {
        obj->head++;
    }

    return obj->tail - obj->head;
}

void recentCounterFree(RecentCounter* obj) {
    free(obj->queue);
    free(obj);
}

/**
 * Your RecentCounter struct will be instantiated and called as such:
 * RecentCounter* obj = recentCounterCreate();
 * int param_1 = recentCounterPing(obj, t);
 * recentCounterFree(obj);
 */