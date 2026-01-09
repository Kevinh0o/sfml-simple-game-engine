#pragma once

#ifndef INPUT_H
#define INPUT_H

class c_Input {
public:
	bool up = false;
	bool left = false;
	bool down = false;
	bool right = false;

	void replicateInput(c_Input input) {
		up = input.up;
		left = input.left;
		down = input.down;
		right = input.right;
	}
};

#endif