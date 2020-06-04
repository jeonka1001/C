
#include <stdio.h>
#include <stdlib.h>
// 자식 노드가 없으면 립 노드 -> 단말노드
// 부모 노드가 없으면 루트 노드 -> 최상위 노드
// 트리 검색의 효율성을 높히기 위해서는 트리의 높이(레벨)을 낮추면 된다.
//  --> 노드가 자식을 많이 갖고있으면 높이가 낮아진다. ( 보통은 한 부모당 자식을 두개 갖도록 만든다 ) => 이진트리
// 이진트리는 검색이 빠르다. (왼쪽에 작은 값 오른족에 큰 값)

// 이진 검색트리 (BST)
typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;
Node *root;

int bstfind(int data){
    Node *node = root;
    while(node !=NULL){
        if(data == node->data){
            return 1;
        }
        if(data > node->data){
            node=node->right;
        }
        else{
            node=node->left;
        }
    }
    return 0;
}
int bstInsert(int data){
    if(root == NULL){
        root = calloc(1,sizeof(Node));
        root->data = data;
        return 0;
    }
    Node* node = calloc(1,sizeof(Node));
    node->data= data;
    if(bstfind(data)==0){ // 중복값 x
        Node* cur = root;
        Node* prev =NULL ;
        while(cur!=NULL){
            prev = cur;
            if(cur->data < data){
                cur=prev->right;
            }
            else{
                cur=prev->left;
            }
        }
        if( prev->data < data){
            prev->right = node;
        }
        else{
            prev->left = node;
        }
        return 0;
    }
    free(node);
    return -1;
}
int printNode(Node* cur){
    if(cur == NULL){
        return 0;
    }
    printNode(cur->left);
    printf("%d ",cur->data);
    printNode(cur->right);
    return 1;
}

int main(){
    int arr[8] = {4,2,1,3,6,5,7,8};
    for(int i  = 0 ; i < 8 ; i ++){
        bstInsert(arr[i]);
    }
    printNode(root);
}
