#include <iostream>

using namespace std;

class Sender
{
public:
	virtual ~Sender() {}
	virtual void send() = 0;
};

class Receiver
{
public:
	virtual ~Receiver() {}
	virtual void receive() = 0;
};

class Communicate : public Sender, public Receiver
{
public:
	virtual void send() override  { cout << " SEND " << endl; }
	virtual void receive() override { cout << " RECEIVE " << endl; }
};

class Client
{
public:
	Client(Sender* _sender)
	{
		sender = _sender;
	}

	void send()
	{
		sender->send();
	}

private:
	Sender* sender;
};

class Server
{
public:
	Server(Receiver* re)
	{
		receiver = re;
	}

	void receive()
	{
		receiver->receive();
	}

private:
	Receiver* receiver;
};

int main()
{
	Communicate * com = new Communicate();

	Client * c = new Client(com);
	Server * s = new Server(com);

	c->send();
	s->receive();

	return 0;
}