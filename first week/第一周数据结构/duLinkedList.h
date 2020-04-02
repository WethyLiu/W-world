/***************************************************************************************
 *	File Name				:	duLinkedList.h
 *	CopyRight				:	2020 QG Studio
 *	SYSTEM					:   win10
 *	Create Data				:	2020.3.28
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/

 /**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/

#ifndef DULINKEDLIST_H_INCLUDED
#define DULINKEDLIST_H_INCLUDED

/**************************************************************
*	Macro Define Section
**************************************************************/

#define OVERFLOW -1

/**************************************************************
*	Struct Define Section
**************************************************************/

// define element type
typedef int ElemType;

// define struct of linked list
typedef struct DuLNode {
	ElemType data;
  	struct DuLNode *prior;
	struct DuLNode  *next;
} DuLNode, *DuLinkedList;

// define Result
typedef enum  {
	error=0,
	success=1,
} Result;


/**************************************************************
*	Prototype Declare Section
**************************************************************/

/**
 *  @name        : Result InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Result
 *  @notice      : None
 */
Result InitList_DuL(DuLinkedList *L);

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : Result
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L);

/**
 *  @name        : Result InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : Result
 *  @notice      : None
 */
Result InsertBeforeList_DuL(DuLNode *p, DuLNode *q);

/**
 *  @name        : Result InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Result
 *  @notice      : None
 */
Result InsertAfterList_DuL(DuLNode *p, DuLNode *q);

/**
 *  @name        : Result DeleteList_DuL(DuLNode *p)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p
 *	@return		 : Result
 *  @notice      : None
 */
Result DeleteList_DuL(DuLNode *p);

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Result
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L);


 /**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif
