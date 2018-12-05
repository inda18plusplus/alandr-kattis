//
// Created by lunar on 04/12/18.
//

#ifndef ALANDR_KATTIS_TREE_HPP
#define ALANDR_KATTIS_TREE_HPP


class Tree {

	struct Node {
		Node(int levels);

		int calcSum();

		int _value = 0;
		int _size = 0;

		Node* _lhs = nullptr;
		Node* _rhs = nullptr;

		int& operator[](int index);
	};

	Node* _root;
	int _size;

public:
	Tree(int size);

	int& operator[](int index);

	int getUpTo(int index);

};


#endif //ALANDR_KATTIS_TREE_HPP
