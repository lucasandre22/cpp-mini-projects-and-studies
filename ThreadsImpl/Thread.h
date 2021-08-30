#define HAVE_STRUCT_TIMESPEC
#include <pthread.h>
#include <iostream>
#pragma once

class Thread {
private:
	pthread_t _threadID;
	pthread_attr_t _tAttribute;
	static pthread_mutex_t _mutex;

	static void* runThread(void* pThread) { 
		Thread* aux = static_cast<Thread*>(pThread);
		try {
			aux->run();
		}
		catch (...)
		{
			std::cout << "Erro ao executar a thread!";
		}
		return NULL;
	}
	virtual void run() {} //metodo que executar�
public:
	Thread() {}
	virtual ~Thread() {}
	void join() { pthread_join(_threadID,NULL); } //espera thread acabar
	void yield() { sched_yield(); } //libera processador
	void start() 
	{
		int status = pthread_attr_init(&_tAttribute);
		status = pthread_attr_setscope(&_tAttribute, PTHREAD_SCOPE_SYSTEM);

		status = pthread_create(&_threadID, &_tAttribute, Thread::runThread, (void*)(this));

		status = pthread_attr_destroy(&_tAttribute);
	}
	void lock() {
		if (_mutex == NULL)
			pthread_mutex_init(&Thread::_mutex, NULL);
		pthread_mutex_lock(&Thread::_mutex);
	}
	void unlock() {
		if (Thread::_mutex != NULL)
			pthread_mutex_unlock(&Thread::_mutex);
	}

	//criaria uma superclasse derivada dessa e de outra, como chef�o por exemplo
};

pthread_mutex_t Thread::_mutex = NULL;
