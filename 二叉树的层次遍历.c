/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 /**
  * Definition for a binary tree node.
  * struct TreeNode {
  *     int val;
  *     struct TreeNode *left;
  *     struct TreeNode *right;
  * };
  */


  /**
   * Return an array of arrays of size *returnSize.
   * The sizes of the arrays are returned as *returnColumnSizes array.
   * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
   */

   /* 说明：
    * 返回值：可以认为是一个动态分配的二维数组，行：树有几层就有几个int *指针，指向一个数组（存储了该层所有结点的值），列：每层结点的值
    * int ** rslt = 【int *             | int *             | int *           | ...】
    *                  ↓                     ↓                 ↓      ...
    *                 【int|int|...】       【int|int|...】    【int|int|...】
    * returnSize：用来返回二位数组的行树，即*returnSize = 有几层就赋值几
    * returnColumnSizes：用来返回每层结点的个数，用一维数组来存储每层结点个数，这个数组要我们分配，调用者来free。
    * 不懂这个参数可以这样思考，如何要在函数内返回一个数组：
    * 1、通过返回值：
    * int *p = f();
    * int *f(void) {
    *    int *a = malloc(sizeof(int)*SIZE);
    *    return a;
    * }
    * 2、通过参数：
    * int *p = NULL;
    * f(p);
    * void f(int *a) {
    *    a = malloc(sizeof(int)*SIZE);
    * }
    * 上面这样可以吗？当然不行，所以，要通过返回值返回一个在函数内分配的数组需要这样：
    * int *p = NULL;
    * f(&p);
    * void f(int **a) {
    *    *a = malloc(sizeof(int)*SIZE);
    * }
    */
#define NODE_SIZE 10000.
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    int** rslt = NULL;
    int* columnSize = NULL;
    struct TreeNode* queue[NODE_SIZE] = { 0 };                    /* 做队列使用 */
    struct TreeNode* pNode = NULL;
    int front = 0, rear = 0, pre_rear;
    int i = 0, j = 0;                                           /* i用来索引行，即层数，j用来索引列，即每层的结点个数 */

    if (!root) {
        *returnSize = 0;
        return NULL;
    }
    queue[rear++] = root;                                       /* 先把root结点入队 */
    while (front < rear) {                                      /* 外层循环：用来处理队列，队列不为空就循环处理 */
        pre_rear = rear;                                        /* 备份上一层的队-尾指针 */
        rslt = realloc(rslt, (i + 1) * sizeof(int*));            /* 外层循环实际就是层数，每次扩充1 */
        rslt[i] = calloc(pre_rear - front, sizeof(int));
        while (front < pre_rear) {                               /* 内层循环：遍历每一层结点，每次出队一个结点，同时并把该结点的孩子入队 */
            pNode = queue[front++];                             /* 出队 */
            rslt[i][j++] = pNode->val;                          /* 存储结点值 */
            if (pNode->left)                                    /* 当前结点左、右孩子存在则将他们入队 */
                queue[rear++] = pNode->left;
            if (pNode->right)
                queue[rear++] = pNode->right;
        }
        columnSize = realloc(columnSize, (i + 1) * sizeof(int));  /* columnSize数组用来存储每层结点个数 */
        columnSize[i++] = j;
        j = 0;
    }

    *returnSize = i;                                            /* 如上注释，这个参数用来“带回”层数 */
    *returnColumnSizes = columnSize;                            /* 这个参数用来“带回”每层的结点个数 */

    return rslt;                                                /* 返回值存储了遍历的结果，上面两个参数用来描述这个结果，以便调用者打印树的形态 */
}