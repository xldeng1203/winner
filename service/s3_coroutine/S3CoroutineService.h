/*
   Copyright (C) 2014-2015 别怀山(fool). See Copyright Notice in core.h
*/
#ifndef H_S3_CALLBACK_SERVICE_H__
#define H_S3_CALLBACK_SERVICE_H__

namespace service{
	/** S3CoroutineService **/
	class S3CoroutineService: public core::CoroutineService{
		typedef core::CoroutineService Super;
		SUPPORT_NEWABLE
		DECLARE_CLASS_INFO
	public:
		enum{
			SERVICE_ID = SERVICE_ID_S3_COROUTINE,
		};
	protected:
		S3CoroutineService();
		virtual ~S3CoroutineService();
	public:
		static Service* New();
	protected:
		virtual bool on_load();
		virtual void on_unload();
		virtual void update(const int64_t now);
		virtual void register_command();
	private:
		static void on_first_request(Object* param);
		static void on_second_request(Object* param);
	};
}
#endif
