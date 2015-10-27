#include <stdio.h>

int push(int number);
int pop();
int top();
int size();
int isEmpty();
int isFull();

int arr[5];
int position = -1;

int main() {
	printf("Please enter a postfix expression:\n");
	while (1) {
		char temp = 0;
		scanf(" %c", &temp);
		if (temp == '=') {
			break;
		}
		if (temp >= '0' && temp <= '9') {
			push(temp - 48);
		} else {
			if (size() < 2) {
				printf("Too few values.\n");
				break;
			}
			int a = top();
			pop();
			int b = top();
			pop();
			switch (temp) {
				case '+':
					push(a + b);
					break;
				case '-':
					push(a - b);
					break;
				case '*':
					push(a * b);
					break;
				default:
					printf("Invalid operation\n");
					return 0;
			}
		}
	}
	if (size() == 1) {
		printf("The answer is %d", top());
		pop();
		return (0);
	} else {
		printf("Too many values given.\n");
		return (0);
	}
}

int push(int number) {
	if (position == 5) {
		return (5);
	}
	position++;
	arr[position] = number;
	return (position);
}

int pop() {
	if (position < 0) {
		return 0;
	}
	arr[position] = 0;
	position--;
	return (position);
}

int top() {
	return (arr[position]);
}

int size() {
	return (position + 1);
}

int isEmpty() {
	return (position == 0);
}

int isFull() {
	return (position == 5);
}