#ifndef LINEAR_H
#define LINEAR_H

#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

/** C++实现单向链表**/
class Node{
    friend class LinkList;
public:
    int data;
    Node *pPre, *pNext;
};

class LinkList{
    friend class Node;
public:
    LinkList();
    ~LinkList();

    void CreateList(const int val);
    void InsertNode(const int pos, const int val );
    void TraverseLinkList(); // 遍历链表
    bool IsEmpty();
    int GetValue(const int pos);
    int GetLength();
    void DeleteNode(const int pos);
    void DeleteLinkList(); 
private:
    Node *head;


};

inline LinkList::LinkList()
{
    head = new Node;
    head->data = 0;
    head->pNext = NULL;
}
inline LinkList::~LinkList()
{
    delete head; 
}

inline void LinkList::CreateList(int val)
{
    if(val < 0)
        cout << "input number of Node error" << endl;
    
    else{

        srand(std::time(0));
        Node *pnew, *ptemp;
        ptemp = head; // 没有这句话会发生段错误
        int ival = val;
        while( ival-- > 0){
            int temp = rand() %100 +1;
            pnew = new Node;
            pnew->data = temp;
            // cout << pnew->data << endl; 
            pnew->pNext = NULL; 
            ptemp->pNext = pnew;
            ptemp = pnew;
        }
    }
}

inline void LinkList::TraverseLinkList()
{
    Node *p = head->pNext;

    while(p != NULL){
        cout << p->data << " ";
        p = p->pNext;
    }

    cout << endl;



}

// 头节点之后的节点算第一个节点
inline void LinkList::InsertNode(int pos, int val)
{
    if(pos <= 0)
        cout << "insert error" << endl;
    else{
        Node *ptemp = head;
        for(int i = 1; i < pos; i++){
            ptemp = ptemp->pNext;
        }

        Node *pnew = new Node;
        pnew->data = val;
        // cout << endl;
        cout << "Insert position: " << pos << 
            " Insert value: " << val << endl;
        pnew->pNext = ptemp->pNext; 
        ptemp->pNext = pnew;

    }

}

inline void LinkList::DeleteNode(int pos)
{
    if(pos <= 0)
        cout << "delete Node error" << endl;
    else{
        Node *ptemp = head;
        for(int i = 1; i < pos; i++){
            ptemp = ptemp->pNext;
        }
        Node *pdelete = ptemp->pNext;
        ptemp->pNext = pdelete->pNext;
        cout << "delete Node postion: " << pos << 
            " delete Node value: " << pdelete->data << endl;
        delete pdelete;
        pdelete = NULL;
    }
}

inline bool LinkList::IsEmpty()
{
    if(head->pNext)
        return true;
    else
        return false;
}

inline int LinkList::GetValue(const int pos)
{
    if(pos <= 0 || pos > GetLength() ){
        cout << "get value error"<< endl;
        return -1;
    }
    else{

        Node *ptemp = head;
        for( int i = 0; i < pos; i++){
            ptemp = ptemp->pNext;
        }

        return ptemp->data;
    }
}

inline int LinkList::GetLength()
{
    Node *ptemp = head;
    int num = 0;
    while( ptemp->pNext != NULL ){
        num++;
        ptemp = ptemp->pNext;
    }

    return num;
}

/**注意删除整个链表的手法***/
// 错误示范
// void LinkList::DeleteLinkList()
// {
//     Node *ptemp = head;
//     while( ptemp->pNext != NULL ){
//         delete ptemp;
//         ptemp = ptemp->pNext;
//     }
// }

inline void LinkList::DeleteLinkList()
{
    Node *ptemp = NULL, *pdelete = head->pNext;
    while( pdelete != NULL ){
        ptemp = pdelete->pNext;
        head->pNext = ptemp;
        delete pdelete;
        pdelete = ptemp;
    }

    // delete head; // 不能加这一句，加了之后编译不报错，运行报错
}


/** C++实现双向链表**/
class DoubleLinkList{
    friend class Node;
    friend class LinkList;
public:
    DoubleLinkList();
    ~DoubleLinkList();

    void CreateList(const int val);
    void InsertNode(const int pos, const int val );
    void TraverseLinkList(); // 遍历链表
    bool IsEmpty();
    int GetValue(const int pos);
    int GetLength();
    void DeleteNode(const int pos);
    void DeleteLinkList(); 
private:
    Node *head;
};

inline DoubleLinkList::DoubleLinkList()
{
    head = new Node;
    head->data = 0;
    head->pPre = NULL;
    head->pNext = NULL;
}

inline DoubleLinkList::~DoubleLinkList()
{
    delete head;
}

inline void DoubleLinkList::CreateList(const int val)
{
    if(val <= 0)
        cout << "creat double list error" << endl;
    else{
        Node *ptemp = head; // 定义一个, 初始化一个
        srand(std::time(0));
        for(int i = 0; i < val; i++ ){
            Node *pnew = new Node;
            int temp = rand() %100 +1;
            pnew->data = temp;
            pnew->pNext = ptemp->pNext;
            pnew->pPre = ptemp;
            ptemp->pNext = pnew;

            ptemp = pnew;
        }
    }
}

inline void DoubleLinkList::TraverseLinkList()
{
    Node *ptemp = head->pNext;
    while(ptemp != NULL){
        cout << ptemp->data << " ";
        ptemp = ptemp->pNext;
    }

    cout << endl;
}

inline int DoubleLinkList::GetLength()
{
    int i = 0;
    Node *ptemp = head->pNext;

    while(ptemp != NULL){
        i++;
        ptemp = ptemp->pNext;
    }

    return i;
}

inline void DoubleLinkList::InsertNode(const int pos, const int val)
{
    if(pos <= 0 || pos > GetLength()+1) 
    {
         cout << "insert error" << endl;
         return ;
    }
       
    Node *ptemp = head;
    for(int i = 1; i < pos; i++){
        ptemp = ptemp->pNext;
    }

    Node *pnew = new Node;
    pnew->data = val;
    pnew->pNext = ptemp->pNext;
    pnew->pPre = ptemp;
    ptemp->pNext = pnew;
}

inline void DoubleLinkList::DeleteNode(const int pos)
{
    if(pos <= 0 || pos > GetLength()){
        cout << "delete Node error" << endl;
        return ;
    }
    else{
        Node *ptemp = head;

        for(int i = 1; i < pos; i++){
            ptemp = ptemp->pNext;
        }

        Node* pdelete = ptemp->pNext;
        ptemp->pNext = pdelete->pNext;
        pdelete->pNext->pPre = ptemp;

        delete pdelete;


    }

}

inline bool DoubleLinkList::IsEmpty()
{
    if(head->pNext)
        return true;
    else
        return false;

}

inline int DoubleLinkList::GetValue(const int pos)
{
    if(pos <= 0 || pos > GetLength()){
        cout << "get value error" << endl;
        return -1;
    }

    Node *ptemp = head->pNext;
    for(int i = 1; i < pos; i++){
        ptemp = ptemp->pNext;
    }

    int val = ptemp->data;

    return val;
}

inline void DoubleLinkList::DeleteLinkList()
{
    // 只能删除一半的节点
    // Node *pdelete = head->pNext;
    // for(int i = 0; i < GetLength(); i++){
    //     cout << i << endl;
    //     Node *ptemp = pdelete->pNext;
    //     head->pNext = ptemp;
    //     if (ptemp != NULL){}
    //         ptemp->pPre = head;

	// 	delete pdelete;
	// 	pdelete = ptemp;
    // }

    Node *pdelete = head->pNext;
	while (pdelete != NULL) {
		Node *ptemp = pdelete->pNext;
		head->pNext = ptemp;
		if (ptemp != NULL)
			ptemp->pPre = head;
		delete pdelete;
		pdelete = ptemp;
    }

}



// template <typename elemType>
// class Node;

// template <typename elemType>
// class LinearList;

// template <typename valType>
// class Node{
//     friend class LinearList<valType>;
// public:
//     Node();
//     Node(const valType &val);
//     bool insert_value( const int pos, const valType &elem);


// private:
//     valType _val;
//     Node* next;


// };



// template <typename valType>
// inline Node<valType>::Node(const valType &val)
//     :_val(val)
// {
//     next = 0;
// }

// // template <typename valType>
// // bool Node<valType>::insert_value(const int pos, const valType &elem)
// // {
    
// // }



// template <typename elemType>
// class LinearList{
//     friend class Node<elemType>;
// public:
//     void init_list(const int &elem);
//     bool insert(const int pos, const elemType & );
//     elemType dis() { return _root->_val; };
// private:
//     Node<elemType> *_root;
//     Node<elemType> *node;
//     Node<elemType> *p;

// };

// template <typename elemType>
// void LinearList<elemType>::init_list(const int &elem)
// {
//     std::srand(std::time(0));
//     // if( ! _root )
//     // {
//         int temp = rand() %100 +1;
//         _root = new Node<elemType>( temp );
//     // }
//     // _root->next = NULL;

//     // Node<elemType>* str_node = _root;

//     // for(int i = 0; i < elem; i++)
//     // {
//     //     int temp = rand()%100 +1;
//     //     p = new Node<elemType>( temp );
//     //     p->next = str_node->next;
//     //     str_node->next = p;


//     // }
// }

// template <typename elemType>
// bool LinearList<elemType>::insert(const int pos, const elemType &elem)
// {
//     if( ! _root )
//     {
//         _root = new Node<elemType>( elem );
//     }
//     else
//     {
//         // _root->insert_value( pos,elem );
//         Node<elemType> *p = 0;
//         int j = 1;

//         while( p && j < pos )
//         {
//             p = p->next;
//             ++j;
//         }
//         if( !p || j > pos )
//             return false;
        
//         node = new Node<elemType>( elem );
//         node->next = p->next;
//         p->next = node;

//         return true;



//     }


  

// }


#endif