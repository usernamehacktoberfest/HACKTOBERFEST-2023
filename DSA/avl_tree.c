#include <stdio.h>
#include <malloc.h>

struct node {
    int data;
    struct node * left;
    struct node * right;
    int balance_factor;
};

typedef struct node node;

int height(node * root){
    if (root == NULL){
        return 0;
    }else{
        int left = height(root->left);
        int right = height(root->right);
        if (left > right){
            return left + 1;
        }else{
            return right + 1;
        }
    }
}

int balance_factor(node * root){
    return height(root->left) - height(root->right);
}

void inorder(node * root){
    if (root != NULL){
        inorder(root->left);
        printf("%d %d\n", root->data, balance_factor(root));
        inorder(root->right);
    }
}


node * LL_rotation(node * root){
    node * temp = root->left->right;
    node * newroot = root->left;
    newroot->right = root;
    root->left = temp;
    return newroot;
}

node * RR_rotation(node * root){
    node * temp = root->right->left;
    node * newroot = root->right;
    newroot->left = root;
    root->right = temp;
    return newroot;
}

node * LR_rotation(node * root){
    node * newroot = root->left->right;
    node * right = newroot->right;
    node * left = newroot->left;
    newroot->right = root;
    newroot->left = root->left;
    root->left = right;
    newroot->left->right = left;
    return newroot;
}

node * RL_rotation(node * root){
    node * newroot = root->right->left;
    node * right = newroot->right;
    node * left = newroot->left;
    newroot->left = root;
    newroot->right = root->right;
    root->right = left;
    newroot->right->left = right;
    return newroot;
}

node * right_inorder(node * root){
    if (root->left){
        node * p = root->left;
        printf("hi");
        while(p->right){
            p = p->right;
        }
        return p;
    }else{
        return NULL;
    }
}

node * deletion(node * root, int x){
    if (root != NULL){
        if (x > root->data){
            root->right = deletion(root->right, x);   
        }else if(x < root->data){
            root->left = deletion(root->left, x);
        }else{
            if (root->left == NULL && root->right == NULL){
                free(root);
                root = NULL;
            }else if(root->left != NULL && root->right != NULL){
                node * imp = right_inorder(root);
                printf("%d", imp->data);
                root->data = imp->data;
                root->left = deletion(root->left, imp->data);       
            }else{
                if (root->right != NULL){
                    node * temp = root->right;
                    free(root);
                    root = temp;
                }else{
                    node * temp = root->left;
                    free(root);
                    root = temp;
                }
            }
        }
        if (root){
            int bfactor = balance_factor(root);
            if (bfactor >=2 || bfactor <= -2){
                if (bfactor == 2 && balance_factor(root->left) == 1){
                    printf("ele: %d ", bfactor);
                    root = LL_rotation(root);
                }else if(bfactor == 2 && balance_factor(root->left) == -1){
                    root = LR_rotation(root);
                    printf("ele: %d ", bfactor);
                }else if(bfactor == -2 && balance_factor(root->right) == -1){
                    root = RR_rotation(root);
                    printf("ele: %d ", bfactor);
                }else if(bfactor == -2 && balance_factor(root->right) == 1){
                    root = RL_rotation(root);
                    printf("ele: %d ", bfactor);
                }else if(bfactor == -2 && balance_factor(root->right) == 0){
                    root = RR_rotation(root);
                }else if(bfactor == 2 && balance_factor(root->left) == 0){
                    root = LL_rotation(root);
                }
            }
        }   

        return root;
    }
}


node * insert(node * root, int x)
{
    if (root != NULL)
    {
        int flag;
        if (x > root->data){
            root->right = insert(root->right, x);
            flag = 1;
        }else{
            root->left = insert(root->left, x);
            flag = 2;
        }

        int bfactor = bf(root);
        int r = 0;

        if (bfactor >= 2 || bfactor <= -2){
            if (flag == 2)
            {
                int temp = bf(root->left);
                if (temp == 1)
                {
                    r = 1;
                }
                else if(temp == -1)
                {
                    r = 2;
                }
            }

            else
            {
                int temp = bf(root->right);
                if (temp == -1)
                {
                    r = 3;
                }
                else if(temp == 1)
                {
                    r = 4;
                }
            }
        }

        if (r==1) {
            root=LLRotation(root);
            printf("LL Rotation has occurred, while inserting node with key %d!!\n", x);
        }
        else if (r==2) {
            root=LRRotation(root);
            printf("LR Rotation has occurred, while inserting node with key %d!!\n", x);
        }
        else if (r==3) {
            root=RRRotation(root);
            printf("RR Rotation has occurred, while inserting node with key %d!!\n", x);
        }
        else if (r==4) {
            root=RLRotation(root);
            printf("RL Rotation has occurred, while inserting node with key %d!!\n", x);
        }
        else {}

        return root;


    }
    else
    {
        node * n = (node *)malloc(sizeof(node));
        n->left = NULL;
        n->right = NULL;
        n->data = x;
        return n;
    }
}

int main(){
    node * root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 25);
    root = insert(root, 28);
    root = insert(root, 27);
    root = insert(root, 5);
    inorder(root);
    printf("\n");
    root = deletion(root, 5);
    inorder(root);
    printf("\n");
    root = deletion(root, 20);
    inorder(root);
    printf("\n");
    root = deletion(root, 10);
    inorder(root);
    printf("\n");
    return 0;
}