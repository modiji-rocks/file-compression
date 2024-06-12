// Structure to store codes in compressed file
typedef struct code {
    char k;
    int l;
    int code_arr[16];
    struct code* p;
} code;

// Function to print codes into file
void printCodesIntoFile(int fd2, struct Node* root,
                        int t[], int top = 0)
{
    int i;
    if (root->l) {
        t[top] = 0;
        printCodesIntoFile(fd2, root->l, t, top + 1);
    }

    if (root->r) {
        t[top] = 1;
        printCodesIntoFile(fd2, root->r, t, top + 1);
    }

    if (isLeaf(root)) {
        data = (code*)malloc(sizeof(code));
        tree = (Tree*)malloc(sizeof(Tree));
        data->p = NULL;
        data->k = root->character;
        tree->g = root->character;
        write(fd2, &tree->g, sizeof(char));
        for (i = 0; i < top; i++) {
            data->code_arr[i] = t[i];
        }
        tree->len = top;
        write(fd2, &tree->len, sizeof(int));
        tree->dec
            = convertBinaryToDecimal(data->code_arr, top);
        write(fd2, &tree->dec, sizeof(int));
        data->l = top;
        data->p = NULL;
        if (k == 0) {
            front = rear = data;
            k++;
        }
        else {
            rear->p = data;
            rear = rear->p;
        }
    }
}
