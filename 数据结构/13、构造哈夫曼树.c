typedef struct TreeNode *HuffmanTree;
struct TreeNode{
    int Weight;
    HuffmanTree Left, Right;
}
HuffmanTree Huffman(MinHeap H)
{ /* 假设H->Size个权值已经存在H->Elements[]->Weight里 */
    int i; HuffmanTree T;
    BuildMinHeap(H); /*将H->Elements[]按权值调整为最小堆*/
    for (i = 1; i < H->Size; i++) { /*做H->Size-1次合并*/
        T = malloc(sizeof(struct TreeNode)); /*建立新结点*/
        T->Left = DeleteMin(H);
        /*从最小堆中删除一个结点，作为新T的左子结点*/
        T->Right = DeleteMin(H);
        /*从最小堆中删除一个结点，作为新T的右子结点*/
        T->Weight = T->Left->Weight + T->Right->Weight;
        /*计算新权值*/
        Insert(H, T); /*将新T插入最小堆*/
    }
    T = DeleteMin(H);
    return T;
}