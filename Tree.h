#pragma once
#include "Node.h"
#include <iostream>

using namespace std;

class Tree {
	Node* _root{ nullptr };

public:
	~Tree() {
		erase(_root);
	}

	void print() {
		print(_root);
	}

	void print(Node* node) {
		if (node == nullptr) return;

		print(node->left);
		cout << node->value << endl;
		print(node->right);
	}

	Node* get_root() const {
		return _root;
	}

	void insert(int value) {
		auto* node = create_node(value);
		Node* parent = nullptr;
		Node* current = _root;

		while (current != nullptr) {
			parent = current;

			if (current->value > node->value)
				current = current->left;
			else
				current = current->right;
		}

		node->parent = parent;

		if (parent == nullptr)
			_root = node;
		else if (node->value < parent->value)
			parent->left = node;
		else
			parent->right = node;
	}

	Node* search(int value) {
		auto* current = _root;

		while (current != nullptr) {
			if (value == current->value)
				return current;

			if (value > current->value)
				current = current->right;
			else
				current = current->left;
		}

		return nullptr;
	}

	void erase(int value) {
		erase(search(value));
	}

	void erase(Node* node) {
		if (node == nullptr) return;

		erase(node->left);
		erase(node->right);

		if (node->parent != nullptr) {
			if (node->parent->left == node)
				node->parent->left = nullptr;
			else
				node->parent->right = nullptr;
		}
		else _root = nullptr;

		delete_node(node);
	}

private:
	Node* create_node(int value) {
		return new Node{ value };
	}

	void delete_node(Node*& node) {
		delete node;
		node = nullptr;
	}
};
