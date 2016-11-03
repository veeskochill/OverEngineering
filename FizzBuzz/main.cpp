#include <iostream>

using namespace std;

class Handler
{
public:
	
	Handler() : successor(NULL) {};
	
	Handler* GetSuccessor()
	{
		return successor;
	};

	void Add(Handler* next)
	{
		if(successor)
		{
			successor->Add(next);
		}
		else
		{
			successor = next;
		}
	}

	virtual void Evaluate(int input)
	{
		if(successor)
		{
			successor->Evaluate(input);
		}
		else
		{
			cout << endl;
		}
	};

private:
	
	Handler* successor;

};

class FizzHandler : public Handler
{
public:

	virtual void Evaluate(int input) override
	{
		if(input % 3 == 0)
		{
			cout << "Fizz";
		}
		Handler::Evaluate(input);
	};
};

class BuzzHandler : public Handler
{
public:

	virtual void Evaluate(int input) override
	{
		if(input % 5 == 0)
		{
			cout << "Buzz";
		}
		Handler::Evaluate(input);
	};
};

int main()
{

	FizzHandler myFizz;
	BuzzHandler myBuzz;

	myFizz.Add(&myBuzz);
	for(int i = 1; i< 100; ++i)
	{
		cout << i << ": ";
		myFizz.Evaluate(i);
	}
	return 0;
}