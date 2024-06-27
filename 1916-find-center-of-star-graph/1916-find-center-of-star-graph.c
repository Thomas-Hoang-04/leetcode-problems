int findCenter(int** edges, int edgesSize, int* edgesColSize) {
    if (**edges == **(edges + 1) || **edges == *(*(edges + 1) + 1)) return **edges;
    else return *(*edges + 1);
}