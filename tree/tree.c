#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
    int data;
    struct tree *l,*r;
}tree;

tree *insert(tree *rt,int x){
    if(rt==NULL){
        rt = (tree*)malloc(sizeof(tree));
        rt->data = x;
        rt->l=rt->r=NULL;
    }
    if(rt->data>x)rt->l = insert(rt->l,x);
    if(rt->data<x)rt->r = insert(rt->r,x);
    return rt;
}

tree *find(tree *rt,int x){
    if(rt==NULL)return NULL;
    if(rt->data==x)return rt;
    if(rt->data>x)return find(rt->l,x);
    if(rt->data<x)return find(rt->r,x);
}

int min(tree *rt){
    if(rt==NULL)return -1;
    tree *ptr = rt;
    while(ptr->l!=NULL){
        ptr = ptr->l;
    }
    return ptr->data;
}

int max(tree *rt){
    if(rt==NULL)return -1;
    tree *ptr = rt;
    while(ptr->r!=NULL){
        ptr = ptr->r;
    }
    return ptr->data;
}

int minrec(tree *rt){
    if(rt==NULL)return -1;
    else{
        if(rt->l==NULL)return rt->data;
        else return minrec(rt->l);
    }
}

void inorder(tree *t){
    if(t){
        inorder(t->l);
        printf("%d ",t->data);
        inorder(t->r);
    }
}

int identical(tree *t1,tree *t2){
    if(t1==NULL && t2==NULL){
        return 1;
    }
    if(t1 && t2){
        return (t1->data==t2->data)&&(identical(t1->l,t2->l))&&(identical(t1->r,t2->r));
    }
    return 0;
}

int cnt(tree *t){
    if(t==NULL)return 0;
    return 1+cnt(t->l)+cnt(t->r);
}

int isComplete(tree *t,int i,int c){
    if(t==NULL)return 0;
    if(i>=c)return 0;
    return isComplete(t->l,2*i+1,c)&&isComplete(t->r,2*i+2,c);
}

void main(){
    tree *t1,*t2;
    t1 = t2 = NULL;
    t1 = insert(t1,10);
    t1 = insert(t1,5);
    t1 = insert(t1,1);
    t1 = insert(t1,50);
    t1 = insert(t1,40);
    t1 = insert(t1,100);
    printf("%d",isComplete(t1,0,cnt(t1)));
}
