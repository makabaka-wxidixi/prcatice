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

   /* ˵����
    * ����ֵ��������Ϊ��һ����̬����Ķ�ά���飬�У����м�����м���int *ָ�룬ָ��һ�����飨�洢�˸ò����н���ֵ�����У�ÿ�����ֵ
    * int ** rslt = ��int *             | int *             | int *           | ...��
    *                  ��                     ��                 ��      ...
    *                 ��int|int|...��       ��int|int|...��    ��int|int|...��
    * returnSize���������ض�λ�������������*returnSize = �м���͸�ֵ��
    * returnColumnSizes����������ÿ����ĸ�������һά�������洢ÿ����������������Ҫ���Ƿ��䣬��������free��
    * �������������������˼�������Ҫ�ں����ڷ���һ�����飺
    * 1��ͨ������ֵ��
    * int *p = f();
    * int *f(void) {
    *    int *a = malloc(sizeof(int)*SIZE);
    *    return a;
    * }
    * 2��ͨ��������
    * int *p = NULL;
    * f(p);
    * void f(int *a) {
    *    a = malloc(sizeof(int)*SIZE);
    * }
    * �������������𣿵�Ȼ���У����ԣ�Ҫͨ������ֵ����һ���ں����ڷ����������Ҫ������
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
    struct TreeNode* queue[NODE_SIZE] = { 0 };                    /* ������ʹ�� */
    struct TreeNode* pNode = NULL;
    int front = 0, rear = 0, pre_rear;
    int i = 0, j = 0;                                           /* i���������У���������j���������У���ÿ��Ľ����� */

    if (!root) {
        *returnSize = 0;
        return NULL;
    }
    queue[rear++] = root;                                       /* �Ȱ�root������ */
    while (front < rear) {                                      /* ���ѭ��������������У����в�Ϊ�վ�ѭ������ */
        pre_rear = rear;                                        /* ������һ��Ķ�-βָ�� */
        rslt = realloc(rslt, (i + 1) * sizeof(int*));            /* ���ѭ��ʵ�ʾ��ǲ�����ÿ������1 */
        rslt[i] = calloc(pre_rear - front, sizeof(int));
        while (front < pre_rear) {                               /* �ڲ�ѭ��������ÿһ���㣬ÿ�γ���һ����㣬ͬʱ���Ѹý��ĺ������ */
            pNode = queue[front++];                             /* ���� */
            rslt[i][j++] = pNode->val;                          /* �洢���ֵ */
            if (pNode->left)                                    /* ��ǰ������Һ��Ӵ������������ */
                queue[rear++] = pNode->left;
            if (pNode->right)
                queue[rear++] = pNode->right;
        }
        columnSize = realloc(columnSize, (i + 1) * sizeof(int));  /* columnSize���������洢ÿ������� */
        columnSize[i++] = j;
        j = 0;
    }

    *returnSize = i;                                            /* ����ע�ͣ�����������������ء����� */
    *returnColumnSizes = columnSize;                            /* ����������������ء�ÿ��Ľ����� */

    return rslt;                                                /* ����ֵ�洢�˱����Ľ���������������������������������Ա�����ߴ�ӡ������̬ */
}