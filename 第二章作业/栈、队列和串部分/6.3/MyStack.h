#if !define DS_HOMEWORK_MyStack

#define DS_HOMEWORK_MyStack

using namespace std;

template <typename T>
class MyStack
{
	public:
	MyStack(int n = 50);
	// Purpose :Class constructor.
	// Parameters :Size of the stack.

	~MyStack();
	// Purpose :Class destructor.

	bool push(const T &item);
	// Purpose :Add an item on the top of the stack.
	// Parameters :item - the item will be added in the stack.
	// Return :true - operation successful.
	//         false - operation feiled.

	bool pop(T &item);
	// Purpose :Remove an item on the top of the stack.
	// Parameters :item - the top item will be copied to this reference.
	// Return :true - operation successful.
	//         false - operation failed.

	inline int stack_size() const;
	// Purpose :Inspector function.
	// Return :Size of the static.

	inline int stack_num() const;
	// Purpose :Inspector function.
	// Return :The number of items in the stack.

	void show() const;
	// Purpose :Show elements in stack.

	inline T get_top_element() const;
	// Purpose :Get the top element of the stack;
	// Return : The top element of the stack;

	private:
	int size;
	int top;
	T* data;
};

#endif