/*
   Copyright (C) 2014-2015 别怀山(fool). See Copyright Notice in core.h
*/
#ifndef H_CORE_COROUTINE_POOL_H__
#define H_CORE_COROUTINE_POOL_H__

namespace core{
	/** CoroutinePool **/
	class CoroutinePool : public Object{
		SUPPORT_NEWABLE
		typedef Object Super;
	public:
		enum{
			MAX_IDLE_COROUTINE_COUNT =1024,
			MAIN_STACK_SIZE =4 * 1024 * 1024 // 4 Mb
		};
	private:
		CoroutinePool();
		virtual ~CoroutinePool();
	public:
		virtual void init();
		virtual void finalize();
	public:
		char* getMainStack();
		int64_t getMainStackSize();
		char* getMainStackHighAddr();
		ucontext_t* getMainContext();
	public:
		int64_t resume(const int64_t id, Object* param);
		int64_t go(Coroutine::PFN_COROUTINE_TASK pfn, Object* arg, int64_t& cr_id);
	private:
		int64_t _resume(Coroutine* cr, Object* param);
		Coroutine* _prepare_coroutine(Coroutine::PFN_COROUTINE_TASK pfn, Object* arg);
	private:
		char m_main_stack[MAIN_STACK_SIZE];
		ucontext_t m_main_context;

		Hash* m_active_coroutine_table;
		Array* m_idle_coroutine_list;

		int64_t m_coroutine_id;
	};
}

#endif
