/*
   Copyright (C) 2014-2015 别怀山(fool). See Copyright Notice in core.h
*/
#ifndef H_CORE_COROUTINE_H__
#define H_CORE_COROUTINE_H__

namespace core{
	/** predeclare **/
	class CoroutinePool;

	/** Coroutine **/
	class Coroutine : public Object{
		SUPPORT_NEWABLE
		typedef Object Super;
	public:
		typedef void (*PFN_COROUTINE_TASK)(Object* arg);
		enum{
			STATUS_INIT =0,
			STATUS_DESTORY =1,
			STATUS_DEAD =2,
			STATUS_RUNNING =3,
			STATUS_WAITING =4,
			STATUS_IDLE =5,
		};
		enum{
			STACK_PROTECT_SIZE =64
		};
	public:
		Coroutine(CoroutinePool* pool);
		virtual ~Coroutine();
	public:
		virtual void init();
		virtual void finalize();
	public:
		void setId(const int64_t id);
		int64_t getId();
	public:
		int64_t getStatus();
		bool isDead();
		bool isRunning();
		bool isWaiting();
		bool isIdle();
	public:
		void setTask(PFN_COROUTINE_TASK pfn, Object* arg);
		PFN_COROUTINE_TASK getTask();
		Object* getArg();
	public:
		bool yield(Object* yield_param);
		Object* getYieldParam();
		static bool Yield(Object* param);
	public:
		int64_t resume(Object* param);
		Object* getResumeParam();
	public:
		static Coroutine* Running();
	private:
		static void _entry();
		bool _yield(Object* yield_param, const int64_t status);
		int64_t _resume(Object* param);
		void _valgrind_register();
		void _valgrind_unregister();
	private:
		ucontext_t m_ctx;
		int64_t m_id;
		CoroutinePool* m_coroutine_pool; // weak ptr
		char* m_stack;
		int64_t m_stack_size;
		int64_t m_status;
		PFN_COROUTINE_TASK m_task;
		Object* m_arg;
		Object* m_yield_param;
		Object* m_resume_param;
		int64_t m_valgrind_id;
		bool m_valgrind_registered;
	};
}

#endif
