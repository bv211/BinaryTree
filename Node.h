#pragma once

struct Node {
	int value{};

	Node* parent{ nullptr };
	Node* left{ nullptr };
	Node* right{ nullptr };
};
