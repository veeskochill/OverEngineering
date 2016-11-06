/*
	In this example, each command object also contains the target receiver.
	We could specify the receiver on invokation, and Execute would take an 
	Evaluator as a parameter. This way we could swap out evaluators based
	on other factors, or distribute the work to a number of receivers.
*/

#include <iostream>

using namespace std;

// Receiver
class FizzBuzzEvaluator
{
public:
	void Evaluate(int number)
	{
		cout << number << ": ";
		if(number % 3 == 0)
		{
			cout << "Fizz";
		}
		if(number % 5 == 0)
		{
			cout <<"Buzz";
		}
		cout << endl;
	}
};

// Abstract Base Class
class Command
{
public:
	virtual void Execute() = 0;
};

// Concrete Command Subclass
class EvaluateNumber : public Command
{
public:

	EvaluateNumber() : mReceiver(0), mNumber(0) {}

	void Initialize(FizzBuzzEvaluator* receiver, int number)
	{
		mReceiver = receiver;
		mNumber = number;
	}

	// delegates work to receiver
	void Execute()
	{
		if(mReceiver)
		{
			mReceiver->Evaluate(mNumber);
		}
	}

private:

	FizzBuzzEvaluator* mReceiver;

	int mNumber;
};

// Invoker
int main()
{
	int CommandArraySize = 100;

	FizzBuzzEvaluator FizzBuzz;

	//Compose a queue of commands to evaluate.
	EvaluateNumber* numberArray = new EvaluateNumber[CommandArraySize];
	for(int i = 0; i < CommandArraySize; ++i)
	{
		numberArray[i].Initialize(&FizzBuzz, i+1);
	}

	//Execute each command in the queue
	for(int i = 0; i < CommandArraySize; ++i)
	{
		numberArray[i].Execute();
	}

	delete[] numberArray;

	return 0;
}